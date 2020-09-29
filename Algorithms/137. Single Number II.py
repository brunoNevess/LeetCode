class Solution:


     # approach: by drawing truth table for 00 -> 01 -> 10 -> 00
        #           l' = ~h & (l ^ i)
        #           h' = ~l' & (h ^ i)
    def singleNumber(self, nums: List[int]) -> int:
        seen_once = seen_twice = 0
        
        for num in nums:

            seen_once = ~seen_twice & (seen_once ^ num)
            seen_twice = ~seen_once & (seen_twice ^ num)
            

        return seen_once