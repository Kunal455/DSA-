//Basic LinkedList
/*
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;

    Node(int data, Node* next){
        this->data = data;
        this->next = next;
    }
};


int main(){ 
    vector<int> v = {1,2,3,4,5};
    Node* y = new Node(v[0], nullptr);
    cout<<y->next;

}
*/

/*
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }


};


Node* Arr2LL(vector<int>& v){
    Node* head = new Node(v[0]);
    Node* mover = head;
    for(int i=1;i<v.size();i++){
        Node* temp = new Node(v[i]);
        mover->next = temp;
        mover=temp;
        
    } 
    
    return head;
    
}
//deletion Part
Node* DeleteHead(Node* head){
    head=head->next;
    return head;
}
    
Node* DeleteTail(Node* head){
    if(head==nullptr || head->next == nullptr) return nullptr; 
    Node* temp = head;
    while(temp->next->next!=nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}
Node* DeleteatK(Node* head, int k){
    if(head == nullptr) return nullptr;
    if(k==1){
         head=head->next; 
         return head;
    }
    int c = 0;
    Node* temp = head;
    Node* prev=NULL;
    while(temp!=nullptr){
        c++;
        if(c==k){
            prev->next = temp->next;
            delete temp;
            break;
        }
        prev=temp;
        temp=temp->next;
    }

    return head;

}


//Insertion Part
Node* insertAtBegin(Node* head, int value){
    Node* temp = new Node(value);
    temp->next = head;
    head=temp;
    return head;

}

Node* insertAtEnd(Node* head, int value2){
    if(head==nullptr) return new Node(value2);
    Node* temp = new Node(value2);
    Node* helper = head;
    while(helper->next!=nullptr){
        helper = helper->next;
    }

    helper->next = temp;
    temp->next = nullptr;

    return head;

}

Node* insertAtPosition(Node* head, int value3, int position){
    Node* temp = new Node(value3);
    if(head==nullptr){
        if(position==1){
            return new Node(value3);
        }
        else{
            return head;
        }
    }

    if(position==1){
        temp->next = head;
        head=temp;
        return head;
    }

    int c=0;
    Node* helper = head;
    Node* prev = nullptr;
    while(helper!=nullptr){
        c++;
        if(c==position){
            prev->next = temp;
            temp->next = helper;
        }
        prev = helper;
        helper = helper->next;
    }

    return head;

}
void print(Node* head){
    Node* temp = head;
    while(temp!=nullptr){
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
int main(){
    vector<int> v = {1,2,3,4,5,6,7,8,9,0};
    Node* head = Arr2LL(v);
    print(head);
    cout<<endl;
    head = DeleteHead(head);
    print(head);
    cout<<endl;
    head = DeleteTail(head);
    print(head);
    cout<<endl;
    int position = 3;
    head = DeleteatK(head, position);
    print(head);
    cout<<endl;
    int value = 11;
    head = insertAtBegin(head, value);
    print(head);
    cout<<endl;
    int value2 = 20;
    head = insertAtEnd(head, value2);
    print(head);
    cout<<endl;
    int value3 = 50;
    head = insertAtPosition(head, value3, position);
    print(head);
    cout<<endl;
    
}*/






// //DOUBLY LINKEDLIST

// #include<bits/stdc++.h>
// using namespace std;
// class Node{
//     public:
//     int data;
//     Node* next;
//     Node* prev;


//     Node(int data, Node* next, Node* prev){
//         this->data = data;
//         this->next = next;
//         this->prev = prev;
//     }

//     Node(int data){
//         this->data=data;
//         this->next = nullptr;
//         this->prev = nullptr;
//     }
// };

// Node* insert(vector<int>& v){
   
//     Node* head = new Node(v[0]);
//     Node* prev = head;
//     for(int i=1;i<v.size();i++){
//         Node* temp = new Node(v[i], nullptr, prev);
//         prev->next = temp;
//         prev = temp;
//     }
//     return head;


// }

// //Deletion in LinkedList
// Node* deleteAtBegin(Node* head){
//     if(head==nullptr || head->next==nullptr) return nullptr;
//     Node* prev = head;
//     head=head->next;
//     head->prev = nullptr;
//     prev->next = nullptr;
//     delete prev;
//     return head;

// }

// Node* deleteAtEnd(Node* head){
//     if(head==nullptr || head->next==nullptr) return nullptr;
//     Node* temp = head;
//     while(temp->next!=nullptr){
//         temp=temp->next;
//     }
//     Node* newTail = temp->prev;
//     newTail->next = nullptr;
//     temp->prev = nullptr;
//     delete temp;
//     return head;

// }

// Node* deleteAtPosition(Node* head, int k){
//     if(head == nullptr) return nullptr;
//     Node* temp = head;
//     int c =0 ;
//     while(temp!=nullptr){
//         c++;
//         if(c==k){
//              break;
//         }

//         temp = temp->next;
//     }

//     Node* back  = temp->prev;
//     Node* front = temp->next;

//     if(back==nullptr && front==nullptr){
//         delete temp;
//         return head;
//     }
//     else if(back == nullptr){
//         head  = deleteAtBegin(head);
//         return head;
//     }
//     else if(front==nullptr){
//         head = deleteAtEnd(head);
//         return head;
//     }

//     back->next  = front;
//     front->prev = back;
//     temp->next = nullptr;
//     temp->prev = nullptr;
//     delete temp;

//     return head;

// }
// void print(Node* head){
//     Node* temp = head;
//     while(temp!=nullptr){
//         cout<<temp->data<<" ";
//         temp=temp->next;
//     }
// }
// int main(){
    
//     vector<int> v = {1,2,3,4,5,6,7,8,9};
//     Node* head = insert(v);
//     print(head);
//     cout<<endl;
//     head = deleteAtBegin(head);
//     print(head);
//     cout<<endl;
//     head=deleteAtEnd(head);
//     print(head);
//     cout<<endl;
//     int position = 2;
//     head = deleteAtPosition(head, position);
//     print(head);
//     cout<<endl;
    

// }













// //206. Reverse Linked List
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) {
//        if(head==nullptr || head->next==nullptr) return head;

//        ListNode* prev = nullptr;
//        ListNode* temp = head;
//        ListNode* nex = temp->next;
//        while(temp!=nullptr){
//         nex=temp->next;
//         temp->next = prev;
//         prev = temp;
//         temp=nex;
//        }


    
//     return prev;
//     }
// };


// //Detect a cycle or loop



// //USING HASHMAP
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         unordered_map<ListNode*, int> mp;
//         ListNode* temp = head;
//         while(temp!=nullptr){
//             if(mp.find(temp)!=mp.end()){
//                 return true;

//             }
//             mp[temp] = 1;
//             temp=temp->next;
//         }
//     return false;
//     }
// };





// //Using TORTOISE 
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     bool hasCycle(ListNode *head) {
//         ListNode* first = head;
//         ListNode* second = head;
        
//         while(second!=nullptr && second->next!=nullptr){
//             first = first->next;
//             second = second->next->next;

//             if(first==second){
//                 return true;
//             }
//         }
//         return false;
//     }
// };







// //Detect Cyle 2
// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;

//             if (slow == fast) break;
//         }

//         if (!fast || !fast->next) return nullptr;

//         fast = head;
//         while (fast != slow) {
//             fast = fast->next;
//             slow = slow->next;
//         }

//         return slow;        
//     }
// };





// //Palindrome checklist

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//        ListNode* temp = head;
//        stack<int> st;

//        while(temp!=nullptr){
//         st.push(temp->val);
//         temp=temp->next;
//        }
//         temp = head;
//        while(temp!=nullptr){
//         if(temp->val!=st.top()){
//             return false;
//         }
//         temp=temp->next;
//         st.pop();
//        }

//        return true;
//     }
// };






// //Using Previous
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* reverse(ListNode* slow){
//         ListNode* prev=nullptr;
//         ListNode* curr=slow;
//         while(curr!=nullptr){
//             ListNode* nex = curr->next;
//             curr->next = prev;
//             prev=curr;
//             curr=nex;
//         }

//         return prev;

//     }
//     bool isPalindrome(ListNode* head) {
//        ListNode* slow = head;
//        ListNode* fast = head;
//        while(fast!=nullptr && fast->next!=nullptr){
//         slow = slow->next;
//         fast=fast->next->next;
//        }

//        slow = reverse(slow);

//        ListNode* first = head;
//        ListNode* second = slow;
//        while(second!=nullptr){
//         if(first->val != second->val){
//             return false;
//         }
//         first = first->next;
//         second = second->next;
//        }
//        return true;
//     }
// };






// //remove the n node from the last node of the linked list


// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* fast = head;
//         ListNode* slow = head;
//         int i = 0;
//         while(i!=n && fast!=nullptr){
//             fast=fast->next;
//             i++;
//         }

//         if(fast == nullptr){
//             ListNode* temp = head;
//             head = head->next;
//             delete temp;
//             return head;
//         }
//         while(fast->next!=nullptr){
//             slow=slow->next;
//             fast = fast->next;
//         }

//         ListNode* del = slow->next;
//         slow->next = slow->next->next;
//         del->next = nullptr;
//         delete del;

//         return head;
//     }
// };




// //Merge two LL
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

     

//        ListNode* head1 = list1;
//        ListNode* head2= list2;
//        ListNode* dummy = new ListNode(0);
//        ListNode* temp = dummy;
//        while(head1!=nullptr && head2!=nullptr){
//         if(head1->val < head2->val){
//             temp->next = head1;
//             head1=head1->next;
//             temp=temp->next;
//         }
//         else{
//             temp->next = head2;
//             head2=head2->next;
//             temp=temp->next;
//         }
//        }

//         if(head1) temp->next = head1; 
//         if(head2) temp->next= head2;

//         return dummy->next;


//     }
// };


// //sort LL
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//  ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//        ListNode* head1 = list1;
//        ListNode* head2= list2;
//        ListNode* dummy = new ListNode(0);
//        ListNode* temp = dummy;
//        while(head1!=nullptr && head2!=nullptr){
//         if(head1->val < head2->val){
//             temp->next = head1;
//             head1=head1->next;
//             temp=temp->next;
//         }
//         else{
//             temp->next = head2;
//             head2=head2->next;
//             temp=temp->next;
//         }
//        }

//         if(head1) temp->next = head1; 
//         if(head2) temp->next= head2;

//         return dummy->next;

//     }
//     ListNode* findMiddle(ListNode* head) {
//         ListNode* slow = head;
//         ListNode* fast = head;
//         ListNode* prev = nullptr;

//         while (fast && fast->next) {
//             prev = slow;
//             slow = slow->next;
//             fast = fast->next->next;
//         }

//         if (prev) prev->next = nullptr; 
//         return slow; 
//     }
//     ListNode* sortList(ListNode* head) {
//         if(head==nullptr || head->next==nullptr) return head;

//         ListNode* middle = findMiddle(head);
//         ListNode* left = head;
//         ListNode* right = middle;
        

//         left = sortList(left);
//         right = sortList(right);
        
//         head = mergeTwoLists(left, right);

//         return head;

//     }
// };



// //segregate 0s 1s 2s

// /*  Node is defined as
//   struct Node {
//     int data;
//     struct Node *next;
//     Node(int x) {
//         data = x;
//         next = NULL;
//     }
// };*/
// class Solution {
//   public:
//     Node* segregate(Node* head) {
//         // code here
//         Node* zero = new Node(0);
//         Node* ones = new Node(1);
//         Node* twos = new Node(2);
        
//         Node* temp = head;
//         Node* z = zero;
//         Node* o = ones;
//         Node* t = twos;
//         while(temp!=nullptr){
//             if(temp->data==0)
//             {
//             z->next = temp;
//             temp=temp->next;
//             z=z->next;
//             }
            
//             else if(temp->data==1){
//                 o->next = temp;
//                 o=o->next;
//                 temp=temp->next;
//             }
//             else{
//                 t->next = temp;
//                 temp=temp->next;
//                 t=t->next;
//             }
//         }
        
//         z->next = (ones->next) ? ones->next : twos->next;
//         o->next= twos->next;
//         t->next = nullptr;
        
        
        
//         return zero->next;
        
//     }
// };



// //Add 1 to LL
// /*

// struct Node
// {
//     int data;
//     struct Node* next;

//     Node(int x){
//         data = x;
//         next = NULL;
//     }
// };

// */

// class Solution {
//   public:
//   Node* reverse(Node* head){
//       Node* prev = nullptr;
//       Node* curr= head;
//       while(curr!=nullptr){
//           Node* nex = curr->next;
//           curr->next = prev;
//           prev = curr;
//           curr=nex;
//       }
      
//       return prev;
//   }
//     Node* addOne(Node* head) {
//         // Your Code here
//         head = reverse(head);
//         Node* temp = head;
//         int carry =1;
//         while(temp!=nullptr){
//             temp->data = temp->data + carry;
            
//             if(temp->data<10){
//                 carry=0;
//                 break;
//             }
//             else{
//                 carry = 1;
//                 temp->data = 0;
                
//             }
            
//             temp=temp->next;
//         }
        
//         head = reverse(head);
        
//         if(carry==1){
//             Node* newNode = new Node(1);
            
//         newNode->next = head;
//         head=newNode;
        
//         }
        
        
//         return head;
//         // return head of list after adding one
//     }
// };





// //ADD 2 NUMBER IN LL
// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//         ListNode* t1 = l1;
//         ListNode* t2 = l2;
//         ListNode* dummy = new ListNode(-1);
//         ListNode* temp= dummy;
//         int carry = 0;
//         while(t1!=nullptr || t2!=nullptr){
//             int sum= carry;

//             if(t1){
//                 sum+=t1->val;
//                 t1=t1->next;
//             }

//             if(t2){
//                 sum+=t2->val;
//                 t2=t2->next;
//             }

//             if(sum>=10){
//                 carry = 1;
//                 ListNode* node = new ListNode(sum%10);
//                 temp->next = node;
//                 temp=temp->next;
//             }

//             else{
//                 carry=0;
//                 ListNode* node = new ListNode(sum%10);
//                 temp->next = node;
//                 temp=temp->next;
//             }
//         }

//         ListNode* result = dummy->next;

//         if(carry == 1){
//             ListNode* node = new ListNode(1);
//             temp->next = node;

//             return result;

//         }

//         return result;
//     }
// };









// //Intersecrtion of Y in LL
// // Using HASHMAP




// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_map<ListNode*, int> mp;
//         ListNode* h1 = headA;
//         ListNode* h2 = headB;
//         ListNode* dummy = new ListNode(-1);
//         ListNode* temp = dummy;

//         while(h1!=nullptr){
//             mp[h1] = 1;
//             h1=h1->next;
//         }

//         ListNode* prev = nullptr;
//         while(h2!=nullptr){
//             if(mp.find(h2)!=mp.end()){
//                 temp->next = h2;
//                 return dummy->next;
//             }

//             prev = h2;
//             h2=h2->next;
//         }

//         return nullptr;
//     }
// };



// //Using Two pointer


// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:

//     ListNode* collisionPoint(ListNode* h1, ListNode* h2, int d){
//         while(d){
//             d--;
//             h2=h2->next;
//         }

//         while(h1!=h2){
//             h1=h1->next;
//             h2=h2->next;
//         }

//         return h1;
//     }


//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode* h1 = headA;
//         ListNode* h2 = headB;

//         int n = 0;
//         int m = 0;

//         while(h1!=nullptr){
//             n++;
//             h1=h1->next;
//         }

//         while(h2!=nullptr){
//             m++;
//             h2=h2->next;
//         }
//         ListNode* slow;
//         ListNode* fast;

//         if(n>m){
//             return collisionPoint(headB, headA, n-m);
//         }
//         else{
//             return collisionPoint(headA, headB, m-n);
//         }

//         return nullptr;

//     }
// };




// //optimal

// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode(int x) : val(x), next(NULL) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         if(headA==nullptr || headB==nullptr) return nullptr;
//         ListNode* t1 = headA;
//         ListNode* t2 = headB;
//         while(t1!=t2){
//             t1=t1->next;
//             t2=t2->next;

//             if(t1==t2) return t1;

//             if(t1==nullptr) t1 = headB ;
//             if(t2==nullptr) t2=headA ;
//         }

//         return t1;
//     }
// };














//DOUBLY LinkedLIst
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }

    Node(int data, Node* next, Node* prev){
        this->data = data;
        this->next=next;
        this->prev = prev;
    }
};

Node* deleteBegin(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* del = head;
    head = head->next;
    head->prev = nullptr;
    delete del;
    return head;

}

Node* deleteEnd(Node* head){
    if(head==nullptr || head->next==nullptr) return nullptr;
    Node* temp = head;
    Node* back = head;
    while(temp->next!=nullptr){
        back=temp;
        temp=temp->next;
        
    }

    Node* del = temp;
    back->next = nullptr;
    temp->prev = nullptr;
    delete del;
    return head;

}

Node* deleteatK(Node* head, int k){
    

    int c= 0;
    Node* temp = head;
    while(temp!=nullptr){
        c++;
        if(c==k){
            break;

        }
        temp=temp->next;
    }
    Node* back = temp->prev;
    Node* front=temp->next;

    if(front==nullptr && back==nullptr){
        delete temp;
        return nullptr;
    }
    else if(back==nullptr){
        Node* del = head;
        head = head->next;
        head->prev = nullptr;
        delete del;
        return head;
    }
    else if(front==nullptr){
        Node* pre = temp->prev;
        pre->next = temp->next;
        temp->prev=nullptr;
        delete temp;
        return head;

    }
    else{
            Node* del = temp;
            back->next = front;
            front->prev = back;
            temp->next=nullptr;
            temp->prev=nullptr;
            delete del;
    }
    return head;
}


Node* insertbegin(Node* head, int val){
    Node* newnode = new Node(val,head,nullptr);
    if(head!=nullptr){
    head->prev=newnode;
    }
    head=newnode;
    return head;
}
Node* insertEnd(Node* head, int val){
    Node* newnode = new Node(val);
    if(head==nullptr){
        return newnode;
    }
    Node* temp = head;
    while(temp->next!=nullptr){
        temp=temp->next;
    }

    temp->next = newnode;
    newnode->next = nullptr;
    newnode->prev=temp;
    return head;
}

Node* insertatK(Node* head, int val, int k){
    Node* newnode = new Node(val);

    if(k==1){
        newnode->next = head;
        if(head!=nullptr){
            head->prev = newnode;
        }
        return newnode;
    }
    

    int c = 0;
    Node* temp = head;
    while(temp!=nullptr){
        c++;
        if(c==k) break;
        temp=temp->next;
    }

    Node* back = temp->prev;
    newnode->next = temp;
    newnode->prev = back;
    back->next = newnode;
    temp->prev= newnode;

    return head;

}
    
Node* arrtoLL(vector<int>& v){
    Node* head = new Node(v[0]);
    Node* prev = head;
    for(int i=1;i<v.size();i++){
        Node* temp = new Node(v[i], nullptr, prev);
        prev->next = temp;
        prev=temp;

    }

    return head;
}

void print(Node*head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    vector<int> v = {11,43,45,4,3,67,2,56};
    Node* head = arrtoLL(v);
    print(head);
    cout<<endl;
    head = deleteBegin(head);
    print(head);
    cout<<endl;
    head = deleteEnd(head);
    print(head);
    cout<<endl;
    int k = 3;
    head = deleteatK(head, k);
    print(head);
    cout<<endl;
    head = insertbegin(head, 100);
    print(head);
    cout<<endl;
    head = insertEnd(head, 200);
    print(head);
    cout<<endl;
    head = insertatK(head, 300, k);
    print(head);
    cout<<endl;

}


//revere DLL

/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
    // Function to reverse a doubly linked list
    
    DLLNode* reverseDLL(DLLNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        // Your code here
        DLLNode* temp = head;
        DLLNode* last = nullptr;
        while(temp!=nullptr){
            last = temp->prev;
            temp->prev = temp->next;
            temp->next = last;
            temp =temp->prev;
            
        }
        return last->prev;
    }
};




//Find sum pair in DLL
//using two pointer

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int sum) {
        // code here
        Node* temp = head;
        vector<pair<int, int>> v;
        
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        
        Node* left = head;
        Node* right = temp;
        
        while(left->data<right->data){
            if(left->data + right->data == sum){
                v.push_back({left->data, right->data});
                right=right->prev;
                left=left->next;
            }
            else if(left->data + right->data > sum){
                right=right->prev;
            }
            else{
                left=left->next;
            }
        }
        return v;
        }
};

//using nested traversal


// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int sum) {
        // code here
        Node* temp1 = head;
        vector<pair<int, int>> v;
        
        while(temp1!=nullptr){
            Node* temp2 = temp1->next;
            
            while(temp2!=nullptr || temp1->data+temp2->data<=sum){
                if(temp1->data + temp2->data ==sum){
                    v.push_back({temp1->data, temp2->data});
                }
                
                temp2=temp2->next;
            }
            temp1=temp1->next;
        }
        
        return v;
    }
};


//using map

// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution {
  public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
        // code here
        unordered_map<int, int> mp;
        vector<pair<int,int>> v;
        
        Node* temp = head;
        while(temp!=nullptr){
            int d = target - temp->data;
            if(mp.find(d)!=mp.end()){
                v.push_back({d, temp->data});
            }
            mp[temp->data]= 1;
            temp=temp->next;
        }
        
        sort(v.begin(), v.end());
        return v;
    }
};