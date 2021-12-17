
def two_sum_brute_force(nums, target):
    n = len(nums)
    for i in range(n):  # O(n)
        for j in range(i+1,n): #O(n)
            if nums[j]+nums[i] == target:
                return [i, j]

def two_sum_sortings(nums,target):
    # two point
    nums_index = [(v, index) for index, v in enumerate(nums)] # o(n) -> space 
    nums_index.sort() # o(nlog(n))
    begin = 0
    end = len(nums) - 1
    while begin < end: # o(n)
        curr = nums_index[begin][0] + nums_index[end][0]
        if curr == target:
            return [nums_index[begin][0], nums_index[end][0]]
        elif curr < target:
            begin += 1
        else:
            end -= 1


if __name__ == '__main__':
    nums = [2,7,11,15]
    target = 9
    print(f"two_sum_brute_force {two_sum_brute_force(nums, target)}")
    print(f"two sum sortings {two_sum_sortings(nums, target)}")