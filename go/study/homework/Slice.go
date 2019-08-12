package homework

import (
	"errors"
	"fmt"
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

func main() {
	nums := [...]int{1, 2, 3, 4, 5, 6}
	//reverse(&nums)
	rotate(nums[:], 4)
}
