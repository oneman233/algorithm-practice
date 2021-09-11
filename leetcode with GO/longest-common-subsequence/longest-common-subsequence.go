package main

func max(a int, b int) int {
	if a > b {
		return a
	}
	return b
}

var dp [1005][1005]int

func longestCommonSubsequence(text1 string, text2 string) int {
	for i := 1; i <= len(text1); i++ {
		for j := 1; j <= len(text2); j++ {
			dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			if text1[i-1] == text2[j-1] {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1)
			}
		}
	}
	return dp[len(text1)][len(text2)]
}
