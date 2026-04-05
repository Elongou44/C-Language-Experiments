#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTEX_NUM 20  // 图中最大顶点数

// 边表结点（存储边的信息）
typedef struct ArcNode {
    int adjvex;              // 该边指向的顶点在顶点表中的下标
    struct ArcNode *nextarc; // 指向下一条邻接边的指针
} ArcNode;

// 顶点表结点（存储顶点的信息）
typedef struct VNode {
    char data;           // 顶点数据（这里用字符表示）
    ArcNode *firstarc;   // 指向该顶点的第一条邻接边
} VNode, AdjList[MAX_VERTEX_NUM]; // 顶点表数组类型

// 图的邻接表存储结构
typedef struct {
    AdjList vertices;    // 顶点表数组
    int vexnum, arcnum;  // 图的当前顶点数和边数
    int kind;            // 图的种类：0-无向图，1-有向图
} ALGraph;

// 队列结构（用于广度优先遍历BFS）
typedef struct {
    int data[MAX_VERTEX_NUM]; // 队列数组
    int front, rear;         // 队首和队尾指针
} Queue;

// 初始化队列
void InitQueue(Queue *Q) {
    Q->front = Q->rear = 0; // 队首队尾都置0
}

// 判断队列是否为空
bool QueueEmpty(Queue *Q) {
    return Q->front == Q->rear;
}

// 入队操作
bool EnQueue(Queue *Q, int e) {
    if ((Q->rear + 1) % MAX_VERTEX_NUM == Q->front) // 队列满
        return false;
    Q->data[Q->rear] = e;
    Q->rear = (Q->rear + 1) % MAX_VERTEX_NUM; // 循环队列
    return true;
}

// 出队操作
bool DeQueue(Queue *Q, int *e) {
    if (QueueEmpty(Q)) // 队列空
        return false;
    *e = Q->data[Q->front];
    Q->front = (Q->front + 1) % MAX_VERTEX_NUM;
    return true;
}

// 根据顶点数据查找其在顶点表中的位置
int LocateVex(ALGraph *G, char v) {
    for (int i = 0; i < G->vexnum; i++) {
        if (G->vertices[i].data == v)
            return i;
    }
    return -1; // 未找到返回-1
}

// 创建图的邻接表
void CreateGraph(ALGraph *G) {
    printf("请输入图的类型(0-无向图，1-有向图): ");
    scanf("%d", &G->kind);
    
    printf("请输入顶点数和边数: ");
    scanf("%d %d", &G->vexnum, &G->arcnum);
    getchar(); // 吸收换行符
    
    // 输入顶点信息
    printf("请输入%d个顶点的信息(字符): ", G->vexnum);
    for (int i = 0; i < G->vexnum; i++) {
        scanf("%c", &G->vertices[i].data);
        G->vertices[i].firstarc = NULL; // 初始化每个顶点的边表
    }
    getchar(); // 吸收换行符
    
    // 输入边信息并建立邻接表
    printf("请输入%d条边的信息(格式:顶点1 顶点2):\n", G->arcnum);
    for (int k = 0; k < G->arcnum; k++) {
        char v1, v2;
        scanf("%c %c", &v1, &v2);
        getchar(); // 吸收换行符
        
        int i = LocateVex(G, v1); // 找到顶点v1的位置
        int j = LocateVex(G, v2); // 找到顶点v2的位置
        
        // 创建边结点并插入到v1的边表中（头插法）
        ArcNode *p = (ArcNode *)malloc(sizeof(ArcNode));
        p->adjvex = j;
        p->nextarc = G->vertices[i].firstarc;
        G->vertices[i].firstarc = p;
        
        // 如果是无向图，还需要创建v2到v1的边
        if (G->kind == 0) {
            ArcNode *q = (ArcNode *)malloc(sizeof(ArcNode));
            q->adjvex = i;
            q->nextarc = G->vertices[j].firstarc;
            G->vertices[j].firstarc = q;
        }
    }
}

// 深度优先遍历（递归实现）
void DFS(ALGraph *G, int v, bool visited[]) {
    visited[v] = true; // 标记当前顶点已访问
    printf("%c ", G->vertices[v].data); // 输出顶点数据
    
    // 遍历当前顶点的所有邻接顶点
    ArcNode *p = G->vertices[v].firstarc;
    while (p != NULL) {
        int w = p->adjvex;
        if (!visited[w]) { // 如果邻接顶点未被访问
            DFS(G, w, visited); // 递归访问
        }
        p = p->nextarc; // 处理下一个邻接顶点
    }
}

// 深度优先遍历入口函数
void DFSTraverse(ALGraph *G) {
    bool visited[MAX_VERTEX_NUM] = {false}; // 访问标记数组
    
    printf("深度优先遍历结果: ");
    for (int v = 0; v < G->vexnum; v++) {
        if (!visited[v]) { // 对每个未访问过的顶点进行DFS
            DFS(G, v, visited);
        }
    }
    printf("\n");
}

// 广度优先遍历（使用队列）
void BFSTraverse(ALGraph *G) {
    bool visited[MAX_VERTEX_NUM] = {false}; // 访问标记数组
    Queue Q;
    InitQueue(&Q); // 初始化队列
    
    printf("广度优先遍历结果: ");
    for (int v = 0; v < G->vexnum; v++) {
        if (!visited[v]) {
            visited[v] = true;
            printf("%c ", G->vertices[v].data);
            EnQueue(&Q, v); // 当前顶点入队
            
            while (!QueueEmpty(&Q)) {
                int u;
                DeQueue(&Q, &u); // 出队一个顶点
                
                // 遍历u的所有邻接顶点
                ArcNode *p = G->vertices[u].firstarc;
                while (p != NULL) {
                    int w = p->adjvex;
                    if (!visited[w]) { // 如果邻接顶点未被访问
                        visited[w] = true;
                        printf("%c ", G->vertices[w].data);
                        EnQueue(&Q, w); // 邻接顶点入队
                    }
                    p = p->nextarc;
                }
            }
        }
    }
    printf("\n");
}

// 打印邻接表（用于调试和验证）
void PrintGraph(ALGraph *G) {
    printf("\n图的邻接表表示:\n");
    for (int i = 0; i < G->vexnum; i++) {
        printf("%c -> ", G->vertices[i].data);
        ArcNode *p = G->vertices[i].firstarc;
        while (p != NULL) {
            printf("%c -> ", G->vertices[p->adjvex].data);
            p = p->nextarc;
        }
        printf("NULL\n");
    }
}

// 显示操作菜单
void Menu() {
    printf("\n==========图的操作菜单==========\n");
    printf("1. 创建图\n");
    printf("2. 深度优先遍历(DFS)\n");
    printf("3. 广度优先遍历(BFS)\n");
    printf("4. 打印邻接表\n");
    printf("0. 退出\n");
    printf("===============================\n");
    printf("请选择操作: ");
}

int main() {
    ALGraph G;
    int choice;
    
    do {
        Menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                CreateGraph(&G); // 创建图
                break;
            case 2:
                DFSTraverse(&G); // 深度优先遍历
                break;
            case 3:
                BFSTraverse(&G); // 广度优先遍历
                break;
            case 4:
                PrintGraph(&G); // 打印邻接表
                break;
            case 0:
                printf("程序退出!\n");
                break;
            default:
                printf("无效的选择，请重新输入!\n");
        }
    } while (choice != 0);
    
    return 0;
}
