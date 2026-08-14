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

        while(pq.size()!=frq.size()-k){
            auto a = pq.top();
            ans.push_back(a.second);
            pq.pop();
        }
       return ans; 
    }
};