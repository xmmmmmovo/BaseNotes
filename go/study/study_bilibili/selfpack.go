package study_bilibili

import "fmt"

// 函数闭包
// 这样看来n有点像static
func AddUpper() func(int) (int) {
	var n int = 10
	return func(x int) int {
		n += x
		return n
	}
}

func main() {
	f := AddUpper()
	fmt.Println(f(1)) // 11
	fmt.Println(f(2)) // 13
}
