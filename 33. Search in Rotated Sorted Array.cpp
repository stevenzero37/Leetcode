#include <iostream>
#include <memory>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0, end=nums.size()-1, mid;
        
        while(start<=end) {
            mid = (start + end)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > nums[end]) {
                if(target >= nums[start] && target < nums[mid])
                    end = mid -1;
                else
                    start = mid + 1;
            } else {
                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        
        return -1;
    }
};

int main() {
    std::vector<int> data1 {4,5,6,7,8,0,1,2};
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();
   
    cout << example->search(data1, 2);

}