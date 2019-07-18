## Rust上手笔记

Rust是一门无GC的高效率语言，其不仅包含单个文件编译程序，还有着完整的包管理系统与项目构建管理器，其被誉为21世纪的C++，下一个40年使用的语言，却又吸收了大量语言的优点，早已经超出了C++的范畴。不过，其上手难度之高，更新之缓慢，社区建设之不完整，使得其编写人数相较于近期的热门语言Go差距较大，所以想学习Rust的在下还是建议观望一段时间。毕竟，论一个语言的前景，要么有个强大框架如rails，要么有个强大的公司如Facebook，要么有个强大的应用如docker，要么有个强大的标准如html5。总之一句话，要有人顶你。

### Rust安装后所包含的

- rustc 可以编译单个文件的编译器
- cargo 包括包管理，项目编译，版本发布与流程控制在内的项目管理器
- rustup 版本管理工具

### IDE推荐

- idea + rust插件
- vscode + rust插件

### Rust快速入门

#### 1.1 变量与绑定

- **let** 绑定的变量默认为不可变，如果想要绑定可变变量需要<br>**let mut**这样<br>
	
	```rust
	let mut a: f64 = 1.0;
	let b = 1;
	```
##### Rust原生类型	

- 布尔类型

- 字符类型(char)

- 数值类型

- 字符串类型：最底层的是不定长类型`str`，更常用的是字符串切片`&str`和堆分配字符串`String`， 其中字符串切片是静态分配的，有固定的大小，并且不可变，而堆分配字符串是可变的。

- 数组：具有固定大小，并且元素都是同种类型，可表示为`[T; N]`。

- 切片：引用一个数组的部分数据并且不需要拷贝，可表示为`&[T]`。

- 元组：具有固定大小的有序列表，每个元素都有自己的类型，通过解构或者索引来获得每个元素的值。

- 指针：最底层的是裸指针`*const T`和`*mut T`，但解引用它们是不安全的，必须放到`unsafe`块里。

- 函数：具有函数类型的变量**实质上是一个函数指针**。

- 元类型：即`()`，其唯一的值也是`()`。

```rust
// 这里字符是unicode字符占4字节
let c = 'c';

// 基础数据类型
let y: u32 = 123_456; // 数据中可以加下划线(小数也可以)
let z: f64 = 1.23e+2; // 可以科学计数法
let zero = z.abs_sub(123.4); // 与负数相减后取绝对值
let bin = 0b1111_0000;
let oct = 0o7320_1546;
let hex = 0xf23a_b049;

// 字符串类型
let str = "Hello, world!";
let mut string = str.to_string();

// 数组与切片
let a = [0, 1, 2, 3, 4];
let middle = &a[1..4]; // 开切
let mut ten_zeros: [i64; 10] = [0; 10];

// 元组
let tuple: (i32, &str) = (50, "hello");
let (fifty, _) = tuple;
let hello = tuple.1;

// 指针
let x = 5;
let raw = &x as *const i32; // 定义指针 as显式转换
let points_at = unsafe { *raw }; // 必须放在非安全块中的解指针

// 函数 本质也是指针
fn foo(x: i32) -> i32 { x }
let bar: fn(i32) -> i32 = foo;

type TestType = i128; // 类似typedef
```

- Rust还支持单字节字符`b'H'`以及单字节字符串`b"Hello"`，仅限制于ASCII字符。 此外，还可以使用`r#"..."#`标记来表示原始字符串，不需要对特殊字符进行转义。
- 使用`&`符号将`String`类型转换成`&str`类型很廉价， 但是使用`to_string()`方法将`&str`转换到`String`类型涉及到分配内存， 除非很有必要否则不要这么做。
- 数组的长度是不可变的，动态的数组称为Vec (vector)，可以使用宏`vec!`创建。
- 元组可以使用`==`和`!=`运算符来判断是否相同。
- 不多于32个元素的数组和不多于12个元素的元组在值传递时是自动复制的。
- Rust不提供原生类型之间的隐式转换，只能使用`as`关键字显式转换。
- 可以使用`type`关键字定义某个类型的别名，并且应该采用驼峰命名法。

#### 1.2 数组，vec，字符串

##### vec

```rust
//创建空Vec
let v: Vec<i32> = Vec::new();
//使用宏创建空Vec
let v: Vec<i32> = vec![];
//创建包含5个元素的Vec
let v = vec![1, 2, 3, 4, 5];
//创建十个零
let v = vec![0; 10];
//创建可变的Vec，并压入元素3
let mut v = vec![1, 2];
```

##### 字符串

```rust
// 创建一个空的字符串
let mut s = String::new();
// 从 `&str` 类型转化成 `String` 类型
let mut hello = String::from("Hello, ");
// 弹出字符。
let mut s = String::from("foo");
assert_eq!(s.pop(), Some('o'));
assert_eq!(s.pop(), Some('o'));
assert_eq!(s.pop(), Some('f'));
assert_eq!(s.pop(), None);
```

#### 1.3 结构体与枚举

- 需要注意，Rust在语言级别不支持域可变性 (field mutability)，所以不能这么写：

    ```rust
    struct Point {
        mut x: i32,
        y: i32,
    }
    // 但是可以这么写
    struct Point {
        x: i32,
        y: Cell<i32>,
    }
    ```

- 为结构体设定函数

    ```rust
    #[derive(Debug)]
    struct Rectangle {
        width: u32,
        height: u32,
    }
    
    // self就相当于this了
    impl Rectangle {
        fn area(&self) -> u32 {
            self.width * self.height
        }
    }
    
    fn main() {
        let rect1 = Rectangle { width: 30, height: 50 };
    
        println!(
            "The area of the rectangle is {} square pixels.",
            rect1.area()
        );
    }
    ```

- 枚举：注意运算符需要自己重载<br>并且枚举每种类型只能实现一次来着

    ```rust
    // enums
    enum Message {
        Quit,
        ChangeColor(i32, i32, i32),
        Move { x: i32, y: i32 },
        Write(String),
    }
    
    let x: Message = Message::Move { x: 3, y: 4 };
    ```







#### 1.4 控制流

- loop：无限循环(不要用while true！！)

    - 还可以在开头设定标签

        ```rust
        'outer: loop {
           println!("Entered the outer loop");
        
           'inner: loop {
               println!("Entered the inner loop");
               break 'outer;
           }
        
           println!("This point will never be reached");
        }
        
        println!("Exited the outer loop");
        ```

##### match

```rust
let day = 5;

match day {
  0 | 6 => println!("weekend"), // 匹配多个值
  1 ... 5 => println!("weekday"), // 匹配一个范围
  _ => println!("invalid"), // 相当于default
}
```

```rust
match x {
    e @ 1 ... 5 => println!("got a range element {}", e), // 可以取出匹配值
    _ => println!("anything"),
}
```

```rust
let x = 5;
let mut y = 5;

match x {
    // the `r` inside the match has the type `&i32`
    ref r => println!("Got a reference to {}", r), // ref 可以获得引用类型
}

match y {
    // the `mr` inside the match has the type `&i32` and is mutable
    ref mut mr => println!("Got a mutable reference to {}", mr),
}
```

```rust
let number = Some(7);
let mut optional = Some(0);

// If `let` destructures `number` into `Some(i)`, evaluate the block.
if let Some(i) = number {
    println!("Matched {:?}!", i);
} else {
    println!("Didn't match a number!");
}

// While `let` destructures `optional` into `Some(i)`, evaluate the block.
while let Some(i) = optional {
    if i > 9 {
        println!("Greater than 9, quit!");
        optional = None;
    } else {
        println!("`i` is `{:?}`. Try again.", i);
        optional = Some(i + 1);
    }
}
"""
Matched 7!
`i` is `0`. Try again.
`i` is `1`. Try again.
`i` is `2`. Try again.
`i` is `3`. Try again.
`i` is `4`. Try again.
`i` is `5`. Try again.
`i` is `6`. Try again.
`i` is `7`. Try again.
`i` is `8`. Try again.
`i` is `9`. Try again.
Greater than 9, quit!
"""
```



















































































