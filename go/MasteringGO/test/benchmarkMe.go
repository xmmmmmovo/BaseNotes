package main

import "fmt"

func fibo11(n int) int {
	if n == 0 {
		return 0
	} else if n == 1 {
		return 1
	} else {
		return fibo11(n-1) + fibo11(n-2)
	}
}

func fibo22(n int) int {
	if n == 0 || n == 1 {
		return n
	}
	return fibo22(n-1) + fibo22(n-2)
}

func fibo3(n int) int {
	fn := make(map[int]int)
	for i := 0; i <= n; i++ {
		var f int
		if i <= 2 {
			f = 1
		} else {
			f = fn[i-1] + fn[i-2]
		}
		fn[i] = f
	}
	return fn[n]
}

func main() {
	fmt.Println(fibo11(40))
	fmt.Println(fibo22(40))
	fmt.Println(fibo3(40))
}
