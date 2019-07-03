use std::io;
use rand::Rng;

fn main() {
    println!("Guess the number!");

    let scret_number = rand::thread_rng().gen_range(1, 101);

    println!("Please input your guess.");

    // 直接let默认定义为不可变变量
    // let mut 默认为可变变量
    let mut guess = String::new();

    io::stdin().read_line(&mut guess)
        .expect("Failed to read line");

    println!("You guessed : {}", guess);
}