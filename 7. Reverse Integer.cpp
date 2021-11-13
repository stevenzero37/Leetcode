#include <iostream>
#include <stdlib.h>
#include <limits.h>
#include <memory>

class Solution {
public:
    int reverse(int x) {
        int sign = 0, ans = 0, temp = 0;
        
        //store the positive/negative
        if (x > 0)
            sign = 1;
        else
            sign = -1;
        
        x = abs(x);
        
        while (x > 0) {
            
			//compare the overflow without unique dight
            if (ans > INT_MAX / 10)
                return 0;

            //get the last dight
            temp = x % 10;
            
            ans = ans * 10 + temp;
            
            //change carry
            x = x / 10;
        }
        
        return ans*sign;
    }
};

int main () {
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();

    std::cout<<example->reverse(-21474834125232);
    
    return 0;
}