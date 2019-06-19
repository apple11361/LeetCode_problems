

char * convert(char * s, int numRows){
    char **rows;
    int dir = 0;
    int *row_index, index, i, j;
    char *ans;
    
    /* special case */
    if(numRows == 1)
    {
        return s;
    }
    
    
    index = 0;
    rows = (char **)malloc(numRows*sizeof(char *));
    row_index = (int *)malloc(numRows*sizeof(int));
    for(i=0;i<numRows;i++)
    {
        rows[i] = (char *)malloc((strlen(s)+1)*sizeof(char));
        row_index[i] = 0;
    }

    for(i=0;s[i]!='\0';i++)
    {
        rows[index][row_index[index]++] = s[i];

        if(!dir)
        {
            index += 1;
            if(index==numRows)
            {
                dir = 1;
                index -= 1;
            }
        }
        if(dir)
        {
            index -= 1;
            if(index < 0)
            {
                dir = 0;
                index = 1;
            }
        }
    }
    
    int k = 0;
    ans = (char *)malloc((strlen(s)+1)*sizeof(char));
    for(i=0;i<numRows;i++)
    {
        
        for(j=0;j<row_index[i];j++)
        {
            ans[k++] = rows[i][j];
        }
    }
    ans[k] = '\0';


    return ans;
}


