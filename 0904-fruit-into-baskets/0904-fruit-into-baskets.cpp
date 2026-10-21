class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int,int> mpp;
        int left = 0;
        int maxi = 0;
        for(int i = 0; i< n;i++){
            mpp[fruits[i]]++;
            if(mpp.size()>2){
                mpp[fruits[left]]--;
                if(mpp[fruits[left]]==0) mpp.erase(fruits[left]);
                left++;
            }
            maxi =max(maxi,i - left+1);
        }
        return maxi;
    }
};