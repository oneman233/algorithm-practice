package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return nil
	}
	stk := []*ListNode{}
	for head != nil {
		stk = append(stk, head)
		head = head.Next
	}
	t := stk[len(stk)-1]
	ans := t
	stk = stk[:len(stk)-1]
	for len(stk) != 0 {
		t.Next = stk[len(stk)-1]
		stk = stk[:len(stk)-1]
		t = t.Next
	}
	t.Next = nil
	return ans
}
