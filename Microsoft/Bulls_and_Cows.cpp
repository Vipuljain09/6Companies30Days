// Link: https://leetcode.com/problems/bulls-and-cows/
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int bullCount = 0 ,cowCount = 0;
        vector<int> count1(10,0);
        vector<int> count2(10,0);

        for(int i=0;i<n;i++){
            if(secret[i]==guess[i]){
                bullCount++;
            }
            else{
                count1[secret[i]-'0']++;
                count2[guess[i]-'0']++;
            }
        }

        for(int i=0;i<10;i++){
            cowCount += min(count1[i],count2[i]);
        }

        string res = to_string(bullCount)+"A"+to_string(cowCount)+"B";
        return res;
    }
};
