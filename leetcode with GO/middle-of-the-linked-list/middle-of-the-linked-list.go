package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func middleNode(head *ListNode) *ListNode {
	tot := 0
	p := head
	for p != nil {
		tot++
		p = p.Next
	}
	tot /= 2
	p = head
	for tot != 0 {
		p = p.Next
		tot--
	}
	return p
}
