use std::error::Error;
use std::num::ParseIntError;
use std::{error, fmt};

fn give_princess(gift: &str) {
    // 公主讨厌蛇，所以如果公主表示厌恶的话我们要停止！
    if gift == "snake" {
        panic!("AAAaaaaa!!!!");
    }

    println!("I love {}s!!!!!", gift);
}

fn option_unwrap_test() {
    // 平民（commoner）们见多识广，收到什么礼物都能应对。
    // 所有礼物都显式地使用 `match` 来处理。
    fn give_commoner(gift: Option<&str>) {
        // 指出每种情况下的做法。
        match gift {
            Some("snake") => println!("Yuck! I'm throwing that snake in a fire."),
            Some(inner) => println!("{}? How nice.", inner),
            None => println!("No gift? Oh well."),
        }
    }

    // 养在深闺人未识的公主见到蛇就会 `panic`（恐慌）。
    // 这里所有的礼物都使用 `unwrap` 隐式地处理。
    fn give_princess(gift: Option<&str>) {
        // `unwrap` 在接收到 `None` 时将返回 `panic`。
        let inside = gift.unwrap();
        if inside == "snake" {
            panic!("AAAaaaaa!!!!");
        }

        println!("I love {}s!!!!!", inside);
    }

    let food = Some("chicken");
    let snake = Some("snake");
    let void = None;

    give_commoner(food);
    give_commoner(snake);
    give_commoner(void);

    let bird = Some("robin");
    let nothing = None;

    give_princess(bird);
    give_princess(nothing);
}

fn map_test() {
    #![allow(dead_code)]

    #[derive(Debug)]
    enum Food {
        Apple,
        Carrot,
        Potato,
    }

    #[derive(Debug)]
    struct Peeled(Food);
    #[derive(Debug)]
    struct Chopped(Food);
    #[derive(Debug)]
    struct Cooked(Food);

    // 削皮。如果没有食物，就返回 `None`。否则返回削好皮的食物。
    fn peel(food: Option<Food>) -> Option<Peeled> {
        match food {
            Some(food) => Some(Peeled(food)),
            None => None,
        }
    }

    // 切食物。如果没有食物，就返回 `None`。否则返回切好的食物。
    fn chop(peeled: Option<Peeled>) -> Option<Chopped> {
        match peeled {
            Some(Peeled(food)) => Some(Chopped(food)),
            None => None,
        }
    }

    // 烹饪食物。这里，我们使用 `map()` 来替代 `match` 以处理各种情况。
    fn cook(chopped: Option<Chopped>) -> Option<Cooked> {
        chopped.map(|Chopped(food)| Cooked(food))
    }

    // 这个函数会完成削皮切块烹饪一条龙。我们把 `map()` 串起来，以简化代码。
    fn process(food: Option<Food>) -> Option<Cooked> {
        food.map(|f| Peeled(f))
            .map(|Peeled(f)| Chopped(f))
            .map(|Chopped(f)| Cooked(f))
    }

    // 在尝试吃食物之前确认食物是否存在是非常重要的！
    fn eat(food: Option<Cooked>) {
        match food {
            Some(food) => println!("Mmm. I love {:?}", food),
            None => println!("Oh no! It wasn't edible."),
        }
    }
    let apple = Some(Food::Apple);
    let carrot = Some(Food::Carrot);
    let potato = None;

    let cooked_apple = cook(chop(peel(apple)));
    let cooked_carrot = cook(chop(peel(carrot)));

    // 现在让我们试试看起来更简单的 `process()`。
    let cooked_potato = process(potato);

    eat(cooked_apple);
    eat(cooked_carrot);
    eat(cooked_potato);
}

fn and_then_test() {
    #![allow(dead_code)]

    #[derive(Debug)]
    enum Food {
        CordonBleu,
        Steak,
        Sushi,
    }
    #[derive(Debug)]
    enum Day {
        Monday,
        Tuesday,
        Wednesday,
    }

    // 我们没有制作寿司所需的原材料（ingredient）（有其他的原材料）。
    fn have_ingredients(food: Food) -> Option<Food> {
        match food {
            Food::Sushi => None,
            _ => Some(food),
        }
    }

    // 我们拥有全部食物的食谱，除了法国蓝带猪排（Cordon Bleu）的。
    fn have_recipe(food: Food) -> Option<Food> {
        match food {
            Food::CordonBleu => None,
            _ => Some(food),
        }
    }

    // 要做一份好菜，我们需要原材料和食谱。
    // 我们可以借助一系列 `match` 来表达这个逻辑：
    fn cookable_v1(food: Food) -> Option<Food> {
        match have_ingredients(food) {
            None => None,
            Some(food) => match have_recipe(food) {
                None => None,
                Some(food) => Some(food),
            },
        }
    }

    // 也可以使用 `and_then()` 把上面的逻辑改写得更紧凑：
    fn cookable_v2(food: Food) -> Option<Food> {
        have_ingredients(food).and_then(have_recipe)
    }

    fn eat(food: Food, day: Day) {
        match cookable_v2(food) {
            Some(food) => println!("Yay! On {:?} we get to eat {:?}.", day, food),
            None => println!("Oh no. We don't get to eat on {:?}?", day),
        }
    }
    let (cordon_bleu, steak, sushi) = (Food::CordonBleu, Food::Steak, Food::Sushi);

    eat(cordon_bleu, Day::Monday);
    eat(steak, Day::Tuesday);
    eat(sushi, Day::Wednesday);
}

fn result_test() {
    // 为带有错误类型 `ParseIntError` 的 `Result` 定义一个泛型别名。
    type AliasedResult<T> = Result<T, ParseIntError>;
    // 就像 `Option` 那样，我们可以使用 `map()` 之类的组合算子。
    // 除去写法外，这个函数与上面那个完全一致，它的作用是：
    // 如果值是合法的，计算其乘积，否则返回错误。
    fn multiply(first_number_str: &str, second_number_str: &str) -> AliasedResult<i32> {
        first_number_str.parse::<i32>().and_then(|first_number| {
            second_number_str
                .parse::<i32>()
                .map(|second_number| first_number * second_number)
        })
    }

    fn print(result: Result<i32, ParseIntError>) {
        match result {
            Ok(n) => println!("n is {}", n),
            Err(e) => println!("Error: {}", e),
        }
    }
    // 这种情况下仍然会给出正确的答案。
    let twenty = multiply("10", "2");
    print(twenty);

    // 这种情况下就会提供一条更有用的错误信息。
    let tt = multiply("t", "2");
    print(tt);
}

fn result_test2() {
    fn multiply(first_number_str: &str, second_number_str: &str) -> Result<i32, ParseIntError> {
        let first_number = first_number_str.parse::<i32>()?;
        let second_number = second_number_str.parse::<i32>()?;

        Ok(first_number * second_number)
    }

    fn print(result: Result<i32, ParseIntError>) {
        match result {
            Ok(n) => println!("n is {}", n),
            Err(e) => println!("Error: {}", e),
        }
    }

    print(multiply("10", "2"));
    print(multiply("t", "2"));
}

fn complex_error_handler() {
    fn double_first(vec: Vec<&str>) -> Option<Result<i32, ParseIntError>> {
        vec.first().map(|first| first.parse::<i32>().map(|n| 2 * n))
    }

    let numbers = vec!["42", "93", "18"];
    let empty = vec![];
    let strings = vec!["tofu", "93", "18"];

    println!("The first doubled is {:?}", double_first(numbers));

    println!("The first doubled is {:?}", double_first(empty));
    // Error 1: the input vector is empty

    println!("The first doubled is {:?}", double_first(strings));
    // Error 2: the element doesn't parse to a number

    fn double_first2(vec: Vec<&str>) -> Result<Option<i32>, ParseIntError> {
        let opt = vec.first().map(|first| first.parse::<i32>().map(|n| 2 * n));

        opt.map_or(Ok(None), |r| r.map(Some))
    }
    let numbers = vec!["42", "93", "18"];
    let empty = vec![];
    let strings = vec!["tofu", "93", "18"];

    println!("The first doubled is {:?}", double_first2(numbers));
    println!("The first doubled is {:?}", double_first2(empty));
    println!("The first doubled is {:?}", double_first2(strings));
}

fn define_error_test() {
    type Result<T> = std::result::Result<T, DoubleError>;

    #[derive(Debug, Clone)]
    // 定义我们的错误类型，这种类型可以根据错误处理的实际情况定制。
    // 我们可以完全自定义错误类型，也可以在类型中完全采用底层的错误实现，
    // 也可以介于二者之间。
    struct DoubleError;

    // 错误的生成与它如何显示是完全没关系的。没有必要担心复杂的逻辑会导致混乱的显示。
    //
    // 注意我们没有储存关于错误的任何额外信息，也就是说，如果不修改我们的错误类型定义的话，
    // 就无法指明是哪个字符串解析失败了。
    impl fmt::Display for DoubleError {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "invalid first item to double")
        }
    }

    // 为 `DoubleError` 实现 `Error` trait，这样其他错误可以包裹这个错误类型。
    impl error::Error for DoubleError {
        fn source(&self) -> Option<&(dyn error::Error + 'static)> {
            // 泛型错误，没有记录其内部原因。
            None
        }
    }

    fn double_first(vec: Vec<&str>) -> Result<i32> {
        vec.first()
            // 把错误换成我们的新类型。
            .ok_or(DoubleError)
            .and_then(|s| {
                s.parse::<i32>()
                    // 这里也换成新类型。
                    .map_err(|_| DoubleError)
                    .map(|i| 2 * i)
            })
    }

    fn print(result: Result<i32>) {
        match result {
            Ok(n) => println!("The first doubled is {}", n),
            Err(e) => println!("Error: {}", e),
        }
    }

    let numbers = vec!["42", "93", "18"];
    let empty = vec![];
    let strings = vec!["tofu", "93", "18"];

    print(double_first(numbers));
    print(double_first(empty));
    print(double_first(strings));
}

fn boxed_error_test() {
    // 为 `Box<error::Error>` 取别名。
    type Result<T> = std::result::Result<T, Box<dyn error::Error>>;

    #[derive(Debug, Clone)]
    struct EmptyVec;

    impl fmt::Display for EmptyVec {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "invalid first item to double")
        }
    }

    impl error::Error for EmptyVec {
        fn description(&self) -> &str {
            "invalid first item to double"
        }

        fn cause(&self) -> Option<&dyn error::Error> {
            // 泛型错误。没有记录其内部原因。
            None
        }
    }

    fn double_first(vec: Vec<&str>) -> Result<i32> {
        vec.first()
            .ok_or_else(|| EmptyVec.into()) // 装箱
            .and_then(|s| {
                s.parse::<i32>()
                    .map_err(|e| e.into()) // 装箱
                    .map(|i| 2 * i)
            })
    }

    fn print(result: Result<i32>) {
        match result {
            Ok(n) => println!("The first doubled is {}", n),
            Err(e) => println!("Error: {}", e),
        }
    }

    let numbers = vec!["42", "93", "18"];
    let empty = vec![];
    let strings = vec!["tofu", "93", "18"];

    print(double_first(numbers));
    print(double_first(empty));
    print(double_first(strings));
}

fn from_error_test() {
    // 为 `Box<error::Error>` 取别名。
    type Result<T> = std::result::Result<T, Box<dyn error::Error>>;

    #[derive(Debug)]
    struct EmptyVec;

    impl fmt::Display for EmptyVec {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            write!(f, "invalid first item to double")
        }
    }

    impl error::Error for EmptyVec {
        fn description(&self) -> &str {
            "invalid first item to double"
        }

        fn cause(&self) -> Option<&dyn error::Error> {
            // 泛型错误，没有记录内部原因。
            None
        }
    }

    // 这里的结构和之前一样，但是这次没有把所有的 `Results` 和 `Options` 串起来，
    // 而是使用 `?` 立即得到内部值。
    fn double_first(vec: Vec<&str>) -> Result<i32> {
        let first = vec.first().ok_or(EmptyVec)?;
        let parsed = first.parse::<i32>()?;
        Ok(2 * parsed)
    }

    fn print(result: Result<i32>) {
        match result {
            Ok(n) => println!("The first doubled is {}", n),
            Err(e) => println!("Error: {}", e),
        }
    }

    let numbers = vec!["42", "93", "18"];
    let empty = vec![];
    let strings = vec!["tofu", "93", "18"];

    print(double_first(numbers));
    print(double_first(empty));
    print(double_first(strings));
}

fn package_error() {
    type Result<T> = std::result::Result<T, DoubleError>;

    #[derive(Debug)]
    enum DoubleError {
        EmptyVec,
        // 在这个错误类型中，我们采用 `parse` 的错误类型中 `Err` 部分的实现。
        // 若想提供更多信息，则该类型中还需要加入更多数据。
        Parse(ParseIntError),
    }

    impl fmt::Display for DoubleError {
        fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
            match *self {
                DoubleError::EmptyVec => write!(f, "please use a vector with at least one element"),
                // 这是一个封装（wrapper），它采用内部各类型对 `fmt` 的实现。
                DoubleError::Parse(ref e) => e.fmt(f),
            }
        }
    }

    impl error::Error for DoubleError {
        fn description(&self) -> &str {
            match *self {
                DoubleError::EmptyVec => "empty vectors not allowed",
                // 这已经实现了 `Error`，所以采用它自己的实现。
                DoubleError::Parse(ref e) => e.description(),
            }
        }

        fn cause(&self) -> Option<&dyn error::Error> {
            match *self {
                DoubleError::EmptyVec => None,
                // 原因采取内部对错误类型的实现。它隐式地转换成了 trait 对象 `&error:Error`。
                // 这可以工作，因为内部的类型已经实现了 `Error` trait。
                DoubleError::Parse(ref e) => Some(e),
            }
        }
    }

    // 实现从 `ParseIntError` 到 `DoubleError` 的转换。
    // 在使用 `?` 时，或者一个 `ParseIntError` 需要转换成 `DoubleError` 时，它会被自动调用。
    impl From<ParseIntError> for DoubleError {
        fn from(err: ParseIntError) -> DoubleError {
            DoubleError::Parse(err)
        }
    }

    fn double_first(vec: Vec<&str>) -> Result<i32> {
        let first = vec.first().ok_or(DoubleError::EmptyVec)?;
        let parsed = first.parse::<i32>()?;

        Ok(2 * parsed)
    }

    fn print(result: Result<i32>) {
        match result {
            Ok(n) => println!("The first doubled is {}", n),
            Err(e) => println!("Error: {}", e),
        }
    }

    let numbers = vec!["42", "93", "18"];
    let empty = vec![];
    let strings = vec!["tofu", "93", "18"];

    print(double_first(numbers));
    print(double_first(empty));
    print(double_first(strings));
}

fn operations_test() {
    let strings = vec!["tofu", "93", "18"];
    let possible_numbers: Vec<_> = strings.into_iter().map(|s| s.parse::<i32>()).collect();
    println!("Results: {:?}", possible_numbers);

    let strings = vec!["tofu", "93", "18"];
    let numbers: Vec<_> = strings
        .into_iter()
        .map(|s| s.parse::<i32>())
        .filter_map(Result::ok)
        .collect();
    println!("Results: {:?}", numbers);

    let strings = vec!["tofu", "93", "18"];
    let numbers: Result<Vec<_>, _> = strings.into_iter().map(|s| s.parse::<i32>()).collect();
    println!("Results: {:?}", numbers);

    let strings = vec!["tofu", "93", "18"];
    let (numbers, errors): (Vec<_>, Vec<_>) = strings
        .into_iter()
        .map(|s| s.parse::<i32>())
        .partition(Result::is_ok);
    println!("Numbers: {:?}", numbers);
    println!("Errors: {:?}", errors);

    let strings = vec!["tofu", "93", "18"];
    let (numbers, errors): (Vec<_>, Vec<_>) = strings
        .into_iter()
        .map(|s| s.parse::<i32>())
        .partition(Result::is_ok);
    let numbers: Vec<_> = numbers.into_iter().map(Result::unwrap).collect();
    let errors: Vec<_> = errors.into_iter().map(Result::unwrap_err).collect();
    println!("Numbers: {:?}", numbers);
    println!("Errors: {:?}", errors);
}

fn main() {
    // option_unwrap_test();
    // result_test();
    // complex_error_handler();
    operations_test();
}
