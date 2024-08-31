from collections import Counter, defaultdict


class Solution:
    def minWindow(self, s: str, t: str) -> str:
        if len(t) > len(s):
            return ""

        # Dictionary to count all characters in t
        t_count = Counter(t)
        required = len(t_count)  # Number of unique characters in t

        # Dictionary to keep track of the window's character counts
        window_count = defaultdict(int)
        left, right = 0, 0
        formed = 0  # To keep track of how many unique characters in t are in the current window with correct frequency
        min_len = float("inf")
        ans = (0, 0)

        while right < len(s):
            # Expand the window by including the current character
            character = s[right]
            window_count[character] += 1

            # If the current character is part of t and its frequency in the window matches the frequency in t
            if character in t_count and window_count[character] == t_count[character]:
                formed += 1

            # Try and contract the window until it ceases to be 'valid'
            while left <= right and formed == required:
                character = s[left]

                # Update the answer if the current window is smaller
                if right - left + 1 < min_len:
                    min_len = right - left + 1
                    ans = (left, right)

                # Remove the leftmost character from the window
                window_count[character] -= 1
                if character in t_count and window_count[character] < t_count[character]:
                    formed -= 1

                # Move the left pointer to the right
                left += 1

            # Move the right pointer to expand the window
            right += 1

        # Return the smallest window or an empty string if no such window exists
        return "" if min_len == float("inf") else s[ans[0]:ans[1] + 1]


# Example usage
solution = Solution()

s1 = "ADOBECODEBANC"
t1 = "ABC"
print(solution.minWindow(s1, t1))  # Output: "BANC"

s2 = "a"
t2 = "a"
print(solution.minWindow(s2, t2))  # Output: "a"

s3 = "a"
t3 = "aa"
print(solution.minWindow(s3, t3))  # Output: ""
