var maxProfit = function(prices) {
    let s0 = -prices[0];
    let s1 = 0;
    for (var i = 1; i < prices.length; i++) {
        s0 = Math.max(s0, -prices[i]);
        s1 = Math.max(s1, s0 + prices[i]);
    }
    return Math.max(0, s1);
};

console.log(maxProfit([7,1,5,3,6,4]));