pub struct Solution {}

impl Solution {
    pub fn max_profit(prices: Vec<i32>) -> i32 {
        let mut s0 = -prices[0];
        let mut s1 = 0;
        for i in 1..prices.len() {
            s0 = i32::max(s0, -prices[i]);
            s1 = i32::max(s1, s0 + prices[i]);
        }

        return i32::max(0, s1);
    }
}


fn main() {
    assert_eq!(Solution::max_profit(vec![7,1,5,3,6,4]), 5);
    assert_eq!(Solution::max_profit(vec![7,6,4,3,1]), 0);
    println!("All test cases are passed");
}