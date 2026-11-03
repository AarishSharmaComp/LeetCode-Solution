class Solution {
private:

    int mcm(vector<int>& arr, int i, int j,
            vector<vector<int>>& dp) {

        // No balloons in this interval
        if(i > j) {
            return 0;
        }

        // Already calculated
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        int mx = INT_MIN;

        // Try every balloon as the LAST balloon to burst
        for(int k = i; k <= j; k++) {

            int temp =
                mcm(arr, i, k - 1, dp) +
                mcm(arr, k + 1, j, dp) +
                arr[i - 1] * arr[k] * arr[j + 1];

            mx = max(mx, temp);
        }

        return dp[i][j] = mx;
    }

public:
    int maxCoins(vector<int>& nums) {

        // Add virtual balloons
        vector<int> arr;

        arr.push_back(1);

        for(auto it : nums) {
            arr.push_back(it);
        }

        arr.push_back(1);

        // Memoization table
        vector<vector<int>> dp(
            arr.size(),
            vector<int>(arr.size(), -1)
        );

        return mcm(arr, 1, nums.size(), dp);
    }
};