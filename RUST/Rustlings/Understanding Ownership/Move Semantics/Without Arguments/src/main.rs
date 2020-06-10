fn main() {
    let vec0 = Vec::new();

    let mut vec1 = fill_vec(vec0);

    println!("{} has length {} content `{:?}`", "vec1", vec1.len(), vec1);

    vec1.push(88);

    println!("{} has length {} content `{:?}`", "vec1", vec1.len(), vec1);
}

// `fill_vec()` no longer take `vec: Vec<i32>` as argument
fn fill_vec() -> Vec<i32> {
    //The vector declaration should be here

    let mut vec = vec /*assign the created variable here*/;

    vec.push(22);
    vec.push(44);
    vec.push(66);

    vec
}
