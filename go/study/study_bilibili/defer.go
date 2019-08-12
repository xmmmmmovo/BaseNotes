package study_bilibili

import "fmt"

func sum(n1 int, n2 int) int {

	// defer 是栈 会先进后出
	defer fmt.Println(n1, n2)
	defer fmt.Println("栈顶")
	fmt.Println(n1 + n2)

	return n1 + n2
}

func main() {
	sum(1, 2)
}
