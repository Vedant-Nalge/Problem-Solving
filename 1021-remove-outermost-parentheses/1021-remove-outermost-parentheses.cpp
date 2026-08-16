class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        int cnt = 0;
        int i = 0;
        string ans = "";
        while (i < n) {

            if (s[i] == '(') {
                if (cnt > 0)
                    ans += '(';
                cnt++;
            }

            else {
                cnt--;

                if (cnt > 0)
                    ans += ')';
                
            }
            i++;
        }
        return ans;
    }
};