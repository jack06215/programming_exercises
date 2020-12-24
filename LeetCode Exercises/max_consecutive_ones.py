import math

def num_digits(num:int):
    return math.floor(math.log10(num) + 1)

def findNumbers(nums) -> int:
    result = 0
    for val in nums:
       if((num_digits(val)%2)==0):
           result = result + 1
    return result

my_list = [12,345,2,6,7896]
print(findNumbers(my_list))