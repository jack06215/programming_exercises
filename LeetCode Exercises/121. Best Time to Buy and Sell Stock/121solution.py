'''
We have 2 options in every element:
Have no stock (s0)
    -> We can buy it
    -> We can do nothing.
Have stock: (s1)
    -> We can sell it.
    -> We can do nothing.
'''
def maxProfit(prices: list) -> int:
    if len(prices) < 2:
        return 0
    
    size = len(prices)
    s0 = [0] * size
    s1 = [0] * size
    
    # initially buy on the first day
    s0[0] = -prices[0]
    for i in range(1, size):
        # If you are in the s0 on i day, 
        # you must transfer from current price on i day or in s0 stat on i - 1 day.
        s0[i] = max(s0[i - 1], -prices[i])
        
        # If you are in the s1 on i day, 
        # you must transfer from the s0 state or in s1 state on i - 1 day.
        s1[i] = max(s1[i - 1], s0[i - 1] + prices[i])

    return max(0, s1[size - 1])

sequence = [7,1,5,3,6,4]
print(maxProfit(sequence))
