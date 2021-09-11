package main

import "fmt"

func numberOfArithmeticSlices(nums []int) int {
	if len(nums) < 3 {
		return 0
	}
	seg := []int{}
	for i := 1; i < len(nums); i++ {
		seg = append(seg, nums[i]-nums[i-1])
	}
	flg, l, ans := seg[0], 1, 0
	for i := 1; i < len(seg); i++ {
		if seg[i] == flg {
			l++
		} else {
			if l >= 2 {
				ans += l * (l - 1) / +2
			}
			flg = seg[i]
			l = 1
		}
	}
	if l >= 2 {
		ans += l * (l - 1) / +2
	}
	return ans
}

func main() {
	fmt.Println(numberOfArithmeticSlices([]int{1}))
}
