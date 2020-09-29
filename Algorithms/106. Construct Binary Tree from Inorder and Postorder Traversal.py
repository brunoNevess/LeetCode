# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

    
# [L] [Root] [R] in
# [L] [R] [Root] po


class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        n = len(inorder)
        if n == 0 : return None
        r = postorder[n-1]
        i = n-1
        while i>0 and inorder[i]!=r : i-=1
        
        root = TreeNode(r)
        
        root.left = self.buildTree(inorder[0:i],postorder[0:i]) 

        root.right = self.buildTree(inorder[i+1:],postorder[i:n-1])
        return root