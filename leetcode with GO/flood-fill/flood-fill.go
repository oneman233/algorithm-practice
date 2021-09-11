package main

func dfs(image [][]int, i int, j int, c int, cc int) {
	if i < 0 || i >= len(image) || j < 0 || j >= len(image[0]) {
		return
	}
	if image[i][j] != c {
		return
	}
	image[i][j] = cc
	dfs(image, i+1, j, c, cc)
	dfs(image, i-1, j, c, cc)
	dfs(image, i, j+1, c, cc)
	dfs(image, i, j-1, c, cc)
}

func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	if image[sr][sc] != newColor {
		dfs(image, sr, sc, image[sr][sc], newColor)
	}
	return image
}

func main() {

}
