package main

import (
	"errors"
	"fmt"
	"unicode"
)

func reverse(nums *[6]int) {
	fmt.Println(*nums)

	nums_len := len(nums)
	//fmt.Println(nums_len
	for i, j := 0, nums_len - 1; i < j; i, j = i+1, j-1 {
		nums[i], nums[j] = nums[j], nums[i]
	}

	fmt.Println(*nums)
}

func rotate(slice []int, mid int) (err error) {
	slice_len := len(slice)

	fmt.Println(slice)

	if mid > slice_len {
		return errors.New("长度错误!")
	}

	res := make([]int, slice_len)
	for i := 0; i < slice_len; i++ {
		index := i + mid
		if index >= slice_len {
			index = index - slice_len
		}
		res[i] = slice[index]
	}

	fmt.Println(res)

	return nil
}

func emptyString(s []string) {
	fmt.Println(s)

	i, index := 0, 0
	s_len := len(s)
	for _, v := range s{
		index = i + 1
		// 如果index大于切片长度直接跳出
		if index >= s_len {
			break
		}
		if v != s[index] {
			s[i] = v
			i++
		}
	}

	fmt.Println(s[:i])
}

/*
练习 4.6： 编写一个函数，原地将一个UTF-8编码的[]byte类型的slice中相邻的空格（参考unicode.IsSpace）替换成一个空格返回
*/
func emptyString2(s []byte) {
	fmt.Println(s)

	index:=0
	num := len(s)
	for i:=0;i<num;i++{
		index =i+1
		num = len(s)
		if index>=num{
			break
		}
		if unicode.IsSpace(rune(s[i])) && unicode.IsSpace(rune(s[index])){
			//结合remove函数
			copy(s[i:],s[index:])
			s=s[:len(s)-1]
			i--
		}
	}

	fmt.Println(s)
}

func reverse1(s []byte) {
	for i, j := 0, len(s)-1; i < j; i, j = i+1, j-1 {
		s[i], s[j] = s[j], s[i]
	}
}

func main() {
	//nums := [...]int{1, 2, 3, 4, 5, 6}
	//s := [...]string{"123", "456", "456"}
	//reverse(&nums)
	//rotate(nums[:], 4)
	//emptyString(s[:])
	//emptyString2()
}
