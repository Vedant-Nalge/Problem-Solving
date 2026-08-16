class Solution {
public:
    int daysneeded(vector<int> & weights,int capacity){
        int d=1;
        int cl=0;;
        for(int i =0;i<weights.size();i++){
        if(cl+weights[i]>capacity){
            d++;
            cl=weights[i];
        }
        else{
            cl+=weights[i];
        }
        }
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(),weights.end());
        int high=0;
        for(int i =0 ; i<weights.size();i++){
            high+=weights[i];
        }
        while(low<high){
            int mid =low +(high-low)/2;
            int daysn=daysneeded(weights,mid);
            if(daysn<=days) high=mid;
            else low =mid+1;
        } 
      return low;  
    }
};