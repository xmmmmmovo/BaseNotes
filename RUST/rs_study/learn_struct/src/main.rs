fn main() {
    #[derive(Debug)]
    struct User {
        name: String,
        account: String,
        nonce: u64,
        active: bool,
    }

    let a = User {
        name: String::from("aa"),
        account: String::from("100_000"),
        nonce: 12,
        active: true,
    };

    println!("{:#?}", a);
}
