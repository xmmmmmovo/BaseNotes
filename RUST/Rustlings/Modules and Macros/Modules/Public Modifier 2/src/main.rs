mod delicious_snacks {
    /*insert a modifier here to make the module accessible from outside*/ use self::fruits::PEAR as fruit;
    /*insert a modifier here to make the module accessible from outside*/ use self::veggies::CUCUMBER as veggie;

    mod fruits {
        pub const PEAR: &'static str = "Pear";
        pub const APPLE: &'static str = "Apple";
    }

    mod veggies {
        pub const CUCUMBER: &'static str = "Cucumber";
        pub const CARROT: &'static str = "Carrot";
    }
}

fn main() {
    println!("favorite snacks: {} and {}",
             delicious_snacks::fruit,
             delicious_snacks::veggie);
}
