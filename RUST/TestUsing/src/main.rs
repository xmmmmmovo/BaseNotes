
#[derive(Debug)]
struct Point {
    x: i32,
    y: i32,
}

impl Point {
    fn back() -> Point {
        return Point {
            x: 1,
            y: 1,
        }
    }
}

fn main() {
    let p = Point{x: 1, y: 2};
    let p2 = Point::back();

    println!("{:#?} {:#?}", p, p2);

}