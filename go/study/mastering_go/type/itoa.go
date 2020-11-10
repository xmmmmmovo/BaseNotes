package main

import "fmt"

// 常量生成器
const (
	p1 = 1 << iota
	p2
	p3
)

func main() {
	fmt.Println(p1)
	fmt.Println(p2)
	fmt.Println(p3)
}
