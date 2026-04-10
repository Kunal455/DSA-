 //fibonacci
/*#include<bits/stdc++.h>
using namespace std;
int fib(int n,vector<int>& v){
    if(n<=1) return n;

    if(v[n]!=-1) return v[n];

    return v[n] = fib(n-1,v) + fib(n-2,v);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n+1,-1);
    cout<<fib(n, arr);
}*/


//fibonacci
/*#include<bits/stdc++.h>
using namespace std;
int main(){
     int n;
     cin>>n;
     int prev = 1;
     int prev2 = 0;
     for(int i=2;i<=n;i++){
        int curr = prev + prev2;
        prev2 = prev;
        prev = curr;
     }

     cout<<prev;
}
*/








//climing all stairs
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int p1 = 1;
    int p2 = 1;
    for(int i=2;i<=n;i++){
        int curr = p1 + p2;
        p2=p1;
        p1=curr;
    }

    cout<<p1;
}*/



//Frog Jump1
/*class Solution {
  public:
 
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        if(n==1) return 0;
        int prev = 0;
        int prev2 = 0;
        for(int i=1;i<n;i++){
            int fs = prev + abs(height[i]-height[i-1]);
            int ss = INT_MAX;
            if(i>1){
                ss = prev2 + abs(height[i]-height[i-2]);
            }
                int curr = min(fs, ss);
                prev2 = prev;
                prev = curr;
            
        }
        return prev;
    }
};*/




//frog jump with k distnace
/*#include<bits/stdc++.h>
using namespace std;
int ans(vector<int>& h, int ind, int k){
    if(ind==0) return 0;
    int minsteps = INT_MAX;
    for(int j=1;j<=k;j++){
        if(ind - j >= 0){
        int jump = ans(h, ind-j, k) + abs(h[ind]-h[ind-j]);
        minsteps = min(minsteps, jump);
        }
    }
    return minsteps;
}
int main(){
    vector<int> h={20,39,40,59,50,29,40,54};
    cout<<ans(h,h.size()-1,2);
} */






/*#include<bits/stdc++.h>
using namespace std;

int main(){
    int k;
    cin>>k;
    vector<int> h={20,39,40,59,50,29,40,54};
    int n = h.size();
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=0;i<n;i++){
       
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                int jump = dp[i-j] + abs(h[i]-h[i-j]);
                dp[i] = min(dp[i], jump);
            }
        }
       
    }

    cout<<dp[n-1];

}















//Adjacnt robber

//recusrion code
class Solution {
public:
    int ans(int ind, vector<int>& v){
        if(ind==0) return v[ind];
        if(ind<0) return 0;

        int pick = v[ind] + ans(ind-2, v);
        int npick = 0 + ans(ind-1,v);

        return max(pick, npick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        return ans(n-1, nums);
    }
};

//memoized code
class Solution {
public:
    int ans(int ind, vector<int>& v, vector<int>& dp){
        if(ind==0) return v[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];

        int pick = v[ind] + ans(ind-2, v,dp);
        int npick = 0 + ans(ind-1,v,dp);

        return dp[ind] = max(pick, npick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return ans(n-1, nums, dp);
    }
};


//Tabulated code

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int prev2 = 0;
        int prev = nums[0];
        for(int i=1;i<n;i++){
            int take = nums[i];
            if(i>1){
                take+= prev2;
            }
            int ntake = prev;
            int curr= max(take, ntake);

            prev2 = prev;
            prev=curr;
        }
        return prev;
    }
};*/



//House Robber 2


/*class Solution {
public:
    int ans(int ind, int i, vector<int>& v, vector<int>& dp){
        if(ind==i) return v[ind];
        if(ind<i) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick = v[ind] + ans(ind-2, i, v, dp);
        int npick = 0 + ans(ind-1,i,v, dp);

        return dp[ind] = max(pick, npick);
    }
    int rob(vector<int>& nums) {
        int n =  nums.size();
        if(n==1) return nums[0];
        if(n==2) return max(nums[0], nums[1]);
        vector<int> dp1(n, -1);
         vector<int> dp2(n, -1);
        return max(ans(n-2, 0, nums, dp1 ), ans(n-1, 1, nums, dp2 ));
    }
};
*/








//Ninja Training

/*class Solution {
  public:
    int ans(vector<vector<int>>& arr, int ind, int last){
        if(ind==0){
            int maxi = 0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi = max(maxi, arr[ind][i]);
                }
            }
            return maxi;
        }
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last){
            int val = arr[ind][i] + ans(arr, ind-1, i);
            maxi = max(val, maxi);
            }
        }
        
        return maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        return ans(arr,n-1, 3);
    }
};*/


//memoization

/*class Solution {
  public:
    int ans(vector<vector<int>>& arr, int ind, int last, vector<vector<int>>& dp){
        
        if(ind==0){
            int maxi = 0;
            for(int i=0;i<3;i++){
                if(i!=last){
                    maxi = max(maxi, arr[ind][i]);
                }
            }
            return maxi;
        }
        
        if(dp[ind][last]!=-1) return dp[ind][last];
        
        int maxi = 0;
        for(int i=0;i<3;i++){
            if(i!=last){
            int val = arr[ind][i] + ans(arr, ind-1, i, dp);
            maxi = max(val, maxi);
            }
        }
        
        return dp[ind][last]=maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return ans(arr,n-1, 3, dp);
    }
};*/



//tabulation

/*class Solution {
  public:
    int ans(vector<vector<int>>& arr, int ind, int last, vector<vector<int>>& dp){
         int n = arr.size();

    // prev[last] = max points till previous day
    // if the previous day's task was `last`
    // last = 0/1/2 means we ended prev day with that task
    // last = 3 means "no restriction"
    vector<int> prev(4, 0);

    // Base case: first day (day 0)
    prev[0] = max(arr[0][1], arr[0][2]); // if yesterday we did task 0, we cannot do 0 today
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][0], arr[0][1]);
    prev[3] = max({arr[0][0], arr[0][1], arr[0][2]}); // no restriction

    // Fill day by day
    for (int day = 1; day < n; day++) {
        vector<int> curr(4, 0);
        for (int last = 0; last < 4; last++) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) { // cannot repeat yesterday's task
                    int points = arr[day][task] + prev[task];
                    maxi = max(maxi, points);
                }
            }
            curr[last] = maxi;
        }
        prev = curr; // move to next day
    }

    // prev[3] is dp[n-1][3] → best total with no restriction on last day's task
    return prev[3];
    }
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(4,-1));
        return ans(arr,n-1, 3, dp);
    }
};*/




//GRID 1

/*class Solution {
public:
    int ans(int i, int j){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        int up = ans(i-1, j);
        int down = ans(i, j-1);
        return up+down;
    }
    int uniquePaths(int m, int n) {
        return ans(m-1,n-1);
    }
};
*/

//Memoisation
/*class Solution {
public:
    int ans(int i, int j){
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = ans(i-1, j);
        int down = ans(i, j-1);
        return dp[i][j] =  up+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return ans(m-1,n-1);
    }
};*/


//Tabulation

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int m=3, n=4;

    vector<vector<int>> dp(m, vector<int> (n, -1));
    dp[0][0] = 1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0 && j==0)
            {dp[i][j]=1;}
            else{
                int up = 0;
                int left = 0;
                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    left = dp[i][j-1];
                }
                dp[i][j]=up+left;
            }
        }
    }
    cout<<dp[m-1][n-1];
}*/


//space optimised
/*#include<bits/stdc++.h>
using namespace std;
int main(){
    int m=3, n=4;

    vector<int> prev(n,0);
    for(int i=0;i<m;i++){
        vector<int> temp(n,0);
        for(int j=0;j<n;j++){
            if(i==0 && j==0){
                temp[j]=1;
            }
            else{
                
                temp[j] = prev[j]+(j>0 ? temp[j-1] : 0);
                
            }
        }
        prev = temp;
    }
    cout<<prev[n-1];
}*/



//GRID2

class Solution {
public:
    int ans(int i, int j){
        if(i>=0 && j>=0 && a[i][j]==1) return 0;
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }
        int up = ans(i-1, j);
        int down = ans(i, j-1);
        return up+down;
    }
    int uniquePaths(int m, int n) {
        return ans(m-1,n-1);
    }
};






//Memoisation
class Solution {
public:
    int ans(int i, int j){
        if(i>=0 && j>=0 && a[i][j]==1) return 0;
        if(i==0 && j==0){
            return 1;
        }
        if(i<0 || j<0){
            return 0;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int up = ans(i-1, j);
        int down = ans(i, j-1);
        return dp[i][j] =  up+down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return ans(m-1,n-1);
    }
};


//Tabulation

#include<bits/stdc++.h>
using namespace std;
int main(){
    int m=3, n=4;

    vector<vector<int>> dp(m, vector<int> (n, -1));
    dp[0][0] = 1;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==1) return 0;
            if(i==0 && j==0)
            {dp[i][j]=1;}
            else{
                int up = 0;
                int left = 0;
                if(i>0){
                    up = dp[i-1][j];
                }
                if(j>0){
                    left = dp[i][j-1];
                }
                dp[i][j]=up+left;
            }
        }
    }
    cout<<dp[m-1][n-1];
}



//space optimization

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<int> prev(n,0);
        for(int i=0;i<m;i++){
            vector<int> temp(n, 0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j] = (obstacleGrid[0][0]==0 ? 1 : 0);
                }
                else if(obstacleGrid[i][j]==1){
                    temp[j]=0;
                }
                else{
                    temp[j]=prev[j]+(j>0?temp[j-1]:0);
                }
               
            }
            prev=temp;
        }
        return prev[n-1];
    }
};



//grid shortest path sum

//recursion
class Solution {
public:
    int ans(int i, int j, vector<vector<int>>& grid){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
     
        int up = ans(i-1,j,grid);
        int left =ans(i, j-1, grid);
        return grid[i][j] + min(up, left); 

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        return ans(m-1, n-1, grid);
    }
};



//memoization
class Solution {
public:
    int ans(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = ans(i-1,j,grid, dp);
        int left =ans(i, j-1, grid, dp);
        return dp[i][j] = grid[i][j] + min(up, left); 

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        return ans(m-1, n-1, grid, dp);
    }
};


//Tabulation 

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        dp[0][0] =1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    dp[i][j]=grid[0][0];
                }
                else{   
                    int up = INT_MAX, left=INT_MAX;
                    if(i>0){
                        up = dp[i-1][j];
                    }
                    if(j>0){
                        left =dp[i][j-1];
                    }
                    dp[i][j] = grid[i][j] + min(up, left); 
                }
            }
        }
        return dp[m-1][n-1];
    }
};



//space optimisation

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        vector<int> prev(n, 0);
        for(int i=0;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                    temp[j]=grid[0][0];
                }
                else{   
                    int up=INT_MAX; int left=INT_MAX;
                    if(i>0){
                        up = prev[j];
                    }
                    if(j>0){
                        left =temp[j-1];
                    }
                    temp[j] = grid[i][j] + min(up, left); 
                }

        }
            prev=temp;
        }
        return prev[n-1];
    }
};




//Triangle Grid

//recursion
class Solution {
public:
    int ans(int i, int j, int n, vector<vector<int>>& triangle){
        if(i==n-1){
            return triangle[n-1][j];
        }
        int down = triangle[i][j] + ans(i+1,j,n,triangle);
        int diag = triangle[i][j] + ans(i+1,j+1,n,triangle);
        return min(down, diag);

    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n= triangle.size();

        return ans(0, 0, n, triangle);
    }
};



//Memoisation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans(int i, int j, int n,
            vector<vector<int>>& triangle,
            vector<vector<int>>& dp)
    {
        // Base: last row
        if (i == n-1) {
            return triangle[n-1][j];
        }

        // Memoized result
        if (dp[i][j] != -1) return dp[i][j];

        int down = triangle[i][j] + ans(i+1, j,   n, triangle, dp);
        int diag = triangle[i][j] + ans(i+1, j+1, n, triangle, dp);

        // ✅ store in dp, don't overwrite triangle
        return dp[i][j] = min(down, diag);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return ans(0, 0, n, triangle, dp);
    }
};



//Tabulation

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        for(int j=0;j<n;j++){
            dp[n-1][j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){

                int down = triangle[i][j] + dp[i+1][j];
                int diag = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, diag);
            }
        }
        return dp[0][0];
    }
};



//Space Optimization
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> front(n,0);
        for(int j=0;j<n;j++){
            front[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> curr(n,0);
            for(int j=0;j<=i;j++){

                int down = triangle[i][j] + front[j];
                int diag = triangle[i][j] + front[j+1];
                curr[j] = min(down, diag);
            }
            front = curr;
        }
        return front[0];
    }
};




//minimum falling path sum

//recursion
class Solution {
public:
    int ans(int i, int j, vector<vector<int>>& matrix){
        if(j<0 || j>=matrix[0].size()) return 1e8;
        if(i==0) return matrix[i][j];

        int u = matrix[i][j] + ans(i-1,j, matrix);
        int l = matrix[i][j] + ans(i-1, j-1, matrix);
        int r = matrix[i][j] + ans(i-1, j+1, matrix);

        return min(u, min(l,r));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 1e8;
        for(int j=0;j<n;j++){
            maxi = min(maxi, ans(n-1,j,matrix));
        }
        return maxi;
    }
};




//memoization

class Solution {
public:
    int ans(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        if(j<0 || j>=matrix[0].size()) return 1e8;
        if(i==0) return matrix[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int l = matrix[i][j] + ans(i-1, j-1, matrix, dp);
        int u = matrix[i][j] + ans(i-1,j, matrix, dp);
        int r = matrix[i][j] + ans(i-1, j+1, matrix, dp);

        return dp[i][j] = min(u, min(l,r));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int maxi = 1e8;
        vector<vector<int>> dp(n,vector<int> (n,-1));
        for(int j=0;j<n;j++){
            maxi = min(maxi, ans(n-1,j,matrix, dp));
        }
        return maxi;
    }
};


//Tabulation

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1));
        for(int j=0;j<n;j++){
            dp[0][j] = matrix[0][j];
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0){
                    dp[i][j] = matrix[i][j];
                }
                else{
                    int up = 1e8 , left = 1e8, right = 1e8;
                    if(j-1>=0){
                    left = matrix[i][j] + dp[i-1][j-1];
                    }
                    up = matrix[i][j] + dp[i-1][j];
                    if(j+1<n){
                    right = matrix[i][j] + dp[i-1][j+1];
                    }
                    dp[i][j] = min({left, up, right});
                    
                }
            }
        }
        int mini = dp[m-1][0];
        for(int i=1;i<n;i++){
            mini = min(mini, dp[n-1][i]);
        }

        return mini;
        
    }
};


//space 

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> prev(n,0);
        for(int j=0;j<n;j++){
            prev[j] = matrix[0][j];
        }

        for(int i=1;i<m;i++){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                    int up = 1e8 , left = 1e8, right = 1e8;
                    if(j-1>=0){
                    left = matrix[i][j] + prev[j-1];
                    }
                    up = matrix[i][j] + prev[j];
                    if(j+1<n){
                    right = matrix[i][j] + prev[j+1];
                    }
                    temp[j] = min({left, up, right});
            }
                prev = temp;
        }
        int mini = prev[0];
        for(int i=1;i<n;i++){
            mini = min(mini, prev[i]);
        }

        return mini;
        
    }
};



//SUBSEQUENCE SUM

class Solution {
  public:
    bool ans(int i, vector<int>& arr, int sum){
        if(sum==0) return true;
        if(i==0) return arr[0]==sum;
        
        bool notTake = ans(i-1, arr, sum);
        bool take = false;
        if(arr[i]<=sum){
            take = ans(i-1, arr, sum-arr[i]);
        }
        
        return notTake || take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        return ans(n-1, arr, sum);
    }
};

//MEMOISATION
class Solution {
  public:
    bool ans(int i, vector<int>& arr, int sum, vector<vector<int>>& dp){
        if(sum==0) return true;
        if(i==0) return arr[0]==sum;
        if(dp[i][sum]!=-1) return dp[i][sum];
        bool notTake = ans(i-1, arr, sum, dp);
        bool take = false;
        if(arr[i]<=sum){
            take = ans(i-1, arr, sum-arr[i], dp);
        }
        
        return dp[i][sum] =  notTake || take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (sum+1, -1));
        return ans(n-1, arr, sum, dp);
    }
};

//tABULATION
class Solution {
  public:
   
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n, vector<bool> (sum+1, false));
        for(int i=0;i<n;i++){
            dp[i][0] = true;
        }
        
        if(arr[0]<=sum){
        dp[0][arr[0]] = true;
        }
        
        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                    
                bool notTake = dp[i-1][target];
                bool take = false;
                if(arr[i]<=target){
                    take = dp[i-1][target-arr[i]];
                }
        
                dp[i][target] =  notTake || take;
            }
        }
        return dp[n-1][sum];
    }
};


//SPACE optimised

class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<bool>prev (sum+1,false);
        prev[0] = true;

        if (arr[0] <= sum) {
            prev[arr[0]] = true;
        }

        // Build table
        for (int i = 1; i < n; i++) {
            vector<bool> temp(sum+1, false);
            temp[0] = true;
            for (int target = 1; target <= sum; target++) {
                bool notTake = prev[target];
                bool take = false;
                if (arr[i] <= target) {
                    take = prev[target - arr[i]];
                }
                temp[target] = notTake || take;
            }
            prev=temp;
        }

       
        return prev[sum];
    }
};

//partition sum
class Solution {
public:
    bool ans(int i, int sum, vector<int>& arr){
        if(sum==0) return true;
        if(i==0) return arr[0]==sum;

        bool ntake = ans(i-1, sum, arr);
        bool take = false;
        if(arr[i]<=sum){
            take = ans(i-1, sum-arr[i], arr);
        }

        return take||ntake;
    }
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2!=0) return false;
        int target = sum/2;

        return ans(n-1, target, nums);
    }
};

//memoization

class Solution {
public:
    bool ans(int i, int sum, vector<int>& arr, vector<vector<int>>& dp){
        if(sum==0) return true;
        if(i==0) return arr[0]==sum;
        if(dp[i][sum]!=-1) return dp[i][sum];

        bool ntake = ans(i-1, sum, arr, dp);
        bool take = false;
        if(arr[i]<=sum){
            take = ans(i-1, sum-arr[i], arr, dp);
        }

        return dp[i][sum] = take||ntake;
    }
    bool canPartition(vector<int>& nums) {
        int n= nums.size();
        int sum = 0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }

        if(sum%2!=0) return false;
        int target = sum/2;
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return ans(n-1, target, nums, dp);
    }
};








//subsequence sum

//recursion 
class Solution {
  public:
    int ans(int i, vector<int>& arr, int target){
        if(i<0){
            
        if(target==0){
            return 1;
        }
        return 0;
        }
        int sum = 0;
        
        int ntake = ans(i-1,arr, target);
        int take = 0;
        if(arr[i]<=target){
            take = ans(i-1, arr, target-arr[i]);
            
        }
        sum = sum+ ntake+take;
        
        return sum;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return ans(n-1, arr, target);
    }
};

//memoisation

class Solution {
  public:
    int ans(int i, vector<int>& arr, int target, vector<vector<int>>& dp){
        if(i<0){
            
        if(target==0){
            return 1;
        }
        return 0;
        }
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        int sum = 0;
        
        int ntake = ans(i-1,arr, target, dp);
        int take = 0;
        if(arr[i]<=target){
            take = ans(i-1, arr, target-arr[i], dp);
            
        }
        sum = sum+ ntake+take;
        
        return dp[i][target] = sum;
    }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return ans(n-1, arr, target, dp);
    }
};



//tabulation


class Solution {
public:
    

    int perfectSum(vector<int>& arr, int target) {
         int n = arr.size();
    vector<vector<long long>> dp(n+1, vector<long long>(target+1, 0));

    // Base Case: Sum 0 can always be made by empty subset
    for (int i = 0; i <= n; i++)
        dp[i][0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int s = 0; s <= target; s++) {
            // not take current element
            dp[i][s] = dp[i-1][s];
            // take current element if it does not exceed current sum
            if (arr[i-1] <= s)
                dp[i][s] += dp[i-1][s - arr[i-1]];
        }
    }
    return dp[n][target];
    }
};


//space optimised
const int MOD = 1e9+7;
        int n = arr.size();
        
        vector<long long> prev(target+1, 0);
        prev[0] = 1; // empty subset
        
        for(int i = 0; i < n; i++) {
            vector<long long> curr(target+1, 0);
            curr[0] = 1; // empty subset always
            
            for(int s = 0; s <= target; s++) {
                // not take arr[i]
                curr[s] = prev[s];
                
                // take arr[i] if possible
                if(arr[i] <= s) {
                    curr[s] = (curr[s] + prev[s - arr[i]]) % MOD;
                }
            }
            
            prev = curr; // move current row to previous row
        }
        
        return prev[target];



//Count Partitions with Given Difference (DP - 18)
class Solution {
  public:
    int mod = (int)(1e9+7);
    int findways(vector<int>& arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int> (target+1, 0));
        if(arr[0]==0) dp[0][0] = 2;
        else dp[0][0] = 1;
        if(arr[0]!=0 && arr[0]<=target) dp[0][arr[0]]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<target+1;j++){
                int nt = dp[i-1][j];
                int t = 0;
                if(arr[i]<=j){
                    t = dp[i-1][j-arr[i]];
                }
                
                dp[i][j] = (nt+t)%mod;
            }
        }
        
        return dp[n-1][target];
        
        
        
        
        
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int total=0;
        for(int i=0;i<n;i++){
            total+=arr[i];
        }
        if(total-d<0 || (total-d)%2) return 0;
        return findways(arr, (total-d)/2);
        
    }
};






//coins change

//recursion

class Solution {
public:
    int sum(vector<int>& coins, int amount, int i) {
        if (i == 0) {
            if (amount % coins[i] == 0) return amount / coins[i];
            else return INT_MAX;
        }

        int ntake = sum(coins, amount, i - 1);
        int take = INT_MAX;

        if (coins[i] <= amount) {
            int temp = sum(coins, amount - coins[i], i);
            if (temp != INT_MAX) take = 1 + temp;
        }

        return min(take, ntake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = sum(coins, amount, n - 1);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};


//memoisation
class Solution {
public:
    int sum(vector<int>& coins, int amount, int i, vector<vector<int>>& dp) {
        if (i == 0) {
            if (amount % coins[i] == 0) return amount / coins[i];
            else return INT_MAX;
        }

        if(dp[i][amount]!=-1) return dp[i][amount];

        int ntake = sum(coins, amount, i - 1, dp);
        int take = INT_MAX;

        if (coins[i] <= amount) {
            int temp = sum(coins, amount - coins[i], i, dp);
            if (temp != INT_MAX) take = 1 + temp;
        }

        return dp[i][amount] =  min(take, ntake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        int ans = sum(coins, amount, n - 1, dp);
        if (ans == INT_MAX) return -1;
        return ans;
    }
};


//tabulation

class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0) dp[0][t] = t/coins[0];
            else dp[0][t] = INT_MAX;
        }

        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                int ntake = dp[i-1][t];
                int take = INT_MAX;
                if (coins[i] <= t && dp[i][t - coins[i]] != INT_MAX)
    take = 1 + dp[i][t - coins[i]];

                dp[i][t] = min(take, ntake);

            }
            
        }
        int ans = dp[n-1][amount];
        if (ans == INT_MAX) return -1;
        return ans;
    }
};


//space optimised 

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount+1, INT_MAX);
        for(int t=0;t<=amount;t++){
            if(t%coins[0]==0){
                prev[t]=t/coins[0];
            }
           
        }

        for(int i=1;i<n;i++){
            vector<int> temp(amount+1, INT_MAX);
            for(int t=0;t<=amount;t++){
                int ntake = prev[t];
                int take=INT_MAX;
                if(coins[i]<=t && temp[t - coins[i]] != INT_MAX){
                    take = 1+  temp[t-coins[i]];
                }
                temp[t] = min(take, ntake);
            }
            prev=temp;

        }

       return (prev[amount] == INT_MAX) ? -1 : prev[amount];
    }
};



//change coins 2

//recusrion

class Solution {
public:
    int sum(int amount, vector<int>& coins, int i){
        if(amount==0) return 1;
        if(i<0) return 0;
        int ntake = sum(amount, coins, i-1);
        int take = 0;
        if(coins[i]<=amount){
            take = sum(amount-coins[i], coins, i);
        }

        return ntake+take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return sum(amount, coins, n-1);
    }
};


//memoisation

class Solution {
public:
    int sum(int amount, vector<int>& coins, int i, vector<vector<int>>& dp){
        if(amount==0) return 1;
        if(i<0) return 0;

        if(dp[i][amount]!=-1) return dp[i][amount];
        int ntake = sum(amount, coins, i-1, dp);
        int take = 0;
        if(coins[i]<=amount){
            take = sum(amount-coins[i], coins, i, dp);
        }

        return dp[i][amount] = take+ntake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return sum(amount, coins, n-1, dp);
    }
};

//tabulation


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[i][t] = number of ways to make amount t using first (i+1) coins
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        // Base case: using only the first coin
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) dp[0][t] = 1;
            else dp[0][t] = 0;
        }

        // Fill the table
        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= amount; t++) {
                int ntake = dp[i-1][t];  // not take coin i
                int take = 0;
                if(coins[i] <= t) take = dp[i][t - coins[i]]; // take coin i
                dp[i][t] = take + ntake;
            }
        }

        return dp[n-1][amount];
    }
};


//tabulation

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // dp[i][t] = number of ways to make amount t using first (i+1) coins
        vector<vector<int>> dp(n, vector<int>(amount+1, 0));

        // Base case: using only the first coin
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) dp[0][t] = 1;
            else dp[0][t] = 0;
        }

        // Fill the table
        for(int i = 1; i < n; i++) {
            for(int t = 0; t <= amount; t++) {
                int ntake = dp[i-1][t];  // not take coin i
                int take = 0;
                if(coins[i] <= t) take = dp[i][t - coins[i]]; // take coin i
                dp[i][t] = take + ntake;
            }
        }

        return dp[n-1][amount];
    }
};


//space


class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount+1, 0);

        // Base case: using only the first coin
        for(int t = 0; t <= amount; t++) {
            if(t % coins[0] == 0) prev[t] = 1;
        }

        for(int i = 1; i < n; i++) {
            vector<int> temp(amount+1, 0);
            for(int t = 0; t <= amount; t++) {
                int ntake = prev[t]; // not take coin i
                int take = 0;
                if(coins[i] <= t) {
                    take = temp[t - coins[i]]; // take coin i
                }
                temp[t] = ntake + take;
            }
            prev = temp;
        }

        return prev[amount];
    }
};



class Solution {
public:
    int sum(vector<int>& g, vector<int>& s, int i, int j){
        if(i >= g.size() || j >= s.size()) return 0;

        if(s[j] >= g[i]){
            return 1 + sum(g, s, i + 1, j + 1);
        } 
        return sum(g, s, i, j + 1);
    }

    int findContentChildren(vector<int>& g, vector<int>& s){
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        return sum(g, s, 0, 0);
    }
};





//Knapsack
// User function Template for C++

class Solution {
  public:
    int ans(vector<int>& val, vector<int>& wt, int capacity, int i, vector<vector<int>> dp){
        if(i==0){
            return (capacity/wt[0])*val[0];
        }
        if(dp[i][capacity]!=-1){
            return dp[i][capacity];
        }
        int ntake = ans(val, wt, capacity, i-1, dp);
        int take = 0;
        if(wt[i]<=capacity){
        take = val[i] + ans(val, wt, capacity-wt[i], i, dp);
        }
        
        return dp[i][capacity] = max(ntake, take);
        
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int> (capacity+1, -1));
        return ans(val, wt, capacity, n-1, dp);
    }
};


//tabulation
class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

        // Base case (first item)
        for (int w = 0; w <= capacity; w++) {
            dp[0][w] = (w / wt[0]) * val[0];
        }

        // Build DP table
        for (int i = 1; i < n; i++) {
            for (int w = 0; w <= capacity; w++) {
                int notTake = dp[i - 1][w];
                int take = INT_MIN;
                if (wt[i] <= w) {
                    take = val[i] + dp[i][w - wt[i]]; // unbounded, so dp[i]
                }
                dp[i][w] = max(take, notTake);
            }
        }

        return dp[n - 1][capacity];
    }
};


class Solution {
public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<int> prev(capacity+1);
        for(int i=0;i<=capacity;i++){
            prev[i] = (i/wt[0])*val[0];
        }

    
       
        for (int i = 1; i < n; i++) {
            vector<int> next(capacity+1);
            for (int w = 0; w <= capacity; w++) {
                int notTake = prev[w];
                int take = INT_MIN;
                if (wt[i] <= w) {
                    take = val[i] + next[w - wt[i]];
                }
                next[w] = max(take, notTake);
            }
            prev = next;
        }

        return prev[capacity];
    }
};




//LCS 

class Solution {
public:
    int ans(string text1, string text2, int i, int j){
        if(i<0 || j<0) return 0;
        if(text1[i]==text2[j]){
            return 1+ans(text1, text2, i-1, j-1);
        }


        return 0+max(ans(text1, text2, i-1, j), ans(text1, text2, i,j-1));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.size();
        int b = text2.size();
        
        return ans(text1, text2, a-1, b-1);
    }
};

//memoisation

class Solution {
public:
    int ans(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i - 1] == text2[j - 1]) {
            return dp[i][j] = 1 + ans(text1, text2, i - 1, j - 1, dp);
        }

        return dp[i][j] = max(ans(text1, text2, i - 1, j, dp),
                              ans(text1, text2, i, j - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.size();
        int b = text2.size();
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
        return ans(text1, text2, a, b, dp);
    }
};

//Tabulation


class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int a = text1.size();
        int b = text2.size();
        vector<vector<int>> dp(a + 1, vector<int>(b + 1, -1));
        for (int i = 0; i <= a; i++) dp[i][0] = 0;
        for (int j = 0; j <= b; j++) dp[0][j] = 0;

        for(int i=1;i<=a;i++){
            for(int j=1;j<=b;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[a][b];
    }
};




//Longest common palindrome subsequence

//Recurrence
class Solution {
public:
    int ans(string s, string t, int i , int j){
        if(i<0 ||j<0) return 0;
        if(s[i]==t[j]){
            return 1+ans(s,t, i-1, j-1);
        }
        return 0 + max(ans(s, t, i-1, j), ans(s, t, i, j-1));


    }
    int longestPalindromeSubseq(string s) {
        string  t = reverse(s.begin(), s.end());
        int n = s.size();
        return ans(s, t, n-1, n-1)
    }
};

//memoisation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans(string &s, string &t, int i , int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j])
            return dp[i][j] = 1 + ans(s, t, i - 1, j - 1, dp);

        return dp[i][j] = max(ans(s, t, i - 1, j, dp),
                              ans(s, t, i, j - 1, dp));
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, -1));
        return ans(s, t, n - 1, n - 1, dp);
    }
};



//1 based memoisation 
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ans(string &s, string &t, int i , int j, vector<vector<int>>& dp) {
        if (i == 0 || j == 0) return 0; // ✅ 1-based base case
        if (dp[i][j] != -1) return dp[i][j];

        if (s[i - 1] == t[j - 1])
            return dp[i][j] = 1 + ans(s, t, i - 1, j - 1, dp);

        return dp[i][j] = max(ans(s, t, i - 1, j, dp),
                              ans(s, t, i, j - 1, dp));
    }

    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return ans(s, t, n, n, dp); // ✅ 1-based call
    }
};


//tabulation


//memoisation
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        int n = s.size();

        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        for(int j=0;j<=n;j++){
            dp[0][j] = 0;
        }

        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if (s[i - 1] == t[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
                
            }
        }
        return dp[n][n];
    }
};






//1312. Minimum Insertion Steps to Make a String Palindrome

//recurrence

class Solution {
public:
    int ans(string s, int i, int j){
        if(i>=j){
            return 0;
        }
        
        if(s[i]==s[j]){
            return ans(s, i+1, j-1);
        }
            int left = 1 + ans(s, i+1, j);
            int right = 1 + ans(s, i, j-1);
            return min(left, right);

        
    }
    int minInsertions(string s) {
        int n = s.size();
        
        return ans(s, 0, n-1);
    }
};


//memoisation
class Solution {
public:
    int ans(string s, int i, int j, vector<vector<int>>& dp){
        if(i>=j){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j] = ans(s, i+1, j-1, dp);
        }
        else{
            int left = 1 + ans(s, i+1, j, dp);
            int right = 1 + ans(s, i, j-1, dp);
            return dp[i][j] = min(left, right);
        }

        
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return ans(s, 0, n-1, dp);
    }
};


//shortest common supersequence

class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        for(int j=0;j<=m;j++) dp[0][j] = 0;
        for(int i=0;i<=n;i++) dp[i][0] = 0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        string ans = "";
        int i=n;
        int j=m;
        while(i>0 && j>0){
            if(s[i-1]==t[j-1]){
                ans+= s[i-1];
                i--;
                j--;
            }
            else if(dp[i-1][j]>dp[i][j-1]){
                ans+= s[i-1];
                i--;
            }
            else{
                ans+= t[j-1];
                j--;
            }
        }

        while(i>0){
            ans+= s[i-1];
            i--;
        }

        while(j>0){

            ans+= t[j-1];
            j--;
        }

        reverse(ans.begin(), ans.end());

        return ans;

    }
};



//edit distance

//memoisation
class Solution {
public:
    int ans(string s, string t, int i, int j, vector<vector<int>>& dp){

        if(i<0) return j+1;
        if(j<0) return i+1;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]) return dp[i][j] = 0 + ans(s,t,i-1,j-1, dp);
        
            //insertion, deletion, replace
            return dp[i][j] =  1 + min(ans(s,t,i,j-1, dp), min(ans(s,t, i-1, j, dp), ans(s, t, i-1, j-1, dp)));
            
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return ans(word1, word2, n-1, m-1, dp);
    }
};

//tabulation

class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=0;i<=n;i++){
            dp[i][0] = i;
        }
        for(int j=0;j<=m;j++){
            dp[0][j] = j;
        }
        

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j], dp[i-1][j-1]));
                }
            }
        }

        return dp[n][m];
    }
};




//Distinct Subsequences 

class Solution {
public:
    int ans(int i, int j, string s, string t){
        if(j<0) return 1;
        if(i<0) return 0;

        if(s[i]==t[j]){
            return ans(i-1, j-1, s, t) + ans(i-1, j, s, t);
        }
        else{
            return ans(i-1, j, s, t);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        return ans(n-1, m-1, s, t);
    }
};











//SELL AND BUY STOCKS 2

class Solution {
public:
    int ans(int i, int b, vector<int>& prices, int n, vector<vector<int>> dp){
        if(i==n) return 0;
        if(dp[i][b]!=-1){
            return dp[i][b];
        }
        long profit = 0;
        if(b){
            profit = max(-prices[i] + ans(i+1, 0, prices, n, dp), ans(i+1, 1, prices, n, dp));
        }
        else{
            profit  = max(prices[i] + ans(i+1, 1, prices, n, dp), ans(i+1, 0, prices, n, dp));
        }

        return dp[i][b] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, -1));
        return ans(0, 1, prices, n, dp);
    }
};

//tabulation
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1, vector<int> (2, -1));
        dp[n][0] = dp[n][1] = 0;
        for(int i=n-1;i>=0;i--){
            for(int b = 0;b<=1;b++){
            long profit=0;
                if(b){
            profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]);
        }
        else{
            profit  = max(prices[i] + dp[i+1][1], dp[i+1][0]);
        }
            dp[i][b]=profit;
            }  
                  }
        
        return dp[0][1];
    }
};

//space 
class Solution {
public:
    
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> prev(2,0);
        prev[0] = prev[1] = 0;
        for(int i=n-1;i>=0;i--){
            vector<int> curr(2,0);
            for(int b = 0;b<=1;b++){
            long profit=0;
                if(b){
            profit = max(-prices[i] + prev[0], prev[1]);
        }
        else{
            profit  = max(prices[i] + prev[1], prev[0]);
        }
            curr[b]=profit;
            }  
            prev=curr;
                  }
        
        return prev[1];
    }
};

//BUY SELL STOCK 3

//recursion
class Solution {
public:
    int solve(int i, int buy, vector<int> &prices, int trans) {
        if(i == prices.size() || trans == 2) return 0;

        int profit = 0;
        
        if(buy) {
            
            int take = -prices[i] + solve(i+1, 0, prices, trans);
            
            int skip = solve(i+1, 1, prices, trans);

            profit = max(take, skip);
        }
        
        else {
            
            int sell = prices[i] + solve(i+1, 1, prices, trans + 1);
            
            int skip = solve(i+1, 0, prices, trans);

            profit = max(sell, skip);
        }

        return profit;
    }

    int maxProfit(vector<int>& prices) {
        return solve(0, 1, prices, 0);
    }
};

//memoisation
class Solution {
public:
    int solve(int i, int buy, vector<int> &prices, int trans, vector<vector<vector<int>>>& dp) {
        if(i == prices.size() || trans == 2) return 0;
        if(dp[i][buy][trans]!=-1) return dp[i][buy][trans];
        int profit = 0;
        
        if(buy) {
            
            int take = -prices[i] + solve(i+1, 0, prices, trans, dp);
            
            int skip = solve(i+1, 1, prices, trans, dp);

            profit = max(take, skip);
        }
        
        else {
            
            int sell = prices[i] + solve(i+1, 1, prices, trans + 1, dp);
            
            int skip = solve(i+1, 0, prices, trans, dp);

            profit = max(sell, skip);
        }

        return dp[i][buy][trans] = profit;
    }

    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>> (2, vector<int> (3, -1)));
        return solve(0, 1, prices, 0, dp);
    }
};


//longest increasing subsequence
//recusrion
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int i, int prev, vector<int>& nums) {
        // Base case
        if (i == nums.size()) return 0;

        // Option 1: skip current element
        int notTake = solve(i + 1, prev, nums);

        // Option 2: take current element (if possible)
        int take = 0;
        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums);
        }

        // Return max of both choices
        return max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        return solve(0, -1, nums);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10,9,2,5,3,7,101,18};
    cout << sol.lengthOfLIS(nums);
}

//dp
class Solution {
public:
    int solve(int i, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;

        // Shift prev by +1 to handle -1 index in dp
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int notTake = solve(i + 1, prev, nums, dp);
        int take = 0;

        if (prev == -1 || nums[i] > nums[prev]) {
            take = 1 + solve(i + 1, i, nums, dp);
        }

        return dp[i][prev + 1] = max(take, notTake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // dp[i][prev+1]
        return solve(0, -1, nums, dp);
    }
};



