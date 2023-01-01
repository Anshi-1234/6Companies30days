class Solution {
public:
void solve(int index,vector<int>&ans,vector<vector<int>>&res,int sum,int k,int n)
{
    if(sum==n && k==0)
    {
       res.push_back(ans);
        return;
    }
    if(sum>n)
    {
        return;
    }

    for(int i=index;i<=9;i++)
    {
        ans.push_back(i);
        solve(i+1,ans,res,sum+i,k-1,n);
        ans.pop_back();
    }
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>ans;
        vector<vector<int>>res;

        solve(1,ans,res,0,k,n);
        return res;
    }
};
