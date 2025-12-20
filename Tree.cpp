/*#include <iostream>
using namespace std;

// Node structure for Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

void preorder(Node* root){
    if(root==NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void inorder(Node* root){
    if(root==NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

int main() {
    // Creating nodes using linked structure
    Node* root = new Node(1);         // Root node
    root->left = new Node(2);         // Left child of root
    root->right = new Node(3);        // Right child of root
    root->left->left = new Node(4);   // Left child of node 2
    root->left->right = new Node(5);  // Right child of node 2
    root->right->left = new Node(6);
    root->right->right = new Node(7); 

    // Printing nodes (preorder traversal)
    cout << "Root: " << root->data << endl;
    cout << "Left child of root: " << root->left->data << endl;
    cout << "Right child of root: " << root->right->data << endl;
    cout << "Left child of node 2: " << root->left->left->data << endl;
    cout << "Right child of node 2: " << root->left->right->data << endl;
    cout<<"Preorder: ";
    preorder(root);
    cout<<endl;
    cout<<"Inorder: ";
    inorder(root);
    cout<<endl;
    cout<<"Postorder: ";
    postorder(root);

    return 0;
}
*/

//Level order traversal
/*#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(int val){
        data=val;
        left=right=NULL;
    }

};

 vector<vector<int>> traversal(TreeNode* root){
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<TreeNode*> q;

    q.push(root);
    while(!q.empty()){
        int size = q.size();
        vector<int> level;
        for(int i=0;i<size;i++){
            TreeNode* node = q.front();
            q.pop();

            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);

            level.push_back(node->data);
        }
        ans.push_back(level);
    }

    return ans;

}

void inorder(TreeNode* root){
    stack<TreeNode*> st;
    TreeNode* node = root;
    while(true){
        if(node!=NULL){
            st.push(node);
            node=node->left;
        }
        else{
            if(st.empty() == true) break;
            node=st.top();
            st.pop();
            cout<<node->data<<" ";
            node=node->right;
        }
    }
    

    

}

void preorder(TreeNode* root){
    if(root==NULL) return;
    stack<TreeNode*> st;
    st.push(root);
    while(!st.empty()){
        TreeNode* node = st.top();
        st.pop();
        cout<<node->data<<" ";
        if(node->right!=NULL) st.push(node->right);
        if(node->left!=NULL) st.push(node->left);

    }
}

void postorder(TreeNode* root){
    if(root==NULL) return;
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    st1.push(root);
    while(!st1.empty()){
        TreeNode* root = st1.top();
        st1.pop();
        st2.push(root);
        if(root->left!=NULL){

            st1.push(root->left);
        }
        if(root->right!=NULL){

            st1.push(root->right);
        }
    }
    while(!st2.empty()){
        cout<<st2.top()->data<<" ";
        st2.pop();
    }
}
int main(){
        TreeNode* root = new TreeNode(1);
        root->left = new TreeNode(2);
        root->right = new TreeNode(3);
        root->left->left = new TreeNode(8);
        root->left->right = new TreeNode(3);
        root->right->left = new TreeNode(9);
        root->right->right = new TreeNode(6);
        
        vector<vector<int>> ans = traversal(root);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<ans[i].size();j++){
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

        cout<<"Preorder"<<endl;
        preorder(root);
        cout<<"inorder"<<endl;
        inorder(root);
        cout<<"postorder"<<endl;
        postorder(root);
        
} 

*/


//LEETCODE

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
/*class Solution {
public:
    void preorder(TreeNode* node, vector<int>& level){
        if(node==nullptr) return;

        level.push_back(node->val);
        preorder(node->left, level);
        preorder(node->right, level);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> level;
        preorder(root,level);
        return level;


    }
};*/


#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        right=left=NULL;
    }
};

int length(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int l = length(root->left);
    int r = length(root->right);
    return 1 + max(l, r);



}
int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(5);

    int ans = length(root);
    cout<<ans; 
}







//balanced bt
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int length(TreeNode* root){
        if(root==NULL) return 0;

        int l = length(root->left);
        int r = length(root->right);

        return 1+max(l,r);
    }
    bool isBalanced(TreeNode* root) {
        if(root==nullptr) return true;

        int leftheight = length(root->left);
        int rightheight = length(root->right);

        if(abs(leftheight-rightheight)>1) return false;

        bool left = isBalanced(root->left);
        bool right = isBalanced(root->right);

        if(!left || !right) return false;

        return true;


    }
};