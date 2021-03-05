use futures::future::join_all;
use std::borrow::BorrowMut;

async fn fetch_path(path: String) -> surf::Result<String> {
    Ok(surf::get(&path).await?.body_string().await?)
}

#[async_std::main]
async fn main() -> surf::Result<()> {
    let path = vec![
        "http://localhost/ip".to_string(),
        "http://localhost/".to_string(),
    ];

    let res_list = join_all(path.into_iter().map(|path| fetch_path(path))).await;

    for res in res_list.into_iter() {
        if res.is_ok() {
            println!("len : {}", res?.len())
        }
    }

    Ok(())
}
