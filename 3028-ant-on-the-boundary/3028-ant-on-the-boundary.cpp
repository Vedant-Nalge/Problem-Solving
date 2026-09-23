class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums) {
        int position = 0;
        int count = 0;
        
        for (int step : nums) {
            position += step;
            if (position == 0) {
                count++;
            }
        }
        
        return count;
    }
};