//
// Created by MinseokK on 24. 7. 29.
//
// Queue

#define SIZE 5

typedef struct Queue {
    int *arr_q;
    int head;
    int tail;
}Queue;

void initialize(Queue *Q, int capacity) {
    Q-> arr_q = (int *)malloc(capacity * sizeof(int));
    if (Q->arr_q == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    Q -> head = -1;
    Q -> tail = -1;
}
int isEmpty(Queue *Q) {
    int a;
    a =  (Q->head < 0 || Q->head > Q->tail);
    printf("a ========%d\n", a);
    return a;
}
int isFull(Queue *Q) {
    return Q -> tail == SIZE -1;
}

void enquene(Queue *Q, int x) {
    if (isFull(Q)) {
        printf("FULL\n");
        return;
    }
    if (Q-> head == -1) {
        Q->head = 0;
        //int v =Q->tail;
    }
    Q -> arr_q[++(Q->tail)] = x;
}

int dequene(Queue *Q) {

    if(isEmpty(Q)) {
        printf("Empty\n");
        return -1;
    }
    int value = Q->arr_q[Q->head];
    Q->head++;

    // 큐가 비어있다면 재설정
    if (Q->head > Q->tail) {
        Q-> head = -1;
        Q->tail = -1;
    }
    return value;


}

void printQ(Queue *Q) {
    printf("tail = %d\n", Q -> tail);
    printf("head = %d\n", Q -> head);
    if (Q->head == -1) {
        printf("Empty\n");
        return;
    }
    for(int i=Q->head;i< Q->tail+1;i++) {

        printf("i ===== %d", Q->arr_q[i]);
    }
}
int main() {
    Quene q;

    initialize(&q, SIZE);
    enquene(&q, 5);
    enquene(&q, 2);
    enquene(&q, 5);
    enquene(&q, 6);
    enquene(&q, 7);

    dequene((&q));
    dequene((&q));
    dequene((&q));
    dequene((&q));
    dequene((&q));

    printQ(&q);
}