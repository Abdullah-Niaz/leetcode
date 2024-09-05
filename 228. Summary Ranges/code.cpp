#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to return the summary of ranges
vector<string> summaryRanges(vector<int> &nums)
{
    vector<string> result;
    int n = nums.size();

    if (n == 0)
        return result;

    // Start the first range
    int start = nums[0];

    for (int i = 1; i < n; i++)
    {
        // If current number is not consecutive to the previous one
        if (nums[i] != nums[i - 1] + 1)
        {
            // Add the range to the result
            if (start == nums[i - 1])
            {
                result.push_back(to_string(start));
            }
            else
            {
                result.push_back(to_string(start) + "->" + to_string(nums[i - 1]));
            }
            // Start a new range
            start = nums[i];
        }
    }

    // Add the last range after the loop
    if (start == nums[n - 1])
    {
        result.push_back(to_string(start));
    }
    else
    {
        result.push_back(to_string(start) + "->" + to_string(nums[n - 1]));
    }

    return result;
}

// Main function to test the implementation
int main()
{
    // Example 1
    vector<int> nums1 = {0, 1, 2, 4, 5, 7};
    vector<string> result1 = summaryRanges(nums1);
    cout << "Input: {0, 1, 2, 4, 5, 7}\nOutput: ";
    for (const string &s : result1)
    {
        cout << s << " ";
    }
    cout << endl;

    // Example 2
    vector<int> nums2 = {0, 2, 3, 4, 6, 8, 9};
    vector<string> result2 = summaryRanges(nums2);
    cout << "Input: {0, 2, 3, 4, 6, 8, 9}\nOutput: ";
    for (const string &s : result2)
    {
        cout << s << " ";
    }
    cout << endl;

    return 0;
}
