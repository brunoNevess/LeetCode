class Solution(object):
    def reorderList(self, head):
        """
        :type head: ListNode
        :rtype: None Do not return anything, modify head in-place instead.
        """
        if not head:
            return head
        
        nodes = []
        while head:
            nodes.append(head)
            head = head.next
        
        i, j = 0, len(nodes)-1
        while j - i > 1:
            nodes[j].next = nodes[i].next
            nodes[i].next = nodes[j]
            i, j = i + 1, j - 1
        while j - i > -1:
            nodes[j].next = None
            i, j = i + 1, j - 1

        return nodes[0]