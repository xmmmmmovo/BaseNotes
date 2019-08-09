package main

import (
	"fmt"
	"strings"
)

func makeShuffix(shuf string) func(string) string {
	return func(name string) string {
		if strings.HasSuffix(name, shuf) {
			return name
		}
		return name + shuf
	}
}

func main() {
	s := makeShuffix(".jpg")
	fmt.Println("不处理:", s("test.jpg"))
	fmt.Println("处理", s("test"))
}
