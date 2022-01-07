# Problem : Median of Two Sorted Arrays
Given two sorted arrays, a[] and b[], the task is to find the median of these sorted arrays, in O(log n + log m) time complexity, when n is the number of elements in the first array, and m is the number of elements in the second array. 

# Example: 

    nums1=[-5, 3, 6, 12, 15],nums2= [-12, -10, -6, -3, 4, 10]
    median(nums1, nums2) returns 3
    explanation The merged array is :
        nums3 = {-12, -10, -6, -5 , -3,
                 3, 4, 6, 10, 12, 15},
       So the median of the merged array is 3