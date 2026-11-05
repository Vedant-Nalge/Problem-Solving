class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int result = 0;
        int bitpos = 0;
        while(n>0){
            int flipped = (n&1) ^ 1;
            result = result | (flipped<<bitpos);
            bitpos++;
            n = n >>1;

        }
        return result;
        
    }
};