#include <iostream>
#include <cstdlib>
using namespace std;
struct node {
int val;
node *next;
};
struct Stack {
node *front;
};
struct Stack *initialize_stack() {
struct Stack *s = new Stack;
s->front = nullptr;
return s;
}
void print_stack(struct Stack *s) {
cout << "Stack: ";

for (node *cur = s->front; cur; cur = cur->next) {
cout << cur->val;
if(cur->next) cout << " -> ";
}
cout << endl;
}
void push_stack(int val, struct Stack *s) {
node *temp = new node();
temp->val = val;
temp->next = s->front;
s->front = temp;
}
int pop_stack(struct Stack *s) {
if (s->front == nullptr) {
cout << "Stack Underflow\n";
return -1;
}
node *temp = s->front;
int val = temp->val;
s->front = temp->next;
delete temp;
return val;
}
int top_stack(struct Stack *s) {
if(s->front == nullptr) {
cout << "Stack Empty\n";
return -1;
}
return s->front->val;
}
int main() {
struct Stack *s = initialize_stack();
push_stack(1, s);
push_stack(2, s);
push_stack(3, s);
print_stack(s);
cout << "Popped: " << pop_stack(s) << endl;
cout << "Top: " << top_stack(s) << endl;
cout << "Popped: " << pop_stack(s) << endl;
print_stack(s);
return 0;
}