class Solution {
public:

    void markIslandVisited(vector<vector<char>>& grid, int rowIdx, int colIdx)
    {
        if(rowIdx < 0 || colIdx < 0 || rowIdx >= grid.size() || colIdx >= grid[0].size() || grid[rowIdx][colIdx] == '0')
            return;

        grid[rowIdx][colIdx] = '0'; // mark visited

        markIslandVisited(grid, rowIdx+1, colIdx);
        markIslandVisited(grid, rowIdx-1, colIdx);
        markIslandVisited(grid, rowIdx, colIdx+1);
        markIslandVisited(grid, rowIdx, colIdx-1);
    }

    int numIslands(vector<vector<char>>& grid) 
    {
        if(grid.empty()) return 0;

        int islandsCount = 0;

        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == '1')
                {
                    islandsCount++;
                    markIslandVisited(grid, i, j);
                }
            }
        }

        return islandsCount;
    }
};
