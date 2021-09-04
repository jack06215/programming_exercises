#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

// int rodCut_resursive(const std::vector<int>& prices, int n_piece);
// int rodCut_dp(const std::vector<int>& prices, int n_piece);

// int main()
// {
//     const std::vector<int> arr{1, 5, 8, 9, 10, 17, 17, 20};
//     std::cout << rodCut_dp(arr, arr.size());

//     return 0;
// }

int rodCut_resursive(const std::vector<int>& prices, int n_piece)
{
    if (n_piece <= 0)
        return 0;
    
    int result = std::numeric_limits<int>::min();
    for (int i = 0; i < n_piece; i++)
        result = std::max(result, prices[i] + rodCut_resursive(prices, n_piece - i - 1));
    
    return result;
}

int rodCut_dp(const std::vector<int>& prices, int n_piece)
{
    if (n_piece <= 0)
        return 0;
    
    std::vector<int> result(n_piece + 1);
    result[0] = 0;
    for (int i = 1; i <= n_piece; i++)
    {
        int max_price = std::numeric_limits<int>::min();
        for (int j = 0; j < i; j++)
            max_price = std::max(max_price, prices[j] + result[i - j - 1]);

        result[i] = max_price;
    }

    return result[n_piece];
}