class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.size();
        map<char,int>hash;
        for (char ch : s) {
            hash[ch]++;
        }

        int even = 0;
        int odd = 0;
        int unique = 0;

        for (auto it : hash) {
            if (it.second % 2 == 0) {
                even += it.second;
            }

            else {
                if (it.second > 2) {
                    odd += it.second - 1;
                    unique = 1;
                } else
                    unique = 1;
            }
        }

        return even + odd + unique;
    }
};