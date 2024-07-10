#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0;
        for(int j = 1; j < nums.size(); j++){
            if(nums[i]  != nums[j]){
                nums[i+1] = nums[j];
                i++;
            }
        }
        return i + 1;
    }
};

int main(){
    Solution solution;
    std::vector<int> nums = {1, 1, 2, 2, 3, 4, 4, 5};

    int newLength = solution.removeDuplicates(nums);

    std::cout << "New length: " << newLength << std::endl;
    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < newLength; i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;
    
    
    return 0;
}