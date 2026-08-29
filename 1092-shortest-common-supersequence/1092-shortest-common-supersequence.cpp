class Solution {
public:
    int helper(int ind1, int ind2, const  string& s1, const string& s2,
               vector<vector<int>>& dp) {
        if (ind1 < 0 || ind2 < 0)
            return 0;

        if (dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if (s1[ind1] == s2[ind2])
            return dp[ind1][ind2] = 1 + helper(ind1 - 1, ind2 - 1, s1, s2, dp);
        else {
            return dp[ind1][ind2] = max(helper(ind1 - 1, ind2, s1, s2, dp),
                                        helper(ind1, ind2 - 1, s1, s2, dp));
        }
    }
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        string ans = "";

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        int i = n - 1;
        int j = m - 1;

        helper(i, j, str1, str2, dp);

        while (i >= 0 && j >= 0) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i--;
                j--;
            }

            else if (i == 0) {
                ans += str2[j];
                j--;
            }

            else if (j == 0) {
                ans += str1[i];
                i--;
            }

            else if (i > 0 && j > 0 && dp[i - 1][j] >= dp[i][j - 1]) {
                ans += str1[i];
                i--;
            }

            else {
                ans += str2[j];
                j--;
            }
        }

        while (i >= 0) {
            ans += str1[i];
            i--;
        }

        while (j >= 0) {
            ans += str2[j];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};