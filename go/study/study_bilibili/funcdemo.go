package study_bilibili

import "fmt"

func main() {
	// 匿名函数
	res := func(n1 int32, n2 int32) (int32) {
		return n1 + n2
	}(12, 23)

	fmt.Println(res)
}
