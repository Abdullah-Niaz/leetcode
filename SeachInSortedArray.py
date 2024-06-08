def RotatedSearch(nums,target):
    l= 0
    h = len(nums) - 1

 
    while(l <= h ):
        mid = (l + h ) // 2
        if(nums[mid] == target ):
            return mid
        # Check if the left half is Sorted or not
        if(nums[l] <= nums[mid]):
           # if sorted it will enter
           if target > nums[mid]:
               l = mid + 1
           elif(targt < nums[l]):
               l = mid + 1

            # adjust the right prointer the left half to narrow down the search 
           else:
               r = mid - 1

        # Target in the Right half 
        else:
                if target < nums[mid] or target > nums[r]:
                    r = mid - 1
                else:
                    l = mid + 1
    return -1







# If the left half is sorted:
    # If the target is greater than the element at mid or less than the element at l,
    # it means the target is not in the sorted left half, so we adjust the left pointer to search in the right half (l = mid + 1).
    # Otherwise, the target must be in the sorted left half, so we adjust the right pointer to narrow the search to the left half (r = mid - 1).      
