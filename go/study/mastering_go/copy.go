package main

import "fmt"

func main() {
	a6 := []int{-10, 1, 2, 3, 4, 5}
	a4 := []int{-1, -2, -3, -4}
	fmt.Println("a6:", a6)
	fmt.Printf("a4:", a4)

	fmt.Println()

	copy(a6,a4)
	fmt.Println("a6:", a6)
	fmt.Printf("a4:", a4)
	fmt.Println()
}
