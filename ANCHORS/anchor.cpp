//Kadane Algo

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        long long maxi = INT_MIN;
        long long sum = 0;
        int starti = -1;
        int endi = -1;
        int start = -1;
        for(int i=0;i<n;i++){
            if(sum==0) start=i;
            sum+=nums[i];

            if(sum>maxi){
                maxi = sum;
                starti = start;
                endi = i;
            }

            if(sum<0) sum=0;
        }
        return maxi;
    }
};




//Two SUM
class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        map<int, int> mp;
        for(int i=0;i<n;i++){
            int d = target-arr[i];
            if(mp.find(d)!=mp.end()){
                if(mp[d]>0){
                    return true;
                }
            }
            
            mp[arr[i]]++;
        }
        return false;
    }
};



class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
          vector<pair<int, int>>v;
          for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
          }
          sort(v.begin(), v.end());
    
          int l = 0;
          int r = n-1;
          while (l<r){
            int sum = v[l].first+v[r].first;
            if(sum==target){
                return {v[l].second, v[r].second};
            }
    
            else if(sum<target){
                l++;
            }
    
            else{
                r--;
            }
          }
          return {-1,-1};
    
        }
    };



//Longest Consecutive sequence

