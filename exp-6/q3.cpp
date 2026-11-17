#include <stdio.h>
#include <stdlib.h>
struct stack {
int *arr;
int top;
int capacity;
};
struct stack* createStack(int n) {
struct stack *s = (struct stack*)malloc(sizeof(struct stack));
s->arr = (int*)malloc(n * sizeof(int));
s->top = -1;
s->capacity = n;
return s;
}
void push(struct stack *s, int val) {
if(s->top == s->capacity - 1) {
printf("Stack Overflow\n");
return;
}
s->top++;
s->arr[s->top] = val;
}
int pop(struct stack *s) {
if(s->top == -1) {
printf("Stack Underflow\n");
return -1;
}
int x = s->arr[s->top];
s->top--;
return x;
}
int peek(struct stack *s) {
if(s->top == -1) {
printf("Stack is empty\n");
return -1;
}
return s->arr[s->top];
}

void display(struct stack *s) {
if(s->top == -1) {
printf("Stack is empty\n");
return;
}
printf("Stack elements: ");
for(int i = 0; i <= s->top; i++) {
printf("%d ", s->arr[i]);
}
printf("\n");
}
int main() {
struct stack *s = createStack(5);
push(s, 10);
push(s, 20);
push(s, 30);
display(s);
printf("Popped: %d\n", pop(s));
printf("Top element: %d\n", peek(s));
display(s);
return 0;
}
