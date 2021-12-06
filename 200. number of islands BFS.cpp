#include <iostream>
#include <memory>
#include <vector>
#include <queue>

class Solution {
public:
    void bfs(std::vector<std::vector<char>>& grid, int i, int j) {
        //BFS, check four direction
        std::vector<std::pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        //If it is the land, add it into the queue for next BFS
        std::queue<std::pair <int, int>> landList;
        std::pair<int, int> land;
        
        landList.push({i, j});
        grid[i][j] = '2';
        
        while (!landList.empty()) {
            land = landList.front(); landList.pop(); 
            for (auto dir: directions) {
                
                int newX = land.first + dir.first;
                int newY = land.second + dir.second;
                
                if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[newX].size()) {
                    //if it is the land, push into queue for the further invesigation
                    if (grid[newX][newY] == '1') {
                        grid[newX][newY] = '2';
                        landList.push({newX, newY});
                    }
                }
            }  
        }
    }

    int numIslands(std::vector<std::vector<char>>& grid) {
        int counter = 0;
        
        if (grid.empty())
            return counter;
        
        for(int i=0;i<grid.size();++i) {
            for(int j=0;j<grid[i].size();++j) {
                if (grid[i][j] == '1') {
                    counter++;
                    bfs(grid, i, j);
                }
            }
        }
        
        return counter;
    }
};

int main() {
    std::vector<std::vector<char>> grid = {{'1','1','1','1','0'},
                                           {'1','1','1','1','0'},
                                           {'1','1','1','1','0'},
                                           {'1','1','1','1','0'}};
    
    std::unique_ptr<Solution> example = std::make_unique<Solution>();
    
    std::cout<< example->numIslands(grid);
    
    return 0;
}