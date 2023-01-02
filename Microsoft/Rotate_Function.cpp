Link : https://leetcode.com/problems/rotate-function/
My Solution Link : https://leetcode.com/problems/rotate-function/submissions/869519093/ 
using ll = long long int ;
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        
        ll ans = 0 ,curr_ans=0;
        ll n = nums.size();
        ll totalSum = 0;

        for(ll i=0;i<n;i++){
            ll a = nums[i];
            ans += (i*a);
            totalSum+=a;
        }
        curr_ans = ans ;
        for(ll i=0;i<n-1;i++){
            ll a = nums[i];
            ll x = totalSum-a;
            curr_ans = curr_ans - x + (a*(n-1));
            ans = max(ans,curr_ans);
    
        }
        return ans;
    }
};
