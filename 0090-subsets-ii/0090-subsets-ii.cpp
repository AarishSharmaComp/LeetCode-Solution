class Solution {
public:
    void backtrack(vector<int>& nums, int index, vector<int>& subset,
                   vector<vector<int>>& subsets) {
        if (index == nums.size()) {
            subsets.push_back(subset);
            return;
        }

        if (subset.empty() || nums[index] != subset.back())
            backtrack(nums, index + 1, subset, subsets);

        subset.push_back(nums[index]);
        backtrack(nums, index + 1, subset, subsets);
        subset.pop_back();
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> subsets;
        vector<int> subset;
        backtrack(nums, 0, subset, subsets);
        return subsets;
    }
};