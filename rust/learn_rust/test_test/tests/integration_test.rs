// 声明被测试的外部 crate，就像其他使用该 crate 的程序要声明的那样。
extern crate test_test;

// 导入共用模块。
mod common;

#[test]
fn test_add() {
    common::setup();
    assert_eq!(test_test::add(3, 2), 5);
}
