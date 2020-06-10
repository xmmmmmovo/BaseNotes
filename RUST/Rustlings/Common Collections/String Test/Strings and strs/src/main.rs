fn string_slice(arg: &str) { println!("{}", arg); }

fn string(arg: String) { println!("{}", arg); }

fn main() {
    TODO("blue");
    TODO("red".to_string());
    TODO(String::from("hi"));
    TODO("rust is fun!".to_owned());
    TODO("nice weather".into());
    TODO(format!("Interpolation {}", "Station"));
    TODO(&String::from("abc")[0..1]);
    TODO("  hello there ".trim());
    TODO("Happy Monday!".to_string().replace("Mon", "Tues"));
    TODO("mY sHiFt KeY iS sTiCkY".to_lowercase());
}