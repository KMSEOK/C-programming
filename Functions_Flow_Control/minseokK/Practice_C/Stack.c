//
// Created by MinseokK on 24. 7. 29.
//
// Stack
#define SIZE 5

typedef struct Stack{
    int top;
    int *stack_arr;

}Stack;

void initialize(Stack *S, int capacity) {
    S->stack_arr = (int *)malloc(capacity * sizeof(int));
    if (S->stack_arr == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    (*S).top = -1;
}
int isEmpty(Stack *S) {
    return S->top == -1;
}

int isFull(Stack *S) {
    return (*S).top == SIZE;
}
void push(Stack *S, int x) {
    if (isFull(S)) {
        printf("Stack is FULL\n");
        return;
    }
    S -> stack_arr[++(S->top)] = x;


}

void pop(Stack *S) {
    if(isEmpty(S)) {
        printf("Stuck is Empty");
        return;
    }
    S->stack_arr[--S->top];
}
void print(Stack *S) {
    for(int i =0; i< S->top+1; i++) {
        printf("%d", S->stack_arr[i]);
    }
}




int main() {
    Stack S;
    initialize(&S, SIZE);
    push(&S, 1);
    push(&S, 2);
    push(&S, 2);
    push(&S, 2);
    pop(&S);
    pop(&S);
    pop(&S);
    pop(&S);
    push(&S, 2);
    print(&S);
}
