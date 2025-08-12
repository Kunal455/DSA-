 //Second Largest element

 //Brute
 
//  class Solution {
//   public:
//     // Function returns the second
//     // largest elements
//     int getSecondLargest(vector<int> &arr) {
//         // Code Here
//        int n = arr.size();
//        sort(arr.begin(), arr.end());
//        int sm=-1;
//        for(int i=n-2;i>=0;i--){
//            if(arr[i]!=arr[n-1]){
//                sm = arr[i];
//                break;
//            }
//        }
//        return sm;
//     }     
// };




//BETTER
/*class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
       int n = arr.size();
       int max = arr[0];
       for(int i=0;i<n;i++){
           if(arr[i]>max){
               max = arr[i];
           }
       }
       int sm = -1;
       for(int i=0;i<n;i++){
           if(arr[i]>sm && arr[i]!=max){
               sm=arr[i];
           }
       }
       return sm;
    }
       
};


//Optimal
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
       int n = arr.size();
       int max = arr[0];
       int sm=-1;
       for(int i=1;i<n;i++){
           if(arr[i]>max){
               sm=max;
               max = arr[i];
               
           }
           else if(arr[i]>sm && arr[i]<max){
               sm=arr[i];
           }
       }
       return sm;
    }
       
};


//My set approach
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        set<int> st;
        int n = arr.size();
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        if(st.size()<2)  return -1;
        auto it = st.rbegin();
        ++it;
        return *it;
        
    }
};*/


//Q. 26. Remove Duplicates from Sorted Array
//BRUTE     O(nlogn+n)
/*class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> unique_nums(nums.begin(), nums.end()); // Store unique elements

        int index = 0;
        for (int num : unique_nums) {
            nums[index++] = num; // Overwrite nums with unique values
        }

        return index; // Number of unique elements (k)
    }
};
*/



//Optimal
/*class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        for(int j=1;j<n;j++){
            if(arr[i]!=arr[j]){
                arr[i+1] = arr[j];
                i++;
            }
        }
        return i+1;
    }
};*/








//Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.
//Brute Force
/*
class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        int n = arr.size();
        int m = k%n;
        int t = n-m;
        vector<int> temp(t,0);
        for(int i=0;i<t;i++){
            temp[i] = arr[i]; 
        }
        for(int i=0;i<m;i++){
            arr[i] = arr[i+t];
        }

        for(int i=0;i<t;i++){
            arr[i+m] = temp[i];
        }
        

    }
};
*/

//optimal
/*
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        int t = k%n;
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin()+t);
        reverse(nums.begin()+t, nums.end());

    }
};
*/


//Moving Zeroes at end
//Brute
/*class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        vector<int> v(n, 0);  // Step 1: Create a new vector of size n, initialized to 0 (O(n))
        
        int j = 0;
        for (int i = 0; i < n; i++) {  // Step 2: Traverse arr to copy non-zero elements (O(n))
            if (arr[i] != 0) {
                v[j] = arr[i];
                j++;
            }
        }

        for (int i = 0; i < n; i++) {  // Step 3: Copy v back to arr (O(n))
            arr[i] = v[i];
        }
    }
};
*/

//Optimal
/*
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int j = 0;  // Pointer for non-zero elements

        // Move all non-zero elements to the front
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] != 0) {
                swap(arr[i], arr[j]);
                j++;
            }
        }
    }
};

*/


//Union
//Brute  O(nlogn)+O(mlogm)
/*
class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        set<int> st;
        for (int i = 0; i < a.size(); i++) {
            st.insert(a[i]);  // Insertion in set
        }
        for (int j = 0; j < b.size(); j++) {
            st.insert(b[j]);  // Insertion in set
        }
        
        return vector<int>(st.begin(), st.end());  // Copying set to vector
    }
};

*/


//Optimal





























//268. Missing Number
/*Given an array nums containing n distinct numbers in the range [0, n], return the only number in the range that is missing from the array.

 

Example 1:

Input: nums = [3,0,1]

Output: 2

Explanation:

n = 3 since there are 3 numbers, so all numbers are in the range [0,3]. 2 is the missing number in the range since it does not appear in nums.

Example 2:

Input: nums = [0,1]

Output: 2

Explanation:

n = 2 since there are 2 numbers, so all numbers are in the range [0,2]. 2 is the missing number in the range since it does not appear in nums.

Example 3:

Input: nums = [9,6,4,2,3,5,7,0,1]

Output: 8

Explanation:

n = 9 since there are 9 numbers, so all numbers are in the range [0,9]. 8 is the missing number in the range since it does not appear in nums.

 
 

 

 

Constraints:

n == nums.length
1 <= n <= 104
0 <= nums[i] <= n
All the numbers of nums are unique.*/

//ANS.
//Using Map O(N LOGN)
/*class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n=nums.size();
            map<int, int> mp;
            for(int i=0;i<n;i++){
                mp[nums[i]]+=1;
            }
    
            for(int i=0;i<n+1;i++){
                if(mp[i]!=1){
                    return i;
                }
            }
            return -1;
        }
    };*/






//Using Brute Force  O(NLOG N)  sc=o(1)
/*class Solution {
    public:
        int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int d=-1;
        int j=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=j){
                d=j;
                break;
            }
            j++;
        }
        if(d==-1){
            return j;
        }
        return d;
        }
    };*/


//OPTIMAL SUM N(N+1)/2 - SUM OF ALL ELEMENTS
/*class Solution {
    public:
        int missingNumber(vector<int>& nums) {
            int n = nums.size();
            int sum=(n*(n+1))/2;
            int Asum=0;
            for(int i=0;i<n;i++){
                Asum+=nums[i];
            }
    
            return sum - Asum;
        }
    };*/






/*136. Single Number
Solved
Easy
Topics
Companies
Hint
Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only constant extra space.

 

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Example 3:

Input: nums = [1]

Output: 1

//ANS.

//Using HASH

//OPTIMAL TC O(N)
class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            int n = nums.size();
            int xorr = 0;
            for(int i=0;i<n;i++){
                xorr = xorr ^ nums[i];
            }
            return xorr;
    
        }
    };*/







    /*
    Longest Subarray with Sum K
Difficulty: MediumAccuracy: 24.64%Submissions: 588K+Points: 4
Given an array arr[] containing integers and an integer k, your task is to find the length of the longest subarray where the sum of its elements is equal to the given value k. If there is no subarray with sum equal to k, return 0.

Examples:

Input: arr[] = [10, 5, 2, 7, 1, -10], k = 15
Output: 6
Explanation: Subarrays with sum = 15 are [5, 2, 7, 1], [10, 5] and [10, 5, 2, 7, 1, -10]. The length of the longest subarray with a sum of 15 is 6.
Input: arr[] = [-5, 8, -14, 2, 4, 12], k = -5
Output: 5
Explanation: Only subarray with sum = 15 is [-5, 8, -14, 2, 4] of length 5.
Input: arr[] = [10, -10, 20, 30], k = 5
Output: 0
Explanation: No subarray with sum = 5 is present in arr[].
    */

/*
//Brute
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        int len = 0;

        for (int i = 0; i < n; i++) {
            int sum = 0;  // Reset sum for each new subarray starting at 'i'
            for (int j = i; j < n; j++) {  // j starts from i
                sum += arr[j];

                if (sum == k) {
                    len = max(len, j - i + 1);  // Update max length
                }
            }
        }
        return len;
    }
};
*/

/*
//better
*/

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
       unordered_map<long long, int>mp;
       long long sum = 0;
       int maxlen = 0;
       for(int i=0;i<n;i++){
           sum+=arr[i];
           if(sum==k){
               maxlen = max(maxlen, i+1);
           }
           
           int rem = sum - k;
           if(mp.find(rem)!=mp.end()){
               int len = i - mp[rem];
               maxlen= max(maxlen, len);
           }
           
           if(mp.find(sum)!=mp.end()){
               mp[sum] = i;
           }
       }
       
       return maxlen;
       
    }
};













//TWO SUM
//optimal
// class Solution {
//     public:
//         vector<int> twoSum(vector<int>& nums, int target) {
//             int n = nums.size();
//           vector<pair<int, int>>v;
//           for(int i=0;i<n;i++){
//             v.push_back({nums[i],i});
//           }
//           sort(v.begin(), v.end());
    
//           int l = 0;
//           int r = n-1;
//           while (l<r){
//             int sum = v[l].first+v[r].first;
//             if(sum==target){
//                 return {v[l].second, v[r].second};
//             }
    
//             else if(sum<target){
//                 l++;
//             }
    
//             else{
//                 r--;
//             }
//           }
//           return {-1,-1};
    
//         }
//     };



//Sort an array of 0's 1's and 2's
//Optimal
// class Solution {
//     public:
//         void sortColors(vector<int>& ans) {
//          int n = ans.size();
//          int low = 0;
//          int mid = 0;
//          int high = n-1;
//          while(mid<=high){
//             if(ans[mid]==0){
//                 swap(ans[mid], ans[low]);
//                 low++;
//                 mid++;
//             }
//             else if(ans[mid]==1){
//                 mid++;
//             }
//             else{
//                 swap(ans[high], ans[mid]);
//                 high--;
//             }
//          }
          
//         }
//     };






// 169. Majority Element
// Easy
// Topics
// Companies
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
 

//optimal
//BOYERS MOORES ALGORITHM
// class Solution {
//     public:
//         int majorityElement(vector<int>& v) {
//             int n = v.size();
//             int c = 0;
//             int el;
//             for(int i=0;i<n;i++){
//                 if(c==0){
//                     c=1;
//                     el=v[i];
//                 }
    
//                 else if(v[i] == el){
//                     c++;
//                 }
//                 else{
//                     c--;
//                 }
//             }
    
//             c = 0;
//             for(int i=0;i<n;i++){
//                 if(v[i]==el){
//                     c++;
//                 }
//                 if(c > (n/2)){
//                     return el;
//                 }
//             }
//             return -1;
//         }
//     };















// 53. Maximum Subarray
// Medium
// Topics
// Companies
// Given an integer array nums, find the subarray with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.


//Brute 
// class Solution {
//     public:
//         int maxSubArray(vector<int>& nums) {
//             int n = nums.size();
//             int max = 0;
//             for(int i=0;i<n;i++){
//                 for(int j=i;j<n;j++){
//                     int sum = 0;
//                     for(int k=i;k<j;k++){
//                         sum+=nums[k];
//                     }
    
//                     if(sum>max){
//                         max = sum;
//                     }
//                 }
//             }
//             return max;
//         }
//     };









//Better

// class Solution {
// public:
// int maxSubArray(vector<int>& nums) {
//     int n = nums.size();
//     int max = INT_MIN;
//     for(int i=0;i<n;i++){
//         int sum = 0;
//         for(int j=i;j<n;j++){
//             sum+=nums[j];
//             if(sum>max){

//                 max = sum;
            
//         }
//         }
//     }
//     return max;
// }
// };





//KADANE's ALGORITHM
//oPtimal
// class Solution {
//     public:
//         int maxSubArray(vector<int>& nums) {
//             int n = nums.size();
//             int maxs = INT_MIN;
//             int sum = 0;
            
//             for(int i=0;i<n;i++){   
//                 sum+=nums[i];
//                 maxs = std::max(sum, (int)maxs);
    
//                 if(sum<0){
//                     sum = 0;
//                 }
    
//             }
    
//             return maxs;
//         }
//     };



//2149. Rearrange Array Elements by Sign
/*Solved
Medium
Topics
Companies
Hint
You are given a 0-indexed integer array nums of even length consisting of an equal number of positive and negative integers.

You should return the array of nums such that the the array follows the given conditions:

Every consecutive pair of integers have opposite signs.
For all integers with the same sign, the order in which they were present in nums is preserved.
The rearranged array begins with a positive integer.
Return the modified array after rearranging the elements to satisfy the aforementioned conditions.

 

Example 1:

Input: nums = [3,1,-2,-5,2,-4]
Output: [3,-2,1,-5,2,-4]
Explanation:
The positive integers in nums are [3,1,2]. The negative integers are [-2,-5,-4].
The only possible way to rearrange them such that they satisfy all conditions is [3,-2,1,-5,2,-4].
Other ways such as [1,-2,2,-5,3,-4], [3,1,2,-2,-5,-4], [-2,3,-5,1,-4,2] are incorrect because they do not satisfy one or more conditions. */



//Brute
/*class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& arr) {
           int n = arr.size();
           int i = 0;
           int j = 1;
           while(i>n-1 || j>n-1){
            if(arr[i]>0){
                i+=2;
            }
            if(arr[j]<0){
                j+=2;
            }
            if(arr[j]>0){
                swap(arr[i], arr[j]);
                i+=2;
                j+=2;
    
            }
            if(arr[j]<0){
                swap(arr[j], arr[i]);
                j+=2;
                i+=2;
            }
           }
           return arr;
        }
    };*/





//Optimal
/*class Solution {
    public:
        vector<int> rearrangeArray(vector<int>& arr) {
           int n = arr.size();
           int i = 0;
           int j = 1;
           vector<int> ans(n,0);
           for(int k=0;k<n;k++){
            if(arr[k]>0){
                ans[i]=arr[k];
                i+=2;
            }
            else{
                ans[j]=arr[k];
                j+=2;
            }
           }
           return ans;
        }
    };*/





//Next permutation
//Better
/*class Solution {
    public:
        void nextPermutation(vector<int>& A) {
            next_permutation(A.begin(), A.end());
        }
    };*/


//Optimal
/*
class Solution {
public:
    void nextPermutation(vector<int>& a) {
        int n = a.size();
        int idx = -1;
        for(int i=n-2;i>=0;i--){
            if(a[i]<a[i+1]){
                
                    idx = i;
                    break;

                
            }
        }
        if(idx==-1){
            reverse(a.begin(), a.end());
            return;
        }

        for(int i=n-1;i>idx;i--){
            if(a[i]>a[idx]){
                swap(a[i], a[idx]);
                break;
            }
        }

        reverse(a.begin()+idx+1,a.end());
    }
};*/





//Longest consecutive sequence in an array

//Better
/*class Solution {
    public:
        int longestConsecutive(vector<int>& arr) {
            int n = arr.size();
            sort(arr.begin(), arr.end());
            int longest =1;
            int c = 0;
            int ls = INT_MIN;
            if(n==0){
                return 0;
            }
            for(int i=0;i<n;i++){
                if(arr[i]-1 == ls){
                    c+=1;
                    ls=arr[i];
                }
                else if(arr[i]!=ls){
                    c=1;
                    ls = arr[i];
                }
                longest=max(longest, c);
            }
            return longest;
    
            
        }
    };*/




    //Optimal
    /*
    class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return 0;
        int longest = 1;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(arr[i]);
        }
        for(auto i : st){
            if(st.find(i-1)==st.end()){
                int c=1;
                int x=i;
                while(st.find(x+1)!=st.end()){
                    c+=1;
                    x=x+1;
                }

                longest=max(longest, c);
            }
        }
            return longest;
        
    }
};
    */



    //Matrix zero
    //Brute
    /*
    class Solution {
public:
    void rows(int i, int m, vector<vector<int>>& arr){
        for(int j=0;j<m;j++){
            if(arr[i][j]!=0){
                arr[i][j]=-1e9;
            }
        }
    }

    void cols(int j, int n, vector<vector<int>>& arr){
        for(int i=0;i<n;i++){
            if(arr[i][j]!=0){
                arr[i][j]=-1e9;
            }
        }
    }

    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size();
        int m= arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    rows(i,m,  arr);
                    cols(j,n,  arr);
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==-1e9){
                    arr[i][j]=0;
                }
            }
        }
    }
};

    */

//better
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        vector<int> r(n,0);
        vector<int> c(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    r[i]=1;
                    c[j]=1;
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(r[i]==1 || c[j]==1){
                    arr[i][j]=0;
                }
            }
        }
    }
};
*/

//Optimal
/*
class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        int col0 = 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(arr[i][j]==0){
                    arr[i][0] = 0;

                    if(j!=0){
                        arr[0][j]=0;
                    }
                    else{
                        col0=0;
                    }
                }
            }
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(arr[i][0]==0 || arr[0][j]==0){
                    arr[i][j]=0;
                }
            }
        }
        if(arr[0][0]==0){
            for(int j=0;j<m;j++){
                arr[0][j]=0;
            }
        }
        if(col0==0){
            for(int i=0;i<n;i++){
                arr[i][0]=0;
            }
        }
    }
};
*/


//Rotate matrix by 90degree
//Brute
/*
class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n= arr.size();
        int m = arr[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                    v[j][(n-1)-i] = arr[i][j];
                
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                    arr[i][j] = v[i][j];
                
            }
        }
        
    }
};*/

//optimal
/*
class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n= arr.size();
        int m = arr[0].size();
        vector<vector<int>> v(n,vector<int>(m,0));
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                    swap(arr[i][j], arr[j][i]);
                
            }
        }

        for(int i=0;i<n;i++){
            reverse(arr[i].begin(), arr[i].end());
        }
        
        
    }
};
*/


//SPIRAL MATRIX

/*
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();

        int l=0;
        int r=m-1;
        int t=0;
        int b=n-1;
        vector<int> ans;
        while(l<=r || t<=b){
            for(int i=l;i<=r;i++){
                ans.push_back(arr[t][i]);
            }
                t++;

            for(int i=t;i<=b;i++){
                ans.push_back(arr[i][r]);
            }
                r--;

            if (t <= b) {  
                for (int i = r; i >= l; i--)
                    ans.push_back(arr[b][i]);
                b--; // Move bottom boundary up
            }

            // Traverse bottom → top (ONLY IF there are remaining columns)
            if (l <= r) {  
                for (int i = b; i >= t; i--)
                    ans.push_back(arr[i][l]);
                l++; // Move left boundary right
            }
        
        }
        return ans;
    }
};
*/


//560. Subarray Sum Equals K

//Brute
/*class Solution {
    public:
        int subarraySum(vector<int>& arr, int k) {
            int n = arr.size();
            
                    int c = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int sum=0;
                    for(int k=i;k<=j;k++){
                        sum+=arr[k];
                    }
                    if(sum==k){
                        c+=1;
                    }
                }
            }
            return c;
        }
    };*/




    //Better

    /*
    class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        int n = arr.size();
        
        int c = 0;
        for(int i=0;i<n;i++){
        int sum=0;
            for(int j=i;j<n;j++){
                sum+=arr[j];
                if(sum==k){
                    c+=1;
                }
            }
        }
        return c;
    }
};
    */


//Optimal

// class Solution {
//     public:
//         int subarraySum(vector<int>& nums, int k) {
//             int n = nums.size();
//             map<int, int> mp;
//             mp[0]=1;
//             int psum=0;
//             int c = 0;
//             for(int i=0;i<n;i++){
//                 psum+=nums[i];
//                 int r = psum-k;
//                 c+=mp[r];
//                 mp[psum] += 1;
    
//             }
    
//             return c;
//         }
//     };





