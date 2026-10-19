class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(int i = 0 ; i<n ;i++){
            st.insert(nums[i]);
        }
        
        int s = st.size();
        int i =0;
        for(int val : st){
            nums[i] = val;
            i++;
        }
       return s; 
    }
};