class Solution {
public:
    string getHint(string secret, string guess) 
    {
        int count1=0;
        vector<int>v1(10,0);
        vector<int>v2(10,0);
         string s="";
        
        for(int i=0;i<guess.length();i++)
        {
                if(guess[i]==secret[i])
                    count1++;   
                else 
                {
                   v1[secret[i]-'0']++;
                   v2[guess[i]-'0']++;
                }
        }
        int count2=0;
        for(int i=0;i<=9;i++)
        {
         count2+=min(v1[i],v2[i]);
        }
         s=to_string(count1)+'A'+to_string(count2)+'B';
        return s;
        }
};
