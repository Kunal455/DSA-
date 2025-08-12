//Longest Substring without repeating character
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int maxLen = 0;
        int start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (mp.find(s[i]) != mp.end() && mp[s[i]] >= start) {
                // Character is repeated inside the current window
                start = mp[s[i]] + 1;
            }
            mp[s[i]] = i; // Update last seen index
            maxLen = max(maxLen, i - start + 1);
        }

        return maxLen;
    }
};







//Max Consecutive Ones III
//better
 class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n =nums.size();
        int l=0,r=0,len=0,zeros=0;
        while(r<n){
            if(nums[r]==0){
                zeros++;
            }
            while(zeros>k){
                if(nums[l]==0) zeros--;
                l++;
            }

            if(zeros<=k){
                len=max(len, r-l+1);
            }

            r++;
        }

    return len;
    }
};







//optimal
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();

        int l=0;
        int r=0;
        int z=0;
        int len = 0;

        while(r<n){
            if(nums[r]==0) z++;

            if(z>k){
                if(nums[l]==0) z--;
                l++;
            }

            if(z<=k){
                len = max(len, r-l+1);
            }

            r++;
        }

        return len;
    }
};







//Longest Reapeating character replacement

//optimal
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxCount = 0, maxLength = 0;
        int left = 0;
        vector<int> freq(26, 0); // For characters A-Z

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'A']++;
            maxCount = max(maxCount, freq[s[right] - 'A']);

            // If changes needed > k, shrink window
            while ((right - left + 1) - maxCount > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};







//Binary Subarrays with sum
//Brute

class Solution {
public:
int atmost(vector<int>& nums, int goal){
    if(goal<0) return 0;
        int l=0,r=0,sum=0,count=0;
        int len=0;
        while(r<nums.size()){
            sum+=nums[r];

            while(sum>goal && l<nums.size()){
                sum-=nums[l];
                l++;
            }
            
                count+=(r-l+1);
                r+=1;
            
        }
        return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        
        return atmost(nums, goal) - atmost(nums, goal-1);
    }
};







//Optimal
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        int count = 0;
        vector<int> ps(n,0);

        ps[0] = nums[0];

        for(int i=1;i<n;i++){
            ps[i] = ps[i-1] + nums[i];
        }

        unordered_map<int, int> mp;

        for(int j=0;j<n;j++){
            if(ps[j] == goal){
                count++;
            }
            int value = ps[j] - goal;
        if(mp.find(value)!=mp.end()){
            count+=mp[ps[j]-goal];
        }

        mp[ps[j]]++;
        }

        return count;
        
    }
};




//count the number with nice subarrays
//sliding window
class Solution {
public:
    int atmost(vector<int>& nums, int k){
        int n = nums.size();
        int r =0 ;
        int l=0;
        int sum=0;
        int ans = 0;
        while(r<n){
            sum+= nums[r]%2;

            while(sum>k){
                sum-=nums[l]%2;
                l++;
            }

            
                ans = ans+(r-l+1);
                r++;
            
        }
        return ans;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        

        return atmost(nums, k) - atmost(nums,k-1);
    }
};



//Hash

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> odds;

        odds[0] = 1;
        int c= 0;
        int ans =0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0) c=c+1;

            int value = c-k;
            if(odds.find(value)!=odds.end()){
                ans += odds[value];
            }

            odds[c]++;

            
        }

        return ans;
    }
};










//1423. Maximum Points You Can Obtain from Cards
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int lsum  = 0;
        int sum = 0;
        int rsum = 0;
        for(int i=0;i<k;i++){
            lsum+=cardPoints[i];
        }
        sum = lsum;
        int r=n-1;
        for(int i=k-1;i>=0;i--){
            rsum = rsum+cardPoints[r];
            lsum = lsum - cardPoints[i];
            r--;
            sum = max(sum, rsum+lsum);
        }

        return sum;


    }
};





//Fruits in  the basket
class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        unordered_map<int, int> mp;
        int r = 0, l = 0, maxlen = 0;

        while (r < n) {
            mp[fruits[r]]++;

            while (mp.size() > 2) {
                mp[fruits[l]]--;
                if (mp[fruits[l]] == 0) {
                    mp.erase(fruits[l]);
                }
                l++;
            }

            maxlen = max(maxlen, r - l + 1);
            r++;
        }

        return maxlen;
    }
};
