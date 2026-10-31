class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        
        sort(pairs.begin(), pairs.end(), []( vector<int>& a, vector<int>& b) {
            return a[1] < b[1];
        });

        int chainLen = 0;
        int currentEnd = INT_MIN;

        for ( auto& p : pairs) {
            if (p[0] > currentEnd) {
                chainLen++;
                currentEnd = p[1]; 
            }
        }

        return chainLen;
    }
};