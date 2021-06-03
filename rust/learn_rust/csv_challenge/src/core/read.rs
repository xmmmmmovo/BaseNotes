use super::*;

/// # Usage:
/// ```ignore
/// use std::path::PathBuf;
/// let filename = PathBuf::from("./files/challenge.csv");
/// let csv_data = load_csv(filename);
/// assert!(csv_data.is_ok());
/// ```
pub fn load_csv(csv_file: PathBuf) -> Result<String, Error> {
    let file = read(csv_file)?;
    Ok(file)
}

/// # Usage:
/// ```ignore
/// let filename = PathBuf::from("./files/challenge.csv");
/// let csv_data = load_csv(filename).unwrap();
/// let modified_data = replace_column(csv_data, "City", "Beijing").unwrap();
/// let output_file = write_csv(&modified_data, "output/test.csv");
/// assert!(output_file.is_ok());
/// ```
pub fn write_csv(csv_data: &str, filename: &str) -> Result<(), Error> {
    write(csv_data, filename)?;
    Ok(())
}


fn read(path: PathBuf) -> Result<String, Error> {
    let mut buf = String::new();
    let mut file = open(path)?;
    file.read_to_string(&mut buf)?;
    if buf.is_empty() {
        Err("input file missing")?
    } else {
        Ok(buf)
    }
}

fn open(path: PathBuf) -> Result<File, Error> {
    let file = File::open(path)?;
    Ok(file)
}

fn write(data: &str, filename: &str) -> Result<(), Error> {
    let mut buf = File::create(filename)?;
    buf.write_all(data.as_bytes())?;
    Ok(())
}

#[cfg(test)]
mod test {
    use crate::core::read::load_csv;
    use std::path::PathBuf;

    #[test]
    fn test_valid_load_csv() {
        let filename = PathBuf::from("./input/challenge.csv");
        let csv_data = load_csv(filename);
        assert!(csv_data.is_ok());
    }
}
