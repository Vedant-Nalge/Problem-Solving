class Solution {
public:
    string largestPalindromic(string num) {
        // Count frequency of each digit (0-9)
        vector<int> digitCount(10, 0);
        for (char c : num) {
            digitCount[c - '0']++;
        }
      
        // Find the largest odd-count digit for middle position
        string middle = "";
        for (int digit = 9; digit >= 0; digit--) {
            if (digitCount[digit] % 2 == 1) {
                middle += (char)(digit + '0');
                digitCount[digit]--;
                break;
            }
        }
      
        // Build the first half of palindrome using pairs
        string firstHalf = "";
        for (int digit = 0; digit <= 9; digit++) {
            if (digitCount[digit] > 0) {
                // Use half of the remaining count (pairs)
                int pairCount = digitCount[digit] / 2;
                while (pairCount > 0) {
                    firstHalf += (char)(digit + '0');
                    pairCount--;
                }
            }
        }
      
        // Remove leading zeros from first half
        while (!firstHalf.empty() && firstHalf.back() == '0') {
            firstHalf.pop_back();
        }
      
        // Construct the palindrome: reverse(firstHalf) + middle + firstHalf
        string result = firstHalf;
        reverse(result.begin(), result.end());
        result += middle + firstHalf;
      
        // Handle edge case: if result is empty, return "0"
        return result.empty() ? "0" : result;
    }
};
