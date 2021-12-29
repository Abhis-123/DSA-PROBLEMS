

def isPalindrome(str):
    # get size of the string
    length = len(str)
    # create a pointer the traverse the string elements
    idx = 0
    while idx<length//2:
        if str[idx] != str[length - idx-1]:
            return False
        idx += 1
    return True

# def longest_palindromic_substring(string):
#     # # get the size of the string
#     # length = len(string)
#     # # build a hash of the string characters and their indexes
#     # characters_index_hash = {}
#     # for i in range(length):
#     #     try:
#     #         characters_index_hash[string[i]].append(i)
#     #     except KeyError:
#     #         characters_index_hash[string[i]] = [i]

#     # iterate over all substrings which could be palindromic 



        

if __name__ == '__main__':
    list_of_numbers =[1,2,3,4,5,6]
    value = 7
    print(len(list_of_numbers))
    list_of_pairs = []
    for i in range(0,len(list_of_numbers)-1):
        for j in range (i+1,len(list_of_numbers)-1):
            total = list_of_numbers[i] +list_of_numbers[j]
            print(total)
            if total == value:
                list_of_pairs.append([list_of_numbers[i], list_of_numbers[j]])
    print(list_of_pairs)
    #print(isPalindrome("abba"))