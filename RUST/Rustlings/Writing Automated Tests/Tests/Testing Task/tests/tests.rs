#[cfg(test)]
mod tests {
    use testing_task::is_even;

    #[test]
    fn is_true_when_even() {
        assert!(is_even(/*insert the parameter for the assertion here*/));
    }

    #[test]
    fn is_false_when_odd() {
        assert_eq!(is_even(/*insert the parameter for the assertion here*/), false);
    }
}






