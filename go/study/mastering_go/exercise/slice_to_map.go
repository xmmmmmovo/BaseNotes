package main

import "fmt"

func sliceToMap(s *[]int) (m map[int]int) {
	m = make(map[int]int)
	for k, v := range *s {
		m[k] = v
	}
	return m
}

func main() {
	s := []int{1, 1, 4, 5, 1, 4}
	fmt.Println(sliceToMap(&s))
}
