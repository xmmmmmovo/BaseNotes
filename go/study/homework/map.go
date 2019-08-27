package main

import "fmt"

func main() {
	//args := make(map[string]int)

	args := map[string]int{
		"alice":   31,
		"charlie": 34,
	}
	fmt.Println(args)

	for key, value := range args{
		fmt.Println(key, value)
	}

}
