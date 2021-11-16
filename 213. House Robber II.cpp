#include <iostream>
#include <vector>
#include <memory>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        int length = nums.size();
        std::vector<int> rob;
        rob.resize(length);
        
        if (length == 0)
            return 0;
        if (length == 1)
            return nums[0];
        
        //rob the second house instead of the firt house
        //can rob the last house 
        int temp, prev = 0, current = nums[1];
        for (int i = 2; i<length; ++i) {
            temp = prev; prev = current;
            current = std::max (nums[i] + temp, prev);
        }
        
        int result1 = current;
        
        //rob the first house, so we cannot rob the last house
        prev = nums[0], current = nums[0];
        for (int i = 2; i<length-1; ++i) {
            temp = prev; prev = current;
            current = std::max (nums[i] + temp, prev); 
        }
        
        int result2 = current;
        
        return std::max(result1, result2); 
    }
};

int main () {
    std::vector<int> data {2,3,2};
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();
    
    std::cout << example->rob(data);
}