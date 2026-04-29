class Solution {
public:
    void getIslandArea(vector<vector<int>>& grid, int rowIdx, int colIdx, int& islandArea)
    {
        if(rowIdx < 0 || rowIdx >= grid.size() || colIdx < 0  || colIdx >= grid[0].size() || grid[rowIdx][colIdx] == 0)
            return;
        
        islandArea++;
        grid[rowIdx][colIdx] = 0;

        getIslandArea(grid, rowIdx-1, colIdx, islandArea);
        getIslandArea(grid, rowIdx+1, colIdx, islandArea);
        getIslandArea(grid, rowIdx, colIdx+1, islandArea);
        getIslandArea(grid, rowIdx, colIdx-1, islandArea);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) 
    {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++)
        {
            for(int j = 0; j < grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    int islandArea = 0;
                    getIslandArea(grid, i, j, islandArea);
                    maxArea = max(maxArea, islandArea);
                }
            }
        }  

        return maxArea;      
    }
};
