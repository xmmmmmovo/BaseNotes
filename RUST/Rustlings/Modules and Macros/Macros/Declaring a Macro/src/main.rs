fn main() {
    my_macro!();
}

macro_rules! my_macro {
    () => {
        println!("Check out my macro!");
    };
}

/*the main function declaration should be below the macro declaration*/
