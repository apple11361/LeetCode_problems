#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

unsigned char *path;
int row_size, col_size;
int word_len;

bool dfs(int row_index, int col_index, int word_index, char *word, char **board)
{
    int path_index;

    path_index = row_index * col_size + col_index;
    if(board[row_index][col_index] == word[word_index] && !path[path_index])
    {
        if(word_index + 1 == word_len)
        {
            return true;
        }

        path[path_index] = 1;

        if(row_index - 1 >= 0 && dfs(row_index - 1, col_index, word_index + 1, word, board))
        {
            return true;
        }
        if(col_index + 1 < col_size && dfs(row_index, col_index + 1, word_index + 1, word, board))
        {
            return true;
        }
        if(row_index + 1 < row_size && dfs(row_index + 1, col_index, word_index + 1, word, board))
        {
            return true;
        }
        if(col_index - 1 >= 0 && dfs(row_index, col_index - 1, word_index + 1, word, board))
        {
            return true;
        }

        path[path_index] = 0;
    }

    return false;
}

bool exist(char **board, int boardSize, int *boardColSize, char *word)
{
    int path_len;

    row_size = boardSize;
    col_size = boardColSize[0];
    word_len = strlen(word);
    path_len = row_size * col_size; 

    path = (unsigned char *)malloc(path_len * sizeof(char));
    memset(path, 0, path_len);

    for(int i = 0; i < row_size; ++i)
    {
        for(int j = 0; j < col_size; ++j)
        {
            if(dfs(i, j, 0, word, board))
                return true;
        }
    }

    return false;
}

int main()
{
    int m = 3;
    int n = 4;
    char **board;
    bool answer;
    char *word = "ABCB";

    board = (char **)malloc(m * sizeof(char *));
    for(int i = 0; i < m; ++i)
    {
        board[i] = (char *)malloc(n * sizeof(char));
    }

    board[0][0] = 'A';
    board[0][1] = 'B';
    board[0][2] = 'C';
    board[0][3] = 'E';
    board[1][0] = 'S';
    board[1][1] = 'F';
    board[1][2] = 'C';
    board[1][3] = 'S';
    board[2][0] = 'A';
    board[2][1] = 'D';
    board[2][2] = 'E';
    board[2][3] = 'E';

    answer = exist(board, m, &n, word);

    if(answer)
        printf("true\n");
    else
        printf("false\n");

    return 0;
}
