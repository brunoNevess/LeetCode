# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    
    def build(self,v,i,j):
        if i > j:
            return
        med = i + int((j-i)/2)
        
        n = TreeNode(v[med])
        n.left = self.build(v,i,med-1)
        n.right = self.build(v,med+1,j)
        return n
        
    
    def sortedListToBST(self, head: ListNode) -> TreeNode:
        v = []
        i = head
        while i:
            v.append(i.val)
            i = i.next
        n = self.build(v,0,len(v)-1)
        return n