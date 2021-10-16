#include <iostream>
#include <memory>
#include <vector>

class Solution {
public:
    void printMatrix(std::vector<std::vector<int>> &dp) {
        for (int i=0;i<dp.size();++i) {
            for (int j=0;j<dp[i].size();++j)
                std::cout << dp[i][j] << " ";
            std::cout << std::endl;
        }      
    
    }

    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> dp(m, std::vector<int>(n,1));

        for (int i=1;i<dp.size();++i)
            for (int j=1;j<dp[m-1].size();++j) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            
        return dp[m-1][n-1];
    }
};

int main() {
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();
    
    std::cout << example->uniquePaths(3, 7);
}