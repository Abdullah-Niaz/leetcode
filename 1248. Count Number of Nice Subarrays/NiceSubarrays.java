import java.util.HashMap;

public class NiceSubarrays {

    public static int numberOfSubarrays(int[] nums, int k) {
        HashMap<Integer, Integer> prefixCounts = new HashMap<>();
        prefixCounts.put(0, 1);  // Base case: There's one way to have 0 odd numbers before starting
        int oddCount = 0;
        int result = 0;

        for (int num : nums) {
            if (num % 2 == 1) {
                oddCount++;
            }

            if (prefixCounts.containsKey(oddCount - k)) {
                result += prefixCounts.get(oddCount - k);
            }

            prefixCounts.put(oddCount, prefixCounts.getOrDefault(oddCount, 0) + 1);
        }

        return result;
    }

    public static void main(String[] args) {
        int[] nums = {1, 1, 2, 1, 1};
        int k = 3;
        System.out.println(numberOfSubarrays(nums, k));  // Output: 2
    }
}
