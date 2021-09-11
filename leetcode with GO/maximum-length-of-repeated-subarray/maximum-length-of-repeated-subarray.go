package main

var dp [1005][1005]int

func max(x ...int) int {
	ret := -1
	for i := range x {
		if i > ret {
			ret = i
		}
	}
	return ret
}

func findLength(nums1 []int, nums2 []int) int {
	for i := 1; i <= len(nums1); i++ {
		for j := 1; j <= len(nums2); j++ {
			dp[i][j] = 0
			if nums1[i-1] == nums2[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			}
		}
	}
	ans := 0
	for i := 1; i <= len(nums1); i++ {
		for j := 1; j <= len(nums2); j++ {
			// fmt.Println(i, j, dp[i][j])
			if dp[i][j] > ans {
				ans = dp[i][j]
			}
		}
	}
	return ans
}
