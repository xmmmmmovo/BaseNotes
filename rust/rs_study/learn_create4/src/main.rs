use crypto::sha3::Sha3;
use crypto::digest::Digest;

fn main() {
    let mut hasher = Sha3::sha3_256();
    hasher.input_str("hello world");
    let result = hasher.result_str();
    println!("hash = {}", result);
}
