class Solution:
    def grayCode(self, n: int) -> List[int]:
        return [_ >> 1 ^ _ for _ in range(1 << n)]
    
    
    