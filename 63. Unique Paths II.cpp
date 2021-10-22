#include <iostream>
#include <memory>
#include <vector>

class Solution {
public:
    void printMatrix(std::vector<std::vector<int>> &dp) {
        for (int i=0;i<dp.size();++i) {
            for (int j=0;j<dp[dp.size()-1].size();++j)
                std::cout << dp[i][j] << " ";
            std::cout << std::endl;
        }      
    
    }

    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[obstacleGrid.size()-1].size();
        
        std::vector<std::vector<int>> dp(m, std::vector<int>(n));

        if (obstacleGrid[0][0] == 1)
            return 0;
        else
            dp[0][0] = 1;
        
        for (int i=0;i<m;++i)
            for (int j=0;j<n;++j) {
                if (obstacleGrid[i][j] != 1) {
                    if(i-1 >= 0)
                        dp[i][j] += dp[i-1][j];
                    if(j-1 >= 0)
                        dp[i][j] += dp[i][j-1];
                }
            }
        return dp[m-1][n-1];
    }
};

int main() {
    std::unique_ptr<Solution> example = std::make_unique<Solution> ();
    
    std::vector<std::vector<int>> dp = {
        {0,1,0},
        {0,1,0},
        {0,0,0},
    };
    std::cout << example->uniquePathsWithObstacles(dp);
}