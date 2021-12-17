
def two_sum_brute_force(nums, target):
    n = len(nums)
    for i in range(n):  # O(n)
        for j in range(i+1,n): #O(n)
            if nums[j]+nums[i] == target:
                return [i, j]

def two_sum_sortings(nums,target):
    # create number and index pairs for number list
    nums_index = [(v, index) for index, v in enumerate(nums)] # o(n) -> space 
    # sort the list of num , index pairs 
    nums_index.sort() # o(nlog(n))

    # pointer to track the elements from left
    begin = 0
    # pointer to track the elements from right
    end = len(nums) - 1
    while begin < end: # o(n)
        # get sum of begin and end elements
        sum_of_nums = nums_index[begin][0] + nums_index[end][0]
        # return indexs if  sum mateches the target
        if sum_of_nums == target:
            return [nums_index[begin][1], nums_index[end][1]]
        # move the left point to the right by one step to increase the sum of numbers
        elif sum_of_nums < target:
            begin += 1
        # move the right point to the left by one step to decrease the sum of numbers
        else:
            end -= 1

def two_sum_hashing(nums, target):
    nums_hash ={}

    # create a hash table for each number
    for index,num in enumerate(nums):
        # try to find the number
        try:
        # append the index to the hash table
            nums_hash[num].append(index)
        # catch the KeyError and create a new key for number 
        except KeyError:
            nums_hash[num] = [index]
    for index,num in enumerate(nums):
        # get the complement of the number 
        complement = target - num
        # try to find the complement of the number in the hash table
        try:
            complement_indexes = nums_hash[complement]
            # once get the complement check the length of index list
            # to counter the case of repeating elements 
            if len(complement_indexes)>1:
                return complement_indexes[:2]
            else:
                return [index, complement_indexes[0]]
        except KeyError:
            pass



if __name__ == '__main__':
    nums = [2,7,11,15]
    target = 9
    print(f"two_sum_brute_force {two_sum_brute_force(nums, target)}")
    print(f"two sum sortings {two_sum_sortings(nums, target)}")
    print(f"two sum hashing {two_sum_hashing(nums, target)}")