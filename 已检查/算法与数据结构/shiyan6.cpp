#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20
#define BLOCK_SIZE 5

// 顺序查找
int sequential_search(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// 折半查找
int binary_search(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// 分块查找
typedef struct {
    int max;
    int start;
    int end;
} Block;

int block_search(int arr[], int n, Block blocks[], int block_num, int key) {
    // 先确定key在哪个块中
    int block_index = -1;
    for (int i = 0; i < block_num; i++) {
        if (key <= blocks[i].max) {
            block_index = i;
            break;
        }
    }
    if (block_index == -1) return -1;
    
    // 在确定的块中顺序查找
    for (int i = blocks[block_index].start; i <= blocks[block_index].end; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}

// 二叉排序树结构
typedef struct BSTNode {
    int data;
    struct BSTNode *left, *right;
} BSTNode, *BSTree;

// 创建二叉排序树节点
BSTNode* create_bst_node(int value) {
    BSTNode* node = (BSTNode*)malloc(sizeof(BSTNode));
    node->data = value;
    node->left = node->right = NULL;
    return node;
}

// 插入元素到二叉排序树
void bst_insert(BSTree *root, int value) {
    if (*root == NULL) {
        *root = create_bst_node(value);
        return;
    }
    
    if (value < (*root)->data) {
        bst_insert(&(*root)->left, value);
    } else if (value > (*root)->data) {
        bst_insert(&(*root)->right, value);
    }
}

// 查找二叉排序树中的元素
BSTNode* bst_search(BSTree root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return bst_search(root->left, key);
    } else {
        return bst_search(root->right, key);
    }
}

// 删除二叉排序树中的元素
BSTNode* bst_delete(BSTree root, int key) {
    if (root == NULL) return root;
    
    if (key < root->data) {
        root->left = bst_delete(root->left, key);
    } else if (key > root->data) {
        root->right = bst_delete(root->right, key);
    } else {
        // 节点有一个或没有子节点
        if (root->left == NULL) {
            BSTNode* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            BSTNode* temp = root->left;
            free(root);
            return temp;
        }
        
        // 节点有两个子节点，获取右子树的最小节点
        BSTNode* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        
        // 复制数据并删除右子树的最小节点
        root->data = temp->data;
        root->right = bst_delete(root->right, temp->data);
    }
    return root;
}

// 中序遍历显示二叉排序树
void bst_inorder(BSTree root) {
    if (root != NULL) {
        bst_inorder(root->left);
        printf("%d ", root->data);
        bst_inorder(root->right);
    }
}

// 创建二叉排序树
BSTree create_bst(int arr[], int n) {
    BSTree root = NULL;
    for (int i = 0; i < n; i++) {
        bst_insert(&root, arr[i]);
    }
    return root;
}

// 显示菜单
void display_menu() {
    printf("\n======== 查找算法实现及应用 ========\n");
    printf("1. 顺序查找\n");
    printf("2. 折半查找\n");
    printf("3. 分块查找\n");
    printf("4. 二叉排序树操作\n");
    printf("0. 退出\n");
    printf("===================================\n");
    printf("请选择操作: ");
}

// 显示二叉排序树操作子菜单
void display_bst_menu() {
    printf("\n===== 二叉排序树操作 =====\n");
    printf("1. 建立二叉排序树\n");
    printf("2. 显示二叉排序树(中序遍历)\n");
    printf("3. 插入元素\n");
    printf("4. 删除元素\n");
    printf("5. 查找元素\n");
    printf("0. 返回主菜单\n");
    printf("=========================\n");
    printf("请选择操作: ");
}

int main() {
    int choice, bst_choice;
    int arr[MAX_SIZE];
    int n = 0;
    BSTree bst = NULL;
    
    // 初始化数组
    printf("请输入数组元素个数(不超过%d): ", MAX_SIZE);
    scanf("%d", &n);
    printf("请输入%d个整数:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    while (1) {
        display_menu();
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: { // 顺序查找
                int key;
                printf("请输入要查找的值: ");
                scanf("%d", &key);
                int result = sequential_search(arr, n, key);
                if (result != -1) {
                    printf("找到元素 %d 在数组中的位置: %d\n", key, result);
                } else {
                    printf("未找到元素 %d\n", key);
                }
                break;
            }
            case 2: { // 折半查找
                // 先检查数组是否有序
                int sorted = 1;
                for (int i = 0; i < n - 1; i++) {
                    if (arr[i] > arr[i + 1]) {
                        sorted = 0;
                        break;
                    }
                }
                if (!sorted) {
                    printf("数组未排序，无法使用折半查找\n");
                    break;
                }
                
                int key;
                printf("请输入要查找的值: ");
                scanf("%d", &key);
                int result = binary_search(arr, n, key);
                if (result != -1) {
                    printf("找到元素 %d 在数组中的位置: %d\n", key, result);
                } else {
                    printf("未找到元素 %d\n", key);
                }
                break;
            }
            case 3: { // 分块查找
                // 先对数组进行分块
                int block_num = (n + BLOCK_SIZE - 1) / BLOCK_SIZE;
                Block blocks[block_num];
                
                for (int i = 0; i < block_num; i++) {
                    blocks[i].start = i * BLOCK_SIZE;
                    blocks[i].end = (i + 1) * BLOCK_SIZE - 1;
                    if (blocks[i].end >= n) blocks[i].end = n - 1;
                    
                    // 找出块中的最大值
                    blocks[i].max = arr[blocks[i].start];
                    for (int j = blocks[i].start + 1; j <= blocks[i].end; j++) {
                        if (arr[j] > blocks[i].max) {
                            blocks[i].max = arr[j];
                        }
                    }
                }
                
                int key;
                printf("请输入要查找的值: ");
                scanf("%d", &key);
                int result = block_search(arr, n, blocks, block_num, key);
                if (result != -1) {
                    printf("找到元素 %d 在数组中的位置: %d\n", key, result);
                } else {
                    printf("未找到元素 %d\n", key);
                }
                break;
            }
            case 4: { // 二叉排序树操作
                while (1) {
                    display_bst_menu();
                    scanf("%d", &bst_choice);
                    
                    switch (bst_choice) {
                        case 1: { // 建立二叉排序树
                            if (bst != NULL) {
                                printf("二叉排序树已存在，是否重新创建?(1-是, 0-否): ");
                                int confirm;
                                scanf("%d", &confirm);
                                if (!confirm) break;
                            }
                            bst = create_bst(arr, n);
                            printf("二叉排序树创建成功\n");
                            break;
                        }
                        case 2: { // 显示二叉排序树
                            if (bst == NULL) {
                                printf("二叉排序树为空\n");
                            } else {
                                printf("二叉排序树中序遍历结果: ");
                                bst_inorder(bst);
                                printf("\n");
                            }
                            break;
                        }
                        case 3: { // 插入元素
                            int value;
                            printf("请输入要插入的值: ");
                            scanf("%d", &value);
                            bst_insert(&bst, value);
                            printf("插入成功\n");
                            break;
                        }
                        case 4: { // 删除元素
                            int value;
                            printf("请输入要删除的值: ");
                            scanf("%d", &value);
                            BSTNode* node = bst_search(bst, value);
                            if (node == NULL) {
                                printf("未找到元素 %d\n", value);
                            } else {
                                bst = bst_delete(bst, value);
                                printf("删除成功\n");
                            }
                            break;
                        }
                        case 5: { // 查找元素
                            int value;
                            printf("请输入要查找的值: ");
                            scanf("%d", &value);
                            BSTNode* node = bst_search(bst, value);
                            if (node == NULL) {
                                printf("未找到元素 %d\n", value);
                            } else {
                                printf("找到元素 %d\n", value);
                            }
                            break;
                        }
                        case 0: // 返回主菜单
                            break;
                        default:
                            printf("无效选择\n");
                    }
                    
                    if (bst_choice == 0) break;
                }
                break;
            }
            case 0: // 退出
                printf("程序结束\n");
                exit(0);
            default:
                printf("无效选择\n");
        }
    }
    
    return 0;
}
