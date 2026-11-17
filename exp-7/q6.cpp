#include <iostream>
using namespace std;
struct Node {
int val;
Node *next;
};
struct QueueLL {
Node *front;
Node *rear;
};
void pushLL(QueueLL *q, int x) {
Node *temp = new Node;
temp->val = x;
temp->next = nullptr;
if(q->rear == nullptr) {
q->front = q->rear = temp;
return;
}
q->rear->next = temp;
q->rear = temp;
}
int popLL(QueueLL *q) {
if(q->front == nullptr) {
cout << "Underflow\n";
return -1;
}
Node *temp = q->front;
int x = temp->val;
q->front = q->front->next;
if(q->front == nullptr) q->rear = nullptr;
delete temp;
return x;
}
struct QueueArr {
int *arr;
int front, rear, size;
};
QueueArr* createArrQ(int n) {
QueueArr *q = new QueueArr;
q->size = n;
q->arr = new int[n];
q->front = 0;
q->rear = -1;
return q;
}
void pushArr(QueueArr *q, int x) {
if(q->rear == q->size - 1) {
cout << "Overflow\n";
return;
}
q->arr[++q->rear] = x;
}
int popArr(QueueArr *q) {
if(q->front > q->rear) {
cout << "Underflow\n";
return -1;
}
return q->arr[q->front++];
}
int main() {
QueueLL *lq = new QueueLL{nullptr, nullptr};
pushLL(lq, 10);
pushLL(lq, 20);
cout << "Popped from LL Queue: " << popLL(lq) << endl;
QueueArr *aq = createArrQ(5);
pushArr(aq, 30);
pushArr(aq, 40);
cout << "Popped from Array Queue: " << popArr(aq) << endl;
return 0;
}
