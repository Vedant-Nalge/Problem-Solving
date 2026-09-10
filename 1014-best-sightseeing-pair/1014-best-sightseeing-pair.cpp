class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_score = 0;
        int maxi = values[0] + 0;

        for (int j = 1; j < values.size(); ++j) {
           
            max_score = max(max_score, maxi + values[j] - j);
            
            maxi = max(maxi, values[j] + j);
        }

        return max_score;
    }
};