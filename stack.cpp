// #include<bits/stdc++.h>
// using namespace std;

// class S{
// public:
// int top=-1;
// int arr[10];

// void push(int x){
//     if(top>=9){
//         return;
//     }
//    arr[++top] = x;
// }

// void pop(){
//     if(top==-1){
//         return;
//     }
//     top--;

// }
// void print(){
//     for(int i=0;i<top;i++){
//         cout<<arr[i];
//     }
// }
// void last(){
//     if(top==-1){
//         return;
//     }
//     cout<<arr[top]<<" ";
// }

// void sizeOf(){
//     cout<<top+1;
// }
// };
// int main(){
//     int n =10;
//     S s = S();
//     for(int i=0;i<n;i++){
//         int x;
//         cin>>x;
//         s.push(x);
//     }
    
//     s.pop();
//     s.pop();
//     s.print();
//     cout<<endl;
//     s.sizeOf();
//     s.last();
//     s.pop();
//     s.last();
    

// }








//Using Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    

    Node(int data){
        this->data = data;
        this->next=nullptr;
    }
};

class S{
    public:
    int size;
    Node* top;

    S(){
        this->size=0;
        this->top = nullptr;
    }

    
    
    void push(int data){
        Node* newnode = new Node(data);
        newnode->next = top;
        top = newnode;
        size++;
    }

    void pop(){
        if(top==nullptr) return;
        Node* temp = top;
        top=top->next;
        delete temp;
        size--;

    }

    int tops(){
        if(top==nullptr) return -1;

        return top->data;
    }

    

    void print(){
        if(size==0) return;

        Node* temp = top;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }



};

int main(){
    int n;
    cout<<"Enter the size of elements: ";
    cin>>n;
    S s;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        s.push(x);

    }
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    s.pop();
    s.print();
    cout<<endl;
    cout<<s.tops();

}











//valid parenthesis

class Solution {
public:
    bool isValid(string s) {

        stack<char> st;

        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                st.push(s[i]);
            }
            else{
                if(st.empty()) return false;
                char ch = st.top();
                st.pop();
                if((s[i]==')' && ch=='(') || (s[i]==']' && ch=='[') || (s[i]=='}' && ch=='{')){
                    continue;
                }
                else{
                    return false;
                }
            }
        }

        return st.empty();

        
    }
};













//Infix Postfix Prefix






//postfix to infix

// User function Template for C++

class Solution {
  public:
    string postToInfix(string s) {
        // Write your code here
        
        stack<string> st;
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                st.push(string(1,s[i]));
            }
            else{
                if(!st.empty()){
                    string  a = st.top(); st.pop();
                    string  b = st.top(); st.pop();
                    
                    string ans = '(' + b + s[i] + a + ')';
                    st.push(ans);
                    
                }
            }
        }
        
        return st.top();
    }
};



//infix to postfix

// C++ Program to illustrate how to use a stack to convert
// an infix expression to a postfix expression
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check the precedence of operators
int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Function to convert infix expression to postfix
// expression
string infixToPostfix(string infix)
{
    stack<char> st;
    string postfix = "";
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        // If the scanned character is an operand, add it to
        // output string.
        if (isalnum(c))
            postfix += c;

        // If the scanned character is an '(', push it to
        // the stack.
        else if (c == '(')
            st.push('(');

        // If the scanned character is an ')', pop and to
        // output string from the stack until an '(' is
        // encountered.
        else if (c == ')') {
            while (st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }

        // If an operator is scanned
        else {
            while (!st.empty()
                   && precedence(c)
                          <= precedence(st.top())) {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main()
{
    string infix = "A+B*C";
    cout << "Infix Expression: " << infix << endl;
    cout << "Postfix Expression: " << infixToPostfix(infix)
         << endl;
    return 0;
}










//prefix to infix



// User function Template for C++

class Solution {
  public:
    string preToInfix(string s) {
        // Write your code here
        stack<string> st;
        
        for(int i=s.size()-1;i>=0;i--){
            if(isalnum(s[i])){
                st.push(string(1, s[i]));
            }
            else{
                    string t1 = st.top();  st.pop();
                    string t2 = st.top();  st.pop();
                    string ans = '(' + t1 + s[i] + t2 + ')';
                    st.push(ans);
            }
        }
        return st.top();
    }
};





//next greater 1
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        int m = nums1.size();
        stack<int> st;
        vector<int> v(n);
        st.push(nums2[n-1]);
        v[n-1] = -1;
       

        for(int i=n-2;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();

            }
            if(st.empty()){
                v[i] = -1;
            }
            else{
            v[i] = st.top();
            }

            st.push(nums2[i]);
        }

        unordered_map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums2[i]] = v[i];
        }

        vector<int> ans(m);
        for(int i=0;i<m;i++){
            ans[i] = mp[nums1[i]];
        }
    return ans;
    }
};






//Trapping Water

class Solution {
public:
    int leftmax(vector<int>& arr, int n){
        int max = INT_MIN;
        for(int i=0;i<n;i++){
            if(arr[i]>max){
                max = arr[i];
            }
        }
        return max;

    }
    int rightmax(vector<int>& arr, int n){
        int max =  INT_MIN;
        for(int i=arr.size()-1;i>=n;i--){
            if(arr[i]>max){
                max = arr[i];
            }
        }

        return max;


    }
    int trap(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for(int i=0;i<n;i++){
            int left = leftmax(arr,i);
            int right = rightmax(arr,i);

            if(arr[i]<left && arr[i]<right){
                total+= min(right,left)-arr[i];
            }
        }

        return total;
    }

}

//optimal

class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int l=0,r=n-1;
        int rmax=0, lmax=0, total=0;
        while(l<r){
            lmax = max(lmax, arr[l]);
            rmax = max(rmax, arr[r]);

            if(lmax<rmax){
                total += lmax- arr[l];
                l++;
            }
            else{
                total += rmax - arr[r];
                r--;
            }
        }
        return total;
    }
};





//Asteroid 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {
        stack<int> st;

        for (int i = 0; i < arr.size(); ++i) {
            bool destroyed = false;

            while (!st.empty() && arr[i] < 0 && st.top() > 0) {
                if (abs(arr[i]) > st.top()) {
                    st.pop();
                    continue;
                } else if (abs(arr[i]) == st.top()) {
                    st.pop();
                    destroyed = true;
                    break;
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) {
                st.push(arr[i]);
            }
        }

        vector<int> res(st.size());
        for (int i = st.size() - 1; i >= 0; --i) {
            res[i] = st.top();
            st.pop();
        }

        return res;
    }
};



//remove K elements


class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;

        for (int i = 0; i < n; i++) {
      
            while (!st.empty() && k > 0 && st.top() > num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }

        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

      
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());

        int i =0;
        while(i<res.size() && res[i]=='0'){
            i++;
        }

        res = res.substr(i);

        return res.empty() ? "0" : res;



    }
};


