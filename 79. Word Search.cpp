#include <iostream>
#include <memory>
#include <vector>

using namespace std;

/*
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

A B C E
S F C S
A D E E

DFS

if it is match word charater, mark word to '.', it don't need to check it again

if we search all direction and it didn't match the word, just backtracking, remove the mark
*/

class Solution {
public:
    bool search(vector<vector<char>>& board, string word, int x, int y, int index) {
        if(index == word.size())    //search finish, scan all word search
            return true;
        
        if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y] == '.')
            return false;
        
        if(board[x][y] != word[index])
            return false;
        
        char temp = board[x][y];
        board[x][y] = '.';
        
        if(search(board, word, x+1, y, index+1) || 
           search(board, word, x-1, y, index+1) || 
           search(board, word, x, y+1, index+1)  ||
           search(board, word, x, y-1, index+1))
               return true;
        
        board[x][y] = temp;
        return false;    
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int x=0;x<board.size();++x)
            for(int y=0;y<board[0].size();++y)
                if(search(board, word, x, y, 0))
                    return true;
        
        return false;
    }

};

int main() {
    unique_ptr<Solution> example = make_unique<Solution>();
    vector<vector<char>> inputData {{'A', 'B', 'C', 'E'},
                                    {'S', 'F', 'C', 'S'},
                                    {'A', 'D', 'E', 'E'}};
    
    
    cout << example->exist(inputData, "ABCCED");
    
}