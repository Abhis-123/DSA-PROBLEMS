# Problem : Move all negative numbers to beginning and positive to end with constant extra space

Note: You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.

# Example:

    vars, nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    merge_two_sorted_arrays(nums1,m,nums2,n) returns [1,2,2,3,5,6]
    Explanation: The arrays we are merging are [1,2,3] and [2,5,6].
    The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.