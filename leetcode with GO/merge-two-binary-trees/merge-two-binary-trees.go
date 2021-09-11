package main

type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func dfs(x *TreeNode, y *TreeNode) {
	if x == nil || y == nil {
		return
	}
	x.Val += y.Val
	if x.Left == nil && y.Left != nil {
		x.Left = new(TreeNode)
	}
	if x.Right == nil && y.Right != nil {
		x.Right = new(TreeNode)
	}
	dfs(x.Left, y.Left)
	dfs(x.Right, y.Right)
}

func mergeTrees(root1 *TreeNode, root2 *TreeNode) *TreeNode {
	p1 := new(TreeNode)
	p1.Left = root1
	p2 := new(TreeNode)
	p2.Left = root2
	dfs(p1, p2)
	return p1.Left
}

func main() {

}
