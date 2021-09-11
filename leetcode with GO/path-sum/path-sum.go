package main

func dfs(now *TreeNode, sum int, target int) bool {
	if now.Left == nil && now.Right == nil {
		if sum+now.Val == target {
			return true
		} else {
			return false
		}
	}
	tmp := false
	if now.Left != nil {
		tmp = tmp || dfs(now.Left, sum+now.Val, target)
	}
	if tmp {
		return true
	}
	if now.Right != nil {
		tmp = tmp || dfs(now.Right, sum+now.Val, target)
	}
	return tmp
}

func hasPathSum(root *TreeNode, targetSum int) bool {
	if root == nil {
		return false
	}
	return dfs(root, 0, targetSum)
}

// type TreeNode struct {
// 	Val   int
// 	Left  *TreeNode
// 	Right *TreeNode
// }
