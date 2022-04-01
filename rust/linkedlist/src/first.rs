pub struct List {
    head: Link,
}

struct Node {
    elem: i32,
    next: List,
}

pub enum Link {
    Empty,
    More(Box<Node>),
}
