package main

import "fmt"

func searchInsert(nums []int, target int) int {
	l := 0
	r := len(nums) - 1
	for l <= r {
		m := (l + r) / 2
		if nums[m] >= target {
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return l
}

func main() {
	fmt.Println(searchInsert([]int{1, 3, 5, 6}, 5))
}
