//Link : https://leetcode.com/problems/number-of-pairs-satisfying-inequality/description/

using ll = long long int;
class Tree{
    int data;
    Tree *left, *right;
    int le , data_count;
    
    public:

    Tree(){
        le=0;
        data_count=0;
        left=NULL;
        right=NULL;
        data=-1;
    }
    Tree(int val){
        data = val;
        left=NULL;
        right=NULL;
        le=0;
        data_count=1;
    }
    Tree* insert(Tree* root,int val){
        if (!root) {
            return new Tree(val);
        }
    
        if (val > root->data) {
            root->right = insert(root->right, val);
        }
        else if (val < root->data){
            root->le+=1;
            root->left = insert(root->left, val);
        }
        else{
            root->data_count+=1;
        }
        return root;
    }

    int search(Tree* root,int val){
        
        if(root==NULL)return 0;

        if(root->data < val){
            return root->le + root->data_count + search(root->right,val);
        }
        else{
            return search(root->left,val);
        }
    }

};
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        int n = nums1.size();
        ll ans = 0;
        
        Tree b, *root = NULL;
        root = b.insert(root, nums1[n-1]-nums2[n-1]);

        for(int i=n-2;i>=0;i--){
            int x = nums1[i]-nums2[i]-diff;
            ll temp =n-i-1-(b.search(root,x));
            ans += (temp);
            b.insert(root,nums1[i]-nums2[i]);
        }
        return ans;
    }
};
