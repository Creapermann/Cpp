#include <iostream>
#include <vector>
#include <algorithm>
#include <set>


class Solution
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& m_sudoku);
    
private:
    bool isValidInRows() const;
    bool hasNoDuplications(const std::vector<char>& vec) const;
    bool isValidInColumns() const;
    bool isValidInSquares() const;
    int addBlockToSet(std::set<char>& set, int row, int column) const;
    
    std::vector<std::vector<char>> m_sudoku;
    char m_emptyFieldCharacter = '.';
};

bool Solution::isValidSudoku(std::vector<std::vector<char>>& board)
{
    m_sudoku = board;
    return isValidInRows() && isValidInColumns() && isValidInSquares();
}

bool Solution::isValidInRows() const
{
    for(auto& row : m_sudoku)
    {
        if(!hasNoDuplications(row))
            return false;
    }
    return true;
}

bool Solution::hasNoDuplications(const std::vector<char>& vec) const
{
    std::set<char> set;
    for(int i = 0; i < vec.size(); ++i)
    {
        if(vec[i] == m_emptyFieldCharacter)
            continue;
        
        auto preInsertSize = set.size();
        set.insert(vec[i]);
        auto postInsertSize = set.size();
        
        if(preInsertSize == postInsertSize)
            return false;
    }
    
    return true;
}

bool Solution::isValidInColumns() const
{
    for(int i = 0; i < 9; ++i)
    {
        std::set<char> set;
        for(int k = 0; k < 9; ++k)
        {
            if(m_sudoku[k][i] == m_emptyFieldCharacter)
                continue;
    
            auto preInsertSize = set.size();
            set.insert(m_sudoku[k][i]);
            auto postInsertSize = set.size();
    
            if(preInsertSize == postInsertSize)
                return false;
        }
    }
    
    return true;
}

bool Solution::isValidInSquares() const
{
    int row = 0;
    int column = 0;
    for(int i = 0; i < 9; ++i)
    {
        std::set<char> set;
    
        int emptyChars = addBlockToSet(set, row, column);
    
        column += 3;
        if(column >= 9)
        {
            column = 0;
            row += 3;
        }
        
        if(set.size() + emptyChars != 9)
            return false;
    }
    
    return true;
}

int Solution::addBlockToSet(std::set<char>& set, int row, int column) const
{
    int emptyChars = 0;
    for(int i = row; i < row+3; ++i)
    {
        for(int k = column; k < column+3; ++k)
        {
            if(m_sudoku[i][k] == m_emptyFieldCharacter)
            {
                ++emptyChars;
                continue;
            }
    
            set.insert(m_sudoku[i][k]);
        }
    }
    
    return emptyChars;
}

int main()
{
    std::vector<std::vector<char>> data =
    {{'5','3','.','.','7','.','.','.','.'}
    ,{'6','4','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
    
    Solution solution;
    std::cout << std::boolalpha << solution.isValidSudoku(data);
    std::cout << "Hello World\n";
    
    return 1;
}