#include <iostream>
#include <vector>
#include <memory>

class Solution {
public:
    void dfs (std::vector<std::vector<char>>& grid, int i, int j) {
        
        if (i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j] != '1')
            return;

        grid[i][j] = '2';
        dfs(grid, i, j+1);
        dfs(grid, i+1, j);
        dfs(grid, i-1, j);
        dfs(grid, i, j-1);
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        int counter = 0;
        for (int i=0;i<grid.size();++i) {
            for (int j=0;j<grid[i].size();++j) {
                std::cout << "i=" << i << ", " << "j=" << j << std::endl;
                if (grid[i][j] == '1') {
                    counter++;
                    dfs(grid, i, j);
                }
            }
        }
        
        return counter;
    }
};

int main() {
    std::unique_ptr<Solution> example = std::make_unique<Solution>();
    
    std::vector<std::vector<char>> grid = {{'1','1','0','0','0'},
                                           {'1','1','0','0','0'},
                                           {'0','0','1','0','0'},
                                           {'0','0','0','1','1'}};

    std::cout << example->numIslands(grid);
}