#include <iostream>
using namespace std;
struct Node
{
int val;
Node *next;
Node *prev;
Node(int v) {
val = v;
next = nullptr;
prev = nullptr;
}
};
class dll {
public:
void insert_end(Node *&head, int val) {
Node *temp = new Node(val);
if (head == nullptr) {
head = temp;
return;
}
Node *cur = head;
while (cur->next != nullptr) {
cur = cur->next;
}
cur->next = temp;
temp->prev = cur;
}
void reverse_dll(Node *&head) {
if (head == nullptr || head->next == nullptr) {
return;
}
Node *prev_node = nullptr;
Node *cur = head;
while (cur != nullptr) {
prev_node = cur->prev;
cur->prev = cur->next;
cur->next = prev_node;
cur = cur->prev; 
}
head = prev_node->prev;
}
void print_ll(Node *head) {
if (head == nullptr) {
cout << "Linked list is empty.\n";
return;
}
Node *cur = head;
while (cur->next != nullptr) {
cout << cur->val << " -> ";
cur = cur->next;
}
cout << cur->val << "\n";
}
};
int main() {
Node *head = nullptr;
dll list;
list.insert_end(head, 1);
list.insert_end(head, 2);
list.insert_end(head, 3);
list.print_ll(head);
list.reverse_dll(head);
cout << "After reversing: ";
list.print_ll(head);
return 0;
}