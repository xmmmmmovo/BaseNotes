// 测试用的程序
fn main() {
    let mut v = vec![1, 2, 3, 4, 5];
    for i in v.iter() {
    }
    let x = v.pop().expect("cant pop");
}