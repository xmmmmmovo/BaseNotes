use std::{
    io::{ErrorKind, Read, Write},
    net::TcpListener,
    sync::mpsc,
    thread,
    time::Duration,
    usize,
};

const MSG_LEN: usize = 1024;
const LOCAL_SERVER: &str = "127.0.0.1:8888";

fn main() {
    let server = TcpListener::bind(LOCAL_SERVER).expect("error");
    server
        .set_nonblocking(true)
        .expect("failed to set_nonblocking");
    let mut clients = vec![];
    let (tx, rx) = mpsc::channel::<String>();
    loop {
        if let Ok((mut socket, addr)) = server.accept() {
            println!("{} connected", addr);
            clients.push(socket.try_clone().expect("failed to clone"));

            let tx = tx.clone();
            thread::spawn(move || loop {
                let mut buffer = vec![0; MSG_LEN];
                match socket.read_exact(&mut buffer) {
                    Ok(_) => {
                        let msg = buffer
                            .into_iter()
                            .take_while(|&x| x != 0)
                            .collect::<Vec<_>>();

                        let msg_string = String::from_utf8(msg).expect("Invalid utf8 message");
                        println!("{}: {:?}", addr, msg_string);
                        tx.send(msg_string).expect("failed message to chan");
                    }
                    Err(ref err) if err.kind() == ErrorKind::WouldBlock => (),
                    Err(_) => {
                        println!("Closing connection with {}", addr);
                        break;
                    }
                }
                thread::sleep(Duration::from_millis(100));
            });
        }

        if let Ok(msg) = rx.try_recv() {
            clients = clients
                .into_iter()
                .filter_map(|mut client| {
                    let mut buffer = msg.clone().into_bytes();
                    buffer.resize(MSG_LEN, 0);
                    client.write_all(&buffer).map(|_| client).ok()
                })
                .collect::<Vec<_>>();
        }
        thread::sleep(Duration::from_millis(100));
    }
}
