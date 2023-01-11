// Max Heap

#include <stdio.h>

typedef struct Heap {
    int heap[20];
    //int num;
    int index;
    int size;
}Heap;

void init(Heap* h) {
    h->index = 1;   // 0은 사용 x
    h->size = 20;
}

void swap(Heap* h, int i, int j) {
    int temp;
    temp = h->heap[i];
    h->heap[i] = h->heap[j];
    h->heap[j] = temp;
}

void insert(Heap* h, int data) {
    int temp = h->index;
    h->heap[temp] = data;
    
    if(h->index != 1) {
        while(h->heap[temp] > h->heap[temp / 2] && temp / 2 != 0) {   // 삽입 노드와 부모 노드의 비교, 삽입 노드가 더 크다면. 
            swap(h, temp, temp / 2);
            printf("swapped\n");
            temp = temp / 2;
        }
    }
    h->index += 1;
}

void delete(Heap* h) {
    int i = 1;
    h->heap[i] = h->heap[h->index-1];

    while(h->heap[i] < h->heap[i*2]) {  // 부모노드와 자식노드 비교, 부모노드가 더 작다면
        swap(h, i, i*2);
        i *= 2;
    }
    h->index -= 1;  // 트리 크기 감소
}

void printh(Heap* h) {
    for(int i=0; i<h->index-1; i++) {
        printf("%d ", h->heap[i+1]);
    }
    printf("\n");
}

int main() {
    Heap heap;
    int sel, data;
    init(&heap);

    while(1) {
        printf("=====HEAP=====\n1. insert\n2. delete\n3. show\n4. exit\n\nenter : ");
        scanf("%d", &sel);

        switch(sel) {
            case 1 :
                printf("insert : ");
                scanf("%d", &data);
                insert(&heap, data);
                printf("finished\n\n");
                break;
            case 2 :
                delete(&heap);
                
                break;
            case 3 : 
                printh(&heap);
                break;
            case 4 :
                return 0;
        }
    }

}
