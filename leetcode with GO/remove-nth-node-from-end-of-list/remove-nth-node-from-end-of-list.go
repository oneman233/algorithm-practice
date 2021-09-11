package main

type ListNode struct {
	Val  int
	Next *ListNode
}

func removeNthFromEnd(head *ListNode, n int) *ListNode {
	fake := new(ListNode)
	fake.Next = head
	// 创建fake节点便于处理头节点的删除
	fp := fake
	p := head
	q := head
	cnt := n - 1
	for cnt != 0 {
		q = q.Next
		cnt--
	}
	for q.Next != nil {
		p = p.Next
		q = q.Next
		fp = fp.Next
	}
	fp.Next = p.Next
	return fake.Next
}
