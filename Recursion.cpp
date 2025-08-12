// sum of n numbers using recursion

/*
#include<bits/stdc++.h>
using namespace std;
int sumof(int i, int sum){
    if(i<0) return sum;

    sumof(i-1, sum+i);
}
int main(){
    int n;
    cin>>n;

    int sum = 0;
    cout<<sumof(n, sum);


}*/

/*
//Recusrion oN Array reverse
#include<bits/stdc++.h>
using namespace std;
vector<int> func(vector<int>& arr, int l, int r){
    if(l>=r) return arr;

    swap(arr[l], arr[r]);
    return func(arr, l+1, r-1);
}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int l=0;
    int r = n-1;
    vector<int> ans = func(arr, l, r);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }
}
*/
//also use swap(a[i], a[n-i-1])


//check string is 
/*#include<bits/stdc++.h>
using namespace std;
bool func(string name, int i){
    if(i>=name.size()/2) return true;
    if(name[i]!=name[name.size()-i-1]) return false;
    return func(name, i+1);

}
int main(){
string name = "KANAK";

bool palindromes  = func(name, 0);

if(palindromes){
    cout<<"yes";
}
else{
    cout<<"No";
}



}

*/








/*
#include<bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n<=1) return n;

    return fibo(n-1) + fibo(n-2);
}
int main(){
    int n;
    cin>>n;

    int ans = fibo(n);
    cout<<ans;
}*/


//subarrays
#include<bits/stdc++.h>
using namespace std;
void fun(int i, vector<int>& arr, vector<int>& v){
    if(i>=arr.size()){
        for(int j=0;j<v.size();j++){
            cout<<v[j];
        }
        cout<<endl;
        return;
    }

    v.push_back(arr[i]);
    fun(i+1, arr, v);
    v.pop_back();
    fun(i+1, arr, v);
    

}
int main(){
    int n;
    cin>>n;

    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int> v;

    fun(0, arr, v);
}