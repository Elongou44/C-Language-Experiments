#include <stdio.h>
#include <stdlib.h>

// 定义节点结构，包含数据和指向下一个节点的指针
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// 定义队列结构，包含队首和队尾指针
typedef struct {
    Node *front; // 队首指针，指向第一个元素
    Node *rear;  // 队尾指针，指向最后一个元素
} Queue;

// 创建队列，分配队列结构体的内存并初始化指针
Queue* createQueue() {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->front = q->rear = NULL; // 初始化时队列为空
    return q;
}

// 入队操作，将元素添加到队列尾部
void enqueue(Queue *q, int value) {
    Node *newNode = (Node*)malloc(sizeof(Node)); // 创建新节点
    newNode->data = value; // 设置节点数据
    newNode->next = NULL;  // 新节点的指针初始化为空

    if (q->rear == NULL) {
        // 如果队列为空，新节点既是队首又是队尾
        q->front = q->rear = newNode;
    } else {
        // 将新节点添加到队尾
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

// 出队操作，从队列首部移除元素并返回其值
int dequeue(Queue* q) {
    if (q->front == NULL) {
        // 如果队列为空，返回错误值
        printf("队列为空。出队失败！\n");
        return -1;
    }
    
    Node *temp = q->front; // 保存队首节点
    int value = temp->data; // 获取队首节点数据
    q->front = q->front->next; // 将队首指针移向下一个节点
    
    if (q->front == NULL) {
        // 如果队列变为空，更新队尾指针
        q->rear = NULL;
    }
    
    free(temp); // 释放被删除节点的内存
    return value;
}

// 判断队列是否为空并提示
void checkEmpty(Queue* q) {
    if (q->front == NULL) {
        printf("队列为空。\n");
    } else {
        printf("队列不为空。\n");
    }
}

// 打印队列中的元素
void printQueue(Queue* q) {
    if (q->front == NULL) {
        printf("队列为空。\n");
        return;
    }
    
    Node *current = q->front;
    printf("队列元素：");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// 测试队列操作
int main() {
    Queue *q = createQueue();
    
    //初始为空
    printQueue(q);
    
    // 入队操作演示
    printf("执行入队操作：\n");
    
    enqueue(q, 10);
    printQueue(q);
    enqueue(q, 20);
    printQueue(q);
    enqueue(q, 30);
    
    // 打印队列状态
    printQueue(q);
    
    // 检查队列是否为空
    printf("\n检查队列是否为空：\n");
    checkEmpty(q);
    
    // 出队操作演示
    printf("\n执行出队操作：\n");
    printf("出队元素：%d\n", dequeue(q));
    printQueue(q);
    printf("出队元素：%d\n", dequeue(q));
    
    // 打印队列状态
    printQueue(q);
    
    // 再次检查队列是否为空
    printf("\n再次检查队列是否为空：\n");
    checkEmpty(q);
    
    // 再次入队操作演示
    printf("\n再次执行入队操作：\n");
    enqueue(q, 40);
    enqueue(q, 50);
    
    // 再次打印队列状态
    printQueue(q);
    
    return 0;
}
