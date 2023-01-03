
// Problem Link : https://leetcode.com/problems/course-schedule/description/
// Intution : Intution of that problem is simple . If we make a directed graph with the help of prereq-array then We just check that if there is cycle present or not . If Cycle is
//present then we cannot complete the courses that belong to that cycle , Hence we return false . Otherwise return true.
class Solution {
public:
    bool isCyclePresent(int node,int pre,vector<int>&vis,vector<int> &currPathVis,vector<int> graph[]){
        vis[node]=1;
        currPathVis[node]=1;
        for(auto it:graph[node]){
            if(vis[it]==0){
                if(isCyclePresent(it,node,vis,currPathVis,graph))return true;
            }
            else if(currPathVis[it]==1){
                return true;
            }
            
        }

        currPathVis[node]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prereq) {
        
        vector<int> vis(numCourses,0);
        vector<int> graph[numCourses];

        for(auto it:prereq){
            graph[it[0]].push_back(it[1]);
        }

        for(int i=0;i<numCourses;i++){
            if(vis[i]==0){
                vector<int> currPathVis(numCourses,0);
                if(isCyclePresent(i,-1,vis,currPathVis,graph))return false;
            }
        }
        return true;
    }
};
