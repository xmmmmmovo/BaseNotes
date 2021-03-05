use std::cmp::Ordering;

pub fn calculateprice(num:i32) -> i32 {
    if num > 40 { num } else { num * 2 }
}
