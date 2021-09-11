package main

import "fmt"

var dp [1005][1005]int

func numDistinct(s string, t string) int {
	for i := 1; i <= len(s); i++ {
		for j := 1; j <= len(t); j++ {
			dp[i][j] = dp[i-1][j] + dp[i][j-1]
			if s[i-1] == t[j-1] {
				dp[i][j]++
			}
		}
	}
	return dp[len(s)][len(t)]
}

func main() {
	fmt.Println(numDistinct("babb", "bb"))
}
