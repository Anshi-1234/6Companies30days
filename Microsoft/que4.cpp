class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
       int total=0;
       int n=nums.size();
       total=accumulate(nums.begin(),nums.end(),0);
        int f0=0;
        for(int j=0;j<n;j++)
        {
               f0+=j*nums[j];
        }

        vector<int>v;
         v.push_back(f0);
         long long f=f0;
         long long sum=0;
        for(int i=1;i<n;i++)  
        {
          sum=v[i-1]+total-n*nums[n-i];
          v.push_back(sum);
          f=max(sum,f);
        }
        return int(f);
    }
};
