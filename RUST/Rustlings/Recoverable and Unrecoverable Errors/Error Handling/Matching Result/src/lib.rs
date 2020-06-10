use std::num::ParseIntError;

pub fn total_cost(item_quantity: &str) -> Result<i32, ParseIntError> {
    let processing_fee = 1;
    let cost_per_item = 5;
    let qty = item_quantity.parse::<i32>()/*this is the short way, but you can just match the result of the parse*/;

    Ok(qty * cost_per_item + processing_fee)
}
