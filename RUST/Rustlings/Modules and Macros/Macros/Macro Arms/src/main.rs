macro_rules! my_macro {
    () => {
        println!("Check out my macro!");
    }/*separate the "macro arms" here*/
    ($val:expr) => {
        println!("Look at this other macro: {}", $val);
    }
}

fn main() {
    my_macro!();
    my_macro!(7777);
}
