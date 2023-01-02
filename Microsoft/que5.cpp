class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>dp(n+1,1);
            vector<int>v;
        if(nums.size()==1)
        {
            v.push_back(nums[0]);
            return v;
        }
        int dp1=INT_MIN;
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i])
                {
                  dp[i]=1+dp[j];
                }
              dp1=max(dp1,dp[i]);
            }
        }
    
        int prev=-1;
        for(int i=n-1;i>=0;i--)
        {
            if(dp1==dp[i] && (prev%nums[i]==0||prev==-1))
            {
               v.push_back(nums[i]);
                dp1--;
                prev=nums[i];
            }
        }
        sort(v.begin(),v.end());
        return v;
    }
};
