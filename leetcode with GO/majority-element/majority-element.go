package main

func majorityElement(nums []int) int {
	flg := -1000000
	cnt := 0
	for _, i := range nums {
		if i != flg {
			cnt--
			if cnt == -1 {
				flg = i
				cnt = 0
			}
		} else {
			cnt++
		}
	}
	return flg
}
