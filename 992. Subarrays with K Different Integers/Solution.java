import java.util.HashMap;

public class Solution {

    private int atMostKDistinct(int[] nums, int k) {
        int n = nums.length;
        HashMap<Integer, Integer> freqMap = new HashMap<>();
        int left = 0, count = 0;

        for (int right = 0; right < n; ++right) {
            // Add the current element to the frequency map
            freqMap.put(nums[right], freqMap.getOrDefault(nums[right], 0) + 1);

            // If we have more than k distinct elements, shrink the window
            while (freqMap.size() > k) {
                freqMap.put(nums[left], freqMap.get(nums[left]) - 1);
                if (freqMap.get(nums[left]) == 0) {
                    freqMap.remove(nums[left]);
                }
                left++;
            }

            // All subarrays ending with 'right' and starting from any index
            // between 'left' and 'right' are valid subarrays
            count += right - left + 1;
        }

        return count;
    }

    public int subarraysWithKDistinct(int[] nums, int k) {
        // Number of subarrays with exactly k distinct integers
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }

    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums1 = { 1, 2, 1, 2, 3 };
        int k1 = 2;
        int result1 = solution.subarraysWithKDistinct(nums1, k1); // Output: 7
        System.out.println(result1);

        int[] nums2 = { 1, 2, 1, 3, 4 };
        int k2 = 3;
        int result2 = solution.subarraysWithKDistinct(nums2, k2); // Output: 3
        System.out.println(result2);
    }
}
