import java.util.ArrayList;
import java.util.List;

public class SummaryRanges {

    // Function to return the summary of ranges
    public static List<String> summaryRanges(int[] nums) {
        List<String> result = new ArrayList<>();
        int n = nums.length;

        if (n == 0) return result;

        // Start the first range
        int start = nums[0];

        for (int i = 1; i < n; i++) {
            // If current number is not consecutive to the previous one
            if (nums[i] != nums[i - 1] + 1) {
                // Add the range to the result
                if (start == nums[i - 1]) {
                    result.add(String.valueOf(start));
                } else {
                    result.add(start + "->" + nums[i - 1]);
                }
                // Start a new range
                start = nums[i];
            }
        }

        // Add the last range after the loop
        if (start == nums[n - 1]) {
            result.add(String.valueOf(start));
        } else {
            result.add(start + "->" + nums[n - 1]);
        }

        return result;
    }

    // Main function to test the implementation
    public static void main(String[] args) {
        // Example 1
        int[] nums1 = {0, 1, 2, 4, 5, 7};
        System.out.println("Input: [0, 1, 2, 4, 5, 7]");
        System.out.println("Output: " + summaryRanges(nums1));

        // Example 2
        int[] nums2 = {0, 2, 3, 4, 6, 8, 9};
        System.out.println("Input: [0, 2, 3, 4, 6, 8, 9]");
        System.out.println("Output: " + summaryRanges(nums2));
    }
}
