package main

import (
	"fmt"
	"strings"
)

func toGoatLatin(S string) string {
	vowel := "aeiouAEIOU"
	ans := ""

	// 按空格切分
	split_string := strings.Split(S, " ")

	fmt.Println(split_string)

	for _, value := range split_string {
		if strings.ContainsRune(vowel, rune(value[0])) {
			println(value)
		}
	}

	return ans
}

func main() {
	fmt.Println(toGoatLatin("I speak Goat Latin"))
	fmt.Println(toGoatLatin("The quick brown fox jumped over the lazy dog"))
}
