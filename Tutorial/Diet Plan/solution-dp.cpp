#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class result {
public:
  int weight;
  vector<bool> eat_days;
};

class Solution {
public:
  Solution() {
    cin >> N >> W >> A >> B;
    C.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> C[i];
    }
  }
  result findMinimumWeight() {
    dp.resize(N + 1, vector<int>(N + 1, numeric_limits<int>::max()));
    parent.resize(N + 1, vector<int>(N + 1, -1));

    dp[0][0] = W;

    // Dynamic programming to find the minimum weight
    for (int day = 0; day < N; day++) {
      for (int stress = 0; stress <= day; stress++) {
        if (dp[day][stress] == numeric_limits<int>::max()) {
          continue;
        }

        // Option 1: Eat bread
        int newWeight = dp[day][stress] + C[day];
        if (newWeight < dp[day + 1][0]) {
          dp[day + 1][0] = newWeight;
          parent[day + 1][0] = stress;  // Came from stress level `stress` by eating
        }

        // Option 2: Do not eat bread
        newWeight = dp[day][stress] - A + B * (stress + 1);
        if (newWeight < dp[day + 1][stress + 1]) {
          dp[day + 1][stress + 1] = newWeight;
          parent[day + 1][stress + 1] = stress;  // Came from stress level `stress` by not eating
        }
      }
    }

    // Find minimum weight on the last day
    int minWeight = numeric_limits<int>::max();
    int bestStress = -1;
    for (int stress = 0; stress <= N; stress++) {
      if (dp[N][stress] < minWeight) {
        minWeight = dp[N][stress];
        bestStress = stress;
      }
    }

    // Reconstruct the path of decisions
    vector<bool> eat_days(N, false);
    int day = N;
    while (day > 0) {
      int stress = bestStress;
      int prevStress = parent[day][stress];
      eat_days[day - 1] = (prevStress == stress - 1);
      bestStress = prevStress;
      day--;
    }

    // Output the results
    cout << "Minimum weight is: " << minWeight << "kg.\n";
    for (int i = 0; i < N; i++) {
      string label;
      if (i == 0) {
        label = "st";
      }
      else if (i == 1) {
        label = "nd";
      }
      else if (i == 2) {
        label = "rd";
      }
      else {
        label = "th";
      }
      label += " day = ";
      cout << (i + 1) << label << (eat_days[i] ? "eat" : "not eat") << endl;
    }

    return { minWeight, eat_days };
  }
private:
  int N, W, A, B;
  vector<int> C;
  vector<vector<int>> dp;
  vector<vector<int>> parent;
};

int main() {
  auto solution = Solution();
  result result = solution.findMinimumWeight();
  return 0;
}
