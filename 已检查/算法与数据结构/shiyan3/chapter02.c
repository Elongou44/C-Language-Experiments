#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100  // 定义队列最大容量

// 定义队列结构体，包含数据存储数组、队头指针和队尾指针
typedef struct {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// 初始化队列，将队头和队尾指针都设为0
void initQueue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

// 判断队列是否为空，队头和队尾相等则为空
int isEmpty(Queue *q) {
    return q->front == q->rear;
}

// 判断队列是否已满，队尾加1后与队头相同则已满
int isFull(Queue *q) {
    return (q->rear + 1) % MAX_SIZE == q->front;
}

// 入队操作，添加元素到队尾
int enqueue(Queue *q, int value) {
    if (isFull(q)) {  // 先判断队列是否已满
        printf("队列已满，无法入队！\n");
        return 0;
    }
    q->data[q->rear] = value;  // 将元素放入队尾位置
    q->rear = (q->rear + 1) % MAX_SIZE;  // 队尾指针后移
    return 1;
}

// 出队操作，移除并返回队头元素
int dequeue(Queue *q, int *value) {
    if (isEmpty(q)) {  // 先判断队列是否为空
        printf("队列为空，无法出队！\n");
        return 0;
    }
    *value = q->data[q->front];  // 获取队头元素
    q->front = (q->front + 1) % MAX_SIZE;  // 队头指针后移
    return 1;
}

// 显示队列中的所有元素
void displayQueue(Queue *q) {
    if (isEmpty(q)) {
        printf("队列为空！\n");
        return;
    }
    printf("队列中的元素：");
    int i = q->front;
    while (i != q->rear) {  // 从队头到队尾遍历队列
        printf("%d ", q->data[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

// 主菜单函数，显示可进行的操作选项
void menu() {
    printf("********** 队列操作菜单 **********\n");
    printf("1. 入队\n");
    printf("2. 出队\n");
    printf("3. 查看队列元素\n");
    printf("4. 判断队列是否为空\n");
    printf("5. 判断队列是否已满\n");
    printf("6. 退出\n");
    printf("**********************************\n");
    printf("请选择操作：");
}

int main() {
    Queue q;
    initQueue(&q);  // 初始化队列
    int choice, value;

    while (1) {  // 主循环，不断显示菜单并执行操作
        menu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:  // 入队操作
                printf("请输入要入队的元素：");
                scanf("%d", &value);
                enqueue(&q, value);
                break;
            case 2:  // 出队操作
                if (dequeue(&q, &value)) {
                    printf("出队元素：%d\n", value);
                }
                break;
            case 3:  // 显示队列元素
                displayQueue(&q);
                break;
            case 4:  // 判断是否为空
                if (isEmpty(&q)) {
                    printf("队列为空！\n");
                } else {
                    printf("队列不为空！\n");
                }
                break;
            case 5:  // 判断是否已满
                if (isFull(&q)) {
                    printf("队列已满！\n");
                } else {
                    printf("队列未满！\n");
                }
                break;
            case 6:  // 退出程序
                printf("程序结束！\n");
                exit(0);
            default:
                printf("无效的选择，请重新输入！\n");
        }
    }

    return 0;
}
