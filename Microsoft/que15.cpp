class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int idx_a=-1;
        int idx_b=-1;
        int idx_c=-1;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a')
             idx_a=i;
            else if(s[i]=='b')
             idx_b=i;
            else if(s[i]=='c')
             idx_c=i;

            if(i>1)
            {
             ans+=min(idx_a,min(idx_b,idx_c))+1;
            }
        }
       
        return ans;
    }
};
