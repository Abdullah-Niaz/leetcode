#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        // Early exit if the input vector is empty
        if (strs.empty()) return "";

        std::string ans;
        int n = strs.size();

        // Traverse all characters of the first string
        for (int i = 0; i < strs[0].length(); i++) {
            char ch = strs[0][i];
            bool match = true;
            
            // Compare ch with the rest of the strings
            for (int j = 1; j < n; j++) {
                // If the length of the current string is less than or equal to i, or
                // the current character does not match, set match to false
                if (strs[j].size() <= i || ch != strs[j][i]) {
                    match = false;
                    break;
                }
            }
            
            // If match is false, break out of the loop
            if (!match) {
                break;
            } else {
                ans.push_back(ch);
            }
        }
        
        return ans;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> strs = {"flower", "flow", "flight"};
    std::string result = sol.longestCommonPrefix(strs);
    std::cout << "Longest Common Prefix: " << result << std::endl;
    return 0;
}
