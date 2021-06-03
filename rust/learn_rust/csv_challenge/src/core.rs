pub mod read;
pub mod write;
use crate::err::Error;
use std::fs::File;
use std::io::{Read, Write};
use std::path::PathBuf;