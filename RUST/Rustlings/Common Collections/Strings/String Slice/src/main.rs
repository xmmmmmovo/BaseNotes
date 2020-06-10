fn main() {
    let word = String::from("green"); // Try not changing this line :)
    if is_a_color_word(/*coerce the String into a string slice here*/word) {
        println!("That is a color word I know!");
    } else {
        println!("That is not a color word I know.");
    }
}

fn is_a_color_word(attempt: &str) -> bool {
    attempt == "green" || attempt == "blue" || attempt == "red"
}
