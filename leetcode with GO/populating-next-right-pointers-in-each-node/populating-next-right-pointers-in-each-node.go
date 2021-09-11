package main

type Node struct {
	Val   int
	Left  *Node
	Right *Node
	Next  *Node
}

func dfs(now *Node, f *Node, flg int) {
	if f == nil {
		now.Next = nil
	} else {
		if flg == 0 {
			now.Next = f.Right
		} else if flg == 1 {
			if f.Next == nil {
				now.Next = nil
			} else {
				now.Next = f.Next.Left
			}
		}
	}
	if now.Left != nil {
		dfs(now.Left, now, 0)
	}
	if now.Right != nil {
		dfs(now.Right, now, 1)
	}
}

func connect(root *Node) *Node {
	if root == nil {
		return nil
	}
	dfs(root, nil, 0)
	return root
}

func main() {

}
