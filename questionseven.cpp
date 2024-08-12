#include<iostream>
using namespace std;
class Node{
    public: 
    char data;
    Node* next;
    public:
    Node(char data1){
        data=data1;
        next=NULL;
    }
};
int getLength(Node* &head){
    int cnt=0;
    Node* temp= head;
    while(temp!=nullptr){
        temp=temp->next;
        cnt++;
    }
    return cnt;
}
void Displaymore(Node * &head){
    Node* temp=head;
    int i=1;
    while(temp!=nullptr){
        cout<<"Address of node "<<i<<" "<<temp<<endl;
        cout<<"Data at node "<<i<<" "<<temp->data<<endl;
        cout<<"Address of next node "<<temp->next<<endl;
     i++;
     temp=temp->next;
    }
}
void addAtBeg(Node* &head,int val){
    if(head==NULL){
        Node*temp=new Node(val);
        temp->next=head;
        head=temp;
    }
    else{
        Node*temp=new Node(val);
        temp->next=head;
        head=temp;
    } 
}
void append(Node*&head,char ch){
    if(head==NULL){
        Node*temp=new Node(ch);
        temp->next=head;
        head=temp;
    }
    else{
        Node* add=new Node(ch);
        Node* temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=add;
    }
}
void addAtPOS(Node* &head,char ch,int k){
      Node* add=new Node(ch);
      Node* temp=head;
      for(int i=1;i<k;i++){
        temp=temp->next;
      }
      Node* arr=temp->next;
      temp->next=add;
 add->next=arr;
}
void RemoveFirst(Node* &head){
    Node* temp=head;
    head=head->next;
    temp->next=nullptr;
    delete temp;
}
void RemoveLast(Node* &head){
    Node*temp=head;
  while(temp->next->next!=nullptr){
        temp=temp->next;
    }
    Node* tail=temp->next;
    temp->next=nullptr;
    delete tail;
}
void RemovePOS(Node*& head,int k){
    Node* temp=head;
    for(int i=1;i<k;i++){
        temp=temp->next;
    }
    temp->next->data=temp->data;
    Node* remove=temp->next;
    temp->next=temp->next->next;
    delete remove;
}
void display(Node * head){
     Node*temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    Node*head=NULL;
    addAtBeg(head,'a');
    addAtBeg(head,'b');
    append(head,'c');
    addAtPOS(head,'d',2);
    cout<<getLength(head)<<endl;
    display(head);
    Displaymore(head);
    RemoveFirst(head);
    RemoveLast(head);
    RemovePOS(head,2);
   
}