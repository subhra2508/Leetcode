//basically it's a topological sort//

class Solution {
public:
    bool detectCycle_util(vector<vector<int>>&adj,vector<int>&visited,int v){
        if(visited[v]==1){
            return true;
        }
        if(visited[v]==2)return false;
        visited[v]=1;
        for(int i=0;i<adj[v].size();i++){
            if(detectCycle_util(adj,visited,adj[v][i]))return true;
        }
        visited[v]=2;
        return false;
    }
    bool detectCycle(vector<vector<int>>&adj,int n){
        vector<int>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                if(detectCycle_util(adj,visited,i)){
                    return true;
                }
            }
           
        }
         return false;
        
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        
        //create a adj list
        vector<vector<int>>adj(numCourses);
        for(int i=0;i<n;i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        //for res
        vector<int>res;
        
        //check if it is a DAG if cyclic then return res
        if(detectCycle(adj,numCourses)){
            return res;
        }
        
        //create a stack to store the topsort
        stack<int>stk;
        vector<bool>visited(numCourses,false);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                topologicalSort(adj,i,visited,stk);
            }
        }
        while(!stk.empty()){
           res.push_back(stk.top());
            stk.pop();
        }
        
     
         
        return res;
    }
    
    void topologicalSort(vector<vector<int>>&adj,int v,vector<bool>&visited,stack<int>&stk){
        visited[v]=true;
        for(int i=0;i<adj[v].size();i++){
            if(!visited[adj[v][i]]){
                topologicalSort(adj,adj[v][i],visited,stk);
            }
        }
        stk.push(v);
    }
};

//this first method is giving some error
 Input
1
[]
Output
[]
Expected
[0]

if you figure out give a PR😀



























