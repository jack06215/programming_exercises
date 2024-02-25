#include "codec.h"
#include "prettyprint.h"

#include <string>
using namespace std;

#include <string>
using namespace std;

int solution(string& S) {
    int i = S.size() - 1;
    int res = 0;
    while (i > 0) {
        res++;

        // number is odd,
        // it needs to be subtracted by 1 before it can be divided by 2.
        if (S[i] == '1') {
            res++;
        }
        i--;
    }

    // If the MSB is '1', one final operation needed
    if (S[i] == '1') {
        res++;
    }
    return res;
}

// int solution(string& S) {
//     int count = 0;
//     for (char c : S) {
//         if (c == '1') {
//             count++;
//         }
//     }
//     return count + S.length() - 1;
// }


int main() {
    string S = "101";
    cout << solution(S) << endl;
}
