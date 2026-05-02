class Solution {
public:

    std::vector<std::pair<int, int>> directions = { { 1,  0}, // down
                                                    {-1,  0}, // up
                                                    { 0,  1}, // right
                                                    { 0, -1}  // left
                                                  };

    bool findTheWord(vector<vector<char>>& board, int r, int c, int currIndex, string word)
    {
        // If we matched all characters
        if(currIndex == word.size())
            return true;

        if(r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || currIndex >= word.size())
            return false;
        
        // Character mismatch
        if(board[r][c] != word[currIndex])
            return false;

        // Mark visited (temporary change)
        char temp = board[r][c];
        board[r][c] = '#';

        // Explore neighbors
        for(auto dir : directions)
        {
            if(findTheWord(board, r + dir.first, c + dir.second, currIndex + 1, word))
                return true;
        }

        // Backtrack: restore original character
        board[r][c] = temp;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) 
    {
         for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[0].size(); j++)
            {
                if(findTheWord(board, i, j, 0, word))
                    return true;
            }
        }
        return false;
    }
};
