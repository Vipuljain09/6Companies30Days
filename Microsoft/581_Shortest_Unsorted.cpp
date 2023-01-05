//Link :https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i=n,j=n;
        int maxi = INT_MIN;
        stack<pair<int,int>> st;

        for(int k=0;k<n;k++){
            if(nums[k]<maxi){
                j=k;
                while(!st.empty() && st.top().first > nums[k]){
                    i = min(i,st.top().second);
                    st.pop();
                }
            }
            else{
                st.push({nums[k],k});
            }
            maxi = max(maxi,nums[k]);
        }
        
        if(i<j)return j-i+1;
        return 0;
    }
};


