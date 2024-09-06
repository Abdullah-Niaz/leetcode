
import java.util.HashSet;

public class Solution {
    public ListNode modifiedList(int[] nums, ListNode head) {
        // Create a HashSet and add elements from the array
        HashSet<Integer> set = new HashSet<>();
        for (int num : nums) {
            set.add(num); // Add each element from nums array to the HashSet
        }

        // Remove nodes from the start of the list that match the set values
        while (head != null && set.contains(head.val)) {
            head = head.next;
        }

        // Traverse through the remaining list and remove matching nodes
        ListNode curr = head;
        while (curr != null && curr.next != null) {
            if (set.contains(curr.next.val)) {
                curr.next = curr.next.next; // Remove node by skipping it
            } else {
                curr = curr.next;
            }
        }

        return head;
    }
}
