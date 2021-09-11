package main

import "fmt"

func reverseBits(num uint32) uint32 {
	ans := uint32(0)
	for i := 31; i >= 0; i-- {
		flg := uint32(1<<i) & num
		if flg != uint32(0) {
			flg >>= i
			ans |= flg << (31 - i)
		}
	}
	return ans
}

func main() {
	fmt.Println(reverseBits(uint32(43261596)))
}
