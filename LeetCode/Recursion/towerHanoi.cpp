#include <iostream>

using namespace std;

void towerOfHanoi(int n, char src, char aux, char dst) {
    if (n == 1) {
        cout << "Move disk 1 from rod " << src << " to rod " << aux << endl;
        return;
    }
    towerOfHanoi(n - 1, src, dst, aux);
    cout << "Move disk " << n << " from rod " << src << " to rod " << aux << endl;
    towerOfHanoi(n - 1, dst, aux, src);
}

int main() {
    int n = 5;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
