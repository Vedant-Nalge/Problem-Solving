class Solution {
public:
    int findmaxi(int c, vector<vector<int>>& mat) {
        int maxi = INT_MIN;
        int ind = 0;
        for (int i = 0; i < mat.size(); i++) {
            if (maxi < mat[i][c]) {
                maxi = mat[i][c];
                ind = i;
            }
        }
        return ind;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0;
        int high = m - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int ind = findmaxi(mid, mat);
            int maxele = mat[ind][mid];
            int l = mid-1;
            int r = mid+1;
            if (l >= 0)
                 l = mat[ind][mid - 1];
            else
                 l = -1;
            if (r <= m - 1)
                 r = mat[ind][mid + 1];
            else
                 r = -1;

            if (maxele >l  && maxele > r) {
                return {ind, mid};
            } else if (maxele > l) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
};