class Solution {
public:
    int minimizeXor(int num1, int num2) {

        int Set_Bit = 0;
        while (num2 > 0) {
            if ((num2 & 1) == 1)
                Set_Bit++;
            num2 = num2 >> 1;
        }

        int ans = 0;

        for (int i = 30; i >= 0; i--) {
            int mask = (1 << i);
            if ((mask & num1) != 0) { // If the i-th bit of num1 is set (1)
                ans = ans | mask;     // Set the i-th bit of ans to 1
                Set_Bit--;            // Use up one set bit
                if (Set_Bit == 0) {   // All required 1s used
                    break;
                }
            }
        }

        // Step 3: If we still have set bits left, set 1s in `ans` where `num1`
        // has 0s (from LSB to MSB)
        if (Set_Bit > 0) {
            for (int i = 0; i <= 30; i++) {
                int mask = (1 << i);
                if ((mask & num1) ==
                    0) {              // If the i-th bit of num1 is unset (0)
                    ans = ans | mask; // Set the i-th bit of ans to 1
                    Set_Bit--;        // Use up one set bit
                    if (Set_Bit == 0) {
                        break;
                    }
                }
            }
        }

        return ans;
    }
};