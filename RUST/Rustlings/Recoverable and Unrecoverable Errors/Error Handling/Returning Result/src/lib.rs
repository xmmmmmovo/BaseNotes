use std::error::Error;

pub fn generate_nametag_text(name: String) -> Option<String> {
    if name.len() > 0 {
        Some(format!("Hi! My name is {}", name))
    } else {
        // The error message should be: "`name` was empty; it must be nonempty."
        None
    }
}
