# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def flatten(self, root):
        s = []
        while root and (root.left or root.right or s):
            if root.right:
                s.append(root.right)
                root.right = None
            if root.left:
                root.right,root.left = root.left,None
                root = root.right
            elif s:
                root.right = s.pop()
                root = root.right   