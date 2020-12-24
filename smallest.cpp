// you can use includes, for example:
#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>
#include <map>


using namespace std;

// int solution(vector<int> &A) {
//     std::unordered_set<int> lookup_table;
//     for (auto val: A){
//         lookup_table.insert(val);
//     }
//     auto max_val = *max_element(A.begin(), A.end());
//     for (int i = 1; i <= max_val + 1; i++){
//         if (lookup_table.find(i) == lookup_table.end()){
//             return i;
//         }

//     }
// }

// int solution(vector<int> &A) {
//     // set all states to FALSE
//     std::vector<int> state_arr(A.size(), 0);
    
//     // moment is 0 initially
//     int moment = 0;
    
//     for (int i = 0; i < A.size(); i++){
//         // a bulb is switch on, so we toggle the state
//         int bulb = A[i];
//         state_arr[bulb - 1] = 1;

//         // increase the moment counter
//         if (bulb == 1){
//             moment++;
//         }


//         else{
//             // int cond1 = std::find(state_arr.begin(), state_arr.begin() + i, true) == state_arr.begin() + i;
//             int cond2 = (i !=0);
//             if ((std::find(state_arr.begin(), state_arr.begin() + i, true) == state_arr.begin() + i) & cond2){
//                 moment++;
//             }
//         }
//         if (std::accumulate(state_arr.begin(), state_arr.end(), 0) == state_arr.size()){
//             return moment;
//         }
//     }
//     return -1;
// }

int solution(vector<int> &A) {
    int N = A.size();
    int result = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (A[i] == A[j])
                result = max(result, abs(i - j));
    return result;
}

int countDivisibleSubseq(string str, int n) 
{ 
    int len = str.length(); 
  
    // division by n can leave only n remainder 
    // [0..n-1]. dp[i][j] indicates number of 
    // subsequences in string [0..i] which leaves 
    // remainder j after division by n. 
    int dp[len][n]; 
    memset(dp, 0, sizeof(dp)); 
  
    // Filling value for first digit in str 
    dp[0][(str[0]-'0')%n]++; 
  
    for (int i=1; i<len; i++) 
    { 
        // start a new subsequence with index i 
        dp[i][(str[i]-'0')%n]++; 
  
        for (int j=0; j<n; j++) 
        { 
            // exclude i'th character from all the 
            // current subsequences of string [0...i-1] 
            dp[i][j] += dp[i-1][j]; 
  
            // include i'th character in all the current 
            // subsequences of string [0...i-1] 
            dp[i][(j*10 + (str[i]-'0'))%n] += dp[i-1][j]; 
        } 
    } 
  
    return dp[len-1][0]; 
} 




int main(){
    std::vector<int> list{4,6,2,2,6,6,1};

    std::cout << solution(list) << std::endl;
    return 0;
}