package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func mergeTwoLists(l1 *ListNode, l2 *ListNode) *ListNode {
	head := &ListNode{-1, nil}
	p := head
	for l1 != nil && l2 != nil {
		nxt := &ListNode{-1, nil}
		if l1.Val <= l2.Val {
			nxt.Val = l1.Val
			l1 = l1.Next
		} else {
			nxt.Val = l2.Val
			l2 = l2.Next
		}
		p.Next = nxt
		p = p.Next
	}
	for l1 != nil {
		p.Next = &ListNode{l1.Val, nil}
		p = p.Next
		l1 = l1.Next
	}
	for l2 != nil {
		p.Next = &ListNode{l2.Val, nil}
		p = p.Next
		l2 = l2.Next
	}
	return head.Next
}
