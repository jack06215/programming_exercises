// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version) {
    return false;
}

class Solution {
public:
    int firstBadVersion(int n) {
        int head{0}, tail{n};
        while (head < tail) {
            int mid = head + (tail - head) / 2;
            if (isBadVersion(mid)) {
                tail = mid; 
            }
            else {
                head = mid + 1;
            }
        }
        return head;
    }
};