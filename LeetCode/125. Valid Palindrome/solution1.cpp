#include <string>

using namespace std;

class Solution1 {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        while(left < right) {
            if(!isalnum(s[left])) {
                left++;
            }
            else if(!isalnum(s[right])) {
                right--;
            }
            else if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            else {
                left++; 
                right--;
            }
        }
        return true;
    }
};

class Solution2 {
public:
	bool isPalindrome(string s) {
		int left = 0;
		int right = s.size() - 1;
		while(left < right) {
			while(left < right && !isalnum(s[left])) {
				left++;
			}
			while(left < right && !isalnum(s[right])) {
				right--;
			}
			if(tolower(s[left]) != tolower(s[right])) {
				return false;
			}
			left++;
			right--;
		}
		return true;
	}
};
