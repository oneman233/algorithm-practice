package main

func isPowerOfTwo(n int) bool {
	if n == 0 {
		return false
	}
	lowb := func(x int) int {
		return x & -x
	}
	return n == lowb(n)
}
