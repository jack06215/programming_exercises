def maxProfit(prices:int) -> int:
    if len(prices) < 2:
        return 0
    
    size = len(prices)
    s0 = [0] * size
    s1 = [0] * size
    s2 = [0] * size
    s3 = [0] * size
    
    s0[0] = s2[0] = -prices[0]
    for i in range(1, size):
        s0[i] = max(s0[i - 1], -prices[i])
        s1[i] = max(s1[i - 1], s0[i - 1] + prices[i])
        
        s2[i] = max(s2[i - 1], s1[i - 1] - prices[i])
        s3[i] = max(s3[i - 1], s2[i - 1] + prices[i])
    
    return max(0, s3[size - 1])

seq = [1,2,3,4,5]
print(maxProfit(seq))