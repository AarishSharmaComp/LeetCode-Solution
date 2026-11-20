class Solution {
public:
    int findPoisonedDuration(vector<int>& nums, int duration) {
        int n=nums.size();
        int ans=0;
        int start=nums[0];
        int end=nums[0]+duration-1;
        for(int i=1;i<n;i++)
        {
            if(nums[i]>=start&&nums[i]<=end)
            {
                end=max(end,nums[i]+duration-1);
            }
            else
            {
                ans+=end-start+1;
                start=nums[i];
                end=nums[i]+duration-1;
                

            }
        }
        ans+=(end-start+1);
        return ans;
    }
};