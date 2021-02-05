# @param {Integer[]} prices
# @return {Integer}
# def max_profit(prices)
#     size = prices.length
#     s0 = Array(size)
#     s1 = Array(size)
#     s0[0] = -prices[0]
#     s1[0] = 0

#     prices.drop(1).each.with_index(1) do |_value, index|
#         s0[index] = [s0[index - 1], -prices[index]].max
#         s1[index] = [s1[index - 1], prices[index] + s0[index - 1]].max
#     end
#     s1[size - 1]
# end

def max_profit_reduce(prices)
    s0 = -prices[0]
    s1 = 0

    prices[1..-1].each {|price|
        s0 = [s0, -price].max
        s1 = [s1, price + s0].max
    }   
    s1
end

prices = [7, 1, 5, 3, 6, 4]
puts "%d" % [max_profit_reduce(prices)]