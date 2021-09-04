def maxProfit(prices:list) -> int:
    if len(prices) < 2:
        return 0
    
    size = len(prices)
    s0 = [0] * size
    s1 = [0] * size
    
    s0[0] = -prices[0]
    for i in range(1, size):
        # If you are in the s0 on i day, 
        # you must transfer from the s1 state or in s0 state on i - 1 day.
        s0[i] = max(s0[i - 1], s1[i - 1] - prices[i])
        
        # If you are in the s1 on i day, 
        # you must transfer from the s0 state or in s1 state on i - 1 day.
        s1[i] = max(s1[i - 1], s0[i - 1] + prices[i])
    
    return max(0, s1[size - 1])

seq = [7,1,5,3,6,4]
print(maxProfit(seq))