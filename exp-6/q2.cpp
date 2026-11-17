#include <iostream>
using namespace std;
struct node {
int val;
node *next;
};
void insert(node **head, int x) {
node *temp = new node;
temp->val = x;
temp->next = NULL;
if(*head == NULL) {
*head = temp;
return;
}
node *curr = *head;
while(curr->next != NULL) {
curr = curr->next;
}
curr->next = temp;
}
void rev(node **head) {
node *p = NULL;
node *c = *head;
node *n = NULL;
while(c != NULL) {
n = c->next;
c->next = p;
p = c;
c = n;
}
*head = p;
}
void display(node *head) {
node *t = head;
while(t != NULL) {
cout << t->val << " -> ";
t = t->next;
}
cout << "NULL\n";
}
int main() {
node *head = NULL;
insert(&head, 5);
insert(&head, 10);
insert(&head, 15);
insert(&head, 20);
cout << "Original: ";
display(head);
rev(&head);
cout << "Reversed: ";
display(head);
return 0;
}