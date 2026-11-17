#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;

    node (int val){
        data=val;
        next=nullptr;
    }

};
class linkedlist{
    public:
    void insert_beginning(node* &head, int x){
        node *newnode= new node(x);
        newnode->next= head;
        head= newnode;

    }
    void insert_end(node * &head, int x){
        node *newnode= new node(x);
        node *temp = head;
        while(temp->next!=nullptr){
            temp= temp->next;

        }
        temp->next= newnode;

    }
    void insert_mid(node * &head, int x, int n){
        node *newnode= new node(x);
        if(n%2==0){
            n= n/2 -1;
            node *temp= head;
            node *next_temp= head;
            int next_n= n+1;

            while(n--){
                temp= temp->next;
            }
            while(next_n--){
                next_temp= next_temp->next;
            }
            temp->next= newnode;
            newnode->next= next_temp;
        }
        else{
            n=n/2;
            node *temp= head;
            node *next_temp= head;
            int next_n= n+1;

            while(n--){
                temp= temp->next;
            }
            while(next_n--){
                next_temp= next_temp->next;
            }
            temp->next= newnode;
            newnode->next= next_temp;
        }
    }
    void delete_begin(node * &head){
        node *temp= head;
        head= head->next;
        delete temp;
    }
    void delete_end(node * &head){
        node *temp = head;
        
        while(temp->next->next!=nullptr){
            temp =temp->next;
        }
        
        delete temp->next;
        temp->next = nullptr;

    }
    void delete_mid(node * &head, int n){
        if (head == nullptr) cout << "List is empty";
        n= n-1;
        node *temp= head;
        
        while(n--){
            temp= temp->next;
            
        }
        node *Del= temp->next;
        temp->next= temp->next->next;
        delete Del;
    }
    void print(node *head){
        node *temp =head;
        
        while(temp!=nullptr){
            cout << temp->data<< " ";
            temp = temp->next;
        }
    }
};
int main(){
    node *first= new node(10);
    node *second = new node(20);
    node *third= new node(30);
    


    node *head= first;
    first->next= second;
    second-> next = third;
    

    linkedlist sll;
    
    // sll.insert_beginning(head, 5);
    // sll.insert_end(head, 40);
    // sll.insert_mid(head,15,4);
    // sll.delete_begin(head);
    // sll.delete_end(head);
    sll.delete_mid(head, 3/2);
    // sll.insert_end(head,50);
    
    sll.print(head);
    
}