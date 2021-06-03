// 仅用于测试的外部 crate
#[cfg(test)]
#[macro_use]
extern crate pretty_assertions;

mod lib;

trait View {}

struct Button {}

struct TextView {}

impl View for TextView {}

impl View for Button {}

fn some_fn(k: i32) -> Box<dyn View> {
    if k > 1 {
        Box::new(Button {})
    } else {
        Box::new(TextView {})
    }
}

fn main() {}
