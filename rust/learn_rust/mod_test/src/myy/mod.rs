mod inaccessible;
pub mod nested;

pub fn function() {
    println!("called `myy::function()`");
}

fn private_function() {
    println!("called `myy::private_function()`");
}

pub fn indirect_access() {
    print!("called `myy::indirect_access()`, that\n> ");

    private_function();
}