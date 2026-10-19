class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        vector<int> ans;
        unordered_map<int,int> mpp;  //val,index

        for(int i = 0 ; i < n ; i++){
            int complement = target - numbers[i];

            if(mpp.find(complement)!=mpp.end()){
                ans.push_back(mpp[complement]);
                ans.push_back(i+1);
                break;
            }
            mpp.insert({numbers[i],i+1});
        }

        return ans;  
    }
};