package main

var a []int
var now []int
var vis map[int]bool
var ans [][]int

func dfs(x int) {
	if x == len(a) {
		ans = append(ans, make([]int, len(a)))
		for i := 0; i < len(a); i++ {
			ans[len(ans)-1][i] = now[i]
		}
		return
	}
	for i := 0; i < len(a); i++ {
		if !vis[a[i]] {
			vis[a[i]] = true
			now = append(now, a[i])
			dfs(x + 1)
			vis[a[i]] = false
			now = now[:len(now)-1]
		}
	}

}

func permute(nums []int) [][]int {
	ans = [][]int{}
	vis = map[int]bool{}
	a = nums
	dfs(0)
	return ans
}
