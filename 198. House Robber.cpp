#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> rob;
        int length = nums.size();
        rob.resize(length);
        
        if (length == 0)
            return 0;
        if (length == 1)
            return nums[0];

        rob[0] = nums[0];
        rob[1] = max(nums[0], nums[1]);

        for (int i=2;i<length;++i)
            rob[i] = max(nums[i] + rob[i-2], rob[i-1]);
        
        return rob[length-1];    
    }
};

int main () {
    vector<int> res {2,7,9,3,1};
    shared_ptr<Solution> example = make_shared<Solution> ();
    
    std::cout << example->rob(res);
    
    return 0;
}