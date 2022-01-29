#include <algorithm>

using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        // base condition
        if (n == 1 && k == 1) {
            return 0;
        }
        // length of the row
        int lengthOfRow = pow(2, n - 1);
        // calculate the mid
        int mid = lengthOfRow / 2;

        // if k belongs to the first half
        if (k <= mid) {
            return kthGrammar(n - 1, k);
        }
        // if k belongs to the second half
        else {
            return !(kthGrammar(n - 1, k - mid));
        }
    }
};

/*
    row 0:                                         0
                                /                                     \
    row 1:                     0                                       1
                    /                \                      /                 \
    row 2:           0                  1                    1                   0
                /       \          /        \           /       \           /       \
    row 3:      0         1        1          0         1         0         0         1
            /  \      /  \      /  \      /  \      /  \      /  \      /  \      /  \
    row 4:   0    1    1    0    1    0    0    1    1    0    0    1    0    1    1    0
    i    :   0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15
    bin i: 0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111


    Number of index in binary representation shows us the path we need to go. If we meet 0 in the path we go to the left, if it's 1 we go to the right.
    As an example we take number 13. The binary representation of number 13 is 1101. So we go from left of the binary.

    row 0:                                        0
                                /                                      \\
    row 1:                     0                                        1
                    /                  \                     /                 \\
    row 2:           0                    1                   1                   0
    i    :           0                    1                   2                   3
    bin i:          00                   01                  10                  11
                /       \          /        \           /       \           //      \
    row 3:      0         1        1          0         1         0         0         1
    i    :      0         1        2          3         4         5         6         7
    bin i:     000       001      010        011       100       101       110       111
            /  \      /  \      /  \      /  \      /  \      /  \      /  \\     /  \
    row 4:   0    1    1    0    1    0    0    1    1    0    0    1    0    1    1    0
    i    :   0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15
    bin i: 0000 0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111

    Here we see
    - if we meet 1 in the path it changes the value of the previous node where we were
    - if we meet 0 in the path nothing changes for the next node value.
*/