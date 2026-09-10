class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int f = edges[0][0];
        int s = edges[0][1];

        for (int i = 0; i < 2; i++) {
            if (edges[1][i] == f)
                return f;
             if (edges[1][i] == s)
                return s;
        }
        return 0;
    }
};