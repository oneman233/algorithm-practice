package main

func hammingWeight(num uint32) int {
	if num == 0 {
		return 0
	}
	ans := 0
	lowb := func(x uint32) uint32 {
		return x & -x
	}
	for num != 0 {
		num -= lowb(num)
		ans++
	}
	return ans
}
