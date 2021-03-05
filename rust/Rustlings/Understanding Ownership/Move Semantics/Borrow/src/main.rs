use std::borrow::{Borrow, BorrowMut};

fn main() {
    let vec0 = Vec::new();

    let vec_0 = vec0.clone();

    let mut vec1 = fill_vec(vec_0);

    // Do not change the following line!
    println!("{} has length {} content `{:?}`", "vec0", vec0.len(), vec0);

    vec1.push(88);

    println!("{} has length {} content `{:?}`", "vec1", vec1.len(), vec1);
}

fn fill_vec(mut vec: Vec<i32>) -> Vec<i32> {
    /*you could borrow vec value*/

    vec.push(22);
    vec.push(44);
    vec.push(66);

    vec /*and then you don't have to return anything here*/
}
