class Solution {
public:
    string longestPrefix(string s) {
        int n=s.length();
        vector<int>prefix(n,0);

        int i=0,j=1;
        while(j<n)
        {
            if(s[i]==s[j])
            {
               prefix[j]=i+1;
               i++;
               j++;
            }
            else
            {
                if(i)
                {
                  i=prefix[i-1];
                }
                else
                {
                    j++;
                }
            }
        }
        // for(auto i:prefix)
        // {
        //     cout<<i<<endl;
        // }
       return s.substr(0,i);
       
    }
};
