class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int,int>> pq;
        unordered_map<int,int> frq;
        vector<int> ans;
        for(int i =0;i<n;i++){
            frq[nums[i]]++;
        }

        for(auto it :frq){
            pq.push({it.second,it.first});
        }
        while(k>0){
            int a = pq.top().second;
            ans.push_back(a);
            pq.pop();
            k--;

        }
        return ans;
        
    }
};