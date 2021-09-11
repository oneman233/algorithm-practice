package main

var inf int = 1000000

func orangesRotting(grid [][]int) int {
	n, m := len(grid), len(grid[0])
	dis := [15][15]int{}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 2 {
				dis[i][j] = 0
			} else {
				dis[i][j] = inf
			}
		}
	}
	q := [][]int{}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 2 {
				q = append(q, []int{i, j})
			}
		}
	}
	d := [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	ok := func(i int, j int) bool {
		return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == 1
	}
	for len(q) != 0 {
		f := q[0]
		q = q[1:]
		grid[f[0]][f[1]] = 2
		for i := 0; i < 4; i++ {
			if ok(f[0]+d[i][0], f[1]+d[i][1]) {
				if dis[f[0]][f[1]]+1 < dis[f[0]+d[i][0]][f[1]+d[i][1]] {
					dis[f[0]+d[i][0]][f[1]+d[i][1]] = dis[f[0]][f[1]] + 1
				}
				q = append(q, []int{f[0] + d[i][0], f[1] + d[i][1]})
			}
		}
	}
	// for i := 0; i < n; i++ {
	// 	for j := 0; j < m; j++ {
	// 		fmt.Print(grid[i][j])
	// 		fmt.Print(" ")
	// 	}
	// 	fmt.Println()
	// }
	ans := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if grid[i][j] == 1 {
				return -1
			}
			if grid[i][j] == 2 && dis[i][j] > ans {
				ans = dis[i][j]
			}
		}
	}
	return ans
}
