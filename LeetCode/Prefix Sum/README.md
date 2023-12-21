
# 53. Maximum Subarray
1. **Initialization**:

    - `maxSum = INT_MIN` (Initially, set to the smallest possible integer)
    - `minPrefixSum = 0`
    - `prefixSum = 0`
2. **Iterate through the array**:

    | Index | arr\[i\] | prefixSum (Cumulative) | minPrefixSum | maxSum Calculation | maxSum |
    | --- | --- | --- | --- | --- | --- |
    | 0 | \-2 | \-2 | 0 | max(INT\_MIN, -2 - 0) = -2 | \-2 |
    | 1 | 1 | \-1 | \-2 | max(-2, -1 - (-2)) = 1 | 1 |
    | 2 | \-3 | \-4 | \-2 | max(1, -4 - (-2)) = 1 | 1 |
    | 3 | 4 | 0 | \-4 | max(1, 0 - (-4)) = 4 | 4 |
    | 4 | \-1 | \-1 | \-4 | max(4, -1 - (-4)) = 4 | 4 |
    | 5 | 2 | 1 | \-4 | max(4, 1 - (-4)) = 5 | 5 |
    | 6 | 1 | 2 | \-4 | max(5, 2 - (-4)) = 6 | 6 |
    | 7 | \-5 | \-3 | \-4 | max(6, -3 - (-4)) = 6 | 6 |
    | 8 | 4 | 1 | \-4 | max(6, 1 - (-4)) = 6 | 6 |

3. **Result**:

    - The maximum sum is `6`, which is the sum of the subarray `[4, -1, 2, 1]`.

In this example, `prefixSum` is the cumulative sum at each index, `minPrefixSum` is the smallest prefix sum seen up to the current point, and `maxSum` is updated to reflect the maximum subarray sum found so far. The algorithm correctly identifies `[4, -1, 2, 1]` as the subarray with the largest sum, which is `6`.
