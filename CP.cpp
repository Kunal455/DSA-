// //MergeSort
// #include<bits/stdc++.h>
// using namespace std;
// void merge(vector<int>& arr, int low, int mid, int high){
//     int left = low;
//     int right = mid+1;
//     vector<int> temp;

//     while(left<=mid && right<=high){
//         if(arr[left]<=arr[right]){
//             temp.push_back(arr[left]);
//             left++;
//         }
//         else{
//             temp.push_back(arr[right]);
//             right++;
//         }
//     }

//     while(left<=mid){
//         temp.push_back(arr[left]);
//         left++;
//     }

//     while(right<=high){
//         temp.push_back(arr[right]);
//         right++;
//     }

//     for(int i=low; i<=high;i++){
//         arr[i] = temp[i-low];
//     }
// }
// void mergesort(vector<int>& arr, int low, int high){
//     if(low>=high) return;
//     int mid = (low+high)/2;
//     mergesort(arr, low, mid );
//     mergesort(arr, mid+1, high);
//     merge(arr, low, mid, high);
// }

// int main(){
//     int n;
//     cin>>n;

//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         int data;
//         cin>>data;
//         arr[i]=data;
//     }

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     mergesort(arr, 0, n-1);

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }

// }

// //QS
// #include<bits/stdc++.h>
// using namespace std;
// int pivot(vector<int>& arr, int low, int high){
//     int pe = arr[low];
//     int i=low;
//     int j=high;
//     while(i<j){
//         while(arr[i]<=pe && i<high){
//             i++;
//         }
//         while(arr[j]>pe && j>low){
//             j--;
//         }

//         if(i<j){
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[low], arr[j]);
//     return j;
// }
// void QS(vector<int>& arr, int low, int high){
//     if(low>=high) return;

//     int pe = pivot(arr, low, high);
//     QS(arr, low, pe-1);
//     QS(arr, pe+1, high);
// }
// int main(){
//     int n;
//     cin>>n;

//     vector<int> arr(n);
//     for(int i=0;i<n;i++){
//         int data;
//         cin>>data;
//         arr[i]=data;
//     }

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }
//     cout<<endl;
//     QS(arr, 0, n-1);

//     for(int i=0;i<n;i++){
//         cout<<arr[i]<<" ";
//     }

// }

// sort by frequency
#include <bits/stdc++.h>
using namespace std;

// Global frequency map
unordered_map<int, int> freq;

// Comparator function
// bool cmp(int a, int b) {
//     if (freq[a] != freq[b])
//         return freq[a] > freq[b];   // higher frequency first
//     return a < b;                   // smaller value first
// }

// int main() {
//     int n;
//     cin >> n;

//     vector<int> arr(n);
//     for (int i = 0; i < n; i++) {
//         cin >> arr[i];
//         freq[arr[i]]++;   // count frequency
//     }

//     // Sort using cmp function
//     sort(arr.begin(), arr.end(), cmp);

//     // Output
//     for (int x : arr) {
//         cout << x << " ";
//     }

//     return 0;
// }

// Finding Minimum Length Sorted Sub-array to Sort an Array

// If an array is already sorted → answer is 0.

// Otherwise:

// Find where order breaks from left

// Find where order breaks from right

// Find min & max in this unsorted range

// Extend boundaries if needed

// vector<int> arr = {1, 3, 5, 4, 2, 6, 7};
// #include <bits/stdc++.h>
// using namespace std;

// int minLengthSubarray(vector<int>& arr) {
//     int n = arr.size();
//     int start = -1, end = -1;

//     // Step 1: find start
//     for (int i = 0; i < n - 1; i++) {
//         if (arr[i] > arr[i + 1]) {
//             start = i;
//             break;
//         }
//     }

//     // Already sorted
//     if (start == -1)
//         return 0;

//     // Step 2: find end
//     for (int i = n - 1; i > 0; i--) {
//         if (arr[i] < arr[i - 1]) {
//             end = i;
//             break;
//         }
//     }

//     // Step 3: find min & max in subarray
//     int subMin = INT_MAX, subMax = INT_MIN;
//     for (int i = start; i <= end; i++) {
//         subMin = min(subMin, arr[i]);
//         subMax = max(subMax, arr[i]);
//     }

//     // Step 4: extend start
//     while (start > 0 && arr[start - 1] > subMin)
//         start--;

//     // Step 5: extend end
//     while (end < n - 1 && arr[end + 1] < subMax)
//         end++;

//     return end - start + 1;
// }

// int main() {
//     vector<int> arr = {1, 3, 5, 4, 2, 6, 7};
//     cout << minLengthSubarray(arr);
//     return 0;
// }

// Sorting Strings
// 1. lexicographical
//  Strings are compared character by character using ASCII values.

// 'A' < 'a'

// 'apple' < 'banana'
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     vector<string> arr(n);
//     for(int i = 0; i < n; i++) {
//         cin >> arr[i];
//     }

//     sort(arr.begin(), arr.end());   // lexicographical sort

//     for(string s : arr) {
//         cout << s << " ";
//     }
// }

// Sorting Strings by Length
// 🔹 Rule

// Shorter strings come first

// If lengths are equal → lexicographical order

// bool cmp(string a, string b) {
//     if(a.length() != b.length())
//         return a.length() < b.length();  // shorter first
//     return a < b;                        // lexicographical
// }

// int main() {
//     vector<string> arr = {"apple", "bat", "cat", "banana"};
//     sort(arr.begin(), arr.end(), cmp);

//     for(string s : arr)
//         cout << s << " ";
// }

// 3️⃣ Case-Insensitive String Sorting
// 🔹 Meaning

// Ignore case (Apple = apple)

// Q.Case-Specific Sorting of Strings
// 📌 Problem Statement

// Given a string, sort the characters such that:

// Lowercase letters remain in lowercase positions

// Uppercase letters remain in uppercase positions

// Sorting happens independently within each case

// Approach (Step-by-Step)

// Traverse the string

// Store lowercase characters separately

// Store uppercase characters separately

// Sort both lists independently

// Traverse original string again

// If character is lowercase → pick next from lowercase list

// If character is uppercase → pick next from uppercase list

// s = "dAeBc"
// #include <bits/stdc++.h>
// using namespace std;

// string caseSpecificSort(string s) {
//     vector<char> lower, upper;

//     // Step 1: Separate characters
//     for(char c : s) {
//         if(islower(c))
//             lower.push_back(c);
//         else
//             upper.push_back(c);
//     }

//     // Step 2: Sort separately
//     sort(lower.begin(), lower.end());
//     sort(upper.begin(), upper.end());

//     // Step 3: Rebuild string
//     int l = 0, u = 0;
//     for(int i = 0; i < s.length(); i++) {
//         if(islower(s[i]))
//             s[i] = lower[l++];
//         else
//             s[i] = upper[u++];
//     }

//     return s;
// }

// int main() {
//     string s;
//     cin >> s;
//     cout << caseSpecificSort(s);
//     return 0;
// }

// 🔢 Count Distinct Pairs with Difference = K
//  arr = {1, 5, 3, 4, 2}
//  k = 2
//  #include <bits/stdc++.h>
//  using namespace std;

// int countPairs(vector<int>& arr, int k) {
//     int n = arr.size();
//     sort(arr.begin(), arr.end());

//     int i = 0, j = 1;
//     int count = 0;

//     while (j < n) {
//         int diff = arr[j] - arr[i];

//         if (diff == k) {
//             count++;

//             int a = arr[i], b = arr[j];
//             while (i < n && arr[i] == a) i++;   // skip duplicates
//             while (j < n && arr[j] == b) j++;
//         }
//         else if (diff < k) {
//             j++;
//         }
//         else {
//             i++;
//         }

//         if (i == j) j++;
//     }

//     return count;
// }

// int main() {
//     vector<int> arr = {1, 5, 3, 4, 2};
//     int k = 2;
//     cout << countPairs(arr, k);
//     return 0;
// }

// #binomial coeeficient
//  #include<bits/stdc++.h>
//  using namespace std;
//  int ncr(int n, int r){
//      if(r==0 || r==n) return 1;

//     return ncr(n-1, r-1) + ncr(n-1, r);
// }
// int main(){
//     int n;
//     cin>>n;
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<ncr(i,j)<<" ";
//         }
//         cout<<endl;
//     }
// }

// memoi
//  #include<bits/stdc++.h>
//  using namespace std;
//  int ncr(int n, int r, vector<vector<int>>& dp){
//      if(r==0 || r==n) return 1;
//      if(dp[n][r]!=-1) return dp[n][r];

//     return dp[n][r] = ncr(n-1, r-1, dp) + ncr(n-1, r, dp);
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=i;j++){
//             cout<<ncr(i,j, dp)<<" ";
//         }
//         cout<<endl;
//     }

// }

#include <bits/stdc++.h>
using namespace std;

int nCr(int n, int r, vector<vector<int>>& dp) {
    // Base cases
    if (r == 0 || r == n)
        return 1;

    // If already computed
    if (dp[n][r] != -1)
        return dp[n][r];

    // Recurrence relation
    return dp[n][r] = nCr(n - 1, r - 1, dp) + nCr(n - 1, r, dp);
}

int main() {
    int n, r;
    cin >> n >> r;

    vector<vector<int>> dp(n + 1, vector<int>(r + 1, -1));

    cout << nCr(n, r, dp);
}


// Tabulation
//  #include<bits/stdc++.h>
//  using namespace std;
//  int main(){
//      int n;
//      cin>>n;

//     int r;
//     cin>>r;
//     vector<vector<int>> dp(n+1, vector<int> (n+1, -1));
//     for(int i=0;i<=n;i++){
//         for(int j=0;j<=min(i,r);j++){
//             if(j==0 || j==i) dp[i][j]=1;
//             else
//             dp[i][j] = dp[i-1][j-1]+dp[i-1][j];

//         }
//     }

//     cout<<dp[n][r];
// }


//knapsack

// #include<bits/stdc++.h>
// using namespace std;
// int solve(vector<int> wt, vector<int> value, int w, int i){
//     if(i==0){
//         if(wt[0]<=w){
//             return value[0];
//         }
//         else{
//             return 0;
//         }
//     }

//     int ntake = 0 + solve(wt, value, w, i-1);
//     int take = INT_MIN;
//     if(wt[i]<=w){
//         take = value[i] + solve(wt, value, w-wt[i], i-1);
//     }

//     return max(ntake, take);

// }
// int main(){
//     int n;
//     cin>>n;
//     int w;
//     cin>>w;
//     vector<int> wt(n), value(n);
//     for(int i=0;i<n;i++){
//         int data;
//         cin>>data;
//         wt[i] = data;
//     }

//     for(int i=0;i<n;i++){
//         int data;
//         cin>>data;
//         value[i] = data;
//     }

//     cout<<solve(wt, value, w, n-1);

// }

// memoi
//  #include <bits/stdc++.h>
//  using namespace std;

// int solve(vector<int>& wt, vector<int>& val, int w, int i,
//           vector<vector<int>>& dp) {

//     if (i == 0) {
//         if (wt[0] <= w)
//             return val[0];
//         else
//             return 0;
//     }

//     if (dp[i][w] != -1)
//         return dp[i][w];

//     int notTake = solve(wt, val, w, i - 1, dp);
//     int take = INT_MIN;

//     if (wt[i] <= w) {
//         take = val[i] + solve(wt, val, w - wt[i], i - 1, dp);
//     }

//     return dp[i][w] = max(notTake, take);
// }

// int main() {
//     int n, w;
//     cin >> n >> w;

//     vector<int> wt(n), val(n);
//     for (int i = 0; i < n; i++) cin >> wt[i];
//     for (int i = 0; i < n; i++) cin >> val[i];

//     vector<vector<int>> dp(n, vector<int>(w + 1, -1));

//     cout << solve(wt, val, w, n - 1, dp);
// }

// //Tabu
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n, W;
//     cin >> n >> W;

//     vector<int> wt(n), val(n);
//     for (int i = 0; i < n; i++) cin >> wt[i];
//     for (int i = 0; i < n; i++) cin >> val[i];

//     vector<vector<int>> dp(n, vector<int>(W + 1, 0));

//     // Base case: first item
//     for (int w = wt[0]; w <= W; w++) {
//         dp[0][w] = val[0];
//     }

//     // Fill DP table
//     for (int i = 1; i < n; i++) {
//         for (int w = 0; w <= W; w++) {
//             int notTake = dp[i - 1][w];
//             int take = INT_MIN;

//             if (wt[i] <= w)
//                 take = val[i] + dp[i - 1][w - wt[i]];

//             dp[i][w] = max(notTake, take);
//         }
//     }

//     cout << dp[n - 1][W];
// }

// //edit distance
// int solve(string &s1, string &s2, int i, int j) {
//     if (i == 0) return j;
//     if (j == 0) return i;

//     if (s1[i - 1] == s2[j - 1])
//         return solve(s1, s2, i - 1, j - 1);

//     return 1 + min({
//         solve(s1, s2, i - 1, j),     // delete
//         solve(s1, s2, i, j - 1),     // insert
//         solve(s1, s2, i - 1, j - 1)  // replace
//     });
// }

// //memo
// #include <bits/stdc++.h>
// using namespace std;

// int solve(string &s1, string &s2, int i, int j,
//           vector<vector<int>>& dp) {

//     if (i == 0) return j;
//     if (j == 0) return i;

//     if (dp[i][j] != -1)
//         return dp[i][j];

//     if (s1[i - 1] == s2[j - 1])
//         return dp[i][j] = solve(s1, s2, i - 1, j - 1, dp);

//     return dp[i][j] = 1 + min({
//         solve(s1, s2, i - 1, j, dp),     // delete
//         solve(s1, s2, i, j - 1, dp),     // insert
//         solve(s1, s2, i - 1, j - 1, dp)  // replace
//     });
// }

// int main() {
//     string s1, s2;
//     cin >> s1 >> s2;

//     int n = s1.size(), m = s2.size();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

//     cout << solve(s1, s2, n, m, dp);
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     string s1, s2;
//     cin >> s1 >> s2;

//     int n = s1.size(), m = s2.size();
//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

//     // Base cases
//     for (int i = 0; i <= n; i++) dp[i][0] = i;
//     for (int j = 0; j <= m; j++) dp[0][j] = j;

//     // Fill DP table
//     for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (s1[i - 1] == s2[j - 1])
//                 dp[i][j] = dp[i - 1][j - 1];
//             else
//                 dp[i][j] = 1 + min({
//                     dp[i - 1][j],     // delete
//                     dp[i][j - 1],     // insert
//                     dp[i - 1][j - 1]  // replace
//                 });
//         }
//     }

//     cout << dp[n][m];
// }

// Longest Common Subsequence (LCS)

// #include<bits/stdc++.h>
// using namespace std;
// int solve(string s1, string s2, int i, int j){
//     if(i==0 || j==0) return 0;

//     if(s1[i-1]==s2[j-1]) return 1 + solve(s1,s2,i-1,j-1);
//     return max(solve(s1,s2,i-1,j), solve(s1,s2,i,j-1));
// }
// int main(){
//     string s1;
//     cin>>s1;
//     string s2;
//     cin>>s2;

//     cout<<solve(s1, s2, s1.size(), s2.size());
// }

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     string s1;
//     cin>>s1;
//     string s2;
//     cin>>s2;

//     vector<vector<int>> dp(s1.size()+1, vector<int> (s1.size()+1, 0));

//      for (int i = 1; i <= n; i++) {
//         for (int j = 1; j <= m; j++) {
//             if (s1[i - 1] == s2[j - 1])
//                 dp[i][j] = 1 + dp[i - 1][j - 1];
//             else
//                 dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
//         }
//     }

//     cout << dp[n][m];
// }

// LIS
//  #include<bits/stdc++.h>
//  using namespace std;
//  int solve(vector<int> a, int i, int p){
//      if(i==a.size()) return 0;

//     int ntake = solve(a, i+1, p);

//     int take = INT_MIN;
//     if(p==-1 || a[i]>a[p]){
//         take = 1+solve(a, i+1, i);
//     }
//     return max(take, ntake);

// }
// int main(){
//     vector<int> a = {1,5,3,8,5,9};

//     cout<<solve(a, 0, -1);
// }

// //memo
// #include <bits/stdc++.h>
// using namespace std;

// int solve(int i, int prev, vector<int>& arr,
//           vector<vector<int>>& dp) {

//     if (i == arr.size())
//         return 0;

//     if (dp[i][prev + 1] != -1)
//         return dp[i][prev + 1];

//     int notTake = solve(i + 1, prev, arr, dp);
//     int take = 0;

//     if (prev == -1 || arr[i] > arr[prev]) {
//         take = 1 + solve(i + 1, i, arr, dp);
//     }

//     return dp[i][prev + 1] = max(take, notTake);
// }

// int main() {
//     vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
//     int n = arr.size();

//     vector<vector<int>> dp(n, vector<int>(n + 1, -1));
//     cout << solve(0, -1, arr, dp);
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
//     int n = arr.size();

//     vector<int> dp(n, 1);

//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < i; j++) {
//             if (arr[i] > arr[j]) {
//                 dp[i] = max(dp[i], dp[j] + 1);
//             }
//         }
//     }

//     cout << *max_element(dp.begin(), dp.end());
// }
// arr = {10, 9, 2, 5, 3, 7, 101, 18}
// n = 8

// //
// bool subsetSum(int i, int sum, vector<int>& arr) {
//     if (sum == 0) return true;
//     if (i == 0) return arr[0] == sum;

//     bool notTake = subsetSum(i - 1, sum, arr);
//     bool take = false;
//     if (arr[i] <= sum)
//         take = subsetSum(i - 1, sum - arr[i], arr);

//     return take || notTake;
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr = {1, 6, 11, 5};
//     int total = accumulate(arr.begin(), arr.end(), 0);

//     vector<bool> dp(total + 1, false);
//     dp[0] = true;

//     for (int x : arr) {
//         for (int s = total; s >= x; s--) {
//             dp[s] = dp[s] || dp[s - x];
//         }
//     }

//     int ans = INT_MAX;
//     for (int s1 = 0; s1 <= total / 2; s1++) {
//         if (dp[s1]) {
//             ans = min(ans, abs(total - 2 * s1));
//         }
//     }

//     cout << ans;
// }

// #include <bits/stdc++.h>
// using namespace std;

// bool solve(int i, int sum, vector<int>& arr,
//            vector<vector<int>>& dp) {

//     if (sum == 0) return true;
//     if (i == 0) return arr[0] == sum;

//     if (dp[i][sum] != -1)
//         return dp[i][sum];

//     bool notTake = solve(i - 1, sum, arr, dp);
//     bool take = false;

//     if (arr[i] <= sum)
//         take = solve(i - 1, sum - arr[i], arr, dp);

//     return dp[i][sum] = take || notTake;
// }

// int main() {
//     vector<int> arr = {1, 5, 11, 5};

//     int total = accumulate(arr.begin(), arr.end(), 0);

//     // If total sum is odd, equal partition not possible
//     if (total % 2 != 0) {
//         cout << "false";
//         return 0;
//     }

//     int target = total / 2;
//     int n = arr.size();

//     vector<vector<int>> dp(n, vector<int>(target + 1, -1));

//     cout << (solve(n - 1, target, arr, dp) ? "true" : "false");
// }

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     vector<int> arr = {1, 5, 11, 5};
//     int total = accumulate(arr.begin(), arr.end(), 0);

//     if (total % 2 != 0) {
//         cout << "false";
//         return 0;
//     }

//     int target = total / 2;
//     vector<bool> dp(target + 1, false);
//     dp[0] = true;

//     for (int x : arr) {
//         for (int s = target; s >= x; s--) {
//             dp[s] = dp[s] || dp[s - x];
//         }
//     }

//     cout << (dp[target] ? "true" : "false");
// }
// // //partition array into two equal product subsets
// // /*#include<bits/stdc++.h>
// // using namespace std;
// // bool fun(int i, int p1, int p2, int t, vector<int>& v){
// //     if(p1>t || p2>t) return false;

// //     if(i==v.size()) return p1==t && p2==t;

// //     bool a = fun(i+1, p1*v[i], p2, t, v);
// //     bool b = fun(i+1, p1, p2*v[i], t, v);

// //     return a || b;

// // }
// // int main(){
// //     int n;
// //     cin>>n;
// //     vector<int> v(n);
// //     for(int i=0;i<n;i++){
// //         cin>>v[i];
// //     }
// //     int target;
// //     cin>>target;

// //     bool ans = fun(0,1,1,target, v);
// //     cout<<ans;
// // }*/

// // //next happy Number
// // class Solution {
// //   public:
// //     bool solve(int n){
// //         if(n==1 || n==7) return true;
// //         if(n<10) return false;
// //         int sum = 0;
// //         while(n){
// //             int r = n%10;
// //             sum+=(r*r);
// //             n/=10;
// //         }
// //         return solve(sum);
// //     }
// //     int nextHappy(int N) {
// //         // code here
// //         while(true){
// //             N++;
// //             if(solve(N)) return N;
// //         }
// //     }
// // };

// // //different ways to add parenthesis

// // class Solution {
// // public:
// //     vector<int> diffWaysToCompute(string expression) {
// //         int n = expression.size();
// //         vector<int> res;
// //         for(int i=0;i<expression.length();i++){
// //             if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*'){
// //                 vector<int> left = diffWaysToCompute(expression.substr(0,i));
// //                 vector<int> right = diffWaysToCompute(expression.substr(i+1));
// //                 for(int x:left){
// //                     for(int y:right){
// //                         if(expression[i]=='+') res.push_back(x+y);
// //                         if(expression[i]=='-') res.push_back(x-y);
// //                         if(expression[i]=='*') res.push_back(x*y);
// //                     }
// //                 }
// //             }
// //         }
// //         if(res.empty()) res.push_back(stoi(expression));
// //         return res;
// //     }
// // };

// // //add string

// // class Solution {
// // public:
// //     string addStrings(string num1, string num2) {
// //         string res = "";
// //         int carry = 0;
// //         int i = num1.length()-1;
// //         int j = num2.length()-1;
// //         while(i>=0 || j>=0|| carry){
// //             int sum = carry;
// //             if(i>=0) sum+=num1[i--] - '0';
// //             if(j>=0) sum+=num2[j--] - '0';
// //             res+=(sum%10) + '0';
// //             carry = sum/10;
// //         }
// //         reverse(res.begin(), res.end());
// //         return res;
// //     }
// // };

// // //water overflow
// // class Solution {
// //   public:
// //     double waterOverflow(int K, int R, int C) {
// //         // code here
// //         vector<vector<double>> a(K+1, vector<double> (K+1, 0));
// //         a[0][0] = K;
// //         for(int i=0;i<R;i++){
// //             for(int j=0;j<=i;j++){
// //                 if(a[i][j]>1){
// //                     double extra = a[i][j] - 1;
// //                     a[i][j] = 1;
// //                     a[i+1][j]+= extra/2;
// //                     a[i+1][j+1] += extra/2;
// //                 }
// //             }
// //         }
// //         return a[R-1][C-1];
// //     }
// // };

// // //generate binary string

// // class Solution {
// //   public:
// //     void fun(int n, vector<string>& ans, string& s){
// //         if(n<1) ans.push_back(s);
// //         else{
// //             s[n-1] = '0';
// //             fun(n-1, ans, s);
// //             s[n-1] = '1';
// //             fun(n-1, ans, s);
// //         }
// //     }
// //     vector<string> binstr(int n) {
// //         // code here
// //         vector<string> ans;
// //         string s(n, '\0');
// //         fun(n, ans, s);
// //         sort(ans.begin(), ans.end());
// //         return ans;
// //     }
// // };

// // //

// // //generate binary with nonadjecent
// // class Solution {
// // public:
// //     void fun(int n, int f, vector<string>& ans, string& s){
// //         if(n<0){
// //             ans.push_back(s);
// //             return;
// //         }
// //         else{
// //             s[n-1] = '1';
// //             fun(n-1, 1, ans, s);
// //             if(f==1){
// //                 s[n-1] = '0';
// //                 fun(n-1, 0, ans, s);
// //             }
// //         }
// //     }
// //     vector<string> validStrings(int n) {
// //         vector<string> ans;
// //         string s(n, '\0');
// //         fun(n, 1 , ans, s);
// //         return ans;
// //     }
// // };

// // //subsets
// // class Solution {
// // public:
// //     void solve(int i, vector<int>& nums, vector<vector<int>>& ans, vector<int> arr){
// //             if(i==nums.size()){
// //                 ans.push_back(arr);
// //                 return;
// //             }

// //             solve(i+1, nums, ans, arr);
// //             arr.push_back(nums[i]);
// //             solve(i+1, nums, ans, arr);
// //             arr.pop_back();

// //     }
// //     vector<vector<int>> subsets(vector<int>& nums) {
// //         vector<vector<int>> ans;
// //         vector<int> arr;
// //         solve(0, nums, ans, arr );
// //         return ans;
// //     }
// // };

// // //n queen
// // class Solution {
// // public:
// //     bool check(int n,vector<string>& board, int row, int col){
// //         int row = i;
// //         int col = j;
// //         while(row>-1 &&  col>-1){
// //             if(board[row][col]=='Q'){
// //                 return 0;
// //             }
// //                 row--, col--;
// //         }
// //         row = i;
// //         col = j;
// //         while(row>-1 && col<n){
// //             if(board[row][col]=='Q'){
// //                 return 0;
// //             }
// //                 row--;
// //                 col++;
// //         }
// //         return true;
// //     }
// //     void find(int row, int n, vector<string>& board,vector<vector<string>>& ans, vector<bool>& col)
// // {
// //     if(row==n){
// //         ans.push_back(board);
// //         return;
// //     }

// //     for(int j=0;j<n;j++){
// //         if(col[j]==0 && check(n, board, row, j)){
// //             col[j]=1;
// //             board[row][j] = 'Q';
// //             find(row+1, n, board, ans, col);
// //             col[j]=0;
// //             board[row][j]='.';
// //         }

// //     }
// // }

// //     vector<vector<string>> solveNQueens(int n) {
// //         vector<vector<string>> ans;
// //         vector<string> board(n);
// //         for(int i=0;i<n;i++){
// //             for(int j=0;j<n;j++){
// //                 board[i].push_back('.');
// //             }
// //         }
// //         vector<bool> col(n);

// //         find(0, n, board, ans, col);
// //         return ans;
// //     }
// // };

// #include<bits/stdc++.h>
// using namespace std;
// bool isSafe(int row, int col, int n, vector<string>& board){
//     //col check
//     for(int i=0;i<row;i++){
//         if(board[i][col]=='Q'){
//             return false;
//         }
//     }

//     //left dig

//     for(int i=row,j=col;i>=0&&j>=0;i--,j--){
//         if(board[i][j]=='Q'){
//             return false;
//         }
//     }

//     //right dig
//     for(int i=row,j=col;i>=0&&j<n;i--,j++){
//         if(board[i][j]=='Q'){
//             return false;
//         }
//     }

//     return true;
// }
// void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans){
//     if(row==n){
//         ans.push_back(board);
//         return;
//     }

//     for(int j=0;j<n;j++){
//         if(isSafe(row, j, n, board)){
//             board[row][j] = 'Q';
//             solve(row+1, n, board, ans);
//             board[row][j] = '.';
//         }
//     }
// }
// int main(){
//     int n;
//     cin>>n;

//     vector<vector<string>> ans;
//     vector<string> board(n, string(n, '.'));

//     solve(0, n, board, ans);

//     for(auto &solution : ans){
//     for(auto &row : solution){
//         cout << row << endl;
//     }
//     cout << endl;
// }

// }

// Rat in a Maze
//  // #include<bits/stdc++.h>
//  // using namespace std;
//  // void helper(vector<vector<int>>& mat, int r, int c, string path, vector<string>& ans){
//  //     int n = mat.size();
//  //     if(r < 0 || c < 0 || r >= n || c >= n || mat[r][c] == 0 || mat[r][c] == -1)
//  // {
//  //         return;
//  //     }

// //     if(r==n-1 && c==n-1){
// //         ans.push_back(path);
// //         return;
// //     }

// //     mat[r][c]=-1;
// //     helper(mat, r+1, c, path+'D',ans );
// //     helper(mat, r, c+1, path+'R',ans );
// //     helper(mat, r-1, c, path+'U',ans );
// //     helper(mat, r, c-1, path+'L',ans );

// //     mat[r][c]=1;
// // }
// // vector<string> findpath(vector<vector<int>>& mat){
// //     string path="";
// //     vector<string> ans;
// //     helper(mat, 0, 0, path, ans);

// //     return ans;
// // }
// // int main(){
// //     int r;
// //     int c;
// //     cin>>r;
// //     cin>>c;

// //     vector<vector<int>> mat;

// //     for(int i=0;i<r;i++){
// //         vector<int> d;
// //         for(int j=0;j<c;j++){
// //             int data;
// //             cin>>data;
// //             d.push_back(data);
// //         }
// //         mat.push_back(d);
// //     }

// //     for(int i=0;i<r;i++){
// //         for(int j=0;j<c;j++){
// //             cout<<mat[i][j];
// //         }
// //         cout<<endl;
// //     }

// //     vector<string> ans = findpath(mat);

// //     for(string path: ans){
// //         cout<<path<<endl;
// //     }

// // }

// #include<bits/stdc++.h>
// using namespace std;

// void solve(int r, int c, vector<vector<int>>& mat, vector<string>& ans, string path){
//     int n = mat.size();

//     if( r<0 || c<0 || r>=n || c>=n || mat[r][c]==0 || mat[r][c]==-1 ) return;
//     if(r == n-1 && c == n-1){
//     ans.push_back(path);
//     return;
// }

//     mat[r][c] = -1;

//     solve(r+1, c, mat, ans, path+"D");
//     solve(r, c+1, mat, ans, path+"R");
//     solve(r-1, c, mat, ans, path+"U");
//     solve(r, c-1, mat, ans, path+"L");

//     mat[r][c] = 1;

// }
// int main(){
//     int r,c;
//     cin>>r;
//     cin>>c;
//     vector<vector<int>> mat;
//     for(int i=0;i<r;i++){
//         vector<int> d;
//         for(int j=0;j<c;j++){
//             int data;
//             cin>>data;
//             d.push_back(data);

//         }
//         mat.push_back(d);
//     }

//     string path = "";
//     vector<string> ans;
//     if(mat[0][0] == 1)
//         solve(0, 0, mat, ans, path);

//     for(auto x: ans){
//         cout<<x<<endl;
//     }
// }

// //sudoku
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     bool isSafe(vector<vector<char>>& board, int row, int col, char dig) {
//         for(int i = 0; i < 9; i++) {
//             if(board[row][i] == dig) return false;
//             if(board[i][col] == dig) return false;
//         }

//         int srow = (row / 3) * 3;
//         int scol = (col / 3) * 3;

//         for(int i = srow; i < srow + 3; i++) {
//             for(int j = scol; j < scol + 3; j++) {
//                 if(board[i][j] == dig) return false;
//             }
//         }
//         return true;
//     }

//     bool helper(vector<vector<char>>& board, int row, int col) {
//         if(row == 9) return true;

//         int nextRow = row;
//         int nextCol = col + 1;
//         if(nextCol == 9) {
//             nextRow = row + 1;
//             nextCol = 0;
//         }

//         if(board[row][col] != '.') {
//             return helper(board, nextRow, nextCol);
//         }

//         for(char dig = '1'; dig <= '9'; dig++) {
//             if(isSafe(board, row, col, dig)) {
//                 board[row][col] = dig;
//                 if(helper(board, nextRow, nextCol))
//                     return true;
//                 board[row][col] = '.'; // backtrack
//             }
//         }
//         return false;
//     }

//     void solveSudoku(vector<vector<char>>& board) {
//         helper(board, 0, 0);
//     }
// };

// int main() {
//     vector<vector<char>> board(9, vector<char>(9));

//     cout << "Enter the Sudoku board (use . for empty cells):\n";
//     for(int i = 0; i < 9; i++) {
//         for(int j = 0; j < 9; j++) {
//             cin >> board[i][j];
//         }
//     }

//     Solution obj;
//     obj.solveSudoku(board);

//     cout << "\nSolved Sudoku:\n";
//     for(int i = 0; i < 9; i++) {
//         for(int j = 0; j < 9; j++) {
//             cout << board[i][j] << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }

// //word search
// #include <bits/stdc++.h>
// using namespace std;

// bool dfs(int i, int j, vector<vector<char>>& board, int idx, string& word) {
//     if (idx == word.length())
//         return true;

//     if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size()
//         || board[i][j] != word[idx])
//         return false;

//     char temp = board[i][j];
//     board[i][j] = '#';  // mark visited

//     bool found =
//         dfs(i + 1, j, board, idx + 1, word) ||
//         dfs(i - 1, j, board, idx + 1, word) ||
//         dfs(i, j + 1, board, idx + 1, word) ||
//         dfs(i, j - 1, board, idx + 1, word);

//     board[i][j] = temp; // backtrack
//     return found;
// }

// int main() {
//     int m, n;
//     cin >> m >> n;

//     vector<vector<char>> board(m, vector<char>(n));

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> board[i][j];
//         }
//     }

//     string word;
//     cin >> word;

//     bool exists = false;

//     for (int i = 0; i < m; i++) {
//         for (int j = 0; j < n; j++) {
//             if (dfs(i, j, board, 0, word)) {
//                 exists = true;
//                 break;
//             }
//         }
//         if (exists) break;
//     }

//     if (exists)
//         cout << "true\n";
//     else
//         cout << "false\n";

//     return 0;
// }

// #include<bits/stdc++.h>
// using namespace std;
// int gcd(int n, int m){
//     if(m==0) return n;
//     return gcd(m, n%m);
// }
// int main(){
//     int n;
//     cin>>n;
//     int m;
//     cin>>m;
//     cout<<gcd(abs(n),abs(m));
// }

// #include<bits/stdc++.h>
// using namespace std;
// int sum(int n){
//     if(n==0) return 0;

//     return n+sum(n-1);
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<sum(n);
// }

// #include<bits/stdc++.h>
// using namespace std;
// int fact(int n){
//     if(n==0 || n==1) return 1;

//     return n*fact(n-1);
// }
// int main(){
//     int n;
//     cin>>n;

//     cout<<fact(n);
// }

/*#include<bits/stdc++.h>
using namespace std;
int fun(int n, int x){
    if(n==1 && x==1) return 0;

    if(n>x) return 1+fun(n-x, x);
    else return 1+fun(n, x-n);
}
int main(){
    int n;
    cin>>n;

    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        if(__gcd(n,i)!=1) continue;
        ans = min(ans, fun(n, i));
    }

    cout<<ans;
}*/

// #include<bits/stdc++.h>
// using namespace std;
// bool check(int n){
//     if(n==1 || n==7) return true;
//     if(n<10) return false;
//     int sum = 0;
//     while(n){
//         int r = n%10;
//         sum+= r*r;
//         n/=10;
//     }

//     return check(sum);
// }
// int main(){
//     int n;
//     cin>>n;

//     cout<<check(n);
// }

// #include<bits/stdc++.h>
// using namespace std;
// bool isprime(int n){
//     if(n<=1) return false;
//     if(n<=3) return true;
//     if(n%2==0 || n%3==0) return false;
//     for(int i=5;i*i<=n;i+=6){
//         if(n%i==0 || n%(i+2)==0) return false;
//     }

//     return true;
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<isprime(n);
// }

// #include<bits/stdc++.h>
// using namespace std;
// bool isPrime(int n){
//     if(n<=1) return false;
//     if(n<=3) return true;
//     if(n%2==0 || n%3==0) return false;
//     for(int i=5;i*i<=n;i+=6){
//         if(n%i==0 || n%(i+2)==0){
//             return false;
//         }
//     }
//     return true;
//     }

// int main(){
//     int n;
//     cin>>n;

//     cout<<isPrime(n);
// }

// #include<bits/stdc++.h>
// using namespace std;
// bool isPrime(int n){
//     if(n<=1) return false;
//     if(n<=3) return true;
//     if(n%2==0 || n%3==0) return false;
//     for(int i=5;i*i<=n;i+=6){
//         if(n%i==0||n%(i+2)==0) return false;
//     }

//     return true;
// }
// int main(){
//     int n;
//     cin>>n;
//     vector<int> v(n);
//     for(int i=0;i<n;i++){
//         int data;
//         cin>>data;
//         v[i] = data;
//     }
//     int min = 0;
//     for(int i=0;i<n;i++){
//         if(isPrime(v[i])){
//         min=i;
//         break;
//         }
//     }
//     int max = 0;
//     for(int j=n-1;j>=0;j--){
//         if(isPrime(v[j])){
//         max=j;
//         break;
//         }
//     }

//     cout<<abs(max-min);
// }

// check prime
//  #include<bits/stdc++.h>
//  using namespace std;
//  bool isPrime(int n){
//      if(n<=1) return false;
//      if(n<=3) return true;
//      if(n%2==0 || n%3==0) return false;
//      for(int i=5;i*i<=n;i+=6){
//          if(n%i==0 || n%(i+2)==0) return false;
//      }

//     return true;
// }
// int main(){
//     int n;
//     cin>>n;
//     bool ans = true;
//     if(!isPrime(n)) ans = false;

//     while(n!=0){
//         int r = n%10;
//         if(!isPrime(r)) ans = false;
//         n=n/10;
//     }

//     if(ans==false) cout<<"false";
//     else cout<<"true";

// }

// //sieve of eratosthenes
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;

//     vector<bool> isPrime(n+1, true);
//     isPrime[0] = isPrime[1] = false;

//     for(int i=2;i*i<=n;i++){
//         if(isPrime[i]){
//             for(int j=i+i;j<=n;j+=i){
//                 isPrime[j] = false;
//             }
//         }
//     }

//     for(int i=0;i<n;i++){
//         if(isPrime[i]==true){
//             cout<<i;
//         }
//     }
// }

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b;
    cin >> a, b;

    vector<bool> isPrime(b, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= b; i++)
    {
        if (isPrime[i])
        {
            for (int j = i + i; j <= b; j += i)
            {
                isPrime[i] = false;
            }
        }
    }
}

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int left = 50, right = 100;

    // Step 1: Find primes up to sqrt(right)
    int limit = sqrt(right);
    vector<bool> isPrime(limit + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= limit; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= limit; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    // Store primes up to sqrt(right)
    vector<int> primes;
    for (int i = 2; i <= limit; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }

    // Step 2: Create segment [left, right]
    vector<bool> segment(right - left + 1, true);

    // Step 3: Mark multiples of primes in range
    for (int p : primes)
    {
        int start = max(p * p, ((left + p - 1) / p) * p);

        for (int j = start; j <= right; j += p)
        {
            segment[j - left] = false;
        }
    }

    // Step 4: Print primes in range
    for (int i = 0; i < segment.size(); i++)
    {
        if (segment[i] && (i + left) > 1)
            cout << i + left << " ";
    }

    return 0;
}

// LCS - Longest Common Subsequence
#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main()
{
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    cout << "Length of LCS: " << lcs(s1, s2) << endl;
    return 0;
}


#include <bits/stdc++.h>
using namespace std;

bool isSafe(int row, int col, int n, vector<string>& board) {
    // Check column
    for (int i = 0; i < row; i++) {
        if (board[i][col] == 'Q') {
            return false;
        }
    }

    // Check left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    // Check right diagonal
    for (int i = row, j = col; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 'Q') {
            return false;
        }
    }

    return true;
}

void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans) {
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (isSafe(row, j, n, board)) {
            board[row][j] = 'Q';
            solve(row + 1, n, board, ans);
            board[row][j] = '.';
        }
    }
}

int main() {
    int n;
    cin >> n;

    vector<vector<string>> ans;
    vector<string> board(n, string(n, '.'));

    solve(0, n, board, ans);

    for (auto& solution : ans) {
        for (auto& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}



#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2) {
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string s1, s2;
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;
    cout << "Length of LCS: " << lcs(s1, s2) << endl;
    return 0;
}

