package study_bilibili

import "fmt"

// 全局变量会先初始化
// 流程顺序是
// 导入包的 全局变量 init
// 本包的 全局变量 init
var va = test()

func test() (s string) {
	return s
}

// 初始化
// 会在main之前调用
// 引入包之前会被执行
func init() {

}

func main() {
	fmt.Println(va)
}
