class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> mpp;
        priority_queue<pair<int, int>> pq;
        for (auto it : nums) {
            mpp[it]++;
        }
        for (auto it : mpp) {
            pq.push({it.second, it.first});
        }

        while (k > 0) {
            auto node = pq.top();
            pq.pop();
            ans.push_back(node.second);
            k--;
        }
        return ans;
    }
};