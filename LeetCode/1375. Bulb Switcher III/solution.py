import math

Array = [2,1,3,5,4]
def solution(A):
    # the states are initially 0
    state_arr = [0] * len(A)
    moment = 0
    
    # iterate through each bulb switch
    for index, bulb in enumerate(A):
        
        # update the state
        state_arr[bulb - 1] = 1
        
        # easy case when it is the 1st switch
        if bulb == 1:
            moment = moment + 1
        
        # if all bulbs up to this bulb are ON
        else:
            if all(state == 1 for state in state_arr[0: index+1]) and index != 0:
                moment = moment + 1
        
        # if all bulbs are ON, we have the answer
        if all(state == 1 for state in state_arr):
            return moment
    
    return 0
            
 
def solution_2(A):
    max_bulb = 0
    moment = 0
    
    for index, bulb in enumerate(A):
        # always check for max number of bulbs turned on
        max_bulb = max(max_bulb, bulb)
        
        # is number of bulbs the quantity of bulbs
        if max_bulb == index + 1:
            moment = moment + 1
         
    return moment
    
print(solution_2(Array))