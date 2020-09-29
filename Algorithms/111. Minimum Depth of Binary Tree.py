class Solution(object):
    def minDepth(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        currLevel = 0
        if(root):
            queue = [(root,1)]
            while(queue):
                curr = queue.pop(0)
                currNode, currLevel = curr[0],curr[1]
                if(not currNode.left and not currNode.right):
                    return currLevel
                if(currNode.left):
                    queue.append((currNode.left,currLevel+1))
                if(currNode.right):
                    queue.append((currNode.right,currLevel+1))
        
        return currLevel