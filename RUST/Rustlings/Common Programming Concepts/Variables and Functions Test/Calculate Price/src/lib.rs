use std::cmp::Ordering;

pub fn calculateprice(order: i32) -> i32 {
    if order <= 40 {
        2 * order
    } else {
        order
    }
}
