#Question: Given an array with n+2 elements,
# all elements of the array are in range 1 to n and also all elements occur only once except 2 numbers which occur twice. 
#Find those 2 repeating numbers.

#Input: arr [ ] = {6, 2, 6, 5, 2, 3, 1}
#Output: 6 2
# I am using hashmap

nums = [6, 2, 6, 5, 2, 3, 1]
counter = {}
for i in range(len(nums)): # range object already producing numbers from 0 to n-1 , so there is no need to decrease the orignal n
  element =nums[i]
  if element in counter:
    counter[element] = counter[element]+1
    # keys with value greater than 1 
    # check if two keys have greater than 1 to break and dont have to traverse the array
    keys =[]
    for key,value in counter.items():
        if value > 1:
            keys.append(key)
    if len(keys) > 1:
        print(keys)
        # break if found two keys with value greater than 1
        break
  else:
    counter[element]= 1
print(counter)