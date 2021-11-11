#include <iostream>

using namespace std;

class TowerOfHanoi {
public:
    void print_step(int n, char from_rod, char to_rod, char spare_rod) {
        if (n == 1) {
            cout << "Move disk 1 from rod " << from_rod << " to rod " << to_rod << endl;
            return;
        }
        print_step(n - 1, from_rod, spare_rod, to_rod);
        cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
        print_step(n - 1, spare_rod, to_rod, from_rod);
    }
    int total_steps(int n) {
        if (n == 0) return 0;
        return 2*total_steps(n - 1) + 1;
    }
};

int main(int argc, char const *argv[]) {
    TowerOfHanoi toh;
    int n = 3;
    toh.print_step(n, 'A', 'B', 'C');
    cout << toh.total_steps(n) << endl;
    return 0;
}
 
