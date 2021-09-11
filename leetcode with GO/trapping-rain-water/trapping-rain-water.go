package main

var stk []int

func top() int {
	return stk[len(stk)-1]
}

func pop() {
	stk = stk[:len(stk)-1]
}

func push(x int) {
	stk = append(stk, x)
}

func empty() bool {
	return len(stk) == 0
}

func clear() {
	stk = []int{}
}

func min(x int, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func trap(height []int) int {
	clear()
	ans := 0
	for i, v := range height {
		if empty() {
			push(i)
			continue
		}
		for !empty() && v >= height[top()] {
			t1 := top()
			pop()
			if empty() {
				break
			}
			t2 := top()
			ans += (min(v, height[t2]) - height[t1]) * (i - t2 - 1)
		}
		push(i)
	}
	return ans
}
