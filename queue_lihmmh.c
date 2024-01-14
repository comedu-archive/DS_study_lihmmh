#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
//원형큐

//(다른 노드와 연결 가능한) 노드 정의
typedef struct node {
    char data;
    struct node* below;
} node;

//큐 정의
typedef struct queue {
    node* front; // 맨앞에 위치한 노드 가리키는 포인터
    node* rear; //맨뒤에 위치한 노드 가리키는 포인터
    int size;
}queue;

//큐 함수
queue* create_q() {
    queue* q = malloc(sizeof(queue));

    if (q == NULL) {
        printf("Not enough memory");
        exit(EXIT_FAILURE);
    }
    q->size = 0;
    q->front = NULL;
    q->rear = NULL;

    return q;
}

//새로운 노드 생성하는 함수
node* new_node(const char new_data) {
    node* new_node = malloc(sizeof(node));
    if (new_node == NULL) {
        printf("Not enough memory");
        exit(EXIT_FAILURE);
    }
    new_node->data = new_data;
    new_node->below = NULL;
    return new_node;
}

//큐가 비어있는지 확인하는 함수
bool is_empty(const queue* q) {
    return q == NULL || q->rear == NULL;
}

//큐에 노드를 만들어 추가하는 함수
void enqueue(queue* q, const char a) {
    node* temp = new_node(a); //노드 만들고 이를 temp에 저장
    if (is_empty(q)) {
        q->front = temp;
        q->rear = temp;
    } //q가 비어있을때
    else {
        q->rear->below = temp;
        q->rear = temp;
    }
    q->size++;
}


//큐에서 프론트 노드 삭제
void dequeue(queue* q) {
    if (!is_empty(q)) {
        node* del = q->front;
        if (q->front->below == q->front) {
            q->front = NULL;
            q->rear = NULL;
        }
        else {
            q->front = q->front->below;
            q->rear->below = q->front;
        }
        free(del);
        q->size--;
    }

}

//큐의 rear 출력
char peek(const queue* q) {
    if (is_empty(q))
        return '\0';
    return q->rear->data;
}

//큐의 사이즈 출력
int size(const queue* q) {
    if (is_empty(q))
        return 0;
    return q->size;
}
//큐의 출력
void print(queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty");
        return;
    }
    node* now = q->front; // front를 가리키는 now 포인터 생성
    do {
        printf("%c", now->data);
        now = now->below; //다음 노드로 넘어감
    } while (now != q->front);
    printf("\n");
    //do-while은 이장원 교수님께 배움.. 대충 처음엔 무조건 실행하고 그 다음부터 조건문 확인한다는 뜻..
}

//큐 삭제
void clear_queue(queue** q) {
    while (!is_empty(*q))
        dequeue(*q);
    free(*q);
}

//메인함수.. 얘는 gpt 시켰습니다
int main() {
    queue* myQueue = create_q(); // 큐 생성

    char choice;
    char data;

    do {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Print Queue\n");
        printf("5. Queue Size\n");
        printf("6. Clear Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf_s(" %c", &choice);

        switch (choice) {
        case '1':
            printf("Enter data to enqueue: ");
            scanf_s(" %c", &data);
            enqueue(myQueue, data);
            printf("Enqueued %c\n", data);
            break;
        case '2':
            if (!is_empty(myQueue)) {
                data = peek(myQueue);
                dequeue(myQueue);
                printf("Dequeued front one\n", data);
            }
            else {
                printf("Queue is empty\n");
            }
            break;
        case '3':
            if (!is_empty(myQueue)) {
                data = peek(myQueue);
                printf("Peeked element: %c\n", data);
            }
            else {
                printf("Queue is empty\n");
            }
            break;
        case '4':
            print(myQueue);
            break;
        case '5':
            printf("Queue Size: %d\n", size(myQueue));
            break;
        case '6':
            clear_queue(&myQueue);
            printf("Queue cleared\n");
            break;
        case '0':
            printf("Exiting program\n");
            break;
        default:
            printf("Invalid choice\n");
        }

    } while (choice != '0');

    return 0;
}


