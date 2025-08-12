/*#include<bits/stdc++.h>
using namespace std;

class MAXHEAP{
    public:
    int *arr;
    int size;
    int total;

    MAXHEAP(int n){
        arr = new int[n];
        size=0;
        total = n;
        
    }

    void insert(int value){
        if(size==total){
            cout<<"Heap overflow";
            return;
        }

        arr[size] = value;
        int index = size;
        size++;

        while(index>0 && arr[index]>arr[(index-1)/2]){
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }
    }

    void Heapify(int index){
        int largest = index;
        int left = 2*index+1;
        int right = 2*index+2;

        if(left<size && arr[left]>arr[largest]){
            largest = left;
        }
        if(right<size && arr[right]>arr[largest]){
            largest = right;
        }

        if(largest != index){
            swap(arr[largest], arr[index]);
            Heapify(largest);
        }
    }

    void Delete(){
        if(size==0){
            cout<<"Heap UnderFlow/n";
            return;
        }
        arr[0] = arr[size-1];
        size--;

        Heapify(0);
    }

    void print(){
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

};
int main(){
   MAXHEAP h1(6);
   h1.insert(4);
   h1.insert(14);
   h1.insert(80);
   h1.print();
   h1.insert(100);
   h1.insert(60);
   h1.print();
   h1.Delete();
}*/









//max heap and min heap

/*#include<bits/stdc++.h>
using namespace std;
void heapify(int arr[], int i, int n){
    int largest = i;
    int left=2*i+1;
    int right=2*i+2;

    if(left<n && arr[left]>arr[largest]){
        largest = left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }

    if(largest!=i){
        swap(arr[i], arr[largest]);
        heapify(arr, largest, n);
    }
}

void MaxHeap(int arr[], int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr, i, n);
    }
}

void HeapSort(int arr[], int n){

    for(int i=n-1;i>0;i--){
        swap(arr[0], arr[i]);
        heapify(arr, 0, i);
    }

}
void printof(int arr[], int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {10,23,4,34,6,23,56,78,45,13};
    MaxHeap(arr, 10);
    printof(arr, 10);
    HeapSort(arr, 10);
    cout<<endl;
    printof(arr,10);

}*/



//  MAXHEAP Priority Queue

/*#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int> p;

    p.push(12);
    p.push(3);
    p.push(23);
    p.push(45);
    p.push(62);
    p.push(25);

    cout<<p.top()<<endl;
    p.pop();

    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
}
*/

//MINHEAP priority queue
 
/*
#include<bits/stdc++.h>
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int>> p;

    p.push(12);
    p.push(3);
    p.push(23);
    p.push(45);
    p.push(62);
    p.push(25);

    cout<<p.top()<<endl;
    p.pop();

    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
}




*/






//kth largest
/*
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        //min heap
        priority_queue<int, vector<int>, greater<int>> p;
        for(int i=0;i<k;i++){
            p.push(nums[i]);
        }

        for(int i=k;i<n;i++){
            if(nums[i]>p.top()){
                p.pop();
                p.push(nums[i]);
            }
        }

        return p.top();
    }

};


*/


//Hands of Straights
/*
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;

        map<int, int> count;
        for (int card : hand) {
            count[card]++;
        }

        for (auto& [card, freq] : count) {
            if (freq > 0) {
                for (int i = 1; i < groupSize; ++i) {
                    if (count[card + i] < freq) return false;
                    count[card + i] -= freq;
                }
            }
        }

        return true;
    }
};
*/


//sum of elements btw k1th and k2th sammlelest ele
/*
class Solution {
  public:
    long long sumBetweenTwoKth(long long A[], long long N, long long K1, long long K2) {
        // Your code goes here
       
        priority_queue<long long> pq1;
        priority_queue<long long> pq2;
        
        for(long long i=0;i<K1;i++){
            pq1.push(A[i]);
        }
        
        for(long long j=0;j<K2-1;j++){
            pq2.push(A[j]);
        }
        
        for(long long i=K1;i<N;i++){
            if(pq1.top()>A[i]){
                pq1.pop();
                pq1.push(A[i]);
            }
        }
        
        
        
        for(long long i=K2-1;i<N;i++){
            if(pq2.top()>A[i]){
                pq2.pop();
                pq2.push(A[i]);
            }
        }
        
        long long sum1 = 0;
        while(!pq1.empty()){
            sum1+=pq1.top();
            pq1.pop();
        }
        
        
        long long sum2 = 0;
        while(!pq2.empty()){
            sum2+=pq2.top();
            pq2.pop();
        }
        
        return sum2-sum1;
        
    }
};*/




//connect ropes with minimal const

class Solution {
  public:
    int minCost(vector<int>& arr) {
        int n = arr.size();
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        
        for(int i=0;i<n;i++){
            pq.push(arr[i]);
            
        }
        
        int sum = 0;
        while(pq.size()>1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            sum+= a+b;
            pq.push(a+b);
        }
        
        return sum;
    }
};






//max sum combination

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        int m = b.size();
        
        sort(a.rbegin(), a.rend());
        sort(b.rbegin(), b.rend());
        
        priority_queue<pair<int,pair<int,int>>>pq;
        set<pair<int, int>> vis;
        
        
        pq.push({a[0]+b[0], {0,0}});
        vis.insert({0,0});
        vector<int> ans;
        while(ans.size()<k){
            auto top = pq.top();
            pq.pop();
            
            
            
            int sum = top.first;
            int i=top.second.first;
            int j = top.second.second;
            ans.push_back(sum);
            
            
            if(i<n && vis.find({i+1,j})==vis.end()){
                pq.push({a[i+1]+b[j],{i+1,j}});
                vis.insert({i+1,j});
            }
            
            if(j<n && vis.find({i,j+1})==vis.end()){
                pq.push({a[i]+b[j+1],{i,j+1}});
                vis.insert({i,j+1});
            }
        }
        
        return ans;
        
    }
};



//K MOST FREQ ELEMENTS
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map <int, int> mp;
        vector<int> v;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
        }
        int i=0;
        while(i!=k){
            v.push_back(pq.top().second);
            pq.pop();
            i++;
        }

       

        
        return v;
    }
};



//kth largest in a stream

class KthLargest {
public:

    priority_queue<int, vector<int>, greater<int>> pq;
    int K;
    KthLargest(int k, vector<int>& nums) {
        K = k;
        for(int &num : nums){
            pq.push(num);

            if(pq.size()>k){
                pq.pop();
            }
        }

        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>K){
            pq.pop();
        }

        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */








 // find median in stream


 class MedianFinder {
public:
priority_queue<int> left;
priority_queue<int, vector<int> , greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty() || num<left.top()){
            left.push(num);
        }
        else{
            right.push(num);
        }



        //maintain left max heap 1 greater than right min hep

        if(left.size() > right.size()+1){
            right.push(left.top());
            left.pop();
        }
        else if(right.size()>left.size()){
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if(right.size()==left.size()){
            return (left.top()+right.top())/2.0;
        }

        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */








 //Merge M sorted Lists
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct compare{
        bool operator()(ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*> , compare> pq;

          for (ListNode* list : lists) {
            if (list != nullptr) {
                pq.push(list);
            }
        }
        ListNode* root = new ListNode(0);
        ListNode* tail = root;

        ListNode* temp;

        while(!pq.empty()){
            temp = pq.top();
            pq.pop();
            tail->next = temp;
            tail=temp;

            if(temp->next){
                pq.push(temp->next);
            }


        }

        return root->next;

    }
};



//Task Scheduler

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> mp(26,0);

        for(char& ch: tasks){
            mp[ch-'A']++; 
        }

        sort(mp.begin(), mp.end());

        int maxfreq = mp[25];
        int gadhe = maxfreq-1;
        int idleslots = n*gadhe;

        for(int i=24; i>=0; i--){
            idleslots -= min(mp[i], gadhe);
        }

        if(idleslots>0){
            return tasks.size() + idleslots;
        }

        return tasks.size();
    }
};
 
