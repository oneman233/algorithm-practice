package main

var tr [1e6 + 5]int
var tag [1e6 + 5]int

func up(p int) {
	tr[p] = tr[p<<1] + tr[p<<1|1]
}

func down(p int) {
	if tag[p] != 0 {
		tr[p<<1] += tag[p]
		tag[p<<1] += tag[p]
		tr[p<<1|1] += tag[p]
		tag[p<<1|1] += tag[p]
		tag[p] = 0
	}
}

func ask(p int, L int, R int, pos int) int {
	if L == pos && L == R {
		return tr[p]
	}
	m := (L + R) / 2
	var ret int
	down(p)
	if pos <= m {
		ret = ask(p<<1, L, m, pos)
	} else {
		ret = ask(p<<1|1, m+1, R, pos)
	}
	up(p)
	return ret
}

func add(p int, L int, R int, l int, r int, val int) {
	if l > r {
		return
	}
	if l <= L && R <= r {
		tag[p] += val
		tr[p] += val
		return
	}
	m := (L + R) / 2
	down(p)
	if l <= m {
		add(p<<1, L, m, l, r, val)
	}
	if r > m {
		add(p<<1|1, m+1, R, l, r, val)
	}
	up(p)
}

func build(p int, L int, R int) {
	tr[p] = 0
	tag[p] = 0
	if L == R {
		return
	}
	m := (L + R) / 2
	build(p<<1, L, m)
	build(p<<1|1, m+1, R)
}

const MAX int = 2e5

func minMoves(nums []int, limit int) int {
	build(1, 1, MAX)
	for i := 0; i < len(nums)-1-i; i++ {
		a := nums[i]
		b := nums[len(nums)-1-i]
		if a > b {
			a, b = b, a
		}
		add(1, 1, MAX, 1+a, a+b-1, 1)
		add(1, 1, MAX, a+b+1, b+limit, 1)
		add(1, 1, MAX, 2, a, 2)
		add(1, 1, MAX, b+limit+1, 2*limit, 2)
	}
	ans := MAX
	for i := 2; i <= 2*limit; i++ {
		tmp := ask(1, 1, MAX, i)
		if tmp < ans {
			ans = tmp
		}
		// fmt.Println(i, tmp)
	}
	return ans
}
