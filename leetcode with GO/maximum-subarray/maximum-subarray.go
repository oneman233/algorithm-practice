package main

import "fmt"

func maxSubArray(nums []int) int {
	mn := 0
	sum := 0
	ans := -1000000
	for _, i := range nums {
		sum += i
		if sum-mn > ans {
			ans = sum - mn
		}
		if sum < mn {
			mn = sum
		}
	}
	return ans
}

func main() {
	fmt.Println(maxSubArray([]int{-2, 1, -3, 4, -1, 2, 1, -5, 4}))
}
