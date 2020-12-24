use std::fs::File;
use std::io;
use std::io::Read;

fn main() {
    // let f = File::open("hello.txt");
    // let r = match f {
    //     Ok(file) => file,
    //     Err(error) => panic!("{:?}", error),
    // };
    // let f = File::open("hello.txt").unwrap();
    // let f = File::open("hello.txt").expect("error");
    let r = read_username_from_file();
    match r {
        Ok(username) => println!("userrname: {}", username),
        Err(e) => println!("{:?}", e),
    }
}

// fn read_username_from_file() -> Result<String, io::Error> {
//     let f = File::open("hello.txt");
//     let mut f = match f {
//         Ok(file) => file,
//         Err(error) => return Err(error),
//     };
//     let mut s = String::new();
//     match f.read_to_string(&mut s) {
//         Ok(_) => Ok(s),
//         Err(error) => Err(error),
//     }
// }

// fn read_username_from_file() -> Result<String, io::Error> {
//     let mut f = File::open("hello.txt")?;
//     let mut s = String::new();
//     f.read_to_string(&mut s)?;
//     Ok(s)
// }

fn read_username_from_file() -> Result<String, io::Error> {
    let mut s = String::new();
    File::open("hello.txt")?.read_to_string(&mut s)?;
    Ok(s)
}