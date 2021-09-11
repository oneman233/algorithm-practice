package main

import "fmt"

var now []int
var ans [][]int
var n, k int

func dfs(i int, cnt int) {
	if cnt == k {
		// fmt.Println(now)
		ans = append(ans, make([]int, k))
		for i := 0; i < k; i++ {
			ans[len(ans)-1][i] = now[i]
		}
		return
	}
	if i == n+1 {
		return
	}
	now = append(now, i)
	dfs(i+1, cnt+1)
	now = now[:len(now)-1]
	dfs(i+1, cnt)
}

func combine(N int, K int) [][]int {
	ans = [][]int{}
	n = N
	k = K
	dfs(1, 0)
	return ans
}

func main() {
	for _, i := range combine(1, 1) {
		fmt.Println(i)
	}
}
