class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0 ;
        int r = n-1;
        while(l<r){
            int a = numbers[l];
            int b = numbers[r];
            if(a+b==target){
                return{l+1,r+1};
            }
            else if ( a+b<target) l++;
            else r--;
        }
        return {};
    }
};