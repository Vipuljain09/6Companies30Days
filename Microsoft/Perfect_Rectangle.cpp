//Link : https://leetcode.com/problems/perfect-rectangle/description/
//My Solution Link : https://leetcode.com/problems/perfect-rectangle/submissions/869930024/

using ll = long long int;
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        
        ll x1 = INT_MAX , y1 = INT_MAX;
        ll x2 = INT_MIN , y2 = INT_MIN; 
        ll expectArea=0 , currArea=0;
        set<pair<int,int>> st;
        map<pair<int,int>,pair<int,int>> mp;
        map<pair<int,int>,pair<int,int>> mp1;
        for(auto it:rectangles){
            x1 = min(x1,(ll)it[0]);
            x2 = max(x2,(ll)it[2]);
            y1 = min(y1,(ll)it[1]);
            y2 = max(y2,(ll)it[3]);
            ll l = abs(it[2]-it[0]);
            ll h = abs(it[3]-it[1]);
            currArea += (l*h);
            mp[{it[0],it[1]}] = {it[2],it[3]};
        }

        st.insert({x1,y1});
        mp1[{x1,y1}]={x2,y2};
        expectArea = (abs(x2-x1)*abs(y2-y1));
        if(expectArea!=currArea )return false;
        
        while(!st.empty()){
            auto it = st.begin();
            int u1 = (*it).first;
            int v1 = (*it).second;
            int u2 = mp1[{u1,v1}].first;
            int v2 = mp1[{u1,v1}].second;
            cout<<u1<<","<<v1<<" "<<u2<<","<<v2<<endl;
            st.erase(it);
            cout<<st.size()<<endl;
            if(mp.find({u1,v1})==mp.end())return false;
            int x = mp[{u1,v1}].first;
            int y = mp[{u1,v1}].second;
            cout<<x<<" "<<y<<endl;
            if(x<u2){
                st.insert({x,v1});
                mp1[{x,v1}]={u2,y};
            }
            if(y<v2){
                st.insert({u1,y});
                mp1[{u1,y}]={x,v2};
            }
            if(x<u2 && y<v2){
                st.insert({x,y});
                mp1[{x,y}]={u2,v2};
            }

            if(x>u2){
                mp[{u2,v1}]={x,v2};
            }
            if(y>v2){
                mp[{u1,v2}]={u2,y};
            }
            if(x>u2 && y>v2){
                mp[{u2,v2}]={x,y};
            }
        }

        return true;
    }
};
