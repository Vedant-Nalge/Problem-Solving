class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2,
                                       int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> res;
        priority_queue<pair<int,pair<int, int>>, vector<pair<int,pair<int, int>>>,
                       greater<pair<int,pair<int, int>>>>
            pq;
        for (int i = 0; i < n && i < k; i++) {
            pq.push({nums1[i] + nums2[0], {i, 0}});
        }
        
        while (!pq.empty() && k > 0) {
            auto top = pq.top();
            pq.pop();
            
            int u = top.second.first;  // index in nums1
            int v = top.second.second; // index in nums2
            
            res.push_back({nums1[u], nums2[v]});
            k--;
            
            
            if (v + 1 < m) {
                pq.push({nums1[u] + nums2[v + 1], {u, v + 1}});
            }
        }
        
        return res;
    }
};