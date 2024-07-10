#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;

        for(int i = 0 ;i < nums.size(); i++){
            st.insert(nums[i]);
        }   

        int index = 0 ;
        for( auto it:st){
            nums[index]  = it;
            index++;
        }
        return index;
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