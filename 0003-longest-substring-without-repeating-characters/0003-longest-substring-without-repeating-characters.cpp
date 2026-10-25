class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
       
        int maxlen = 0;
        vector<int> last_seen(256, -1);
        for (int r = 0; r < n; r++) {
            if (last_seen[s[r]] >= l) {
                l = last_seen[s[r]] + 1;
            }
            last_seen[s[r]] = r;
            maxlen = max(maxlen, r - l + 1);
        }
        return maxlen;
    }
};