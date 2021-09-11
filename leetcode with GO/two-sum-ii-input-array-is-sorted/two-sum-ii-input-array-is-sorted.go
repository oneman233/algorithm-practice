package main

import "fmt"

func twoSum(numbers []int, target int) []int {
	ret := []int{0, len(numbers) - 1}
	for ; ret[0] < ret[1]; ret[0]++ {
		for numbers[ret[0]]+numbers[ret[1]] > target {
			ret[1]--
		}
		if numbers[ret[0]]+numbers[ret[1]] == target {
			break
		}
	}
	ret[0]++
	ret[1]++
	return ret
}

func main() {
	fmt.Println(twoSum([]int{2, 7, 11, 15}, 9))
}
