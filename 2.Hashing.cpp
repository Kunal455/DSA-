//Hashing

// // Number of times element in array
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//    int n;
//    cin>>n;
//    int arr[n];
//    for(int i=0;i<n;i++){
//     cin>>arr[i];
//    }

//    //precompute
//     int hash[13] = {0};
//     for(int i=0;i<n;i++){
//         hash[arr[i]]+=1;
//     }
//     cout<<hash[1]<<endl;
//    int m;
//    cin>>m;
//    for(int i=0;i<m;i++){
//     int num;
//     cin>>num;

//     //fetch
//     cout<<hash[num]<<" "<<endl;
//    }

// }



//count alphabets
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int hash[256] = {0};
    for(int i=0;i<n;i++){
        hash[arr[i]]+=1;

    }


    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        char a;
        cin>>a;

        cout<<hash[a]<<" "<<endl;
    }
    }*/



//count alphabets
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n;
//     cin>>n;
//     char arr[n];
//     for(int i=0;i<n;i++){
//         cin>>arr[i];
//     }


//     int hash[26] = {0};
//     for(int i=0;i<n;i++){
//         hash[arr[i]-'a']+=1;
//     }


//     int q;
//     cin>>q;
//     for(int i=0;i<q;i++){
//         char a;
//         cin>>a;

//         cout<<hash[a-'a']<<" "<<endl;;
//     }
// }







//Map Hashing  for counting numbers              //time complexity is O(N)           //for unordered map 0(1)
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    map<int, int> mp;    //we can use map<long, long> mp; for 10 power 9
    for(int i=0;i<n;i++){
        mp[arr[i]] += 1;
    }
    

    for(auto it: mp){
        cout<<it.first<<" "<<it.second<<endl;
    }



    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        int num;
        cin>>num;

        cout<<mp[arr[i]]<<" ";
    }
}*/



// Q1.  Given two arrays a[] and b[] of size m and n respectively, the task is to determine whether b[] is a subset of a[]. Both arrays are not sorted, and elements are distinct.

// Examples:

// Input: a[] = [11, 7, 1, 13, 21, 3, 7, 3], b[] = [11, 3, 7, 1, 7]
// Output: true
// Explanation: b[] is a subset of a[]
// Input: a[] = [1, 2, 3, 4, 4, 5, 6], b[] = [1, 2, 4]
// Output: true
// Explanation: b[] is a subset of a[]
// Input: a[] = [10, 5, 2, 23, 19], b[] = [19, 5, 3]
// Output: false
// Explanation: b[] is not a subset of a[]
//ANS.
//{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// } Driver Code Ends
// class Solution {
//   public: 
//     // Function to check if b is a subset of a
//     bool isSubset(vector<int> &a, vector<int> &b) {
//         int n=a.size();
//         int m=b.size();
//         unordered_map<int, int> hash;
        
//         if(m>n) return false;
//         for(int i=0;i<n;i++){
//             hash[a[i]]+=1;
//         }
        
//         for(int j=0;j<m;j++){
//             if(hash[b[j]]>0){
//                 hash[b[j]]--;
//             }
//             else{
//                 return false;
//             }
//         }
//     return true;
//     }
// };



//Q2.
// Explanation: arr[3] + arr[4] = 6 + 10 = 16.
// Input: arr[] = [1, 2, 4, 3, 6], target = 11
// Output: false
// Explanation: None of the pair makes a sum of 11.
// Input: arr[] = [11], target = 11
// Output: false
// Explanation: No pair is possible as only one element is present in arr[].

//ANS.
// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// class Solution {
//   public:
//     bool twoSum(vector<int>& arr, int target) {
//         unordered_map<int, int> hashMap; // Map to store the elements we have seen

//         for (int i = 0; i < arr.size(); i++) {
//             int complement = target - arr[i];  // Calculate the complement

//             // Check if the complement exists in the hashMap
//             if (hashMap.find(complement) != hashMap.end()) {
//                 return true; // Pair found
//             }

//             // Add the current element to the hashMap
//             hashMap[arr[i]] = i;
//         }
        
//         return false; // No pair found
//     }
// };



// Q3. TWO SUM RETURN INDEXES
// 1. Two Sum
// Solved
// Easy
// Topics
// Companies
// Hint
// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.
// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]


//ANS.
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int n = nums.size();
//         unordered_map<int, int> hash;
//         for(int i=0;i<n;i++){
//             int comp = target-nums[i];
//              if(hash.find(comp)!=hash.end()){
//                 return {hash[comp],i};
//              }

//              hash[nums[i]] = i;
//         }
//         return {-1,-1};
//     }
// };





// Count pairs with given sum
// Difficulty: EasyAccuracy: 50.11%Submissions: 38K+Points: 2
// Given an array arr[] and an integer target. You have to find numbers of pairs in array arr[] which sums up to given target.

// Examples:

// Input: arr[] = [1, 5, 7, -1, 5], target = 6 
// Output: 3
// Explanation: Pairs with sum 6 are (1, 5), (7, -1) and (1, 5). 
// Input: arr[] = [1, 1, 1, 1], target = 2 
// Output: 6
// Explanation: Pairs with sum 2 are (1, 1), (1, 1), (1, 1), (1, 1), (1, 1), (1, 1).
// Input: arr[] = [10, 12, 10, 15, -1], target = 125
// Output: 0

//ANS.
//{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;


// // } Driver Code Ends
// class Solution {
//   public:
//     int countPairs(vector<int> &arr, int target) {
//         // Code here
//         int n=arr.size();
//         unordered_map<int, int> hash;
//         int count=0;
//         for(int i=0;i<n;i++){
//             int comp = target-arr[i];
            
//             if(hash.find(comp)!=hash.end()){
//                 count+=hash[comp];
//             }
            
//             hash[arr[i]]++;
//         }
//         return count;
//     }
// };



//Q5.Pairs with difference k
// Difficulty: EasyAccuracy: 22.41%Submissions: 55K+Points: 2
// Given an array arr[] of positive integers. Find the number of pairs of integers whose absolute difference equals to a given number k.
// Note: (a, b) and (b, a) are considered the same. Also, the same numbers at different indices are considered different.

// The answer is guaranteed to fit in a 32-bit integer.

// Examples:

// Input: arr[] = [1, 4, 1, 4, 5], k = 3
// Output: 4
// Explanation: There are 4 pairs with absolute difference 3, the pairs are {1, 4}, {1, 4}, {4, 1} and {1, 4}.
// Input: arr[] = [8, 16, 12, 16, 4, 0], k = 4
// Output: 5
// Explanation: There are 5 pairs with absolute difference 4, the pairs are {8, 12}, {8, 4}, {16, 12}, {12, 16}, {4, 0}.


//ANS.
//{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;
// // } Driver Code Ends
// // User function template for C++
// class Solution { 
//   public:
//     /* Returns count of pairs with difference k  */
//     int countPairs(vector<int>& arr, int k) {
//       int n = arr.size();
//       unordered_map<int, int> hash;
      
//       for(int i=0;i<n;i++){
//           hash[arr[i]]++;
//       }
//       int count=0;
//       for(int i=0;i<n;i++){
//           int d1 = arr[i] - k;
//           int d2 = arr[i] + k;
          
//           if(hash.find(d1)!=hash.end()){
//               count+=hash[d1];
//           }
          
//           if(hash.find(d2)!=hash.end()){
//               count+=hash[d2];
//               }
              
//               hash[arr[i]]--;
//       }
      
//       return count;
//     }
// };


//Q5 3SUM
/*
Attempted
Medium
Topics
Companies
Hint
Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.

 

Example 1:

Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
Example 2:

Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
Example 3:

Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
 

Constraints:

3 <= nums.length <= 3000
-105 <= nums[i] <= 105

//ANS
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool hasTripletSum(vector<int> &arr, int target) {
        // Your Code Here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            int l = i+1;
            int r = n-1;
            while(l<r){
                int sum = arr[i] + arr[l] + arr[r];
                
                if(sum==0) return true;
                else if(sum>0) r--;
                else l++;
            }
        }
        return false;
    }
};

// } Driver Code Ends
*/


//Merge short
/*#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int>& arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
        }
        else{
            temp.push_back(arr[right]);
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
    }

    while(right<=high){
        temp.push_back(arr[right]);
    }

    for(int i=low;i<high;i++){
        arr[i] = temp[i-low];
    }
}
void merge(vector<int>& arr, int low, int high){
    if(low==high) return;
    int mid = (low+high)/2;
    merge(arr, low, mid);
    merge(arr, mid+1, high);
    sort(arr, low, mid, high);

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    merge(arr,0,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}*/



