use std::fmt::{Debug, Display};
use std::marker::PhantomData;
use std::ops::Add;

fn fc() {
    // 一个具体类型 `A`。
    struct A;

    // 在定义类型 `Single` 时，第一次使用类型 `A` 之前没有写 `<A>`。
    // 因此，`Single` 是个具体类型，`A` 取上面的定义。
    struct Single(A);
    //            ^ 这里是 `Single` 对类型 `A` 的第一次使用。

    // 此处 `<T>` 在第一次使用 `T` 前出现，所以 `SingleGen` 是一个泛型类型。
    // 因为 `T` 是泛型的，所以它可以是任何类型，包括在上面定义的具体类型 `A`。
    struct SingleGen<T>(T);

    // `Single` 是具体类型，并且显式地使用类型 `A`。
    let _s = Single(A);

    // 创建一个 `SingleGen<char>` 类型的变量 `_char`，并令其值为 `SingleGen('a')`
    // 这里的 `SingleGen` 的类型参数是显式指定的。
    let _char: SingleGen<char> = SingleGen('a');

    // `SingleGen` 的类型参数也可以隐式地指定。
    let _t = SingleGen(A); // 使用在上面定义的 `A`。
    let _i32 = SingleGen(6); // 使用 `i32` 类型。
    let _char = SingleGen('a'); // 使用 `char`。

    struct S(A); // 具体类型 `S`。
    struct SGen<T>(T); // 泛型类型 `SGen`。

    // 下面全部函数都得到了变量的所有权，并立即使之离开作用域，将变量释放。

    // 定义一个函数 `reg_fn`，接受一个 `S` 类型的参数 `_s`。
    // 因为没有 `<T>` 这样的泛型类型参数，所以这不是泛型函数。
    fn reg_fn(_s: S) {}

    // 定义一个函数 `gen_spec_t`，接受一个 `SGen<A>` 类型的参数 `_s`。
    // `SGen<>` 显式地接受了类型参数 `A`，且在 `gen_spec_t` 中，`A` 没有被用作
    // 泛型类型参数，所以函数不是泛型的。
    fn gen_spec_t(_s: SGen<A>) {}

    // 定义一个函数 `gen_spec_i32`，接受一个 `SGen<i32>` 类型的参数 `_s`。
    // `SGen<>` 显式地接受了类型参量 `i32`，而 `i32` 是一个具体类型。
    // 由于 `i32` 不是一个泛型类型，所以这个函数也不是泛型的。
    fn gen_spec_i32(_s: SGen<i32>) {}

    // 定义一个函数 `generic`，接受一个 `SGen<T>` 类型的参数 `_s`。
    // 因为 `SGen<T>` 之前有 `<T>`，所以这个函数是关于 `T` 的泛型函数。
    fn generic<T>(_s: SGen<T>) {}

    // 使用非泛型函数
    reg_fn(S(A)); // 具体类型。
    gen_spec_t(SGen(A)); // 隐式地指定类型参数 `A`。
    gen_spec_i32(SGen(6)); // 隐式地指定类型参数 `i32`。

    // 为 `generic()` 显式地指定类型参数 `char`。
    generic::<char>(SGen('a'));

    // 为 `generic()` 隐式地指定类型参数 `char`。
    generic(SGen('c'));
}

fn trait_template_test() {
    // 不可复制的类型。
    struct Empty;
    struct Null;

    // `T` 的泛型 trait。
    trait DoubleDrop<T> {
        // 定义一个调用者的方法，接受一个额外的参数 `T`，但不对它做任何事。
        fn double_drop(self, _: T);
    }

    // 对泛型的调用者类型 `U` 和任何泛型类型 `T` 实现 `DoubleDrop<T>` 。
    impl<T, U> DoubleDrop<T> for U {
        // 此方法获得两个传入参数的所有权，并释放它们。
        fn double_drop(self, _: T) {}
    }

    let empty = Empty;
    let null = Null;

    // 释放 `empty` 和 `null`。
    empty.double_drop(null);

    // empty;
    // null;
    // ^ 试一试：去掉这两行的注释。

    // 定义一个函数 `printer`，接受一个类型为泛型 `T` 的参数，
    // 其中 `T` 必须实现 `Display` trait。
    fn printer<T: Display>(t: T) {
        println!("{}", t);
    }
    struct S<T: Display>(T);

    // 报错！`Vec<T>` 未实现 `Display`。此次泛型具体化失败。
    // let s = S(vec![1]);
    // 这个 trait 用来实现打印标记：`{:?}`。

    use std::fmt::Debug;

    trait HasArea {
        fn area(&self) -> f64;
    }

    impl HasArea for Rectangle {
        fn area(&self) -> f64 {
            self.length * self.height
        }
    }

    #[derive(Debug)]
    struct Rectangle {
        length: f64,
        height: f64,
    }

    #[allow(dead_code)]
    struct Triangle {
        length: f64,
        height: f64,
    }

    // 泛型 `T` 必须实现 `Debug` 。只要满足这点，无论什么类型
    // 都可以让下面函数正常工作。
    fn print_debug<T: Debug>(t: &T) {
        println!("{:?}", t);
    }

    // `T` 必须实现 `HasArea`。任意符合该约束的泛型的实例
    // 都可访问 `HasArea` 的 `area` 函数
    fn area<T: HasArea>(t: &T) -> f64 {
        t.area()
    }
    let rectangle = Rectangle {
        length: 3.0,
        height: 4.0,
    };
    let _triangle = Triangle {
        length: 3.0,
        height: 4.0,
    };

    print_debug(&rectangle);
    println!("Area: {}", area(&rectangle));

    //print_debug(&_triangle);
    //println!("Area: {}", area(&_triangle));
    // ^ 试一试：取消上述语句的注释。
    // | 报错：未实现 `Debug` 或 `HasArea`。

    fn compare_prints<T: Debug + Display>(t: &T) {
        println!("Debug: `{:?}`", t);
        println!("Display: `{}`", t);
    }

    fn compare_types<T: Debug, U: Debug>(t: &T, u: &U) {
        println!("t: `{:?}", t);
        println!("u: `{:?}", u);
    }

    let string = "words";
    let array = [1, 2, 3];
    let vec = vec![1, 2, 3];

    compare_prints(&string);
    // compare_prints(&array);
    // 试一试 ^ 将此行注释去掉。

    compare_types(&array, &vec);
}

fn where_test() {
    trait PrintInOption {
        fn print_in_option(self);
    }

    // 这里需要一个 `where` 从句，否则就要表达成 `T: Debug`（这样意思就变了），
    // 或着改用另一种间接的方法。
    impl<T> PrintInOption for T
    where
        Option<T>: Debug,
    {
        // 我们要将 `Option<T>: Debug` 作为约束，因为那是要打印的内容。
        // 否则我们会给出错误的约束。
        fn print_in_option(self) {
            println!("{:?}", Some(self));
        }
    }

    let vec = vec![1, 2, 3];

    vec.print_in_option();
}

fn newtype_test() {
    struct Years(i64);

    struct Days(i64);

    impl Years {
        pub fn to_days(&self) -> Days {
            Days(self.0 * 365)
        }
    }

    impl Days {
        /// 舍去不满一年的部分
        pub fn to_years(&self) -> Years {
            Years(self.0 / 365)
        }
    }

    fn old_enough(age: &Years) -> bool {
        age.0 >= 18
    }

    let age = Years(5);
    let age_days = age.to_days();
    println!("Old enough {}", old_enough(&age));
    println!("Old enough {}", old_enough(&age_days.to_years()));
    // println!("Old enough {}", old_enough(&age_days));
}

fn g_test() {
    struct Container(i32, i32);

    // 这个 trait 检查给定的 2 个项是否储存于容器中
    // 并且能够获得容器的第一个或最后一个值。
    trait Contains {
        // 在这里定义可以被方法使用的泛型类型。
        type A;
        type B;

        fn contains(&self, _: &Self::A, _: &Self::B) -> bool;
        fn first(&self) -> i32;
        fn last(&self) -> i32;
    }

    impl Contains for Container {
        // 指出 `A` 和 `B` 是什么类型。如果 `input`（输入）类型
        // 为 `Container(i32, i32)`，那么 `output`（输出）类型
        // 会被确定为 `i32` 和 `i32`。
        type A = i32;
        type B = i32;

        // `&Self::A` 和 `&Self::B` 在这里也是合法的类型。
        fn contains(&self, number_1: &i32, number_2: &i32) -> bool {
            (&self.0 == number_1) && (&self.1 == number_2)
        }

        // 得到第一个数字。
        fn first(&self) -> i32 {
            self.0
        }

        // 得到最后一个数字。
        fn last(&self) -> i32 {
            self.1
        }
    }

    fn difference<C: Contains>(container: &C) -> i32 {
        container.last() - container.first()
    }

    let number_1 = 3;
    let number_2 = 10;

    let container = Container(number_1, number_2);

    println!(
        "Does container contain {} and {}: {}",
        &number_1,
        &number_2,
        container.contains(&number_1, &number_2)
    );
    println!("First number: {}", container.first());
    println!("Last number: {}", container.last());

    println!("The difference is: {}", difference(&container));
}

fn phantom_test() {
    // 这个虚元组结构体对 `A` 是泛型的，并且带有隐藏参数 `B`。
    #[derive(PartialEq)] // 允许这种类型进行相等测试（equality tests）。
    struct PhantomTuple<A, B>(A, PhantomData<B>);

    // 这个虚类型结构体对 `A` 是泛型的，并且带有隐藏参数 `B`。
    #[derive(PartialEq)] // 允许这种类型进行相等测试。
    struct PhantomStruct<A, B> {
        first: A,
        phantom: PhantomData<B>,
    }

    // 这里的 `f32` 和 `f64` 是隐藏参数。
    // 被指定为 `<char, f32>` 的 `PhantomTuple` 类型。
    let _tuple1: PhantomTuple<char, f32> = PhantomTuple('Q', PhantomData);
    // 被指定为 `<char, f64>` `PhantomTuple` 类型。
    let _tuple2: PhantomTuple<char, f64> = PhantomTuple('Q', PhantomData);

    // 被指定为 `<char, f32>` 的类型。
    let _struct1: PhantomStruct<char, f32> = PhantomStruct {
        first: 'Q',
        phantom: PhantomData,
    };
    // 被指定为 `<char, f64>` 的类型。
    let _struct2: PhantomStruct<char, f64> = PhantomStruct {
        first: 'Q',
        phantom: PhantomData,
    };

    // 编译期错误！类型不匹配，所以这些值不能够比较：
    //println!("_tuple1 == _tuple2 yields: {}",
    //          _tuple1 == _tuple2);

    // 编译期错误！类型不匹配，所以这些值不能够比较：
    //println!("_struct1 == _struct2 yields: {}",
    //          _struct1 == _struct2);

    #[derive(Debug, Clone, Copy)]
    enum Inch {}

    #[derive(Debug, Clone, Copy)]
    enum Mm {}

    /// `Length` 是一个带有虚类型参数 `Unit` 的类型，
    /// 而且对于表示长度的类型（即 `f64`）而言，`Length` 不是泛型的。
    ///
    /// `f64` 已经实现了 `Clone` 和 `Copy` trait.
    #[derive(Debug, Clone, Copy)]
    struct Length<Unit>(f64, PhantomData<Unit>);

    /// `Add` trait 定义了 `+` 运算符的行为。
    impl<Unit> Add for Length<Unit> {
        type Output = Length<Unit>;

        // add() 返回一个含有和的新的 `Length` 结构体。
        fn add(self, rhs: Length<Unit>) -> Length<Unit> {
            // `+` 调用了针对 `f64` 类型的 `Add` 实现。
            Length(self.0 + rhs.0, PhantomData)
        }
    }

    // 指定 `one_foot` 拥有虚类型参数 `Inch`。
    let one_foot: Length<Inch> = Length(12.0, PhantomData);
    // `one_meter` 拥有虚类型参数 `Mm`。
    let one_meter: Length<Mm> = Length(1000.0, PhantomData);

    // `+` 调用了我们对 `Length<Unit>` 实现的 `add()` 方法。
    //
    // 由于 `Length` 了实现了 `Copy`，`add()` 不会消耗 `one_foot`
    // 和 `one_meter`，而是复制它们作为 `self` 和 `rhs`。
    let two_feet = one_foot + one_foot;
    let two_meters = one_meter + one_meter;

    // 加法正常执行。
    println!("one foot + one_foot = {:?} in", two_feet.0);
    println!("one meter + one_meter = {:?} mm", two_meters.0);

    // 无意义的运算当然会失败：
    // 编译期错误：类型不匹配。
    //let one_feter = one_foot + one_meter;
}

fn main() {
    where_test();
    g_test();
    phantom_test();
}
