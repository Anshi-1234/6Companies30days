class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod=1000000007;
        vector<long long>dis(n,LONG_MAX);
        vector<long long>p(n);
        vector<pair<long long,long long>>adj[n];

        for(auto i:roads)
        {
            long long u=i[0];
            long long v=i[1];
            long long wt=i[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        priority_queue <pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>>>pq;

        dis[0]=0;
        p[0]=1;
        pq.push({dis[0],0});

        while(!pq.empty()){
            long long wt=pq.top().first;
            long long curr=pq.top().second;
            pq.pop();

            for(auto i:adj[curr]){
                long long v=i.first;
                long long t=i.second;
                long long nw=wt+t;

                if(nw < dis[v])
                {
                    dis[v] = nw;
                    pq.push({dis[v],v});
                    p[v] = p[curr]; 
                }
                
                else if(nw == dis[v])
                {
                    p[v] = (p[v] + p[curr])%mod;  
                }
            }
        }
        return p[n-1]%mod;
    }
};
