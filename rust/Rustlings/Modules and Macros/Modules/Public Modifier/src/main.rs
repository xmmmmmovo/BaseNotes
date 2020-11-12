mod sausage_factory {
    /*insert the keyword here to make the function public*/fn make_sausage() {
        println!("sausage!");
    }
}

fn main() {
    sausage_factory::make_sausage();
}
