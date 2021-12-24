class ListNode:
    def __init__(self,val=0,next = None):
        self.val = val
        self.next = next

def add_two_numbers(l1,l2):
    """
    l1 and l2 contain digits of two numbers in reversed order
    """
    # linked list of a new number from addition of l1 and l2
    result = ListNode()
    # temporary digits sum 
    temp_digits_sum = 0
    # final digit  to be used for digit of result
    final_digit=0
    # carry over the digits sum 
    carry = 0
    # current digit pointer
    current_digit = result 
    while l1 and l2:
        temp_digits_sum = l1.val + l2.val + carry
        # carry over the digits sum
        carry = temp_digits_sum//10
        # final digit to be used for digit of result
        if temp_digits_sum >10:
            final_digit = temp_digits_sum%10
        else:
            final_digit = temp_digits_sum
        current_digit.val  = final_digit
        current_digit.next = ListNode()
        current_digit      = current_digit.next
        if l1.next ==None and l2.next !=None:
            l1.next = ListNode(0)
        if l1.next!=None and l2.next ==None:
            l2.next = ListNode(0)
        print(f"{l1.val} + {l2.val} : {l1.next} + {l2.next}")
        l1 = l1.next
        l2 = l2.next
    return result

def create_liked_list_from_number(number):
    # number_str = f"{number}"
    # number_length = len(number_str)
    result = ListNode()
    temp_digit = result
    temp_digit.val = number%10
    while number//10 != 0:
        number = number//10
        temp_digit.next = ListNode(number%10)
        temp_digit = temp_digit.next
    temp_digit.val = number
    return result

def liked_list_to_string(linked_list):
    result =""
    while linked_list.next !=None:
        result =result + f"{linked_list.val}-->"
        linked_list = linked_list.next
    result= result + f"{linked_list.val}"
    return result
if __name__ == "__main__":
    num1 = 13291 
    num2 = 123
    l1 = create_liked_list_from_number(13291)
    l2 = create_liked_list_from_number(123)
    l3 = add_two_numbers(l1, l2)
    print(f"{liked_list_to_string(l1)} + {liked_list_to_string(l2)} = {liked_list_to_string(l3)}")
    print(f"{num1} + {num2} = {num1+num2}")
    




        


