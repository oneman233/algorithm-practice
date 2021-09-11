package main

import "fmt"

func lengthOfLongestSubstring(s string) int {
	r := 0
	hav := make(map[byte]int)
	ok := func() bool {
		for _, v := range hav {
			if v > 1 {
				return false
			}
		}
		return true
	}
	ans := 0
	for l := 0; l < len(s); l++ {
		for r < len(s) && ok() {
			hav[s[r]]++
			r++
		}
		if !ok() {
			r--
			hav[s[r]]--
		}
		if r-l > ans {
			ans = r - l
		}
		hav[s[l]]--
	}
	return ans
}

func main() {
	fmt.Println(lengthOfLongestSubstring(" "))
}
