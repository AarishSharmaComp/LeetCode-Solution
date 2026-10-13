class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums,
                                       int indexDiff,
                                       int valueDiff) {

        if (indexDiff <= 0 || valueDiff < 0) {
            return false;
        }

        set<long long> window;

        for (int i = 0; i < nums.size(); i++) {

            // Remove the element outside the valid window.
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }

            long long x = nums[i];

            // Find the first element >= x - valueDiff.
            auto it = window.lower_bound(x - valueDiff);

            // Check whether an element exists in the valid range.
            if (it != window.end() &&
                *it <= x + valueDiff) {
                return true;
            }

            // Add the current element.
            window.insert(x);
        }

        return false;
    }
};