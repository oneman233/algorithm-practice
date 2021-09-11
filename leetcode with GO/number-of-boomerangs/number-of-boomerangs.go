package main

func numberOfBoomerangs(points [][]int) int {
	ans := 0
	n := len(points)
	for i := 0; i < n; i++ {
		mp := make(map[int]int)
		for j := 0; j < n; j++ {
			if i == j {
				continue
			}
			ans += 2 * mp[dis(points[i], points[j])]
			mp[dis(points[i], points[j])]++
		}
	}
	return ans
}

func dis(a []int, b []int) int {
	return (a[0]-b[0])*(a[0]-b[0]) + (a[1]-b[1])*(a[1]-b[1])
}
