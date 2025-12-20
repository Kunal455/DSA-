// #include<bits/stdc++.h>
// using namespace std;
// int gcd(int n, int m){
//     if(m==0) return n;
//     return gcd(m, n%m);
// }
// int main(){
//     int n;
//     cin>>n;
//     int m;
//     cin>>m;
//     cout<<gcd(abs(n),abs(m));
// }



// #include<bits/stdc++.h>
// using namespace std;
// int sum(int n){
//     if(n==0) return 0;

//     return n+sum(n-1);
// }
// int main(){
//     int n;
//     cin>>n;
//     cout<<sum(n);
// }


// #include<bits/stdc++.h>
// using namespace std;
// int fact(int n){
//     if(n==0 || n==1) return 1;

//     return n*fact(n-1);
// }
// int main(){
//     int n;
//     cin>>n;

//     cout<<fact(n);
// }


/*#include<bits/stdc++.h>
using namespace std;
bool fun(int i, int p1, int p2, int t, vector<int>& v){
    if(p1>t || p2>t) return false;

    if(i==v.size()) return p1==t && p2==t;

    bool a = fun(i+1, p1*v[i], p2, t, v);
    bool b = fun(i+1, p1, p2*v[i], t, v);

    return a || b;

}
int main(){
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int target;
    cin>>target;

    bool ans = fun(0,1,1,target, v);
    cout<<ans;
}*/



/*#include<bits/stdc++.h>
using namespace std;
int fun(int n, int x){
    if(n==1 && x==1) return 0;

    if(n>x) return 1+fun(n-x, x);
    else return 1+fun(n, x-n);
}
int main(){
    int n;
    cin>>n;

    int ans=INT_MAX;
    for(int i=1;i<=n;i++){
        if(__gcd(n,i)!=1) continue;
        ans = min(ans, fun(n, i));
    }

    cout<<ans;
}*/



// #include<bits/stdc++.h>
// using namespace std;
// bool check(int n){
//     if(n==1 || n==7) return true;
//     if(n<10) return false;
//     int sum = 0;
//     while(n){
//         int r = n%10;
//         sum+= r*r;
//         n/=10;
//     }

//     return check(sum);
// }
// int main(){
//     int n;
//     cin>>n;

//     cout<<check(n);
// }


#include<bits/stdc++.h>
using namespace std;
bool isprime(int n){
    if(n<=1) return false;
    if(n<=3) return true;
    if(n%2==0 || n%3==0) return false;
    for(int i=5;i*i<=n;i+=6){
        if(n%i==0 || n%(i+2)==0) return false;
    }

    return true;
}
int main(){
    int n;
    cin>>n;
    cout<<isprime(n);
}