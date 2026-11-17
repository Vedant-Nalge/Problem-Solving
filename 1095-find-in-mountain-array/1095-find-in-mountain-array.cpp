/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int n = mountainArr.length();
        int idx = -1;
        int l = 1, h = n - 2;
        while (l < h) {
            int mid = l + (h - l) / 2;

            if (mountainArr.get(mid) < (mountainArr.get(mid + 1)))
                l = mid + 1;
            else
                h = mid;
        }
        idx = h;

        int l1 = 0, h1 = idx, l2 = idx + 1, h2 = n - 1;

        while (l1 <= h1) {
            int mid = l1 + (h1 - l1) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
                break;
            } else if (mountainArr.get(mid) < target)
                l1 = mid + 1;
            else
                h1 = mid - 1;
        }
        while (l2 <= h2) {
            int mid = l2 + (h2 - l2) / 2;
            if (mountainArr.get(mid) == target) {
                return mid;
                break;
            } else if (mountainArr.get(mid) < target)
                h2 = mid - 1;
            else
                l2 = mid + 1;
        }
        return -1;
    }
};