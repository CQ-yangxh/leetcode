#include <vector>
using namespace std;
// 一共有10种经典的排序算法
// 1.冒泡排序
void bubble_sort(vector<int>& arr){
    int len = arr.size();
    for(int i = 0; i < len; i++){
        // 记住都是从0开始，由于j+1的存在，所以j要小于len-1，由于冒泡一个元素之后就可以少冒一个，所以len-1-i
        for(int j = 0; j < len - 1 - i; j++){
            if(arr[j+1] < arr[j]) swap(arr[j], arr[j+1]);
        }
    }
}

// 2.选择排序
void select_sort(vector<int>& arr){
    int len = arr.size();
    int minIndex;
    for(int i = 0; i < len - 1; i++){
        minIndex = i;
        for(int j = i+1; j < len; j++){
            if(arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
    }
}

// 3.插入排序
void insert_sort(vector<int>& arr){
    int len = arr.size();
    for(int i = 1; i < len; i++){
        int temp = arr[i];
        int j = i;
        for(j; j >= 1 && temp < arr[j - 1]; j--)
            arr[j] = arr[j - 1];
        arr[j] = temp;
    }
}

// 4.快速排序
int partition(vector<int>& arr, int left, int right){
    int pivot = arr[left];
    while(left < right){
        while(left < right && arr[right] > pivot) right--;
        arr[left] = arr[right];
        while(left < right && arr[left] < pivot) left++;
        arr[right] = arr[left];
    }
    arr[left] = pivot;
    return left;
}
void quick_sort(vector<int>& arr, int left, int right){
    if(left < right){
        int sep = partition(arr, left, right);
        quick_sort(arr, 0, sep-1);
        quick_sort(arr, sep+1, right);
    }
}

// 5.归并排序
void merge(vector<int>& arr, vector<int>& tempArr, int left, int mid, int right){
    // 标记左半区第一个未排序的元素
    int l_pos = left;
    // 标记右半区第一个未排序的元素
    int r_pos = mid+1;
    // 临时数组元素的下标
    int pos = left;
    
    // 合并，把两个半区的元素填入临时数组，从第一个元素开始比较大小
    while(l_pos <= mid && r_pos <= right){
        if(arr[l_pos] < arr[r_pos]) tempArr[pos++] = arr[l_pos++];
        else tempArr[pos++] = arr[r_pos++];
    }

    // 填入左半区剩余的元素
    while(l_pos <= mid){
        tempArr[pos++] = arr[l_pos++];
    }

    // 填入右半区剩余的元素
    while (r_pos <= right){
        tempArr[pos++] = arr[r_pos++];
    }
    
    // 把临时数组拷贝到原数组
    while(left <= right){
        arr[left] = tempArr[left];
        left++;
    }
}
void sep(vector<int>& arr, vector<int>& tempArr, int left, int right){
    if(left < right){
        int mid = (left + right) / 2;
        // 递归划分左半区
        sep(arr, tempArr, left, mid);
        // 递归划分右半区
        sep(arr, tempArr, mid+1, right);
        // 合并两个半区
        merge(arr, tempArr, left, mid, right);
    }
}
void merge_sort(vector<int>& arr){
    vector<int> tempArr(arr.size());
    int left = 0;
    int right = arr.size() - 1;
    sep(arr, tempArr, left, right);
}

int main(){
    // 0 1  2  3  4  5  6  7  8  9  10
    // 1 17 21 22 29 34 50 60 61 62 72
    vector<int> arr = {61,17,29,22,34,60,72,21,50,1,62};
    // bubble_sort(arr);
    // select_sort(arr);
    // insert_sort(arr);
    // quick_sort(arr, 0, arr.size()-1);
    merge_sort(arr);
    return 0;
}