bool isValidSudoku(char** board, int boardSize, int* boardColSize)
{
    int check[9];

    // Check for rows
    for(int i = 0; i < 9; i++)
    {
        memset(check, 0, 9 * sizeof(int));

        for(int j = 0; j < 9; j++)
        {
            if(board[i][j] == '.')
                continue;

            if(check[board[i][j]-'1'])
                return false;
            else
                check[board[i][j]-'1'] = 1;
        }
    }

    //Check for columns
    for(int i = 0; i < 9; i++)
    {
        memset(check, 0, 9 * sizeof(int));

        for(int j = 0; j < 9; j++)
        {
            if(board[j][i] == '.')
                continue;

            if(check[board[j][i]-'1'])
                return false;
            else
                check[board[j][i]-'1'] = 1;
        }
    }

    //Check for grids
    for(int i = 0; i < 9; i++)
    {
        memset(check, 0, 9 * sizeof(int));

        for(int j = 0; j < 9; j++)
        {
            int row_index, col_index;

            row_index = i / 3 * 3 + j / 3;
            col_index = i * 3 % 9 + j % 3;

            if(board[row_index][col_index] == '.')
                continue;

            if(check[board[row_index][col_index]-'1'])
                return false;
            else
                check[board[row_index][col_index]-'1'] = 1;
        }
    }

    return true;
}
