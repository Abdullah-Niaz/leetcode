#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int numberOfSubarrays(vector<int>& nums, int k) {
    unordered_map<int, int> prefixCounts;
    prefixCounts[0] = 1;  // Base case: There's one way to have 0 odd numbers before starting
    int oddCount = 0;
    int result = 0;

    for (int num : nums) {
        if (num % 2 == 1) {
            oddCount++;
        }

        if (prefixCounts.find(oddCount - k) != prefixCounts.end()) {
            result += prefixCounts[oddCount - k];
        }

        prefixCounts[oddCount]++;
    }

    return result;
}

int main() {
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    cout << numberOfSubarrays(nums, k) << endl;  // Output: 2
    return 0;
}
