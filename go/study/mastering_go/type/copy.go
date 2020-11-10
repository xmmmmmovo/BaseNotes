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

	fmt.Println()
	array4 := [4]int{4, -4, 4, -4}
	s6 := []int{1,-1,1,-1,-5,5}

	copy(s6, array4[0:])
	fmt.Println("array4:", array4[0:])
	fmt.Printf("s6:", s6)
	fmt.Println()
}
