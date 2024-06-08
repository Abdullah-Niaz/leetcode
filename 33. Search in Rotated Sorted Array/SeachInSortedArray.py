def RotatedSearch(nums, target):
    l, h = 0, len(nums) - 1

    while l <= h:
        mid = (l + h) // 2
        
        if nums[mid] == target:
            return mid

        # Check if the left half is sorted
        if nums[l] <= nums[mid]:
            # If target is within the sorted left half
            if nums[l] <= target < nums[mid]:
                h = mid - 1
            else:
                l = mid + 1
        else:
            # If target is within the sorted right half
            if nums[mid] < target <= nums[h]:
                l = mid + 1
            else:
                h = mid - 1

    return -1







# If the left half is sorted:
    # If the target is greater than the element at mid or less than the element at l,
    # it means the target is not in the sorted left half, so we adjust the left pointer to search in the right half (l = mid + 1).
    # Otherwise, the target must be in the sorted left half, so we adjust the right pointer to narrow the search to the left half (r = mid - 1).      
