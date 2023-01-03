class Solution {
public:
 bool isCyclic(unordered_map<int,vector<int>>&adj,vector<int>& visited,int curr)
    {
        if(visited[curr]==2)
            return true;
        
        visited[curr] = 2;
        for(int i=0;i<adj[curr].size();++i)
            if(visited[adj[curr][i]]!=1)
                if(isCyclic(adj,visited,adj[curr][i]))
                    return true;
        
        visited[curr] = 1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
       unordered_map<int,vector<int>>m;
       for(int i=0;i<prerequisites.size();i++)
       {
           m[prerequisites[i][0]].push_back(prerequisites[i][1]);
       }

      vector<int>visited(numCourses,0);
        for(int i=0;i<numCourses;++i)
            if(visited[i]==0)
                if(isCyclic(m,visited,i))
                    return false;
        
        return true;
    }
};
