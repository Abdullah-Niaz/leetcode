def numberOfSubarrays(nums, k):
    prefix_counts = {0: 1}  # Prefix sum dictionary
    odd_count = 0
    result = 0
    
    for num in nums:
        if num % 2 == 1:
            odd_count += 1
        
        # If there is a prefix with sum odd_count - k, add its count to the result
        if odd_count - k in prefix_counts:
            result += prefix_counts[odd_count - k]
        
        # Update the prefix sum count
        if odd_count in prefix_counts:
            prefix_counts[odd_count] += 1
        else:
            prefix_counts[odd_count] = 1
    
    return result
