# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if not preorder: return None
    
        root = TreeNode(preorder[0])
        if len(preorder) == 1: return root
    
        m = inorder.index(preorder[0])
        
        root.left = self.buildTree(preorder[1:m+1],inorder[0:m])
        root.right = self.buildTree(preorder[m+1:],inorder[m+1:])
        
        return root
        
    
    
    
    
#         1
#     2.     3
# 4.   5.   6  7
            
# pre:     [1]  [2 4 5]  [3 6 7]
# inorder: [4 2 5] 1 [6 3 7]
        