//CoderArmy


//iterative approach
/*
#include<bits/stdc++.h>
using namespace std;
int main(){

for(int i=5;i>0;i--){
    cout<<i<<"days left for birthday"<<endl;
}
cout<<"Happy Birthday";
}
*/


//Recusrive Approach
/*
#include<bits/stdc++.h>
using namespace std;
void fun(int i){
    if(i==0){
        cout<<"Happy Birthday"; 
        return;
    }
    cout<<i<<" Days LEFT"<<endl;
    fun(i-1);
}
int main(){
    fun(5);
}
*/


//print 1 to n

/*#include<bits/stdc++.h>
using namespace std;
void print(int i, int n){
    if(i==n+1) return;
    cout<<i<<endl;
    print(i+1, n);
}
int main(){
    int n;
    cin>>n;
    int i=1;
    print(i,n);
}
*/


//print n to 1
/*
#include<bits/stdc++.h>
using namespace std;
void fun(int i){
    if(i==0) return;
    fun(i-1);
    cout<<i<<endl;;
}
int main(){
    int n;
    cin>>n;
    fun(n);
}
*/




//print even
/*#include<bits/stdc++.h>
using namespace std;
void even(int i, int n){
    if(i==n){
        cout<<i;
        return;
    }
    cout<<i;
    even(i+2, n);
}

int main(){
    int n;
    cin>>n;
    int i=0;
    even(i,n);
}
*/




//factorial

/*
#include<bits/stdc++.h>
using namespace std;
int fact(int n){
    if(n==1) return 1;
    return n*fact(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
}
*/

//Sum of n number
/*#include<bits/stdc++.h>
using namespace std;
int sum(int n){
    if(n==1) return 1;
    return n+ sum(n-1);
}
int main(){
    int n;
    cin>>n;
    cout<<sum(n);
}
 */


//power of 2

/*#include<bits/stdc++.h>
using namespace std;
int pow(int i, int n){
    if(n==0) return 1;
    return i * pow(i,n-1);
}
int main(){
    int i;
    cin>>i;
    int n;
    cin>>n;
    cout<<pow(i, n);
}*/





//sum of sq of n
/*#include <bits/stdc++.h>
using namespace std;

int sqsum(int n) {
    if (n == 1) return 1;          // base case
    return n * n + sqsum(n - 1);   // n² + sum of squares of smaller numbers
}

int main() {
    int n;
    cin >> n;
    cout << sqsum(n);
}
*/





//fibonacci series
/*
#include<bits/stdc++.h>
using namespace std;
int fib(int n){
    if(n==1 || n==0) return 1;
    return fib(n-1) + fib(n-2);
}

int main(){
    int n;
    cin>>n;
    cout<<fib(5);
}


*/





//Nth stairs
/*
class Solution {
public:
    int climbStairs(int n) {
     

         if(n<=1){
            return 1;
        }
        return climbStairs(n-1) + climbStairs(n-2);
    }
};
*/

//GCD OF TWO NUMBER
/*
#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        a = abs(a);
        b = abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};
*/



//Recusion in array


/*
#include<bits/stdc++.h>
using namespace std;
void print(vector<int>& v, int i){
    if(i==v.size()){
        return;
    }
    cout<<v[i]<<" ";
    print(v,i+1);
}
int main(){

    vector<int> v = {1,2,3,4,5,6,7,8,9};
    print(v, 0);
}
*/


//sum of array 

/*
#include<bits/stdc++.h>
using namespace std;
int print(vector<int>& v, int i, int sum){
    if(i==v.size()){
        return sum;
    }
    return print(v,i+1, sum+v[i]);
}
int main(){

    vector<int> v = {1,2,3,4,5,6,7,8,9};
    cout<<print(v, 0, 0);

}*/


/*
#include<bits/stdc++.h>
using namespace std;
int print(vector<int>& v, int i){
    if(i==v.size()){
        return 0;
    }
    return v[i] + print(v,i+1);
}
int main(){

    vector<int> v = {1,2,3,4,5,6,7,8,9};
    cout<<print(v, 0);

}*/



//Find the minimum
/*
#include<bits/stdc++.h>
using namespace std;
int minele(vector<int>& v, int i){
    if(i==v.size()){
        return INT_MAX;
    }

    return min(v[i], minele(v, i+1));
}
int main(){
    vector<int> v = {43,12,55,34,56,};
    cout<<minele(v,0);
}
    */




//-------------Recursion on Strings -----------------------------------

//Check Palindrome

/*#include<bits/stdc++.h>
using namespace std;
bool Palindrome(string s, int i, int j){
    if(i>=j) return 1;

    
    if(s[i]!=s[j]){
        return 0;
    }

    return Palindrome(s,i+1, j-1);
}
int main(){
    string s;
    cin>>s;
    int n = s.size();
    bool ans = Palindrome(s,0,n-1);
    cout<<ans;
}*/



//Count Vowels

/*
#include<bits/stdc++.h>
using namespace std;
int vowel(string s, int i){
    if(i==-1){
        return 0;
    }

    if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
        return 1+vowel(s,i-1);
    }
    else{
    return vowel(s,i-1);
    }
}
int main(){
    string s;
    cin>>s;
    cout<<vowel(s,s.size()-1);
}
*/



/*#include<bits/stdc++.h>
using namespace std;
void reverse(string &s, int i, int j){
    if(i>=j){
        return;
    }

    char c = s[i];
    s[i] = s[j];
    s[j] = c;

    reverse(s,i+1,j-1);

}

int main(){
    string s;
    cin>>s;
    cout<<s;
    cout<<endl;
    reverse(s,0,s.size()-1);
    cout<<s;

}*/




//LOWER TO UPPERCASE
/*
#include<bits/stdc++.h>
using namespace std;
void Upper(string &s, int i){
    if(i==s.size()){
        return;
    }

    s[i] = 'A' + s[i] - 'a';

    Upper(s,i+1);
}
int main(){
    string s;
    cin>>s;
    Upper(s,0);
    cout<<s;
}

*/



//Recursion on Binary Search

/*#include<bits/stdc++.h>
using namespace std;
bool Search(vector<int> v, int i, int t){
    if(i==v.size()){
        return 0;
    }

    if(v[i]==t){
        return 1;
    }
    return Search(v,i+1,t);

}
int main(){
    vector<int> v= {1,4,2,55,6,23,34};
    int target = 3;
    cout<<Search(v, 0, target);
}*/


/*
#include<bits/stdc++.h>
using namespace std;
bool BS(vector<int> v, int s, int e, int t){
    if(s>e){
        return 0;
    }

    int m = s + (e-s)/2;
    if(v[m]==t){
        return 1;
    }
    else if(v[m]>t){
        return BS(v,0,m-1,t);
    }
    else{
       return BS(v,m+1,e,t);
    }
}
int main(){
    vector<int> v={3,8,11,15,20,22};
    int t=5;
    cout<<BS(v,0,v.size()-1,t);
}*/




/*
#include<bits/stdc++.h>
using namespace std;
void merge(vector<int>& v, int s, int m ,int e){
    int l = s;
    int r = m+1;
    vector<int> ans(e-s+1);
    int i=0;
    while(l<=m and r<=e){
        if(v[l]<=v[r]){
            ans[i] = v[l];
            i++;
            l++;
        }
        else{
            ans[i] = v[r];
            r++;
            i++;
        }

      
    }

    while(l<=m){
        ans[i] = v[l];
        i++;
        l++;
    }

    while(r<=e){
        ans[i] = v[r];
        i++;
        r++;
    }

    i=0;
    while(s<=e){
        v[s] = ans[i];
        s++;
        i++;
    }
}
void MS(vector<int>& v, int s, int e){

    if(s>=e) return;
    int m = (s+e)/2;

    MS(v,s,m);
    MS(v,m+1,e);
    merge(v,s,m,e);


    
}
int main(){
    vector<int> v = {3,345534,456,436,455,234,46,56};
    int n = v.size();
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    MS(v,0,n-1);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}
*/








//Subsequence

/*
#include<bits/stdc++.h>
using namespace std;
void SUB(vector<int> v, int i, int n, vector<vector<int>>& ans, vector<int> temp){

    if(i==n){
        ans.push_back(temp);
        return;
    }

    SUB(v,i+1,n,ans,temp);
    temp.push_back(v[i]);
    SUB(v, i+1, n, ans, temp);

}
int main(){
    vector<int> v = {4,5,6};
    vector<vector<int>> ans;
    vector<int> temp;

    SUB(v,0,v.size(),ans, temp);

    cout<<ans.size();
}

*/



//Generate Parenthesis
/*#include<bits/stdc++.h>
using namespace std;
void GP(int n, int left, int right, vector<string>& ans, string& temp){
    if(left+right==2*n){
        ans.push_back(temp);
        return;
    }
    //left parenthesis
    if(left<n){
        temp.push_back('(');
        GP(n, left+1, right, ans, temp);
        temp.pop_back();
    }

    //Right Parenthesis
    if(right<left){
         temp.push_back(')');
        GP(n, left, right+1, ans, temp);
        temp.pop_back();
    }

}
int main(){
    int n;
    cin>>n;
    vector<string> ans;
    string temp;
    GP(n,0,0, ans, temp);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<",";
    }
}
*/



//SUBSET SUM
/*
#include<bits/stdc++.h>
using namespace std;
void print(vector<int> v, int i, int n, int sum, vector<int>& temp, map<int, vector<int>>& ans){

    if(i==n){
        ans[sum] = temp;
        return;
    }

    print(v,i+1,n,sum,temp, ans);
    temp.push_back(v[i]);
    print(v,i+1,n,sum+v[i], temp, ans);
    temp.pop_back();
}
int main(){
    vector<int> v={3,4,5};
    vector<int> temp;
    map<int, vector<int>> ans;
    print(v,0,v.size(),0, temp, ans);
    for(auto it : ans){
        cout<<it.first<<"->";
        for(int x: it.second ){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}
    */








//Target subset sum
/*#include<bits/stdc++.h>
using namespace std;
bool find(vector<int> v, int i, int n, int t){
    if(t==0){
        return 1;
    }
    if(i==n || t<0){
        return 0;
    }

    return find(v, i+1, n, t) || find(v,i+1, n, t-v[i]);
}
int main(){
    
    vector<int> v = {3,6,4,5};
    int target=2;
    cout<<find(v,0, v.size(), target );
}*/



//count the target sum

/*#include<bits/stdc++.h>
using namespace std;
int Count(vector<int>& v, int i, int n, int sum){
    if(i==n){
        return sum==0;
    }

    return Count(v,i+1,n, sum) + Count(v,i+1, n, sum-v[i]);
}
int main(){
    vector<int> v = {2,5,6,1};
    int  target = 8;
    cout<<Count(v, 0, v.size(), target);
}
*/



//Repeation on target sum

/*#include<bits/stdc++.h>
using namespace std;
int rep(vector<int>& v, int i, int n, int sum){
    if(sum==0) return 1;

    if(i==n || sum<0) return 0;


    return rep(v,i+1,n, sum) + rep(v,i,n,sum-v[i]);
}
int main(){
    vector<int> v = {2,3,4};
    int sum = 6;
    cout<<rep(v,0,v.size(),sum);
    
}
*/



//Permutation
/*#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int>& nums, vector<int>& temp, vector<vector<int>>& ans, vector<bool>& visited) {
    if (temp.size() == nums.size()) {   // one permutation completed
        ans.push_back(temp);
        return;
    }

    for (int i = 0; i < nums.size(); i++) {
        if (visited[i]) continue;       // skip already used element

        visited[i] = true;              // choose element
        temp.push_back(nums[i]);

        backtrack(nums, temp, ans, visited);

        temp.pop_back();                // undo choice (backtrack)
        visited[i] = false;
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> ans;
    vector<int> temp;
    vector<bool> visited(nums.size(), false);

    backtrack(nums, temp, ans, visited);

    cout << "All permutations are:\n";
    for (auto& perm : ans) {
        for (int x : perm) cout << x;
        cout << "\n";
    }

    return 0;
}*/



//permutation using swap

/*
#include<bits/stdc++.h>
using namespace std;
void perm(vector<int>& v, vector<vector<int>>& ans, int index){
    if(index == v.size()){
        ans.push_back(v);
        return;
    }

    for(int i=index;i<v.size();i++){
        swap(v[i], v[index]);
        perm(v,ans,index+1);
        swap(v[i], v[index]);
    }
}
int main(){
    vector<int> v = {1,2,3};
    vector<vector<int>> ans;
    vector<int> temp;
    perm(v, ans, 0);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}
*/


//permutation without repeatition

/*#include<bits/stdc++.h>
using namespace std;
void perm(vector<int>& arr, vector<vector<int>>& ans, int index){

    if(index==arr.size()){

        ans.push_back(arr);
        return;

    }
    vector<bool> use(21, 0);

    for(int i=0;i<arr.size();i++){
        

        if(use[arr[i]+10]==0){
        swap(arr[i], arr[index]);
        perm(arr, ans, index+1);
        swap(arr[i], arr[index]);
        use[arr[i]+10] = 1;
        }
    }
}
int main(){

    vector<int> arr = {1,1,2,2};
    vector<vector<int>> ans;
    perm(arr, ans, 0);

    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

    
}*/



//Permutation with sum


/*#include<bits/stdc++.h>
using namespace std;
int psum(vector<int>& v, int n, int sum){
     if(sum==0){
        return 1;
     }
     if(sum<0){
        return 0;
     }

     int ans = 0;
     for(int i=0;i<n;i++){
        ans+= psum(v,n,sum-v[i]);
     }

     return ans;
}
int main(){
    vector<int> v = {1,5,6};
    int sum = 7;
    cout<<psum(v,v.size(), sum);
}*/



//TOI
/*#include<bits/stdc++.h>
using namespace std;
void TOH(int n, int s, int h, int d){
    if(n==1){
        cout<<"move "<<n<<" from "<<s<<" to "<<d<<endl;
        return;
    }

    TOH(n-1,s,d,h);
    cout<<"move "<<n<<" from "<<s<<" to "<<d<<endl;
    TOH(n-1,h,s,d);
}
int main(){
    int n;
    cin>>n;
    TOH(n,1,2,3);
}*/



#include<bits/stdc++.h>
using namespace std;

int n;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};
char dir[] = {'U', 'D', 'L', 'R'};


void solve(vector<vector<int>>& maze, int x, int y, string path, vector<string>& ans, vector<vector<int>>& vis){
    if(x==n-1 && y==n-1){
        ans.push_back(path);
    }

    for(int i=0;i<4;i++){
        int newx = x+dx[i];
        int newy = y+dy[i];

        if(newx>=0 && newy>=0 && newx<n && newy<n && !vis[newx][newy] && maze[newx][newy]==1){
            vis[newx][newy] = 1;
            solve(maze, newx, newy, path+dir[i], ans, vis);
            vis[newx][newy] = 0;

        }
    }
}



int main() {
    vector<vector<int>> maze = {
        {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };

    n = maze.size();
    vector<string> ans;
    vector<vector<int>> vis(n, vector<int>(n, 0));

    if (maze[0][0] == 1) {
        solve(maze, 0, 0, "", ans, vis);
    }

    if (ans.empty()) {
        cout << "No path exists" << endl;
    } else {
        cout << "All possible paths:\n";
        for (string s : ans) cout << s << endl;
    }

    return 0;
}







// #include <bits/stdc++.h>
// using namespace std;

// int n;

// // Directions: Down, Left, Right, Up
// int dx[] = {1, 0, 0, -1};
// int dy[] = {0, -1, 1, 0};
// char dir[] = {'D', 'L', 'R', 'U'};

// void solve(vector<vector<int>> &maze, int x, int y, string path, vector<string> &ans, vector<vector<int>> &vis) {
//     // If destination reached
//     if (x == n - 1 && y == n - 1) {
//         ans.push_back(path);
//         return;
//     }

//     // Try all 4 directions using loop
//     for (int i = 0; i < 4; i++) {
//         int newX = x + dx[i];
//         int newY = y + dy[i];

//         // Check boundaries, not visited, and open path
//         if (newX >= 0 && newY >= 0 && newX < n && newY < n &&
//             !vis[newX][newY] && maze[newX][newY] == 1) {
            
//             vis[x][y] = 1;  // mark visited
//             solve(maze, newX, newY, path + dir[i], ans, vis);
//             vis[x][y] = 0;  // backtrack
//         }
//     }
// }

// int main() {
//     vector<vector<int>> maze = {
//         {1, 0, 0, 0},
//         {1, 1, 0, 1},
//         {0, 1, 0, 0},
//         {1, 1, 1, 1}
//     };

//     n = maze.size();
//     vector<string> ans;
//     vector<vector<int>> vis(n, vector<int>(n, 0));

//     if (maze[0][0] == 1) {
//         solve(maze, 0, 0, "", ans, vis);
//     }

//     if (ans.empty()) {
//         cout << "No path exists" << endl;
//     } else {
//         cout << "All possible paths:\n";
//         for (string s : ans) cout << s << endl;
//     }

//     return 0;
// }












//N QUEEN

class Solution {
public:

    void find(int row, int n, vector<vector<string>>& ans, vector<string>& board, vector<bool>& col, vector<bool>& left,             vector<bool>& right ){
        if(row==n){
            ans.push_back(board);
            return;
        }

        for(int j=0;j<n;j++){
        if(col[j]==0 && left[n-1+j-row]==0 && right [row+j]==0){
            col[j]=1;
            left[n-1+j-row]=1;
            right[j+row] = 1;
            board[row][j] = 'Q';
            find(row+1, n, ans, board, col, left, right);
            col[j]=0;
            board[row][j] = '.';
            left[n-1+j-row] = 0;
            right[j+row] = 0;
        }
        }

        }

      


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i].push_back('.');
            }
        }
        vector<bool> col(n,0);
        vector<bool> left(2*n-1,0);
        vector<bool> right(2*n-1,0);

        find(0, n, ans, board, col, left, right);

        return ans;

    }
};

