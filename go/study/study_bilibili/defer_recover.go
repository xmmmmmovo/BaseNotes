package study_bilibili

import (
	"errors"
	"fmt"
)

func test1() {
	defer func() {
		// 两种写法都可以
		//err := recover()
		if err := recover(); err != nil {
			fmt.Println("err = ", err)
		}
	}()

	num1 := 1
	num2 := 0
	res := num1 / num2
	fmt.Println(res)
}

// 自定义异常 interface 类型
func read(name string) (err error) {
	if name == "config.ini" {
		return nil
	}else {
		return errors.New("错误!")
	}
}

func test2() {
	err := read("config.ini")
	if err != nil {
		panic(err)
	}

	fmt.Println("success!")
}

func main() {
	//test1()
	test2()
}
