# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def modifiedList(self, nums: List[int], head: Optional[ListNode]) -> Optional[ListNode]:
        nums_set = set(nums)
        
        # Remove nodes from the start of the list that match the set values
        while head and head.val in nums_set:
            head = head.next

        # Traverse through the remaining list and remove matching nodes
        curr = head
        while curr and curr.next:
            if curr.next.val in nums_set:
                curr.next = curr.next.next  # Remove node by skipping it
            else:
                curr = curr.next
        
        return head
        