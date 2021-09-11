package main

var g [][]int
var n, m int

func dfs(i int, j int) int {
	if i < 0 || i >= n || j < 0 || j >= m {
		return 0
	}
	if g[i][j] == 0 {
		return 0
	}
	g[i][j] = 0
	return 1 + dfs(i+1, j) + dfs(i-1, j) + dfs(i, j+1) + dfs(i, j-1)
}

func maxAreaOfIsland(grid [][]int) int {
	g = grid
	n = len(g)
	m = len(g[0])
	ans := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if g[i][j] == 0 {
				continue
			}
			if tmp := dfs(i, j); tmp > ans {
				ans = tmp
			}
		}
	}
	return ans
}

func main() {

}
