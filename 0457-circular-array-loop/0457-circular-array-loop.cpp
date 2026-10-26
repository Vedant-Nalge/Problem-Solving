
class Solution {
private:
    int getNext(const std::vector<int>& nums, int i) {
        int n = nums.size();
        return ((i + nums[i]) % n + n) % n;
    }

public:
    bool circularArrayLoop(std::vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; ++i) {
            // Skip already processed invalid paths or zeros
            if (nums[i] == 0) continue;

            int slow = i;
            int fast = i;
            bool isForward = nums[i] > 0;

            while (true) {
                // Move slow pointer 1 step
                int nextSlow = getNext(nums, slow);
                if ((nums[nextSlow] > 0) != isForward || nums[nextSlow] == 0) break;
                slow = nextSlow;

                // Move fast pointer 1st step
                int nextFast1 = getNext(nums, fast);
                if ((nums[nextFast1] > 0) != isForward || nums[nextFast1] == 0) break;

                // Move fast pointer 2nd step
                int nextFast2 = getNext(nums, nextFast1);
                if ((nums[nextFast2] > 0) != isForward || nums[nextFast2] == 0) break;
                fast = nextFast2;

                // Cycle detected
                if (slow == fast) {
                    // Check if cycle length is 1 (self loop)
                    if (slow == getNext(nums, slow)) {
                        break;
                    }
                    return true;
                }
            }

            // Mark all nodes in this invalid trajectory as 0
            int curr = i;
            while (nums[curr] != 0 && (nums[curr] > 0) == isForward) {
                int next = getNext(nums, curr);
                nums[curr] = 0;
                curr = next;
            }
        }

        return false;
    }
};