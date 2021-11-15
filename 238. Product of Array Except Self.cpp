#include <iostream>
#include <memory>
#include <vector>

class Solution {
private:
    std::vector<int> ans;
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        int size = nums.size();
        ans.resize(size);
        std::vector<int>toLeft (size, 1);
        std::vector<int>toRight (size, 1);
        
        //product nums from left to right except for own nums
        for(int i=0; i<size-1; ++i)
            toLeft[i+1] = toLeft[i] * nums[i];
        
        //product nums from right to left except for own nums
        for(int i=size-1;i>0;i--)
            toRight[i-1] = toRight[i] * nums [i];
            
       //product together
        for(int i=0;i<size;++i)
            ans[i] = toLeft[i] * toRight[i];

        return ans;
    }
};

int main () {
    std::unique_ptr<Solution> example = std::make_unique<Solution>();
    
    std::vector<int> inputData {4,5,1,8,2};
    std::vector<int> ans;
    
    ans = example->productExceptSelf(inputData);
    
    return 0;
}