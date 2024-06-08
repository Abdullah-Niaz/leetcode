#include <vector>
#include <map>
#include <iostream>

using namespace std;

int singleNumber(vector<int> &nums)
{
    map<int,int> p;
    for ( int i = 0; i < nums.size(); i++)
    {
        p[nums[i]]++;
    }

    for (auto i:p)
    {
        if(i.second ==1 ){
            return i.first;
        }
    }
    return 0;
    
    
};

int main()
{
    vector<int> nums = {4, 1, 2, 1, 2};
    cout <<singleNumber(nums) << endl; // Output: 4
    return 0;
}
