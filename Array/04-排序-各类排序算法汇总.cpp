/*
Author: CagurZhan
Description: 各类排序算法
*/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
void quickSort(vector<int>&nums, int low , int high);
int partition(vector<int>&nums,int low , int high);
void quickSort(vector<int>&nums);

// 针对Leetcode的题目，使用快速排序解决。
vector<int> sortArray(vector<int>& nums) {
    random_shuffle(nums.begin(),nums.end());
    quickSort(nums);
    return nums;
}

// 直接插入排序：将数组分为已排序部分和未排序部分。每次将一个新的元素插入到已排序部分。
// 在此基础上，还有折半插入排序和希尔排序，都属于插入排序的范畴。
void insertSort(vector<int>&nums){
    int val;
    for(int i=1;i<nums.size();i++){
        if(nums[i] < nums[i-1]){
            val = nums[i];
            int j;
            for(j = i-1;j>=0 && nums[j]> val;j--){
                nums[j+1] = nums[j];
            }
            nums[j+1] = val;
        }
    }
}

// 交换类排序：冒泡排序、快速排序
// 冒泡排序：每次排序确定一个位置。
void bubbleSort(vector<int>&nums){
    for(int i=0;i<nums.size()-1;i++){
        for(int j=1;j<nums.size()-i;j++){
            if(nums[j] < nums[j-1]) swap(nums[j],nums[j-1]);
        }
    }
}

// 快速排序
// 快排有点类似于说“前序递归”，就是先找枢纽进行划分，然后再递归操作。
// 而归并排序有点类似于说“后序递归”，就是先递归划分，然后再进行归并操作。
void quickSort(vector<int>&nums){
    // 打乱优化
    random_shuffle(nums.begin(),nums.end());
    quickSort(nums,0,nums.size()-1);
}

void quickSort(vector<int>&nums, int low , int high){
    if(low < high){
        int mid = partition(nums,low, high);
        // 针对Leetcode的TLE做优化，防止出现多元素重复的情况
        int left = mid, right = mid;
        while(left > 0 && nums[left] == nums[left-1]) left --;
        while(right < nums.size() -1 && nums[right] == nums[right+1]) right++;

        quickSort(nums,low,left-1);
        quickSort(nums,right+1,high);
    }
}
// 划分，返回划分后的中间位置，
int partition(vector<int>&nums,int low , int high){
    // 随机选择枢纽
    int random_index = low + rand() % (high-low+1);
    swap(nums[random_index],nums[low]);
    int pivot = nums[low];
    while(low < high){
        while(low < high && nums[high] >= pivot) high--;
        nums[low] = nums[high];
        while(low < high && nums[low] <= pivot) low++;
        nums[high] = nums[low];
    }
    nums[low] = pivot;

    return low;
}


// 选择类排序：简单选择排序、堆排序
// 简单选择排序，每次从序列后面选出最小值放到开头
void selectionSort(vector<int>&nums){
    for(int i=0;i<nums.size();i++){
        int m = i;
        for(int j=i+1;j<nums.size();j++){
            if(nums[j] < nums[m]) m = j;
        }
        if(m!=i) swap(nums[i],nums[m]);
    }
}


// 堆排序
// 调整操作，对元素K为根的子树进行调整
void HeadAdjust(vector<int>&nums,int k,int len){
    nums[0] = nums[k];
    // k指向最终位置
    for(int i=2*k;i<=len;i*=2){
        if(i < len && nums[i] < nums[i+1]) i++;
        if(nums[0] >= nums[i]) break;
        else{
            nums[k] = nums[i];
            k = i;
        }
        nums[k] = nums[0];
    }
}
// 建立大根堆
// 堆的数组一般是下标从1开始
void buildMaxHeap(vector<int>&nums, int len){
    for(int i=len/2;i>0;i--)
        HeadAdjust(nums,i,len);
}

void heapSort(vector<int>&nums){
    buildMaxHeap(nums,nums.size()-1);
    for(int i=nums.size()-1;i>1;i--){
        swap(nums[i],nums[1]);
        HeadAdjust(nums,1,i-1);
    }
}


// 归并排序

void merge(vector<int>&nums, int left, int mid , int right){
    // 将元素复制到临时数组中
    int i,j,k;
    vector<int>tmp(nums);
    for(i=left,j = mid+1,k = i;i<=mid && j<=right;k++){
        if(tmp[i] <= tmp[j]) nums[k] = tmp[i++];
        else nums[k] = tmp[j++]; 
    }
    while(i <= mid) nums[k++] = tmp[i++];
    while(j <= right) nums[k++] = tmp[j++];
}

void mergeSort(vector<int>&nums, int left , int right){
    if(left < right) {
        int mid = (left + right) /2 ;
        mergeSort(nums,left,mid);
        mergeSort(nums,mid+1,right);
        merge(nums,left,mid,right);
    }
}

void mergeSort(vector<int>&nums){
    mergeSort(nums,0,nums.size()-1);
}

// 此外还有基数排序，一般很少要求直接写出代码，因此这里不给出基数排序的代码。


// 辅助方法，打印数组
void printArray(vector<int>&nums){
    for(auto & item : nums){
        cout << item << " ";
    }
    cout << endl;
}

int main(){
    
    vector<int> nums = {1,4,3,3,2,2,3,5,3,1,1,2,8,1,1,8,5,6,9};
    // 用于测试堆排序，下标从1开始
    vector<int> nums_for_heap = {999,1,4,3,3,2,2,3,5,3,1,1,2,8,1,1,8,5,6,9};
    cout << "before sort: " << endl;
    // printArray(nums_for_heap);
    printArray(nums);
    // bubbleSort(nums);
    // insertSort(nums);
    // quickSort(nums);
    // selectionSort(nums);
    // heapSort(nums_for_heap);
    mergeSort(nums);
    cout << "after sort: " << endl;
    // printArray(nums_for_heap);
    printArray(nums);
    return 0;
}