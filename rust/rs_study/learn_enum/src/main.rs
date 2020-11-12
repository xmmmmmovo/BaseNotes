enum Message {
    Quit,
    Move { x: i32, y: i32 },
    Write(String),
    Change(i32, i32, i32),
}

impl Message {
    fn print(&self) {
        match self {
            Message::Quit => println!("Quit"),
            Message::Move { x, y } => println!("Move x = {}, y = {}", x, y),
            Message::Change(a, b, c) => println!("Change a = {}, b = {}, c = {}", a, b, c),
            //_ => println!("Write")
            Message::Write(s) => println!("Write = {}", s)
        }
    }
}

fn main() {
    enum IpAddKind {
        V4(u8, u8, u8, u8),
        V6(String),
    }
    let v4 = IpAddKind::V4(127, 0, 0, 1);
    let v6 = IpAddKind::V6(String::from("::1"));

    let msg = Message::Change(1, 2, 3);
    msg.print();
}
