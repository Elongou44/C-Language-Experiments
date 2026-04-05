#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100  // 定义数组最大容量

// 打印数组当前状态
void printArray(int arr[], int n, const char *step) {
    printf("%s: ", step);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// 交换两个元素
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 直接插入排序
void insertionSort(int arr[], int n) {
    printf("\n直接插入排序:\n");
    for (int i = 1; i < n; i++) {
        int key = arr[i];  // 当前要插入的元素
        int j = i - 1;
        // 将比key大的元素向后移动
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;  // 插入key到正确位置
        char step[20];
        sprintf(step, "第%d趟", i);
        printArray(arr, n, step);
    }
}

// 希尔排序
void shellSort(int arr[], int n) {
    printf("\n希尔排序:\n");
    // 初始间隔为n/2，逐步缩小间隔
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每个子数组进行插入排序
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        char step[20];
        sprintf(step, "增量为%d后", gap);
        printArray(arr, n, step);
    }
}

// 冒泡排序
void bubbleSort(int arr[], int n) {
    printf("\n冒泡排序:\n");
    for (int i = 0; i < n - 1; i++) {
        // 每次遍历将最大的元素冒泡到最后
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
        char step[20];
        sprintf(step, "第%d趟", i + 1);
        printArray(arr, n, step);
    }
}

// 快速排序的分区函数
int partition(int arr[], int low, int high, int n) {
    int pivot = arr[high];  // 选择最后一个元素作为基准
    int i = low - 1;        // i是小于基准的元素的索引
    
    for (int j = low; j < high; j++) {
        // 如果当前元素小于基准
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);  // 交换元素
        }
    }
    swap(&arr[i + 1], &arr[high]);  // 将基准放到正确位置
    
    static int step_count = 1;
    char step[20];
    sprintf(step, "第%d趟", step_count++);
    printArray(arr, n, step);
    
    return i + 1;  // 返回基准的索引
}

// 快速排序
void quickSort(int arr[], int low, int high, int n) {
    if (low < high) {
        // 获取分区点
        int pi = partition(arr, low, high, n);
        // 递归排序左子数组
        quickSort(arr, low, pi - 1, n);
        // 递归排序右子数组
        quickSort(arr, pi + 1, high, n);
    }
}

// 选择排序
void selectionSort(int arr[], int n) {
    printf("\n选择排序:\n");
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;  // 假设当前位置是最小值
        // 在未排序部分查找最小值
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        // 将最小值交换到已排序部分的末尾
        if (min_idx != i) {
            swap(&arr[min_idx], &arr[i]);
        }
        char step[20];
        sprintf(step, "第%d趟", i + 1);
        printArray(arr, n, step);
    }
}

// 归并排序的合并函数
void merge(int arr[], int l, int m, int r, int n) {
    int n1 = m - l + 1;  // 左子数组大小
    int n2 = r - m;      // 右子数组大小
    
    // 创建临时数组
    int *L = (int*)malloc(n1 * sizeof(int));
    int *R = (int*)malloc(n2 * sizeof(int));

    // 复制数据到临时数组
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    // 合并临时数组回原数组
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // 复制剩余元素
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    static int step_count = 1;
    char step[20];
    sprintf(step, "第%d趟合并", step_count++);
    printArray(arr, n, step);

    free(L);
    free(R);
}

// 归并排序
void mergeSort(int arr[], int l, int r, int n) {
    if (l < r) {
        int m = l + (r - l) / 2;  // 计算中间点
        mergeSort(arr, l, m, n);    // 排序左半部分
        mergeSort(arr, m + 1, r, n);// 排序右半部分
        merge(arr, l, m, r, n);     // 合并已排序部分
    }
}

// 堆排序的堆调整函数
void heapify(int arr[], int n, int i, int step) {
    int largest = i;    // 初始化最大值为当前节点
    int l = 2 * i + 1;  // 左子节点
    int r = 2 * i + 2;  // 右子节点

    // 如果左子节点大于当前最大值
    if (l < n && arr[l] > arr[largest]) largest = l;
    // 如果右子节点大于当前最大值
    if (r < n && arr[r] > arr[largest]) largest = r;

    // 如果最大值不是当前节点
    if (largest != i) {
        swap(&arr[i], &arr[largest]);  // 交换
        heapify(arr, n, largest, step); // 递归调整受影响的子树
    }

    if (step) {
        static int step_count = 1;
        char step_str[20];
        sprintf(step_str, "第%d趟调整", step_count++);
        printArray(arr, n, step_str);
    }
}

// 堆排序
void heapSort(int arr[], int n) {
    printf("\n堆排序:\n");
    printf("初始建堆:\n");
    // 从最后一个非叶子节点开始构建堆
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, 0);
    }
    printArray(arr, n, "建堆后");

    // 一个个从堆顶取出元素
    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);  // 将当前最大值移到数组末尾
        char step[20];
        sprintf(step, "第%d趟排序", n - i);
        printArray(arr, n, step);
        printf("调整堆:\n");
        heapify(arr, i, 0, 1);  // 调整剩余堆
    }
}

// 复制数组
void copyArray(int dest[], int src[], int n) {
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int arr[MAX_SIZE], n, choice, original[MAX_SIZE];

    printf("请输入数组大小 (不超过%d): ", MAX_SIZE);
    scanf("%d", &n);

    printf("请输入数组元素:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        original[i] = arr[i];  // 保存原始数组
    }

    do {
        printf("\n排序算法菜单:\n");
        printf("1. 直接插入排序\n");
        printf("2. 希尔排序\n");
        printf("3. 冒泡排序\n");
        printf("4. 快速排序\n");
        printf("5. 选择排序\n");
        printf("6. 归并排序\n");
        printf("7. 堆排序\n");
        printf("8. 退出\n");
        printf("请选择: ");
        scanf("%d", &choice);

        copyArray(arr, original, n);  // 每次排序前恢复原始数组

        switch (choice) {
            case 1: insertionSort(arr, n); break;
            case 2: shellSort(arr, n); break;
            case 3: bubbleSort(arr, n); break;
            case 4: printf("\n快速排序:\n"); quickSort(arr, 0, n - 1, n); break;
            case 5: selectionSort(arr, n); break;
            case 6: printf("\n归并排序:\n"); mergeSort(arr, 0, n - 1, n); break;
            case 7: heapSort(arr, n); break;
            case 8: printf("退出程序\n"); break;
            default: printf("无效选择，请重新输入\n");
        }
    } while (choice != 8);

    return 0;
}
