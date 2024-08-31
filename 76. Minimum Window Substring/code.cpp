#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.length() < t.length()) return "";
        
        // Map to keep track of the count of characters in t
        unordered_map<char, int> tMap;
        for (char c : t) {
            tMap[c]++;
        }
        
        // Variables to track the window and results
        unordered_map<char, int> windowMap;
        int left = 0, right = 0;
        int required = tMap.size();
        int formed = 0;
        int minLength = INT_MAX;
        int minLeft = 0;

        while (right < s.length()) {
            char c = s[right];
            windowMap[c]++;
            
            if (tMap.find(c) != tMap.end() && windowMap[c] == tMap[c]) {
                formed++;
            }
            
            // Try to contract the window
            while (left <= right && formed == required) {
                c = s[left];
                
                // Update the answer
                if (right - left + 1 < minLength) {
                    minLength = right - left + 1;
                    minLeft = left;
                }
                
                // Remove the leftmost character
                windowMap[c]--;
                if (tMap.find(c) != tMap.end() && windowMap[c] < tMap[c]) {
                    formed--;
                }
                left++;
            }
            
            right++;
        }
        
        return minLength == INT_MAX ? "" : s.substr(minLeft, minLength);
    }
};

// Example usage
int main() {
    Solution solution;

    string s1 = "ADOBECODEBANC";
    string t1 = "ABC";
    cout << solution.minWindow(s1, t1) << endl;  // Output: "BANC"

    string s2 = "a";
    string t2 = "a";
    cout << solution.minWindow(s2, t2) << endl;  // Output: "a"

    string s3 = "a";
    string t3 = "aa";
    cout << solution.minWindow(s3, t3) << endl;  // Output: ""

    return 0;
}
