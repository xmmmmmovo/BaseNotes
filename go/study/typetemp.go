package main

import (
	"fmt" // 如果前面加下划线_代表忽略
)

func main() {
	var n1 int8 = 12
	var n3 int8
	var n4 = int32(n1) + 128

	fmt.Println(n3, n4)
}
