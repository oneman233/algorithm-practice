package main

import "sort"

func maxTwoEvents(a [][]int) int {
	b := make([]int, 0)
	for _, i := range a {
		b = append(b, i[0])
		b = append(b, i[1])
	}
	sort.Ints(b)
	for i := range a {
		a[i][0] = sort.SearchInts(b, a[i][0])
		a[i][1] = sort.SearchInts(b, a[i][1])
	}
	mp := make(map[int]int)
	for _, i := range a {
		if i[2] > mp[i[1]] {
			mp[i[1]] = i[2]
		}
	}
	ans := -1
	for i := 1; i <= 2*len(a); i++ {
		if mp[i-1] > mp[i] {
			mp[i] = mp[i-1]
		}
	}
	for _, i := range a {
		if i[2]+mp[i[0]-1] > ans {
			ans = i[2] + mp[i[0]-1]
		}
	}
	return ans
}
