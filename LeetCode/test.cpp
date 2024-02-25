#include <iostream>
#include <string>

using namespace std;

string solution(int N) {
    string ans = "";
    if (N % 2 == 0) {
        for (int i = 0; i < N - 1; i++) {
            ans = ans + 'a';
        }
        ans = ans + 'b';
    }
    else {
        for (int i = 0; i < N; i++) {
            ans = ans + 'b';
        }
    }
    return ans;

}

int main() {
    std::cout << "Example 1 (N=4): " << solution(4) << std::endl;
    std::cout << "Example 2 (N=7): " << solution(7) << std::endl;
    std::cout << "Example 3 (N=1): " << solution(1) << std::endl;

    return 0;
}
