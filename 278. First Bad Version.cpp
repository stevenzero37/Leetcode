#include <iostream>

class Solution {
public:
    int firstBadVersion(int n) {
        long int start = 1, end = n, mid;
        
        while (start <= end) {
            mid = (start + end) / 2;

            if (isBadVersion(mid) == true && isBadVersion(mid - 1) == false)
                return mid;
            else if (isBadVersion(mid) == false)
                start = mid + 1;
            else if (isBadVersion(mid) == true)
                end = mid - 1;
        }
        
        return start;
    }
};

int main () {
    return 0;   
}