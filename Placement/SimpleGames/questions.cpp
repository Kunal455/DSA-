//TWO SORT 
//HASHMAP
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;   // value → index

        for(int i = 0; i < nums.size(); i++){
            int dif = target - nums[i];

            if(mp.find(dif) != mp.end()){
                return { mp[dif], i };
            }

            mp[nums[i]] = i;
        }

        return {};
    }
};



//TWO POINTER
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        vector<pair<int, int>> v;

        for(int i=0;i<n;i++){
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        int l=0;
        int r=n-1;
        int sum = 0;
        while(l<=r){
            sum = v[l].first+ v[r].first;

            if(sum==target){
                return {v[l].second, v[r].second} ;
            }
            else if(sum>target){
                r--;
            }
            else{
                l++;
            }
        }

        return {0,0};
       
    }
};


//stock buy sell

class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        int mini=arr[0];  int profit=0;
        for(int i=1;i<n-1;i++){
            int cash = arr[i]-mini;
            profit= max(profit, cash);
            mini = min(arr[i], mini);

        }

        return profit;
    }
};

//moving zeros
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int n = arr.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=0){
                swap(arr[i], arr[j]);
                j++;
            }
        }
        return;
    }
};

//rotate array by k

class Solution {
public:
    void rotate(vector<int>& arr, int k) {
        
        int n=arr.size();
        k=k%n;
        reverse(arr.begin(), arr.end());
        reverse(arr.begin(), arr.begin()+k);
        reverse(arr.begin()+k, arr.end());

        return;
    }
};

//majority ele

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size();
        
        map<int, int> mp;
        
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        
        for(auto it:mp){
            if(it.second>n/2) return it.first;
        }
        
        return -1;
    }
};


//using moores
class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        int ele;
        int c = 0;
        for(int i=0;i<n;i++){
            if(c==0){
                ele = arr[i];
                c++;
            }
            else if(arr[i]==ele){
                c++;
            }
            else{
                c--;
            }
        }
            int co = 0;
            for(int i=0;i<n;i++){
                if(arr[i]==ele){
                    co+=1;
                }
            }
        if(co>n/2) return ele;
        return -1;
    }
};


//missing number

class Solution {
public:
    int solve(int n){
        if(n==0) return 0;
        return n+ solve(n-1);
    }
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum = solve(n);
        int arrsum = accumulate(nums.begin(), nums.end(), 0);

        return sum-arrsum;
    }
};


//sort array by  k
//set

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        int n = nums.size();
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int idx = 0;
        for(auto s:st){
            nums[idx++]=s;
        }

        return idx;
    }
};

//optimal two pointer

class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        int n = arr.size();
        int j=0;
        for(int i=1;i<n;i++){
            if(arr[j]!=arr[i]){
                j++;
                arr[j]=arr[i];
            }
        }
        return j+1;
    }
};


//max sum of subarray

class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        int n = arr.size();
        int sum = 0;
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            sum += arr[i];
            if(sum>maxi){
                maxi = sum;
            }
            if(sum<0){
                sum=0;
            }
        }
        return maxi;
    }
};





//max subarray with sum k

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> mp;
        int sum=0;
        int maxlen = 0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum==k){
                maxlen = max(maxlen, i+1);
            }
            
            if(mp.find(sum-k)!=mp.end()){
                maxlen = max(maxlen, i-mp[sum-k]);
            }
            if(mp.count(sum) == 0) mp[sum] = i;

        }
        
        return maxlen;
       
    }
};

//duplcate number

class Solution { public: int findDuplicate(vector<int>& nums) { int n = nums.size(); map<int, int> mp; for(int i=0;i<n;i++){ mp[nums[i]]++; } for(auto x: mp){ if(x.second>1){ return x.first; } } return -1; } };


//Top k elemets
//using comparator

class Solution {
public:
    static bool comp(const pair<int, int>& a,const  pair<int, int>& b){
        return a.second>b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        vector<pair<int, int>> p;
        for(auto m: mp){
            p.push_back({m.first, m.second});
        }

        sort(p.begin(), p.end(), comp);

        vector<int> ans;
        for(int i = 0; i < k; i++){
            ans.push_back(p[i].first);
        }

        return ans;
        
    }
};

//using priority q

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for(int i=0;i<n;i++){
            mp[nums[i]]++;

        }


        priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;

        for(auto &x : mp){
            pq.push({x.second, x.first});
            if(pq.size()>k) pq.pop();
        }

        vector<int> v;
        while(!pq.empty()){
            v.push_back(pq.top().second);
            pq.pop();
        }
        return v;
    }
};

//longest consecutive subsequence

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st;

        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        int longest = 0;
        for(int x: st){
            if(st.find(x-1)==st.end()){
                int curr = x;
                int c= 1;
                while(st.find(curr+1)!=st.end()){
                    curr=curr+1;
                    c+=1;
                }
            longest = max(longest, c);
            }
        }

        return longest;
    }
};


//longest substring without k

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l=0;
        int r=0;
        vector<int> v(256, 0);
        int length = 0;
        while(r<n){
            if(v[s[r]]==0){
                v[s[r]]=1;
                length = max(length, r-l+1);
                r++;
            }
            else{
                v[s[l]]=0;
                l++;
            }
        }
        return length;
    }
};

//count distinct elements in window k

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> mp;
        vector<int> ans;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
        }
        
        ans.push_back(mp.size());
        
        for(int i=k;i<n;i++){
            mp[arr[i-k]]--;
            mp[arr[i]]++;
            
            if(mp[arr[i-k]]==0){
                mp.erase(arr[i-k]);
            }
            
            ans.push_back(mp.size());
            
        }
        
        
        
        
        
        return ans;
        
    }
};


//maximum sum subarray of size k
class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int sum = 0;
        
        for(int i=0;i<k;i++){
            sum+=arr[i];
        }
        int maxi = sum;
        for(int i=k;i<n;i++){
            sum-=arr[i-k];
            sum+=arr[i];
            
            maxi = max(maxi,sum);
            
            
        }
        return maxi;
    }
};


//minimum window substring

class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size();
        int m = t.size();

        unordered_map<char,int> hash;

        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }

        int l=0;
        int r=0;
        int count=0;
        int minl = INT_MAX;
        int ind = -1;

        while(r<n){
            if(hash[s[r]]>0){
                count++;
            }
            hash[s[r]]--;
            while(count==m){
                if(r-l+1<minl){
                    minl = r-l+1;
                    ind=l;
                }
                hash[s[l]]++;
                if(hash[s[l]]>0){
                    count--;
                }
                l++;
            }

            r++;
        }
        
        string ans = "";
        if(ind==-1) return ans;
        return s.substr(ind, minl);

        
    }
};






//

class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();

        vector<int> hash(26,0);

        int l=0;
        int r=0;
        int maxf = 0;
        int maxl = 0;
        while(r<n){
            hash[s[r]-'A']++;
            maxf = max(maxf, hash[s[r]-'A']);
            while((r-l+1)- maxf>k){
                hash[s[l]-'A']--;
                int maxf=0;
                for(int i=0;i<26;i++){
                    maxf = max(maxf, hash[i]);
                }
                l++;
            }
            if((r-l+1)-maxf<=k){
                maxl = max(maxl, r-l+1);
            }
            r++;
        }

        return maxl;
    }
};

//find all anagram in string

class Solution {
public:
    bool allZero(vector<int> &hash) {
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) return false;
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();

        vector<int> hash(26,0);
        for(int i=0;i<p.size();i++){
            hash[p[i]-'a']++;
        }

        int l=0;
        int r=0;
        vector<int> ans;

        while(r<n){
            hash[s[r]-'a']--;
            if(r-l+1==p.size()){
                if(allZero(hash)){
                    ans.push_back(l);
                }
            
            hash[s[l]-'a']++;
            l++;
            }

        r++;
        }
        return ans;
    }
};




//LINKED LIST ***********************************************************************************************************8888\
//reverse LinkedList
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr!=NULL){
            ListNode* nex = curr->next;
            curr->next = prev;
            prev=curr;
            curr=nex;
        }

        return prev;
    }
};



//Detect cycle in linkedlist

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow==fast){
                return true;
            }
        }

        return false;
    }
};



//Find starting node in cycle
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> mp;

        ListNode* curr=  head;
        while(curr!=nullptr){
            if(mp.find(curr)!=mp.end()){
                return curr;
            }
            mp[curr]=1;
            curr=curr->next;
        }

        return nullptr;
    }
};


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow=slow->next;
            fast = fast->next->next;

            if(slow==fast){
                slow = head;
                while(slow!=fast){
                    slow=slow->next;
                    fast=fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }
};

//remove n the node from last

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp = head;
        int i = 0;
        while(temp!=nullptr){
            i++;
            temp=temp->next;

        }
    

        int id = i-n;
        if(id==0){
            return head->next;
        }
        ListNode* prev=nullptr;
        int c=0;
        temp = head;
        while(temp!=nullptr){
            if(c==id){
                prev->next = temp->next;
                ListNode* del = temp;
                delete del;
                break;
            }
            prev=temp;
            temp=temp->next;
            c++;

        }

        return head;
    }
};




//TREES

//level order Traversal

/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    
    vector<vector<int>> levelOrder(Node *root) {
        // code here
        vector<vector<int>> ans;
        if(root==nullptr) return ans;
        
        queue<Node*> q;
        
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            for(int i=0;i<size;i++){
                
            Node* node = q.front();
            q.pop();
            
            
            if(node->left!=nullptr) q.push(node->left);
            if(node->right!=nullptr) q.push(node->right);
            level.push_back(node->data);
            }
            ans.push_back(level);
            
        }
        return ans;
        
    }
};




//Height of a Binary Tree

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    int height(Node* root) {
        // code here
        if(root==NULL) return -1;
        
        int l = 1 + height(root->left);
        int r = 1 + height(root->right);
        
        return max(l,r);
        
    }
};


//diameter Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans(TreeNode* root, int &maxi){
        if(root==nullptr) return 0;

        int left = ans(root->left, maxi);
        int right = ans(root->right, maxi);

        maxi = max(maxi, left+right);

        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==nullptr) return 0;
        int maxi = 0;
        ans(root, maxi);
        return maxi;
    }
};