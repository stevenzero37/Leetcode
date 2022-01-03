#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=0, end = nums.size()-1;
        vector<int>ans;
        
        while(start<=end){
            if(nums[start]==target && nums[end]==target)
            {  
                ans.insert(ans.end(), {start, end});
                return ans;
            }
            else if(nums[start]!= target)
                start++;
            else{
                end--;
            }
            
        }
        
        ans.insert(ans.end(), {-1, -1});
        return ans;
    }
};

int main() {
    vector<int> data {5,7,7,8,8,10};
    int target = 8;
    vector<int> ans;
    unique_ptr<Solution> example = make_unique<Solution>();
    
    ans=example->searchRange(data, target);
    
    for(auto num:ans)
        cout << num << endl;
}