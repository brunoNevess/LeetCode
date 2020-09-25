# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        
        r = 0
        
        p1,p2 = l1,l2
        head = ListNode()
        p = head
        while p1 and p2:
            s = p1.val+p2.val+r
            s,r = s%10,s//10
            head.next = ListNode(s)
            head = head.next
            p1,p2 = p1.next,p2.next
        while p1:
            s = p1.val+r
            s,r = s%10,s//10
            head.next = ListNode(s)
            head = head.next
            p1 = p1.next
        while p2:
            s = p2.val+r
            s,r = s%10,s//10
            head.next = ListNode(s)
            head = head.next
            p2 = p2.next
        if r == 1:
            head.next = ListNode(1)
        return p.next