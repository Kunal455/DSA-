
// #include<bits/stdc++.h>
// using namespace std;
// class Q{
//     public:
//     int start = -1;
//     int end = -1;
//     int arr[10];

//     void push(int x){
//         if(end>=10){
//             cout<<"Queue overflow";
//             return;

//         }
//         if(start==-1&& end==-1){
//             start = end = 0;
//         }

//         arr[end++] = x;
//     }


//     void pop(){
//         if(start ==- 1 || start==end){
//             return;
//         }
//         cout<<arr[start];
//         start++;

//         if(start==end){
//             start=end=-1;
//         }
//     }
    

//     void print(){
//         if(start == -1 || start ==end){
//             return;
//         }
//         for(int i=start;i<end;i++){
//             cout<<arr[i]<<" ";
//         }
//     }
// };
// int main(){
//     Q q = Q();
//     for(int i=0;i<10;i++){
//         int x;
//         cin>>x;
//         q.push(x);

//     }

//      q.print();
//      cout<<endl;
//      q.pop();
//      q.pop();
//      q.pop();
//      q.pop();
//      q.pop();
//      q.print();
// }






//Using Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
    public: 
    int data;
    Node* next;
    

    Node(int data){
        this->data = data;
        this->next=nullptr;
    }
};

class Q{
    public:
    int size;
    Node* start;
    Node* end;

    Q(){
        this->size=0;
        this->start = nullptr;
        this->end = nullptr;
    }

    
    
    void push(int data){
        Node* newnode = new Node(data);
        if(start==nullptr){
            start=end=newnode;
        }

        end->next  = newnode;
        end=newnode;
        size++;

        
        
    }

    void pop(){
        if(start==nullptr) return;
        start=start->next;
        size--;

        if(start==nullptr){
            end=start=nullptr;
        }

    }

    int tops(){
        if(start==nullptr) return -1;

        return start->data;
    }

    

    void print(){
        if(size==0) return;

        Node* temp = start;
        while(temp!=nullptr){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }



};

int main(){
    int n;
    cout<<"Enter the size of elements: ";
    cin>>n;
    Q q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q.push(x);

    }
    q.print();
    //q.pop();
    // q.print();
    // q.pop();
    // q.print();
    // q.pop();
    // q.print();
    // cout<<endl;
    // cout<<q.tops();

}

