int lengthOfLongestSubstring(char * s){
    int i, j, ans, temp_ans, temp;
    int hash[256] = {0};
    i = 0;
    j = 0;
    ans = 0;
    temp_ans = 0;
    
    while(s[j] != '\0')
    {
        temp = s[j];
        if(!hash[temp])
        {
            j++;
            temp_ans++;
            hash[temp] = 1;
            if(temp_ans > ans)
                ans = temp_ans;
        }
        else
        {
            temp = s[i];
            i++;
            hash[temp] = 0;
            temp_ans--;
        }
    }
    
    return ans;
}


