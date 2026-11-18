class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
       auto cmp = [](vector<int> &a ,vector<int>&b){
        if(a[0]==b[0]) return a[1]>b[1];
        return a[0]<b[0];
       };

       sort(envelopes.begin(),envelopes.end(),cmp);

       //now we have width in increasing order ,so we just need to take LIS on heights
        vector<int> ans;
        for(auto it : envelopes){
            int h = it[1];
            auto lb = lower_bound(ans.begin(),ans.end(),h);
            //it will search for element in asn which is >=h
            // if we find someone we will replace it with h as we want smallest h to accomdiate max ,if not find we will append as his itslef the maxi
            if(lb == ans.end())ans.push_back(h);
            else *lb = h;
        }
        return ans.size();



    }
};