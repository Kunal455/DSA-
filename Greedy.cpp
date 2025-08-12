//Assign Cookies

/*class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int l=0, r=0;
        while(l<m && r<n){
            if(s[l]>=g[r]){
                r=r+1;
            }

            l=l+1;
        }

        return r;
    }
};
*/


//Lemonage


class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();
        int five=0;
        int ten=0;
        for(int i=0;i<n;i++){
            if(bills[i]==5){
                five++;
            }
            else if(bills[i]==10){
                if(five>0){
                    five--;
                    ten++;
                }
                else{
                    return false;
                }
            }
            else{
                if(five>0 && ten>0){
                    ten--;
                    five--;
                }
                else if(five>=3){
                    five-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};





//MIN no of coins

// User function Template for C++

class Solution {
  public:
    vector<int> minPartition(int N) {
        // code here
       
        
        vector<int> ans;
        int cur[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
        int i=0;
        int notes=0;
        
        while(N!=0){
            notes = N/cur[i];
            while(notes--){
                ans.push_back(cur[i]);
            }
            N%=cur[i];
            i++;
        }
        
        return ans;
        
    }
};


//valid parenthesis

class Solution {
public:
    bool checkValidString(string s) {
        int n = s.size();
        int min=0;
        int max=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                min+=1;
                max+=1;
            }
            else if(s[i]==')'){
                min-=1;
                max-=1;
            }
            else{
                min-=1;
                max+=1;
            }

        if(min<0) min=0;
        if(max<0) return false;

        }
        return (min==0);
    }
};






//JUMP Game

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxind = 0;
        for(int i=0;i<n;i++){
            if(i>maxind) return false;

            maxind = max(maxind, nums[i]+i);
        }

        return true;
    }
};






//JUMP GAME 2
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int jumps = 0;

        while (r < n - 1) { 
            int maxend = 0;
            for (int i = l; i <= r; i++) {
                maxend = max(maxend, i + nums[i]);
            }
            l = r + 1;
            r = maxend;
            jumps++;
        }
        return jumps;
    }
};







//CANDY
//BRUTE FORCE
class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> left(ratings.size());
        vector<int> right(ratings.size());
        left[0] = 1;
        for(int i=1;i<ratings.size();i++){
            if(ratings[i]>ratings[i-1]){
                left[i] = left[i-1]+1;
            }
            else{
                left[i] = 1;
            }
        }

        right[ratings.size()-1] = 1;
        for(int j=ratings.size()-2;j>=0;j--){
            if(ratings[j]>ratings[j+1]){
                right[j] = right[j+1]+1;
            }
            else{
                right[j] = 1;
            }
        }
        int sum=0;
        int maxi=0;
        for(int i=0;i<ratings.size();i++){
            sum += max(left[i], right[i]);
        }

        return sum;
    }
};


//optimal


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int i = 1;
        int candy = n;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                i++;
                continue;
            }

            int peak = 0;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                candy += peak;
                i++;
            }

            int dip = 0;
            while (i < n && ratings[i] < ratings[i - 1]) {
                dip++;
                candy += dip;
                i++;
            }

            // Adjust for peak-dip overlap (the peak element was counted twice)
            candy -= min(peak, dip);
        }

        return candy;
    }
};



//N meetings in a room

#include <bits/stdc++.h>
using namespace std;

struct Meeting {
    int start;
    int end;
    int pos;
};

class Solution {
public:
    static bool comparator(Meeting m1, Meeting m2) {
        if (m1.end == m2.end)
            return m1.pos < m2.pos;
        return m1.end < m2.end;
    }

    vector<int> maxMeetings(vector<int>& start, vector<int>& end) {
        int n = start.size();
        vector<Meeting> meetings;

        // Step 1: Assign Meeting values
        for (int i = 0; i < n; i++) {
            meetings.push_back({start[i], end[i], i + 1});
        }

        // Step 2: Sort meetings by end time
        sort(meetings.begin(), meetings.end(), comparator);

        int lastEnd = -1;
        vector<int> selectedMeetings;

        // Step 3: Greedy selection
        for (int i = 0; i < n; i++) {
            if (meetings[i].start > lastEnd) {
                lastEnd = meetings[i].end;
                selectedMeetings.push_back(meetings[i].pos);
            }
        }

        return selectedMeetings;
    }
};

int main() {
    Solution obj;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end =   {2, 4, 6, 7, 9, 9};

    vector<int> result = obj.maxMeetings(start, end);

    cout << "Meetings positions: ";
    for (int pos : result) {
        cout << pos << " ";
    }
    cout << endl;

    return 0;
}


//Minimum Platforms

class Solution {
  public:
  
    
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        // Your code here
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        
        int c=0;
        int i=0;
        int j =0;
        int maxc = 0;
        while(i<arr.size()){
            if(arr[i]<=dep[j]){
                c++;
                i++;
            }
            else{
                c--;
                j++;
            }
        maxc = max(maxc, c);
        }
        
       return maxc;
    }
};


//Non Overlapping INtervals

class Solution {
public:

    static bool comp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }


    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();

        sort(intervals.begin(), intervals.end(), comp);


        int c=0;
        int last=intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0] < last){
                c++;

            }
            else{
                last = intervals[i][1];
            }
        }

        return c;
    }
};


//insert intervals
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int i = 0, n = intervals.size();

    // 1. Add all intervals before newInterval
    while (i < n && intervals[i][1] < newInterval[0]) {
        res.push_back(intervals[i]);
        i++;
    }

    // 2. Merge all overlapping intervals
    while (i < n && intervals[i][0] <= newInterval[1]) {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);

    // 3. Add remaining intervals
    while (i < n) {
        res.push_back(intervals[i]);
        i++;
    }

    return res;
}

int main() {
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16},{18,20},{21,25},{27,30}};
    vector<int> newInterval = {4,22};

    vector<vector<int>> result = insert(intervals, newInterval);

    for (auto &interval : result) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}

//Merge Interval
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // If 0 or 1 interval, nothing to merge
        if (intervals.size() <= 1) return intervals;

        // Step 1: Sort by start time
        sort(intervals.begin(), intervals.end());

        // Step 2: Result will store merged intervals
        vector<vector<int>> result;

        // Start with the first interval
        vector<int> current = intervals[0];

        // Step 3: Go through all intervals
        for (int i = 1; i < intervals.size(); i++) {
            // If overlapping
            if (intervals[i][0] <= current[1]) {
                // Merge by extending the end time
                current[1] = max(current[1], intervals[i][1]);
            } 
            else {
                // No overlap → push current interval and update current
                result.push_back(current);
                current = intervals[i];
            }
        }

        // Push the last interval
        result.push_back(current);

        return result;
    }
};
