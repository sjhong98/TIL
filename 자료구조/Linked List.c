# Linked List

#include <stdio.h>
#include <stdlib.h>

struct Node {   // 하나의 노드
    int key;
    struct Node* next;
};

struct List {
    struct Node* head;
    struct Node* tail;
    int size;
};

void createNode(struct List* list) {
    list->head = (struct Node*)malloc(sizeof(struct Node));   // head라는 노드구조체 생성
    list->tail = (struct Node*)malloc(sizeof(struct Node));   // tail이라는 노드구조체 생성
    list->head->next = list->tail;
    int size = 0;
}

void addFirst(struct List* list, int data) {
    struct Node* nnode = malloc(sizeof(struct Node));   // 새로운 노드 생성
    nnode->key = data;
    nnode->next = list->head->next;
    list->head->next = nnode;

    printf("head = %p\nnnode = %p\ntail = %p\n\n", list->head->next, nnode->next, list->tail);
}

void addLast(struct List* list, int data) {
    struct Node* tnode = malloc(sizeof(struct Node));
    struct Node* nnode = malloc(sizeof(struct Node));
    tnode = list->head;     // tnode = head

    printf("head = %p\ntnode = %p\ntail = %p\n", list->head->next, tnode->next, list->tail);

    if(tnode->next != list->tail) {    // 헤드 다음이 테일이 아니라면

        while(tnode->next->next != list->tail) {    // tnode의 다음 다음이 tail일 때까지
            //tnode->key = tnode->next->key;    // key값 가져갈 필요 없음. 오히려 밀림
            tnode = tnode->next;
        }   // 종료 시 tnode->next->next가 tail 가리킴, 즉 tail 2개 앞 노드라는 것

        nnode->key = data;        
        nnode->next = tnode->next->next;    // nnode->next가 tail 가리킴
        tnode->next->next = nnode;
    }
    else {      // 리스트가 비었다면
        tnode->key = data;
        tnode->next = list->head->next;
        list->head->next = tnode;
        printf("\n빈 리스트. 중간에 추가\n\n");
    }
}

void removeNode(struct List* list, int data) {
    struct Node* tnode = malloc(sizeof(struct Node));
    tnode = list->head;     // tnode = head

    while(tnode->next->key != data) {   // tnode의 다음 노드의 키값이 찾고자 하는 값일 때까지
        //tnode->key = tnode->next->key;  // tnode 다음 노드의 key값 가져오기
        tnode = tnode->next;
    }

    tnode->next = tnode->next->next;    // 다음 노드 대신 다다음 노드 가리키도록 함


}

void search(struct List* list, int data) {
    struct Node* tnode = malloc(sizeof(struct Node));
    tnode = list->head;
    int count = 0;

    while(tnode->key != data) {
        tnode = tnode->next;
        count++;
    }

    printf("\nfound node :\n  %d는 %d번째 노드임.\n\n", data, count);
}

void printn(struct List* list) {
    struct Node* tnode = malloc(sizeof(struct Node));
    tnode = list->head;
    printf("\n=== printed ===\n");

    if(tnode->next == list->tail)
        printf("\nList가 비었음.\n\n");
    else {
        while(tnode->next != list->tail) {
            printf("%d ", tnode->next->key);
            tnode = tnode->next; 
        }
        printf("\n\n");
    }
}


int main() {
    struct List list;
    createNode(&list);
    int sel, n;

    while(1) {
        printf("===== Linked List =====\n 1. AddFirst\n 2. AddLast\n 3. RemoveNode\n 4. SearchNode\n 5. PrintNode\n 6. 종료\n\n enter : ");
        scanf("%d", &sel);
        printf("\n");

        switch(sel) {
            case 1 :
                printf("enter : ");
                scanf("%d", &n);
                addFirst(&list, n);
                printf("\nfinished\n\n");
                break;
            case 2 : 
                printf("enter : ");
                scanf("%d", &n);
                addLast(&list, n);
                printf("\nfinished\n\n");
                break;
            case 3 :
                printf("enter : ");
                scanf("%d", &n);
                removeNode(&list, n);
                printf("\nfinished\n\n");
                break;
            case 4 :
                printf("enter : ");
                scanf("%d", &n);
                search(&list, n);
                break;
            case 5 : 
                printn(&list);
                break;
            case 6 :
                return 0;
        }
    }
}



