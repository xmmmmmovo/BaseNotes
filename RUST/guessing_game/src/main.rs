use std::io;
use rand::Rng;
use std::cmp::Ordering;

fn main() {
    // const 常量 不可以用mut修饰
    // 数字中可以加入下划线增加可读性
    const MAX_POINT: u32 = 100_000;
    println!("Guess the number!");

    let scret_number = rand::thread_rng().gen_range(1, 101);
    println!("Number is {}", scret_number);

    loop {
        println!("Please input your guess.");

        // 直接let默认定义为不可变变量
        // let mut 默认为可变变量
        let mut guess = String::new();

        io::stdin().read_line(&mut guess).expect("Failed to read line");

        // 惯用方法 把except改成对Result的match
        let guess: u32 = match guess.trim().parse() {
            Ok(num) => num,
            Err(_) => continue,
        };
        println!("You guessed : {}", guess);

        match guess.cmp(&scret_number) {
            Ordering::Less => println!("Too Small"),
            Ordering::Greater => println!("Too Big"),
            Ordering::Equal => {
                println!("You Win!!!");
                break;
            },
        }
    }

}