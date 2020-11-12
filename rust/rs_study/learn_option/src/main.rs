fn main() {
    let some_number = Some(5);
    let some_string = Some(String::from("string"));
    let absence: Option<i32> = None;

    let y: Option<i32> = Some(5);

    let tmp = match y {
        Some(i) => i,
        None => 0,
    };
    let k: Option<i32> = None;
    println!("{:?}", tmp);
}
