use std::error::Error;

pub fn generate_nametag_text<'a>(name: String) -> Result<String, &'a str> {
    if name.len() > 0 {
        Ok(format!("Hi! My name is {}", name))
    } else {
        // The error message should be: "`name` was empty; it must be nonempty."
        Err("`name` was empty; it must be nonempty.")
    }
}
