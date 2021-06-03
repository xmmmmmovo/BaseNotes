mod rary;

fn main() {
    rary::public_function();
    // 报错！ `private_function` 是私有的
    //rary::private_function();
    rary::indirect_access();
}
