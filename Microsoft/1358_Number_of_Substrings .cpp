//Link : https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        int i=0,j=0;
        vector<int> count(3,0);
        while(j<n){
            count[s[j]-'a']++;

            while(count[0]>0 && count[1]>0 && count[2]>0){
                ans += (n-j);
                count[s[i]-'a']--;
                i++;
            }
            j++;
        }
        return ans;
    }
};
