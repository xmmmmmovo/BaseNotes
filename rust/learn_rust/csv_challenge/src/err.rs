use std::io;

#[derive(Debug)]
pub enum Error {
    Io(io::Error),
    Program(&'static str),
}

impl From<io::Error> for Error {
    fn from(e: io::Error) -> Self {
        Error::Io(e)
    }
}

impl From<&'static str> for Error {
    fn from(e: &'static str) -> Self {
        Error::Program(e)
    }
}
