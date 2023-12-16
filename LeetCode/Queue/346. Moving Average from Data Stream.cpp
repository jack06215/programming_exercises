#include <queue>

using namespace std;

class MovingAverage {
private:
    queue<int> stream;
    const int size;
    double sum;

public:
    MovingAverage(int size) : size(size), sum(0) {}

    double next(int val) {
        if (stream.size() == size) {
            sum -= stream.front(); // Remove the oldest element from the sum
            stream.pop(); // Pop the oldest element
        }

        stream.push(val); // Add the new element
        sum += val; // Add the new element to the sum

        return sum / stream.size(); // Calculate the average
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */
