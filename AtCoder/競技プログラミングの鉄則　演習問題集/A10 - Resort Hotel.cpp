#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    int N;
    int D;
    vector<int> A;
    vector<int> L;
    vector<int> R;
public:
    Solution() {
        cin >> N;
        A.resize(N + 1);  // Adjusting the size for 1-based indexing
        for (int i = 1; i <= N; i++) {
            cin >> A[i];
        }

        cin >> D;
        L.resize(D);
        R.resize(D);
        for (int i = 0; i < D; i++) {
            cin >> L[i] >> R[i];
        }
    }

    void solve() {
        vector<int> prefixMax(N + 1, 0);
        vector<int> suffixMax(N + 1, 0);

        /**
         * @brief Prefix Maximum Array
           The prefix maximum array stores the maximum capacity from the start of the array up to i position.
           It essentially answers the question, "Up to this room, what is the largest capacity we have seen?"

           For our example, the prefix maximum array would be:

            Rooms:        1   2   3   4   5   6   7
            Prefix Max:   1   2   5   5   5   5   5

           Explanation:
            Up to room 1, the largest capacity is 1 (only room 1 considered).
            Up to room 2, the largest capacity is 2 (considering rooms 1 and 2).
            Up to room 3, the largest capacity is 5 (considering rooms 1, 2, and 3), and so on.
         *
         */
        prefixMax[1] = A[1];
        for (int i = 2; i <= N; ++i) {
            prefixMax[i] = max(prefixMax[i - 1], A[i]);
        }

        /**
         * @brief Suffix Maximum Array
            The suffix maximum array stores the maximum capacity from each position to the end of the array.
            It answers the question, "From this room to the end, what is the largest capacity available?"

            For our example, the suffix maximum array would be:
                Rooms:        1   2   3   4   5   6   7
                Suffix Max:   5   5   5   5   3   3   1
            
            Explanation:
                From room 7 to the end (just room 7), the largest capacity is 1.
                From room 6 to the end (rooms 6 and 7), the largest capacity is 3.
                From room 5 to the end (rooms 5, 6, and 7), the largest capacity is 3, and so on.

         * 
         */
        suffixMax[N] = A[N];
        for (int i = N - 1; i >= 1; --i) {
            suffixMax[i] = max(suffixMax[i + 1], A[i]);
        }

        /**
         * @brief Query Processing
         * 
         * Let's use the same room capacity example as before:
         * 
         *  Rooms:        1   2   3   4   5   6   7
            Capacities:   1   2   5   5   2   3   1
            Prefix Max:   1   2   5   5   5   5   5
            Suffix Max:   5   5   5   5   3   3   1

            Query Range:   3 - 5 (Under Construction)
            Available:     1, 2, 6, 7

            Before Construction:
            Max in 1 - 2:  2  (from Prefix Max)

            After Construction:
            Max in 6 - 7:  3  (from Suffix Max)

            Result: Max of (2, 3) = 3
         * 
         */
        for (int i = 0; i < D; i++) {
            int left = L[i];
            int right = R[i];

            // Find max capacity outside construction range
            int maxCapacity = 0;
            if (left > 1) {
                maxCapacity = max(maxCapacity, prefixMax[left - 1]);
            }
            if (right < N) {
                maxCapacity = max(maxCapacity, suffixMax[right + 1]);
            }

            cout << maxCapacity << endl;
        }
    }
};

int main() {
    auto solution = Solution();
    solution.solve();
    return 0;
}
