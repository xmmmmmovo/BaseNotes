mod dry;

fn grammar_test() {
    // block
    // expr 用于表达式
    // ident 用于变量名或函数名
    // item
    // pat (模式 pattern)
    // path
    // stmt (语句 statement)
    // tt (标记树 token tree)
    // ty (类型 type)
    macro_rules! create_function {
        ($func_name:ident) => {
            fn $func_name() {
                // `stringify!` 宏把 `ident` 转换成字符串。
                println!("You called {:?}()", stringify!($func_name))
            }
        };
    }

    create_function!(foo);
    create_function!(bar);

    macro_rules! print_result {
        // 此宏接受一个 `expr` 类型的表达式，并将它作为字符串，连同其结果一起
        // 打印出来。
        // `expr` 指示符表示表达式。
        ($expression:expr) => {
            // `stringify!` 把表达式*原样*转换成一个字符串。
            println!("{:?} = {:?}", stringify!($expression), $expression)
        };
    }
    foo();
    bar();

    print_result!(1u32 + 1);

    // 回想一下，代码块也是表达式！
    print_result!({
        let x = 1u32;

        x * x + 2 * x - 1
    });

    // 根据你调用它的方式，`tests!` 将以不同的方式来比较 `$left` 和 `$right`。
    macro_rules! test {
        // 参数不需要使用逗号隔开。
        // 参数可以任意组合！
        ($left:expr; and $right:expr) => {
            println!(
                "{:?} and {:?} is {:?}",
                stringify!($left),
                stringify!($right),
                $left && $right
            )
        };
        // ^ 每个分支都必须以分号结束。
        ($left:expr; or $right:expr) => {
            println!(
                "{:?} or {:?} is {:?}",
                stringify!($left),
                stringify!($right),
                $left || $right
            )
        };
    }

    // tests!(1i32 + 1 == 2i32; and 2i32 * 2 == 4i32);
    test!(true; or false);
}

fn repeat_test() {
    // `min!` 将求出任意数量的参数的最小值。
    macro_rules! find_min {
        // 基本情形：
        ($x:expr) => ($x);
        // 使用 * 来表示该 参数可能出现零次或多次
        // 使用 + 来表示一个参数可能出现一次或多次
        // `$x` 后面跟着至少一个 `$y,`
        ($x:expr, $($y:expr),+) => (
            // 对 `$x` 后面的 `$y` 们调用 `find_min!`
            std::cmp::min($x, find_min!($($y),+))
        )
    }
    println!("{}", find_min!(1u32));
    println!("{}", find_min!(1u32 + 2, 2u32));
    println!("{}", find_min!(5u32, 2u32 * 3, 4u32));
}

fn dsl_test() {
    macro_rules! calculate {
        (eval $e:expr) => {{
            {
                let val: usize = $e; // 强制类型为整型
                println!("{} = {}", stringify!{$e}, val);
            }
        }};
    }
    calculate! {
        eval 1 + 2 // 看到了吧，`eval` 可并不是 Rust 的关键字！
    }

    #[allow(clippy::erasing_op)]
    calculate! {
        eval (1 + 2) * (3 / 4)
    }
}

fn mut_macro_test() {
    macro_rules! calculate {
        // 单个 `eval` 的模式
        (eval $e:expr) => {{
            {
                let val: usize = $e; // Force types to be integers
                println!("{} = {}", stringify!{$e}, val);
            }
        }};

        // 递归地拆解多重的 `eval`
        (eval $e:expr, $(eval $es:expr),+) => {{
            calculate! { eval $e }
            calculate! { $(eval $es),+ }
        }};
    }
    calculate! { // 妈妈快看，可变参数的 `calculate!`！
        eval 1 + 2,
        eval 3 + 4,
        eval (2 * 3) + 1
    }
}

fn main() {
    grammar_test();
    repeat_test();
}
