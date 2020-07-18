
class Solution {
public:
    int f=0;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<int>graph[numCourses];
        for(auto p:prerequisites){
            graph[p[1]].push_back(p[0]);
        }
        vector<int>ans;
        for(int i=0;i<numCourses;i++){
            cycle(vis,graph,i,ans);
        }
        if(f){
            ans.clear();
            return ans;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void cycle(vector<int>&vis,vector<int>graph[],int ind,vector<int>&ans){
        if(vis[ind]!=0){
            return;
        }
        vis[ind]=1;
        for(auto abc:graph[ind]){
            if(vis[abc]==0){
                cycle(vis,graph,abc,ans);
            }
            else if(vis[abc]==1){
                f=1;
            }
        }
        ans.push_back(ind);
        vis[ind]=2;
        
    }
};
