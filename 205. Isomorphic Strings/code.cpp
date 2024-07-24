#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp1;
        unordered_map<char, char> mp2;

        int n = s.length();
        for (int i = 0; i < n; i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            if (mp1.find(ch1) != mp1.end() && mp1[ch1] != ch2
                || mp2.find(ch2) != mp2.end() && mp2[ch2] != ch1) {
                return false;
            }
            mp1[ch1] = ch2;
            mp2[ch2] = ch1;
        }
        return true;
    }
};

int main() {
    Solution solution;
    // Test cases
    string test1_s = "egg", test1_t = "add";
    string test2_s = "foo", test2_t = "bar";
    string test3_s = "paper", test3_t = "title";
    string test4_s = "ab", test4_t = "aa";
    string test5_s = "abcd", test5_t = "xyzz";

    cout << "Test Case 1: " << (solution.isIsomorphic(test1_s, test1_t) ? "True" : "False") << endl;
    cout << "Test Case 2: " << (solution.isIsomorphic(test2_s, test2_t) ? "True" : "False") << endl;
    cout << "Test Case 3: " << (solution.isIsomorphic(test3_s, test3_t) ? "True" : "False") << endl;
    cout << "Test Case 4: " << (solution.isIsomorphic(test4_s, test4_t) ? "True" : "False") << endl;
    cout << "Test Case 5: " << (solution.isIsomorphic(test5_s, test5_t) ? "True" : "False") << endl;

    return 0;
}
