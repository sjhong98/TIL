# Circle Queue

#include <stdio.h>

struct Circle {
    int CQ[8];
    int front;
    int rear;
    int n;
};

void init(struct Circle* q) {
    q->front = 0;
    q->rear = 0;
    q->n = 8;
}

void enqueue(struct Circle* q, int data) {
    if(q->rear+1 % q->n != q->front) {  // isFull
        q->CQ[q->rear] = data;
        q->rear += 1;
        q->rear = q->rear % q->n;
    }
    else
        printf("queue is Full\n");
}

void dequeue(struct Circle* q) {
    if(q->rear != q->front) {   // isEmpty
        printf("dequeue : %d\n", q->CQ[q->front]);
        q->front += 1;
        q->front = q->front % q->n;
    }
    else
        printf("queue is Empty\n");
}

void printq(struct Circle* q){
    printf("=====printint queue=====\n");
    for(int i=0; i<q->n; i++) {
        printf("%d\n", q->CQ[i]);
    }
}

int main(void) {
    struct Circle circle;
    int s, data;

    init(&circle);
    
    while(1) {
        printf("\nqueue\n1. enqueue\n2, dequeue\n3. print\n4. exit\n\n");
        scanf("%d", &s);

        switch(s) {
            case 1 :
                printf("enter integer : ");
                scanf("%d", &data);
                enqueue(&circle, data);
                break;
            
            case 2 :
                dequeue(&circle);
                break;
            
            case 3 :
                printq(&circle);
                break;

            case 4 :
                return 0;

        }
    }

    return 0;
    

}
