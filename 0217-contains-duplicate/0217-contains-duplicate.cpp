class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> stt(nums.begin(), nums.end());
        return (stt.size() != nums.size());
    }
};