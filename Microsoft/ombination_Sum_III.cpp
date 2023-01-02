//Link  : https://leetcode.com/problems/combination-sum-iii/
class Solution {
public:
    void makeAllComb(int num,int curr_count,int curr_sum,int k,int n,vector<int>& curr_vec,vector<vector<int>>& ans){
        
        if(curr_count==k){
            if(curr_sum == n)ans.push_back(curr_vec);
            return;
        }

        if(num==10)return;
        makeAllComb(num+1,curr_count,curr_sum,k,n,curr_vec,ans);

        curr_vec.push_back(num);
        makeAllComb(num+1,curr_count+1,curr_sum + num,k,n,curr_vec,ans);
        curr_vec.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        
        int num=1;
        int curr_sum = 0 ;
        int curr_count = 0 ;
        vector<int> curr_vec;
        vector<vector<int>> ans;
        
        makeAllComb(num,curr_count,curr_sum,k,n,curr_vec,ans);
        
        return ans;
    }
};
