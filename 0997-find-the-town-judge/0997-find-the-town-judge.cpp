class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> cnt(n+1);
        unordered_map<int,int> p;
        for (auto it : trust) {
            int u = it[0];
            int v = it[1];
            cnt[u]--;
            cnt[v]++;
            
        }

        for (int i = 1; i<=n ; i++) {
            if (cnt[i]==n-1) {
                return i;
                break;
            }
        }
        return -1;
    }
};