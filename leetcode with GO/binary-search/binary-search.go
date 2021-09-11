package main

import "fmt"

func search(nums []int, target int) int {
	l := 0
	r := len(nums) - 1
	for l <= r {
		m := (l + r) / 2
		if nums[m] == target {
			return m
		} else if nums[m] > target {
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return -1
}

func main() {
	fmt.Println(search([]int{0, 1, 2}, 2))
	fmt.Println(search([]int{0, 1, 2}, 3))
}
