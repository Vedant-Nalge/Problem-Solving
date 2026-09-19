class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            st.push(s[i]);
        }

        int i = 0;
        while (!st.empty() && i < m) {
            if (t[i] == st.top()) {
                st.pop();
            }
            i++;
        }

        if (st.empty())
            return true;
        else
            return false;
    }
};