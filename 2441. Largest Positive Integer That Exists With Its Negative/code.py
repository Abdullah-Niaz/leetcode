class Solution:
    def findMaxK(nums) -> int:
        maxi = max(nums)
        for i in range(len(nums)):
            if -maxi in nums:
                return maxi
            else:
                nums.remove(maxi)
                if not nums:
                    return -1
                maxi = max(nums)
        return maxi
    
s = Solution
nums = [-1,10,6,7,-7,1]
r = s.findMaxK(nums)
print(r)