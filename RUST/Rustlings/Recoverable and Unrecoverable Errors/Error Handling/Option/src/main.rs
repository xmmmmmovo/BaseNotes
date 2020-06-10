fn main() {
    let mut list = vec![3];

    let last = list.pop().unwrap();
    println!("The last item in the list is {:?}", last);

    let second_to_last = list.pop().unwrap()/*return 3 even if the pop panicks*/;
    println!(
        "The second-to-last item in the list is {:?}",
        second_to_last
    );
}
