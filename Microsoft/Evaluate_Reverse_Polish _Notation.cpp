class Solution {
public:
    
    int evalRPN(vector<string>& tokens) {
        
        stack<int> st;
        for(auto it:tokens){
            int a =INT_MAX,b=INT_MAX;
            
            if(!st.empty()){
                b= st.top();
                st.pop();
            }
            if(!st.empty()){
                a= st.top();
                st.pop();
            }
            
            if(it=="+"){
                int res = a+b;
                st.push(res);
            }
            else if(it=="-"){
                int res = a-b;
                st.push(res);
            }
            else if(it=="*"){
                int res = a*b;
                st.push(res);
            }
            else if(it=="/"){
                int res = a/b;
                st.push(res);
            }
            else{
                if(a!=INT_MAX)st.push(a);
                if(b!=INT_MAX)st.push(b);
                st.push(stoi(it));
            }
        }

        return st.top();
    }
};
