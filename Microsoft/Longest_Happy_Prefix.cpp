//Link : https://leetcode.com/problems/longest-happy-prefix/description/
// We may also use KMP algo here.

using ll = long long int ;
class Solution {
public:
    ll gcdExtended(ll a, ll b, ll *x, ll *y)
    {
        if (a == 0)
        {
            *x = 0, *y = 1;
            return b;
        }
    
        ll x1, y1;
        ll gcd = gcdExtended(b%a, a, &x1, &y1);
    
        *x = y1 - (b/a) * x1;
        *y = x1;
    
        return gcd;
    }
    ll modInverse(ll b, ll m)
    {
        ll x, y; 
        ll g = gcdExtended(b, m, &x, &y);
        if (g != 1)
            return -1;
    
        return (x%m + m) % m;
    }
    bool check(string &s,int n,int i){
        int j=n-1;
        while(i>0){
            if(s[i]!=s[j])return false;
            i--;j--;
        }
        return true;
    }

    string longestPrefix(string s) {
        ll n = s.size();
        ll mod = 1e9+7;
        vector<ll> po(n+1,1);
        int ans = 0;
        for(int i=1;i<=n;i++){
            ll x = 26;
            po[i] = ((po[i-1]*x)%mod);            
        }
        ll st=0;
        ll lst = 0;
        for(int i=0;i<n-1;i++){
            ll tem=26;
            ll x1 = (s[i]-'a')+1;
            ll x2 = (s[n-i-1]-'a')+1;
            st = (st + ((x1*po[i+1])%mod))%mod;
            lst =  ((lst+x2)*tem)%mod;
        }
        for(int i=n-2;i>=0;i--){
            if(st==lst && check(s,n,i)){
                ans = i+1;
                break;
            }
            ll tem=26;
            ll x1 = (s[i]-'a')+1;
            ll x2 = (s[n-i-1]-'a')+1;
            st = (st - ((x1*po[i+1])%mod) + mod)%mod;
            lst = (lst - ((x2*po[1])%mod) + mod)%mod;
            ll inv = modInverse(tem,mod);
            lst = (inv * lst) % mod;
            
        }

        if(ans==0)return "";
        return s.substr(0,ans);
    }
};
