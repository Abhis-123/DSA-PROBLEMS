

def merge_two_sorted_arrays(num_list1,n1,num_list2,n2):
    # num_list1 is the first array contianing sorted 
    # array and extra zeros for the elements of second array
    # n1 is the number of elements first array
    # n2 is the number of elements second array

    # special case for one of two arrays having no elements
    if n1 == 0:
        return num_list2
    if n2 == 0:
        return num_list1

    # for this problem we can start filling the first array from end 
    # the size of num_list1 is n1+n2
    while n1>0 and n2>0:
        # get the max elements of two 
        if num_list1[n1-1]> num_list2[n2-1]:
            num_list1[n1+n2-1]=num_list1[n1-1]
            n1 = n1 -1 
        else: 
            num_list1[n1+n2-1] = num_list2[n2-1]
            n2 = n2 -1
    if n2 != 0:
        num_list1[n1+n2-1] = num_list2[n2-1]
    return num_list1

if __name__ == "__main__":
    print(merge_two_sorted_arrays([1,2,3,0,0,0],3,[2,5,6],3))






