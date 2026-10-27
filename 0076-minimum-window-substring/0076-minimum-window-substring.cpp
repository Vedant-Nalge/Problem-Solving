class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size(), m = t.size();
        if (n < m)
            return "";

        vector<int> hash(256, 0);
        for (int i = 0; i < m; i++) {
            hash[t[i]]++;
        }

        int l = 0, r = 0;
        int minlen = INT_MAX;
        int start = -1;
        int cnt = 0;

        while (r < n) {
            if (hash[s[r]] > 0)
                cnt++;

            hash[s[r]]--;

            while (cnt == m) {
                if (r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }

                hash[s[l]]++;
                if (hash[s[l]] > 0)
                    cnt--;

                l++;
            }
            r++;
        }
        if (start == -1)
            return "" ;
            else return s.substr(start, minlen);
    }
};