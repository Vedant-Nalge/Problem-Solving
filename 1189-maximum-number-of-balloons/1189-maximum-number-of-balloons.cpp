class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();

        vector<int> hash(26, 0);
        for (auto ch : text) {
            hash[ch - 'a']++;
        }

        string s = "balloon";
        int cnt = 0;
        int i = 0;
        int sz = s.size();

        while (hash[s[i] - 'a'] > 0) {
            hash[s[i] - 'a']--;
            i++;
            if (i == sz) {
                i = 0;
                cnt++;
            }
        }
        return cnt;
    }
};