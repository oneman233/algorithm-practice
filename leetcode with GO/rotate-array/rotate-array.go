package main

import (
	"fmt"
)

func swap(x *int, y *int) {
	z := *x
	*x = *y
	*y = z
}

func rev(nums []int, l int, r int) {
	for l < r {
		swap(&nums[l], &nums[r])
		l++
		r--
	}
}

func rotate(nums []int, k int) {
	k %= len(nums)
	rev(nums, 0, len(nums)-1)
	rev(nums, 0, k-1)
	rev(nums, k, len(nums)-1)
}

func main() {
	a := []int{1, 2, 3, 4, 5, 6, 7}
	rotate(a, 3)
	for _, v := range a {
		fmt.Printf("%d ", v)
	}
}
