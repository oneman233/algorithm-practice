package main

const inf int = 1000000

var n, m int
var dis [][]int
var vis [10000][10000]bool

type pair struct {
	i int
	j int
}

var q = []pair{}

func ok(i int, j int) bool {
	return i >= 0 && i < n && j >= 0 && j < m && vis[i][j] == false
}

var dx = []int{0, 0, 1, -1}
var dy = []int{1, -1, 0, 0}

func bfs() {
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			vis[i][j] = false
		}
	}
	for len(q) != 0 {
		f := q[0]
		q = q[1:]
		if vis[f.i][f.j] == true {
			continue
		}
		vis[f.i][f.j] = true
		for i := 0; i < 4; i++ {
			if ok(f.i+dx[i], f.j+dy[i]) {
				if dis[f.i][f.j]+1 < dis[f.i+dx[i]][f.j+dy[i]] {
					dis[f.i+dx[i]][f.j+dy[i]] = dis[f.i][f.j] + 1
				}
				q = append(q, pair{f.i + dx[i], f.j + dy[i]})
			}
		}
	}
}

func updateMatrix(mat [][]int) [][]int {
	n = len(mat)
	m = len(mat[0])
	dis = mat
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if mat[i][j] == 0 {
				dis[i][j] = 0
			} else {
				dis[i][j] = inf
			}
		}
	}
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if mat[i][j] == 0 {
				q = append(q, pair{i, j})
			}
		}
	}
	bfs()
	return dis
}
