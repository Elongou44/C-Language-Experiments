#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义二叉树节点结构
typedef struct BiTNode {
    char data;             // 节点数据
    struct BiTNode *lchild, *rchild;  // 左右子树指针
} BiTNode, *BiTree;

//===== 二叉树基本操作函数 =====
BiTree CreateBiTree();           // 先序递归创建二叉树
void PrintTree(BiTree T);        // 广义表形式输出二叉树
void PreOrderTraverse(BiTree T); // 先序遍历
void InOrderTraverse(BiTree T);  // 中序遍历
void PostOrderTraverse(BiTree T); // 后序遍历
void LevelOrderTraverse(BiTree T); // 层次遍历(队列实现)
int NodeCount(BiTree T);         // 计算节点总数
int LeafCount(BiTree T);         // 计算叶子节点数
int TreeDepth(BiTree T);         // 计算树的深度
void menu();                     // 显示操作菜单

// 用先序方法建立一颗二叉树
BiTree CreateBiTree() {
    char ch;
    scanf("%c", &ch);
    if (ch == '#') return NULL;  // 空节点
    
    // 创建根节点
    BiTree T = (BiTree)malloc(sizeof(BiTNode));
    T->data = ch;
    
    // 递归创建左右子树
    T->lchild = CreateBiTree();
    T->rchild = CreateBiTree();
    
    return T;
}

// 按广义表表示法显示二叉树结构
void PrintTree(BiTree T) {
    if (!T) return;
    printf("%c", T->data);
    
    // 有子树时输出括号
    if (T->lchild || T->rchild) {
        printf("(");
        PrintTree(T->lchild);
        
        // 有右子树时输出逗号
        if (T->rchild) printf(",");
        PrintTree(T->rchild);
        
        printf(")");
    }
}

// 先序遍历：根-左-右
void PreOrderTraverse(BiTree T) {
    if (T) {
        printf("%c ", T->data);      // 访问根节点
        PreOrderTraverse(T->lchild);  // 递归遍历左子树
        PreOrderTraverse(T->rchild);  // 递归遍历右子树
    }
}

// 中序遍历：左-根-右
void InOrderTraverse(BiTree T) {
    if (T) {
        InOrderTraverse(T->lchild);   // 递归遍历左子树
        printf("%c ", T->data);       // 访问根节点
        InOrderTraverse(T->rchild);   // 递归遍历右子树
    }
}

// 后序遍历：左-右-根
void PostOrderTraverse(BiTree T) {
    if (T) {
        PostOrderTraverse(T->lchild);  // 递归遍历左子树
        PostOrderTraverse(T->rchild);  // 递归遍历右子树
        printf("%c ", T->data);        // 访问根节点
    }
}

// 层次遍历：使用队列实现
void LevelOrderTraverse(BiTree T) {
    if (!T) return;
    
    // 定义队列并初始化
    BiTree queue[100];
    int front = 0, rear = 0;
    
    // 根节点入队
    queue[rear++] = T;
    
    // 队列非空时循环处理
    while (front < rear) {
        BiTree node = queue[front++];  // 出队
        printf("%c ", node->data);     // 访问节点
        
        // 左右子节点入队
        if (node->lchild) queue[rear++] = node->lchild;
        if (node->rchild) queue[rear++] = node->rchild;
    }
}

// 求二叉树结点总数
int NodeCount(BiTree T) {
    if (!T) return 0;
    // 根节点数(1) + 左子树节点数 + 右子树节点数
    return 1 + NodeCount(T->lchild) + NodeCount(T->rchild);
}

// 求二叉树的叶子结点数(度为0的节点)
int LeafCount(BiTree T) {
    if (!T) return 0;
    if (!T->lchild && !T->rchild) return 1;  // 叶子节点
    return LeafCount(T->lchild) + LeafCount(T->rchild);
}

// 求二叉树的深度
int TreeDepth(BiTree T) {
    if (!T) return 0;
    
    // 计算左右子树深度
    int leftDepth = TreeDepth(T->lchild);
    int rightDepth = TreeDepth(T->rchild);
    
    // 树的深度为较大子树深度+1
    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// 显示操作菜单
void menu() {
    printf("\n===== 二叉树操作菜单 =====\n");
    printf("1. 建立二叉树\n");
    printf("2. 显示二叉树(广义表形式)\n");
    printf("3. 先序遍历\n");
    printf("4. 中序遍历\n");
    printf("5. 后序遍历\n");
    printf("6. 层次遍历\n");
    printf("7. 结点总数\n");
    printf("8. 叶子结点数\n");
    printf("9. 树的深度\n");
    printf("0. 退出\n");
    printf("=========================\n");
    printf("请输入你的选择: ");
}

int main() {
    BiTree T = NULL;
    int choice;
    
    do {
        menu();
        scanf("%d", &choice);
        getchar();  // 消耗scanf后的换行符
        
        switch (choice) {
            case 1:
                printf("请输入二叉树的先序序列(#表示空节点):\n");
                T = CreateBiTree();
                printf("二叉树建立成功！\n");
                break;
            case 2:
                printf("广义表形式: ");
                PrintTree(T);
                printf("\n");
                break;
            case 3: printf("先序遍历结果: "); PreOrderTraverse(T); printf("\n"); break;
            case 4: printf("中序遍历结果: "); InOrderTraverse(T); printf("\n"); break;
            case 5: printf("后序遍历结果: "); PostOrderTraverse(T); printf("\n"); break;
            case 6: printf("层次遍历结果: "); LevelOrderTraverse(T); printf("\n"); break;
            case 7: printf("结点总数: %d\n", NodeCount(T)); break;
            case 8: printf("叶子结点数: %d\n", LeafCount(T)); break;
            case 9: printf("树的深度: %d\n", TreeDepth(T)); break;
            case 0: printf("程序已退出！\n"); break;
            default: printf("无效选择，请重新输入！\n");
        }
    } while (choice != 0);
    
    return 0;
}    
