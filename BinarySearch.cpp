//Lower Bound
//Brute
//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code hereclass Solution {
        // code here
        int n = arr.size();
        int ans = n;
        int l=0;
        int h = n-1;
        while(l<=h){
            int m = (l+h)/2;
            if(arr[m]>=target){
                ans= m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;

        
    }
};




//insertion code
class Solution {
    public:
        int searchInsert(vector<int>& arr, int target) {
            int n = arr.size();
            int l =0;
            int h = n-1;
            while(l<=h){
                int m = (l+h)/2;
                if(arr[m]==target){
                    return m;
                }
                else if(arr[m]<target){
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
            return l;
        }
    };




//Floor in a Sorted Array
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    int findFloor(vector<int>& arr, int x) {
        // Your code here
        int n = arr.size();
        int l = 0;
        int h = n-1;
        int ans = -1;
        while(l<=h){
            int m = (l+h)/2;
            if(arr[m]<=x){
                ans = m;
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        return ans;
    }
};



//
// Code
// Testcase
// Testcase
// Test Result
// 34. Find First and Last Position of Element in Sorted Array


class Solution {
    public:
        vector<int> searchRange(vector<int>& arr, int target) {
           int n = arr.size();
           int l =0;
           int h=n-1;
           int lower=-1;
           while(l<=h){
            int m = l+(h-l)/2;
            if(arr[m]==target){
                lower=m;
                h=m-1;
            }
            else if(arr[m]<target){
                l=m+1;
            }
            else{
                h=m-1;
            }
           }
    
    
           l =0;
           h=n-1;
           int higher = -1;
           while(l<=h){
            int m = l+(h-l)/2;
            if(arr[m]==target){
                higher = m;
                l=m+1;
            }
            else if(arr[m]<target){
                l=m+1;
            }
            else{
                h=m-1;
            }
           }
            return {lower, higher};
        }
    };





    //33. Search in Rotated Sorted Array
    class Solution {
        public:
            int search(vector<int>& arr, int target) {
                int n = arr.size();
                int l=0;
                int h = n-1;
                while(l<=h){
                    int m = l+(h-l)/2;
                    if(arr[m]==target){
                        return m;
                    }
        
                    if(arr[l]<=arr[m]){
                        if(arr[l]<=target && target<=arr[m]){
                            h=m-1;
                        }
                        else{
                            l=m+1;
                        }
                    }
        
        
                    if(arr[m]<=arr[h]){
                        if(arr[m]<=target && target<=arr[h]){
                            l=m+1;
                        }
                        else{
                            h=m-1;
                        }
                    }
        
                }
                return -1;
            }
        };





  //153. Find Minimum in Rotated Sorted Array
  class Solution {
    public:
        int findMin(vector<int>& arr) {
            int n = arr.size();
            int l =0;
            int h = n-1;
            int ans = INT_MAX;
            while(l<=h){
                int m = l+(h-l)/2;
                if(arr[l]<=arr[h]){
                    ans = min(ans, arr[l]);
                    break;
                }
                if(arr[l]<=arr[m]){
                    ans = min(ans, arr[l]);
                    l=m+1;
                }
                else{
                    ans = min(ans, arr[m]);
                    h=m-1;
                }
            }
            return ans;
        }
    };










////540. Single Element in a Sorted Array
//O(n)
class Solution {
    public:
        int singleNonDuplicate(vector<int>& arr) {
            int n = arr.size();
            if(n==1) return arr[0];
            for(int i=0;i<n;i++){
            if(i==0){
                if(arr[i]!=arr[i+1]) return arr[i];
            }
            else if(i==n-1){
                if(arr[i]!=arr[i-1]) return arr[i];
            }
            else{
                if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1]){
                    return arr[i];
                }
            }
    
            }
            return -1;
        }
    };


//Optimal  O(n)
class Solution {
    public:
        int singleNonDuplicate(vector<int>& arr) {
            int n = arr.size();
            if(n==1) return arr[0];
            if(arr[0]!=arr[1]) return arr[0];
            if(arr[n-1]!=arr[n-2]) return arr[n-1];
            int l = 1;
            int h = n-1;
            while(l<=h){
                int m = (l+h)/2;
                if(arr[m]!=arr[m-1] && arr[m]!=arr[m+1]){
                    return arr[m];
                }
                //left half
                if((m%2==1 && arr[m-1]==arr[m])
                    || (m%2==0 && arr[m+1]==arr[m])){
                        l=m+1;
                    }
                else{
                    h=m-1;
                }
            }
            return -1;
        }
    };



//162. Find Peak Element
class Solution {
    public:
        int findPeakElement(vector<int>& arr) {
            int n = arr.size();
            int l =0;
            int h = n-1;
            while(l<=h){
                int m =(l+h)/2;
                if(m>0 && arr[m]<arr[m-1]){
                    h=m-1;
                }
                else if(m<n-1 && arr[m]<arr[m+1]){
                    l=m+1;
                }
                else{
                    return m;
                }
            }
            return -1;
            
        }
    };




//Find Kth Rotation
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Hereclass Solution {
        int n = arr.size();
        int l =0;
        int h = n-1;
        int ans = INT_MAX;
        int index=-1;
        while(l<=h){
            int m = l+(h-l)/2;
            if(arr[l]<=arr[h]){
                if(arr[l]<ans){
                    ans = arr[l];
                    index = l;
                }
                break;
            }
            if(arr[l]<=arr[m]){
                if(arr[l]<ans){
                    ans = arr[l];
                    index = l;
                }
                l=m+1;
            }
            else{
                h=m-1;
                if(arr[m]<ans){
                    ans = arr[m];
                    index = m;
                }
            }
        }
        return index;
    }
};



//KOKO EATING BANANA
class Solution {
public:
        int fun(vector<int>& p, int m, int n){
            long long sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil((double)p[i]/(double)m);
            if(sum > 1e9) return sum; 
            }
            return sum;
        }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int s = 1;
        int e = *max_element(piles.begin(), piles.end());
        int ans = -1;


        while(s<=e){
            int m = s+(e-s)/2;
            if(fun(piles, m, n)<=h){
                ans = m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }

        return ans;
    }
};









//Minimum Number of Days to Make m Bouquets

class Solution {
public:
    bool possible(vector<int>& bloomDay, int d, int m, int k){
        int flower=0;
        int bonquet=0;
        for(auto day : bloomDay){
            if(day<=d){
                flower++;
                if(flower==k){
                    bonquet++;
                    flower=0;
                }
            }
            else{
                flower=0;
            }
        }

        return bonquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        int n = bloomDay.size();
        if(n<1LL*m*k)  return -1;

        int s=*min_element(bloomDay.begin(), bloomDay.end());
        int e=*max_element(bloomDay.begin(), bloomDay.end());
        int ans=-1;

        while(s<=e){
            int d = s+(e-s)/2;
            if(possible(bloomDay, d, m, k)){
                ans = d;
                e=d-1;
            }
            else{
                s=d+1;
            }
        }
        return ans;
    }
};






//Capacity to Ship Packages within D Days

class Solution {
public:
    int possible(vector<int>& arr, int m,int d){
        int sum=0;
        int c = 1;
        for(int i=0;i<arr.size();i++){
            if(sum + arr[i] > m){
                c++;
                sum = arr[i];
            }
            else{
                sum+=arr[i];
            }
        }

        return c;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n= weights.size();
        int s=*max_element(weights.begin(), weights.end());
        int sum=0;
        int ans = -1;
        int e = accumulate(weights.begin(), weights.end(),0);
        while(s<=e){
            int m =s+(e-s)/2;

            if(possible(weights, m , days)<=days){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }

        return s;
    }
};


//Aggressive Cows
//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    bool possible(vector<int>& arr, int m, int k){
        int c = 1;
        int last = arr[0];
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]-last>=m){
                c++;
                last=arr[i];
            }
            
        }
            if(c>=k) return true;
            
            return false;
    }
    int aggressiveCows(vector<int> &stalls, int k) {

        // Write your code here
        sort(stalls.begin(), stalls.end());
        int n= stalls.size();
        int s = 1;
        int e = *max_element(stalls.begin(), stalls.end()) - *min_element(stalls.begin(), stalls.end());
        while(s<=e){
            int m = s+(e-s)/2;
            if(possible(stalls, m, k)){
                s=m+1;
            }
            else{
                e=m-1;
            }
        }
        
        
        return e;
    }
};


//{ Driver Code Starts.



//Kth Missing Positive Number
class Solution {
public:
   
    int findKthPositive(vector<int>& arr, int k) {
       int n = arr.size();
       int s = 0;
       int e = n-1;
       int missing;
       while(s<=e){
            int m = s+(e-s)/2;
            missing = arr[m] - (m+1);
            if(missing<k){
                s=m+1;
            }
            else{
                e=m-1;
            }
       }

       return e+k+1;
    }
};




//Page allocation

//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
  
    bool possible(vector<int> &arr, int m, int k){
        int c = 1;
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            if(sum+arr[i]>m){
                c++;
                sum = arr[i];
            }
            else{
                sum +=arr[i];
            }
            
        }
        
        return c<=k;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        int s = *max_element(arr.begin(),arr.end());
        int e = accumulate(arr.begin(),arr.end(),0);
        if(k>n) return -1;
        if(k==1) return accumulate(arr.begin(),arr.end(),0);
        int ans = -1;
        while(s<=e){
            int m = s+(e-s)/2;
            
            if(possible(arr, m, k)){
                ans = m;
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return ans;
    }
};







//Median of Two Sorted Arrays
//BETTER   O(N+m)/2
class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int i =0;
        int j =0;
        int s = n+m;
        int idx1 = s/2;
        int idx2 = s/2-1;
        int c=0;
        int el1 = 0;
        int el2 = 0;
        while(i<=n-1 && j<=m-1){
            if(a[i]<b[j]) {
                if(c==idx1) el1 = a[i];
                if(c==idx2) el2 = a[i];
                i++;
                c++;
            }

            else{
                if(c==idx1) el1 = b[j];
                if(c==idx2) el2 = b[j];
                j++;
                c++;
            }

            
        }

        while(i<n){
            if(c==idx1) el1 = a[i];
                if(c==idx2) el2 = a[i];
                i++;
                c++;
        }
        while(j<m){
             if(c==idx1) el1 = b[j];
                if(c==idx2) el2 = b[j];
                j++;
                c++;
        }


        if(s%2==1){
            return el1; 
        }
        
            return(double)((double)(el1+el2)/2.0);
        
    }
};


//OPTIMAL O(log(min(n, m))).

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        if(n>m) return findMedianSortedArrays(b,a);
        int left=(n+m+1)/2;
        int s=0;
        int e=n;
        int sum = (n+m);
        while(s<=e){
            int m1 = s+(e-s)/2;
            int m2 = left - m1;
            int l1 = INT_MIN; int l2 = INT_MIN;
            int r2 = INT_MAX; int r1 = INT_MAX;

            if(m1<n) r1 = a[m1];
            if(m2<m) r2 = b[m2];
            if(m1-1>=0) l1 = a[m1-1];
            if(m2-1>=0) l2 = b[m2-1];

            if(l1<=r2 && l2<=r1){
                if(sum%2==0){
                    return (max(l1,l2)+min(r1,r2))/2.0;
                }
                else{
                    return (double)((double)max(l1,l2));
                }
            }
            else if(l1>r2){
                e=m1-1;
            }
            else{
                s=m1+1;
            }

        }
        return 0;
    
    }
};








