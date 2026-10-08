class Solution {
public:
    int findPosition(vector<int>& nums, int target, bool first) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] == target) {
                ans = mid;

                if (first)
                    right = mid - 1;   // search left
                else
                    left = mid + 1;    // search right
            }
            else if (nums[mid] < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        return ans;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int first = findPosition(nums, target, true);
        int last = findPosition(nums, target, false);

        return {first, last};
    }
};