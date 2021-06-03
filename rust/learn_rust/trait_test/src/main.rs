use std::hash::{Hash, Hasher};
use std::ops;
use std::ops::Add;

fn trait_test() {
    struct Sheep {
        naked: bool,
        name: &'static str,
    }

    trait Animal {
        // 静态方法签名；`Self` 表示实现者类型（implementor type）。
        fn new(name: &'static str) -> Self;

        // 实例方法签名；这些方法将返回一个字符串。
        fn name(&self) -> &'static str;
        fn noise(&self) -> &'static str;

        // trait 可以提供默认的方法定义。
        fn talk(&self) {
            println!("{} says {}", self.name(), self.noise());
        }
    }

    impl Sheep {
        fn is_naked(&self) -> bool {
            self.naked
        }

        fn shear(&mut self) {
            if self.is_naked() {
                // 实现者可以使用它的 trait 方法。
                println!("{} is already naked...", self.name());
            } else {
                println!("{} gets a haircut!", self.name);

                self.naked = true;
            }
        }
    }

    // 对 `Sheep` 实现 `Animal` trait。
    impl Animal for Sheep {
        // `Self` 是实现者类型：`Sheep`。
        fn new(name: &'static str) -> Sheep {
            Sheep {
                name: name,
                naked: false,
            }
        }

        fn name(&self) -> &'static str {
            self.name
        }

        fn noise(&self) -> &'static str {
            if self.is_naked() {
                "baaaaah?"
            } else {
                "baaaaah!"
            }
        }

        // 默认 trait 方法可以重载。
        fn talk(&self) {
            // 例如我们可以增加一些安静的沉思。
            println!("{} pauses briefly... {}", self.name, self.noise());
        }
    }
    // 这种情况需要类型标注。
    let mut dolly: Sheep = Animal::new("Dolly");
    // 试一试 ^ 移除类型标注。

    dolly.talk();
    dolly.shear();
    dolly.talk();
}

fn derive_test() {
    // 通过 #[derive] 属性，编译器能够提供某些 trait 的基本实现。
    // 如果 需要更复杂的行为，这些 trait 也可以手动实现。
    // 下面以下是可以自动推导的 trait：
    // 比较 trait: Eq, PartialEq, Ord, PartialOrd
    // Clone, 用来从 &T 创建副本 T。
    // Copy，使类型具有 “复制语义”（copy semantics）而非 “移动语义”（move semantics）。
    // Hash，从 &T 计算哈希值（hash）。
    // Default, 创建数据类型的一个空实例。
    // Debug，使用 {:?} formatter 来格式化一个值。
    // `Centimeters`，可以比较的元组结构体
    #[derive(PartialEq, PartialOrd)]
    struct Centimeters(f64);

    // `Inches`，可以打印的元组结构体
    #[derive(Debug)]
    struct Inches(i32);

    impl Inches {
        fn to_centimeters(&self) -> Centimeters {
            let &Inches(inches) = self;

            Centimeters(inches as f64 * 2.54)
        }
    }

    // `Seconds`，不带附加属性的元组结构体
    struct Seconds(i32);
    let _one_second = Seconds(1);

    // 报错：`Seconds` 不能打印；它没有实现 `Debug` trait
    //println!("One second looks like: {:?}", _one_second);
    // 试一试 ^ 取消此行注释

    // 报错：`Seconds`不能比较；它没有实现 `PartialEq` trait
    //let _this_is_true = (_one_second == _one_second);
    // 试一试 ^ 取消此行注释

    let foot = Inches(12);

    println!("One foot equals {:?}", foot);

    let meter = Centimeters(100.0);

    let cmp = if foot.to_centimeters() < meter {
        "smaller"
    } else {
        "bigger"
    };

    println!("One foot is {} than one meter.", cmp);
}

fn operator_test() {
    struct Foo;
    struct Bar;

    #[derive(Debug)]
    struct FooBar;

    #[derive(Debug)]
    struct BarFoo;

    // `std::ops::Add` trait 用来指明 `+` 的功能，这里我们实现 `Add<Bar>`，它是用于
    // 把对象和 `Bar` 类型的右操作数（RHS）加起来的 `trait`。
    // 下面的代码块实现了 `Foo + Bar = FooBar` 这样的运算。
    impl ops::Add<Bar> for Foo {
        type Output = FooBar;

        fn add(self, _rhs: Bar) -> FooBar {
            println!("> Foo.add(Bar) was called");

            FooBar
        }
    }

    // 通过颠倒类型，我们实现了不服从交换律的加法。
    // 这里我们实现 `Add<Foo>`，它是用于把对象和 `Foo` 类型的右操作数加起来的 trait。
    // 下面的代码块实现了 `Bar + Foo = BarFoo` 这样的运算。
    impl ops::Add<Foo> for Bar {
        type Output = BarFoo;

        fn add(self, _rhs: Foo) -> BarFoo {
            println!("> Bar.add(Foo) was called");

            BarFoo
        }
    }

    println!("Foo + Bar = {:?}", Foo + Bar);
    println!("Bar + Foo = {:?}", Bar + Foo);
}

fn drop_test() {
    struct Droppable {
        name: &'static str,
    }

    // 这个简单的 `drop` 实现添加了打印到控制台的功能。
    impl Drop for Droppable {
        fn drop(&mut self) {
            println!("> Dropping {}", self.name);
        }
    }
    let _a = Droppable { name: "a" };

    // 代码块 A
    {
        let _b = Droppable { name: "b" };

        // 代码块 B
        {
            let _c = Droppable { name: "c" };
            let _d = Droppable { name: "d" };

            println!("Exiting block B");
        }
        println!("Just exited block B");

        println!("Exiting block A");
    }
    println!("Just exited block A");

    // 变量可以手动使用 `drop` 函数来销毁。
    drop(_a);
    // 试一试 ^ 将此行注释掉。

    println!("end of the main function");

    // `_a` *不会*在这里再次销毁，因为它已经被（手动）销毁。
}

fn iter_test() {
    struct Fibonacci {
        curr: u32,
        next: u32,
    }

    // 为 `Fibonacci`（斐波那契）实现 `Iterator`。
    // `Iterator` trait 只需定义一个能返回 `next`（下一个）元素的方法。
    impl Iterator for Fibonacci {
        type Item = u32;

        // 我们在这里使用 `.curr` 和 `.next` 来定义数列（sequence）。
        // 返回类型为 `Option<T>`：
        //     * 当 `Iterator` 结束时，返回 `None`。
        //     * 其他情况，返回被 `Some` 包裹（wrap）的下一个值。
        fn next(&mut self) -> Option<u32> {
            let new_next = self.curr + self.next;

            self.curr = self.next;
            self.next = new_next;

            // 既然斐波那契数列不存在终点，那么 `Iterator` 将不可能
            // 返回 `None`，而总是返回 `Some`。
            Some(self.curr)
        }
    }

    // 返回一个斐波那契数列生成器
    fn fibonacci() -> Fibonacci {
        Fibonacci { curr: 1, next: 1 }
    }

    // `0..3` 是一个 `Iterator`，会产生：0、1 和 2。
    let mut sequence = 0..3;

    println!("Four consecutive `next` calls on 0..3");
    println!("> {:?}", sequence.next());
    println!("> {:?}", sequence.next());
    println!("> {:?}", sequence.next());
    println!("> {:?}", sequence.next());

    // `for` 遍历 `Iterator` 直到返回 `None`，
    // 并且每个 `Some` 值都被解包（unwrap），然后绑定给一个变量（这里是 `i`）。       println!("Iterate through 0..3 using `for`");
    for i in 0..3 {
        println!("> {}", i);
    }

    // `take(n)` 方法提取 `Iterator` 的前 `n` 项。
    println!("The first four terms of the Fibonacci sequence are: ");
    for i in fibonacci().take(4) {
        println!("> {}", i);
    }

    // `skip(n)` 方法移除前 `n` 项，从而缩短了 `Iterator` 。
    println!("The next four terms of the Fibonacci sequence are: ");
    for i in fibonacci().skip(4).take(4) {
        println!("> {}", i);
    }

    let array = [1u32, 3, 3, 7];

    // `iter` 方法对数组/slice 产生一个 `Iterator`。
    println!("Iterate the following array {:?}", &array);
    for i in array.iter() {
        println!("> {}", i);
    }
}

fn clone_test() {
    // 不含资源的单元结构体
    #[derive(Debug, Clone, Copy)]
    struct Nil;

    // 一个包含资源的结构体，它实现了 `Clone` trait
    #[derive(Clone, Debug)]
    struct Pair(Box<i32>, Box<i32>);

    // 实例化 `Nil`
    let nil = Nil;
    // 复制 `Nil`，没有资源用于移动（move）
    let copied_nil = nil;

    // 两个 `Nil` 都可以独立使用
    println!("original: {:?}", nil);
    println!("copy: {:?}", copied_nil);

    // 实例化 `Pair`
    let pair = Pair(Box::new(1), Box::new(2));
    println!("original: {:?}", pair);

    // 将 `pair` 绑定到 `moved_pair`，移动（move）了资源
    let moved_pair = pair;
    println!("copy: {:?}", moved_pair);

    // 报错！`pair` 已失去了它的资源。
    // println!("original: {:?}", pair);
    // 试一试 ^ 取消此行注释。

    // 将 `moved_pair`（包括其资源）克隆到 `cloned_pair`。
    let cloned_pair = moved_pair.clone();
    // 使用 std::mem::drop 来销毁原始的 pair。
    drop(moved_pair);

    // 报错！`moved_pair` 已被销毁。
    //println!("copy: {:?}", moved_pair);
    // 试一试 ^ 将此行注释掉。

    // 由 .clone() 得来的结果仍然可用！
    println!("clone: {:?}", cloned_pair);
}

fn main() {
    operator_test();
    drop_test();
    clone_test();
}
