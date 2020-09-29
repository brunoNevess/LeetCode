class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        
        self.res = []
        
        #OPTIONAL
        #Reduce nums i.e. if nums = [1,2,3,4,4,4,4,4,4,4,4,4,4,5] 
        #   we will never use more than 4 of any given number so reduce to [1,2,3,4,4,4,4,5]
        '''
        from collections import Counter
        temp = Counter(nums)
        nums = []
        for num in temp:
            nums.extend([num]*min(4,temp[num]))
        ''' 

        #Create a dictionary of all possible sums combinations of 2 numbers and their indices
        pairs = {}
        for i,num1 in enumerate(nums):
            for j,num2 in enumerate(nums[i+1:]):
                pairs[num1 + num2] = pairs.get(num1 + num2,[]) + [tuple( (i,i+1+j) )]
        print (pairs)
                
        #look for complementary pair in pairs
        for s in pairs:
            
            if (target - s) in pairs:

                #check whether all indices are unique i.e. i != j != k != l
                #we already know that i != j and k != l so
                #just make sure (i not in [k, l]) and (j not in [k, l])
                for pair_ij in pairs[s]:

                    for pair_kl in pairs[target - s]:

                        if (pair_ij[0] != pair_kl[0])\
                        and (pair_ij[0] != pair_kl[1])\
                        and (pair_ij[1] != pair_kl[0])\
                        and (pair_ij[1] != pair_kl[1]):
                            self.res.append(tuple(sorted([nums[pair_ij[0]], 
                                                          nums[pair_ij[1]], 
                                                          nums[pair_kl[0]], 
                                                          nums[pair_kl[1]]])))

        return set(self.res)