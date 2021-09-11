package main

import "fmt"

func sortedSquares(nums []int) []int {
	ret := []int{}
	l := -1
	mn := 0x3f3f3f3f
	for i, v := range nums {
		if v < 0 {
			v = -v
		}
		if v < mn {
			mn = v
			l = i
		}
	}
	r := l + 1
	for l >= 0 && r < len(nums) {
		if nums[l]*nums[l] <= nums[r]*nums[r] {
			ret = append(ret, nums[l]*nums[l])
			l--
		} else {
			ret = append(ret, nums[r]*nums[r])
			r++
		}
	}
	for l >= 0 {
		ret = append(ret, nums[l]*nums[l])
		l--
	}
	for r < len(nums) {
		ret = append(ret, nums[r]*nums[r])
		r++
	}
	return ret
}

func main() {
	for i, v := range sortedSquares([]int{-4, -1, 0, 3, 10}) {
		fmt.Println(i, v)
	}
}
