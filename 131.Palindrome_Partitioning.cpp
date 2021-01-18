class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int max_depth = s.length();
        backtrack(0, path, s, ans, max_depth);
        return ans;
    }
private:
    void backtrack(int depth, vector<string>& path, string& s, vector<vector<string>>& ans, int max_depth){
        if(depth == max_depth){
            ans.push_back(path);
            return;
        }
        for(int i = depth; i < s.length(); ++i){
            string tmp = s.substr(depth, i - depth + 1);
            if(is_palindrome(tmp)){
                path.push_back(tmp);
                backtrack(i + 1, path, s, ans, max_depth);
                path.pop_back();
            }
        }
    }
    bool is_palindrome(string& s){
        for(int i = 0, j = s.length() - 1; i < j; ++i, --j){
            if(s[i] != s[j]){
                return false;
            }
        }
        return true;
    }
};
