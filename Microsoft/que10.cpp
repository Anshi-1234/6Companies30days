class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<int>v(n);
      for(int i=0;i<n;i++)
      {
          v[i]=nums[i];
      }
       sort(v.begin(),v.end());
       int flag1=-1;
       for(int i=0;i<n;i++)
       {
           if(v[i]!=nums[i])
           {
             flag1=i;
             break;
           }
       }
       int flag2=-1;
       for(int i=n-1;i>=0;i--)
       {
           if(v[i]!=nums[i])
           {
             flag2=i;
             break;
           }
       }
       if(flag1==flag2)
       return 0;
     return flag2-flag1+1;
    }
};
