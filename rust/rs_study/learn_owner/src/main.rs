fn takes_ownership(str: &String) {
    println!("{}", str);
}

fn make_copy(i: i32) {
    println!("{}", i);
}

fn main() {
    let s = String::from("Hello");
    takes_ownership(&s);
    println!("{}", s);

    let i = 32;
    make_copy(i);
    println!("{}", i);
}