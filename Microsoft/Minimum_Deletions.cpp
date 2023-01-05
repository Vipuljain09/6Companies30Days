//Link : https://leetcode.com/problems/minimum-deletions-to-make-array-divisible/description/

class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        int n = nums.size();        
        int reqGcd = numsDivide[0];
        sort(nums.begin(),nums.end());
        int ans = 0;
        for(auto it:numsDivide){
            reqGcd = __gcd(reqGcd,it);
        }

        for(auto it:nums){
            if((reqGcd%it)==0){
                break;
            }
            ans++;
        }
        if(ans==n)return -1;
        return ans;

    }
};
