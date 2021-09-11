package main

import (
	"fmt"
	"unicode"
)

var ans []string
var s string
var now []rune

func dfs(i int) {
	if i == len(s) {
		ans = append(ans, string(now))
		return
	}
	if unicode.IsLetter(rune(s[i])) {
		t := unicode.ToLower(rune(s[i]))
		now[i] = t
		dfs(i + 1)
		t = unicode.ToUpper(t)
		now[i] = t
		dfs(i + 1)
	} else {
		dfs(i + 1)
	}
}

func letterCasePermutation(S string) []string {
	s = S
	now = []rune(S)
	ans = []string{}
	dfs(0)
	return ans
}

func main() {
	fmt.Println(letterCasePermutation("a1b2"))
}
