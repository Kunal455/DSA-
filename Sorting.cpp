/*#include<bits/stdc++.h>
using namespace std;
void selection(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[mini]){
                mini=j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}
int main(){
    int n;
    cout<<"Size of the array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Before sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    selection(arr,n);
    cout<<"After sorting: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
*/

/*
#include<bits/stdc++.h>
using namespace std;
void Bubble(int arr[], int n){
    for(int i=n-1;i>=0;i--){
    int didswap = 0;
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j], arr[j+1]);
                didswap=1;
            }
        } 
        if(didswap==0) break;
        cout<<"runs";
    }
    return;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    cout<<"Before sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    Bubble(arr, n);

    cout<<"After the Sorting: "<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

}
*/


//Insertion Sort
/*#include<iostream>
using namespace std;
void IS(int arr[], int n){
    for (int i=0;i<n;i++){
        int j = i;
        while(j>0 && arr[j-1]>arr[j]){
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
    return;
}
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    IS(arr, n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }


}
*/


/*//Merge short
#include<iostream>
#include<vector>
using namespace std;
void sort(vector<int>& arr, int low, int mid, int high){
    int left = low;
    int right = mid+1;
    vector<int> temp;
    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
        }
        else{
            temp.push_back(arr[right]);
        }
    }

    while(left<=mid){
        temp.push_back(arr[left]);
    }

    while(right<=high){
        temp.push_back(arr[right]);
    }

    for(int i=low;i<high;i++){
        arr[i] = temp[i-low];
    }
}
void merge(vector<int>& arr, int low, int high){
    if(low==high) return;
    int mid = (low+high)/2;
    merge(arr, low, mid);
    merge(arr, mid+1, high);
    sort(arr, low, mid, high);

}
int main(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    merge(arr,0,n);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
*/

/*class Solution {
public:
    int pivot(vector<int>& arr, int low, int high){
        int pe=arr[low];
        int i=low;
        int j=high;
        while(i<j){
            while(arr[i]<=pe && i<high){
                i++;
            }
            while(arr[j]>pe && j>low){
                j--;
            }
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[low], arr[j]);
        return j;
    }
    void QS(vector<int>& arr, int low, int high){
        if(low>=high){
            return;
        }
        int pi = pivot(arr, low, high);
        QS(arr, low, pi-1);
        QS(arr, pi+1, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        QS(nums, 0, n-1);
        return nums;
    }
};

arr = {10, 80, 30, 90, 40, 50, 70}
QS(arr, 0, 6)  // Calls pivot(arr, 0, 6)

*/

