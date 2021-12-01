#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        if (nums.size() == 0)
            return {};
        
        if (nums.size() == 1 && nums[0] == 0)
            return {};
        
        sort(nums.begin(), nums.end()); 
        vector<vector<int>> ans;
        
        for (int i=0;i<nums.size();++i) {
            int low = i+1; int high = nums.size() - 1;
            int sum = 0;
            
            if (i>0 && nums[i] == nums[i-1])
                continue;
            
            while (low < high) {
                sum = nums[i] + nums[low] + nums[high];
                if (sum < 0) 
                    low++;
                else if (sum > 0) 
                    high--;
                else if (sum == 0) {
                    ans.push_back({nums[i], nums[low], nums[high]});
                    int different_low = low; int different_high = high;
                    while (low < high && nums[different_low] == nums[low])
                        low++;
                    while (low < high && nums[different_high] == nums[high])
                        high--;

                    for (int i=0;i<ans.size();++i) {
                        for (int j=0;j<ans[i].size();++j) {
                            cout << ans[i][j] << " ";
                        }
                        cout << endl;
                    }
                }
            }
        }
            
        return ans;
    }
};

//-1,0,1,2,-1,-4
//-2, 0, 0, 2, 2

int main () {
    vector<int> inputData {-2,0,0,2,2}; //{-2,-1,-1,1,2,3}
    unique_ptr<Solution> example = make_unique<Solution>();
    vector<vector<int>> ans;
    
    ans = example->threeSum (inputData);
    
    return 0;
}