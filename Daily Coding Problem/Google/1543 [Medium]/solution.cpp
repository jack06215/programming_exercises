#include <iostream>
#include <random>
#include <cmath>

using namespace std;

double estimatePi(int iterations) {
  int pointsInsideCircle = 0;
  double x, y;

  // Random number engine
  random_device rd;
  mt19937 gen(rd());

  // Uniform distribution in range [-1, 1]
  uniform_real_distribution<> dis(-1.0, 1.0);

  for (int i = 0; i < iterations; ++i) {
    x = dis(gen);
    y = dis(gen);

    if (x * x + y * y <= 1) {
      ++pointsInsideCircle;
    }
  }

  return 4.0 * pointsInsideCircle / iterations;
}

int main() {
  int iterations = 1000000; // Higher number for better accuracy
  double piEstimate = estimatePi(iterations);
  cout.precision(4);
  cout << "Estimated value of Pi: " << fixed << piEstimate << endl;

  return 0;
}
