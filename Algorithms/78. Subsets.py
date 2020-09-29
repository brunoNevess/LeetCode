class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
                s = [[]]
                for x in nums:
                        s += [y + [x] for y in s ]
                return s