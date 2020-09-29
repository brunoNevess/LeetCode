"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""

class Solution:
    
    
    def copyRandomList(self, head: 'Node') -> 'Node':
        self.node_list = {None:None}
        def create_node(node):
            if node in self.node_list:
                return self.node_list[node]
            else:
                new_node = Node(node.val)
                self.node_list[node] = new_node
                return new_node
        p = head
        while p:
            ans = create_node(p)
            ans.next = create_node(p.next)
            ans.random = create_node(p.random)
            p = p.next
        return self.node_list[head]
            