package vec_slice

func Sum(numbers []int) (sum int) {
	sum = 0
	for _, number := range numbers {
		sum += number
	}
	return sum
}

func SumAll(numberToSum ...[]int) (sums []int) {
	
	for _, numbers := range numberToSum {
		sums = append(sums, Sum(numbers))
	}

	return
}
