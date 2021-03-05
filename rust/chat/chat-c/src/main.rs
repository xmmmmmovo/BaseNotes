use std::{
    io::{stdin, ErrorKind, Read, Write},
    net::TcpStream,
    sync::mpsc,
    thread,
    time::Duration,
    vec,
};

const MSG_LEN: usize = 1024;
const LOCAL_SERVER: &str = "127.0.0.1:8888";

fn main() {
    let mut client = TcpStream::connect(LOCAL_SERVER).expect("connect failed");
    client.set_nonblocking(true).expect("failed to nonblocking");
    let (tx, rx) = mpsc::channel::<String>();
    thread::spawn(move || loop {
        let mut buffer = vec![0; MSG_LEN];
        match client.read_exact(&mut buffer) {
            Ok(_) => {
                let msg = buffer
                    .into_iter()
                    .take_while(|&x| x != 0)
                    .collect::<Vec<_>>();
                let msg_string = String::from_utf8(msg).unwrap();
                println!("recv: {}", msg_string);
            }
            Err(ref err) if err.kind() == ErrorKind::WouldBlock => (),
            Err(_) => {
                println!("server down");
                break;
            }
        }

        match rx.try_recv() {
            Ok(msg) => {
                let mut buffer = msg.clone().into_bytes();
                buffer.resize(MSG_LEN, 0);
                client.write_all(&buffer).expect("writing to socket failed");
                println!("msg send: {:?}", msg);
            }
            Err(mpsc::TryRecvError::Empty) => (),
            Err(mpsc::TryRecvError::Disconnected) => break,
        }
        thread::sleep(Duration::from_millis(100));
    });

    println!("msg:");
    loop {
        let mut buffer = String::new();
        stdin()
            .read_line(&mut buffer)
            .expect("reading from stdin failed");
        let msg = buffer.trim().to_string();
        if msg == "q" || tx.send(msg).is_err() {
            break;
        }
    }
    println!("offline");
}
