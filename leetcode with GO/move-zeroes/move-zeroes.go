package main

import "fmt"

func swap(x *int, y *int) {
	z := *x
	*x = *y
	*y = z
}

func moveZeroes(nums []int) {
	n := len(nums)
	i := 0
	for i < n && nums[i] != 0 {
		i++
	}
	j := i + 1
	for ; i < n && j < n; i++ {
		for j < n && nums[j] == 0 {
			j++
		}
		if j < n {
			swap(&nums[i], &nums[j])
		}
	}
}

func main() {
	a := []int{0, 1, 0, 3, 12}
	moveZeroes(a)
	for _, v := range a {
		fmt.Println(v)
	}
}
