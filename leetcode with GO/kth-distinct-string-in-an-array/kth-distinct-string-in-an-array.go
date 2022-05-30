package main

func kthDistinct(arr []string, k int) string {
	mp := make(map[string]int)

	for _, i := range arr {
		mp[i]++
	}

	j := 0

	for _, i := range arr {
		if mp[i] == 1 {
			j++
			if j == k {
				return i
			}
		}
	}

	return ""
}
