#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {

        bool first_match;

        if(p=="")
            return s=="";

        first_match = s.length()!=0 && (s.at(0) == p.at(0) || p.at(0)=='.');

        if(p.length() >= 2 && p.at(1)=='*')
        {
            if(first_match)
                return isMatch(s.substr(1), p) || isMatch(s, p.substr(2));
            else
                return isMatch(s, p.substr(2));
        }
        else
        {
            return first_match && isMatch(s.substr(1), p.substr(1));
        }
    }
};

int main() {
    Solution sol;
    string s, p;

    getline(cin, s);
    getline(cin, p);

    s = s.substr(5, s.length()-6);
    p = p.substr(5, p.length()-6);

    cout<<sol.isMatch(s, p);

}
