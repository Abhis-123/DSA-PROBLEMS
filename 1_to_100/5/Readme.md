# Problem : Median of Two Sorted Arrays
Given two sorted arrays, a[] and b[], the task is to find the median of these sorted arrays, in O(log n + log m) time complexity, when n is the number of elements in the first array, and m is the number of elements in the second array. 

# Example: 

    nums1=[-5, 3, 6, 12, 15],nums2= [-12, -10, -6, -3, 4, 10]
    median(nums1, nums2) returns 3
    he arrays we are merging are [1,2,3] and [2,5,6].The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.