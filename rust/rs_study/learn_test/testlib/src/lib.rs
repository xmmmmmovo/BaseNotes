pub mod animal;

#[cfg(test)]
mod tests {
    use crate::animal::Cat;

    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }

    #[test]
    fn use_cat() {
        Cat::hello();
    }
}
