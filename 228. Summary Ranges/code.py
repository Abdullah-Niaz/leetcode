# Function to return the summary of ranges
def summaryRanges(nums):
    result = []
    n = len(nums)

    # Return empty list if no elements
    if n == 0:
        return result

    # Start the first range
    start = nums[0]

    for i in range(1, n):
        # If the current number is not consecutive to the previous one
        if nums[i] != nums[i - 1] + 1:
            # Add the range to the result
            if start == nums[i - 1]:
                result.append(f"{start}")
            else:
                result.append(f"{start}->{nums[i - 1]}")
            # Start a new range
            start = nums[i]

    # Add the last range after the loop
    if start == nums[-1]:
        result.append(f"{start}")
    else:
        result.append(f"{start}->{nums[-1]}")

    return result


# Test cases
if __name__ == "__main__":
    # Example 1
    nums1 = [0, 1, 2, 4, 5, 7]
    print(f"Input: {nums1}")
    print(f"Output: {summaryRanges(nums1)}")

    # Example 2
    nums2 = [0, 2, 3, 4, 6, 8, 9]
    print(f"Input: {nums2}")
    print(f"Output: {summaryRanges(nums2)}")

    # Example 3: Empty input
    nums3 = []
    print(f"Input: {nums3}")
    print(f"Output: {summaryRanges(nums3)}")

    # Example 4: Single element
    nums4 = [1]
    print(f"Input: {nums4}")
    print(f"Output: {summaryRanges(nums4)}")

    # Example 5: All elements are consecutive
    nums5 = [1, 2, 3, 4, 5]
    print(f"Input: {nums5}")
    print(f"Output: {summaryRanges(nums5)}")
