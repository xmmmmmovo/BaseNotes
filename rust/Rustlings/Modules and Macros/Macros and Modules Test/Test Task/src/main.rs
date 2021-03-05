macro_rules! my_macro {
    ($val: expr) => {
        "Hello, world!"
    };
}

fn main() {
    if my_macro!("world!") != "Hello world!" {
        panic!("Oh no! Wrong output!");
    }
}
