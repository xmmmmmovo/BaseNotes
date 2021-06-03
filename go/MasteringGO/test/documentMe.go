package main

import "fmt"

// Pie is a global variable
// This is a silly comment!
const Pie = 3.1415912

// The S1() function finds the length of a string
// It iterates over the string using range
func S1(s string) int {
	if s == "" {
		return 0
	}
	n := 0
	for range s {
		n ++
	}
	return n
}

// The F1() function returns the double value of its input integer
// A better function name would have been Double()!
func F1(n int) int {
	return 2 * n
}

func ExampleS1() {
	fmt.Println(S1("123456789"))
	fmt.Println(S1(""))
	// Output:
	// 9
	// 0
}

func ExampleF1() {
	fmt.Println(F1(10))
	fmt.Println(F1(2))
	// Output:
	// 1
	// 55
}