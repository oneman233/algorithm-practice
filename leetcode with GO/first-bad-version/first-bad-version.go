package main

func isBadVersion(version int) bool

func firstBadVersion(n int) int {
	l := 1
	r := n
	for l <= r {
		m := (l + r) / 2
		if isBadVersion(m) {
			r = m - 1
		} else {
			l = m + 1
		}
	}
	return l
}
