
import java.util.HashMap;
import java.util.Map;

public class code {
    public String minWindow(String s, String t) {
        if (s.length() < t.length())
            return "";

        // Map to keep track of the count of characters in t
        Map<Character, Integer> tMap = new HashMap<>();
        for (char c : t.toCharArray()) {
            tMap.put(c, tMap.getOrDefault(c, 0) + 1);
        }

        // Variables to track the window and results
        Map<Character, Integer> windowMap = new HashMap<>();
        int left = 0, right = 0;
        int required = tMap.size();
        int formed = 0;
        int[] ans = { -1, 0, 0 }; // length, left, right

        while (right < s.length()) {
            char c = s.charAt(right);
            windowMap.put(c, windowMap.getOrDefault(c, 0) + 1);

            if (tMap.containsKey(c) && windowMap.get(c).intValue() == tMap.get(c).intValue()) {
                formed++;
            }

            // Try to contract the window
            while (left <= right && formed == required) {
                c = s.charAt(left);

                // Update the answer
                if (ans[0] == -1 || right - left + 1 < ans[0]) {
                    ans[0] = right - left + 1;
                    ans[1] = left;
                    ans[2] = right;
                }

                // Remove the leftmost character
                windowMap.put(c, windowMap.get(c) - 1);
                if (tMap.containsKey(c) && windowMap.get(c).intValue() < tMap.get(c).intValue()) {
                    formed--;
                }
                left++;
            }

            right++;
        }

        return ans[0] == -1 ? "" : s.substring(ans[1], ans[2] + 1);
    }

    public static void main(String[] args) {
        code solution = new code();

        String s1 = "ADOBECODEBANC";
        String t1 = "ABC";
        System.out.println(solution.minWindow(s1, t1)); // Output: "BANC"

        String s2 = "a";
        String t2 = "a";
        System.out.println(solution.minWindow(s2, t2)); // Output: "a"

        String s3 = "a";
        String t3 = "aa";
        System.out.println(solution.minWindow(s3, t3)); // Output: ""
    }
}
