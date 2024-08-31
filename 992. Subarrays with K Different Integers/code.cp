#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int atMostKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq_map;
        int left = 0, count = 0;
        
        for (int right = 0; right < n; ++right) {
            // Add the current element to the frequency map
            freq_map[nums[right]]++;
            
            // If we have more than k distinct elements, shrink the window
            while (freq_map.size() > k) {
                freq_map[nums[left]]--;
                if (freq_map[nums[left]] == 0) {
                    freq_map.erase(nums[left]);
                }
                left++;
            }
            
            // All subarrays ending with 'right' and starting from any index
            // between 'left' and 'right' are valid subarrays
            count += right - left + 1;
        }
        
        return count;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // Number of subarrays with exactly k distinct integers
        return atMostKDistinct(nums, k) - atMostKDistinct(nums, k - 1);
    }
};

// Example usage
int main() {
    Solution solution;
    vector<int> nums1 = {1, 2, 1, 2, 3};
    int k1 = 2;
    int result1 = solution.subarraysWithKDistinct(nums1, k1); // Output: 7

    vector<int> nums2 = {1, 2, 1, 3, 4};
    int k2 = 3;
    int result2 = solution.subarraysWithKDistinct(nums2, k2); // Output: 3
    
    return 0;
}
