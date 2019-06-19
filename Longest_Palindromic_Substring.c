char * longestPalindrome(char * s){
    char str[2002];
    int i, j, left, right, ans_len, ans_l, ans_r;
    char *ret;

    ans_len = 0;
    memset(str, '.', 2002);

    if(s[0] == '\0')
        return s;

    for(i=0;s[i]!='\0';i++)
    {
        str[i*2+1] = s[i];
    }
    str[i*2+1] = '\0';

    for(i=0;str[i]!='\0';i++)
    {
        left = right = i;
        while(left>=0 && str[left]==str[right])
        {
            left--;
            right++;
        }

        if((right-left-1) > ans_len)
        {
            ans_len = right - left - 1;
            ans_l = left+1;
            ans_r = right-1;
        }
    }
    
    
    ans_l = (ans_l)/2;
    ans_r = (ans_r-1)/2;
    s[ans_r+1] = '\0';
    return &s[ans_l];
}



/*char * longestPalindrome(char * s){
    int str_len = 0;
    char str[2002];
    int ans[2002];
    
    //補上字元，使得所有情況都可以看成由中心字元往左右擴散
    str[0] = '.';
    int i;
    for(i=1;s[str_len]!='\0';str_len++)
    {
        str[i++] = s[str_len];
        str[i++] = '.';
    }
    str[i] = '\0';
    
    //找答案
    ans[0] = 1;
    int j;
    for(j=1;j<i;j++)
    {
        
    }
}*/


