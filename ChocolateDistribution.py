def findMinDifference(chocolates, m):
    # Sort the array
    chocolates.sort()

    # Initialize variables
    n = len(chocolates)
    min_diff = float('inf')

    # Traverse through the array
    for i in range(n - m + 1):
        # Find the difference between the maximum and minimum chocolates in the window
        diff = chocolates[i + m - 1] - chocolates[i]
        # Update the minimum difference if a smaller difference is found
        if diff < min_diff:
            min_diff = diff

    return min_diff

# Example usage
chocolates = [71, 13, 21, 41, 91, 2, 56]
m = 3  # Number of students
print("Minimum difference is:", findMinDifference(chocolates, m))
