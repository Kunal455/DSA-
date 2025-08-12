//pairs
// pair <int, int> p = {1, 3};
//p.first = 1, p.second = 3;
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     pair <int, int> p = {1, 3};
//     cout<<p.first<<p.second;  //1,3
// }


//for three numbers
//pair <int , pair<int, int>> p = {1, {3, 4}};
//p.first = 1 , p.second.first = 3, p.second.first = 4
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     pair<int, pair<int, int>> p = {1, {3, 4}};
//     cout<<p.first<<p.second.first<<p.second.first;
// }



//for array 
//pair <int, int> arr[] = {{1,2}, {2,5}, {5,1}}
//arr[1].second = 5
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     pair <int, int> arr[] = {{1,2}, {2,5}, {5,1}};
//     cout<<arr[1].second;
// }


//for vector
//vector< pair<int, int>>vec;
//v.push
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector< pair<int, int>>v;
//     v.push_back({1,2});
//     v.push_back({3, 4});
//     v.push_back({5, 6});
//     v.emplace_back(7,8);



//     vector<int> v1;
//     //to copy vector
//     vector<int> v2(v1); 
      
    
// }



/*#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<int>::iterator it = v.begin();
    it++;
    cout<<*(it)<<" ";
    cout<<*(it)<<" ";
    
    vector<int>::iterator it = v.end();
    
    
}
*/


//iteration in vector
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     vector<int> v;
//     v.push_back(1);
//     v.push_back(2);
//     v.push_back(3);

//     for(vector<int>::iterator it = v.begin(); it != v.end() ; it++){
//         cout<<*it<<" ";
//     }

//     cout<<endl;

//     for(auto it=v.begin(); it!=v.end(); it++){
//         cout<<*(it)<<" ";
//     }
//     cout<<endl;

//     for(auto it:v){
//         cout<<it<<" ";
//     }
//     cout<<endl;
//     //erase
//     v.erase(v.begin()+1, v.begin()+2);

//     for(auto it:v){
//         cout<<it<<" ";
//     }

//     cout <<endl;

//     vector<int> v1(2,100);  //{100, 100}
//     v1.insert(v1.begin(), 300); //{300, 100, 100}
//     v1.insert(v1.begin()+1, 2, 10); //{300, 10, 10, 100, 100}
//     for(auto it:v1){
//         cout<<it<<" ";
//     }
//     cout<<endl;

//     vector<int> copy(2,50);
//     v1.insert(v1.begin()+2, copy.begin(), copy.end());
//     for(auto it:v1){
//         cout<<it<<" ";
//     }

//    v1.swap(v2); //swap v1 {10, 30} v2 {20,40}  then v1{20,40} v2{10,30}
//    v1.clear();  //clear all
// }






//LIST
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     list<int> ls;
//     ls.push_back(5);
//     ls.emplace_back(4);
//     ls.push_front(2);
//     ls.emplace_front(1);

//     for(auto it:ls){
//         cout<<it<<" ";
//     }

//     //begin , swap, end, clear , insert, size all same to vector

// }


//stack  -   O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     stack<int> st;
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     st.push(4);
//     st.push(5);

//     cout<<st.top()<<endl;
//     st.pop();
//     cout<<st.top()<<endl;

//     cout<<st.size()<<endl;
//     cout<<st.empty()<<endl;

// }


//qUEUE - O(1)
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     queue<int> q;
//     q.push(1);
//     q.push(2);
//     q.push(3);
//     q.push(4);

//     cout<<q.back()<<endl;
//     q.back()+=5;
//     cout<<q.back()<<endl; //9

//     cout<<q.front();//1
//     q.pop();
//     cout<<q.front();//2
// }


//priority queue
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     priority_queue<int> pq;
//     pq.push(1);
//     pq.push(2);
//     pq.push(3);
//     pq.push(4);

//     cout<<pq.top()<<endl;

//     pq.pop();

//     cout<<pq.top()<<endl;

//     priority_queue<int, vector<int>, greater<int>> PQ;  //min heap

//     //push pop logn
//     //top O(1)
// }


//set - store unique values in sorted manner


//1. Insertion & Deletion Functions
// Function	Description
// insert(value)	Inserts value into the set (only if it's not already present).
// erase(value)	Removes the element value from the set.
// clear()	Removes all elements from the set.
// swap(set2)	Swaps contents with another set set2.
// emplace(value)	Inserts value directly (faster than insert).
// erase(iterator)	Removes an element at a specific iterator position.

//Function	Description
// count(value)	Returns 1 if value exists, otherwise 0.
// find(value)	Returns an iterator pointing to value, or end() if not found.
// lower_bound(value)	Returns an iterator to the first element ≥ value.
// upper_bound(value)	Returns an iterator to the first element > value.


//3. Iterators
// Function	Description
// begin()	Returns an iterator to the first element.
// end()	Returns an iterator past the last element.
// rbegin()	Returns a reverse iterator to the last element.
// rend()	Returns a reverse iterator past the first element.

// 4. Size & Capacity
// Function	Description
// size()	Returns the number of elements in the set.
// empty()	Returns true if the set is empty, otherwise false.
// max_size()	Returns the maximum possible number of elements the set can hold.

// 5. Set Operations
// Function	Description
// merge(set2)	Merges set2 into the current set.
// equal_range(value)	Returns a pair of iterators for lower_bound and upper_bound.

// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     set<int> s;
//     s.insert(1);
//     s.insert(2);
//     s.insert(2);
//     s.insert(3);


//     auto it = s.find(2);
//     cout<<*(it)<<endl;

//     auto i = s.find(4);
//     cout<<*(it)<<endl;

//     int cnt  =  s.count(1); //if 1 is present then give 1 else 0
//     cout<<cnt<<endl;

//     s.erase(2);
    

//     //{1,2,3,4,5}
//     auto it1 = s.find(2);
//     auto it2 = s.find(4);
//     s.erase(it1, it2); //after erase{1,4,5}
    
//     //all in log n complexity
// auto i1= it1.upperbound(1);
// auto i2 = it1.lowerboound(2);


// }


//Multipleset
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     multiset<int>ms;
//     ms.insert(1);
//     ms.insert(1);
//     ms.insert(1);
//     //{1,1,1};

//     ms.erase(1);  //all 1's erase

//     ms.erase(ms.find(1)); //only a single one erased


// }




//unordered set  :-    not in sorted order  O(1)
//upper and lower bound  sunction doesnot work
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     unordered_set<int> st;
//     all same as set
// }



//MAP  :-   key and values    (unique keys in sorted order)
#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int, int> mp;
    mp[1] = 2;
    mp.emplace(2,3);
    mp.insert({3,6});

    for(int i=1;i<=3;i++){
        cout<<mp[i]<<endl;
    }

    //or

    for(auto it: mp){
        cout<<it.first<<it.second<<endl;
    }

    cout<<mp[1];
    cout<<mp[2];

    auto it = mp.find(2);
    cout<<it->second<<endl;


    auto i1 = mp.upper_bound(1);
    auto i2 = mp.lower_bound(3);
    cout<<i1->second<<" "<<i2->second<<endl;

    map<int, pair<int, int>> mp1;
    mp1[1] = {5,5};
    
    mp1.insert({2,{8,8}});
    
    
    
    //O(1)

}


//Unordered map :-  unique keys but not sorted


//Sorting algorithm
//array = {1,5,3,7,89,4}
//sort(array, array+4);
//sort(a, a+n);
//sort(v.begin(), v.end());
//sort(a, a+, greater<int>);



//comparator
//bool comp(pair<int, int> p1,  pair<int, int>p2){
//sort acc to second ele
//if(p1.second<p2.second) return true;
//if(p1.second>p2.secodnd) return false;

//if second ele same then acc to first
// if(p1.first<p2.first) return true;
// if(p1.first>p2.first) return false;

//}
//pair<int, int> a[] = {{1,2}, {2,3}, {3,4}. {4,5}};
//sort(a, a+n, comp)
