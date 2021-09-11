package main

var stk []*ListNode

func push(x *ListNode) {
	stk = append(stk, x)
}

func pop() {
	stk = stk[:len(stk)-1]
}

func empty() bool {
	return len(stk) == 0
}

func size() int {
	return len(stk)
}

func clear() {
	stk = []*ListNode{}
}

func top() *ListNode {
	return stk[len(stk)-1]
}

func reverseKGroup(head *ListNode, k int) *ListNode {
	clear()
	from := new(ListNode)
	from.Next = head
	ans := from
	now := head
	for now != nil {
		if size() == k {
			to := now
			tmp := from
			for !empty() {
				tmp.Next = top()
				tmp = tmp.Next
				pop()
			}
			tmp.Next = to
			from = tmp
		}
		push(now)
		now = now.Next
	}
	if size() == k {
		tmp := from
		for !empty() {
			tmp.Next = top()
			tmp = tmp.Next
			pop()
		}
		tmp.Next = nil
		from = tmp
	}
	return ans.Next
}

type ListNode struct {
	Val  int
	Next *ListNode
}
