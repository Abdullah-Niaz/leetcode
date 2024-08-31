from collections import defaultdict
from typing import List


class Solution:
    def atMostKDistinct(self, nums: List[int], k: int) -> int:
        n = len(nums)
        freq_map = defaultdict(int)
        left = 0
        count = 0

        for right in range(n):
            # Add the current element to the frequency map
            freq_map[nums[right]] += 1

            # If we have more than k distinct elements, shrink the window
            while len(freq_map) > k:
                freq_map[nums[left]] -= 1
                if freq_map[nums[left]] == 0:
                    del freq_map[nums[left]]
                left += 1

            # All subarrays ending with 'right' and starting from any index
            # between 'left' and 'right' are valid subarrays
            count += right - left + 1

        return count

    def subarraysWithKDistinct(self, nums: List[int], k: int) -> int:
        # Number of subarrays with exactly k distinct integers
        return self.atMostKDistinct(nums, k) - self.atMostKDistinct(nums, k-1)


# Example usage
solution = Solution()
nums1 = [1, 2, 1, 2, 3]
k1 = 2
print(solution.subarraysWithKDistinct(nums1, k1))  # Output: 7

nums2 = [1, 2, 1, 3, 4]
k2 = 3
print(solution.subarraysWithKDistinct(nums2, k2))  # Output: 3
