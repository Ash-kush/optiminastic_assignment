#include<bits/stdc++.h>
using namespace std;
void merge(vector<int> &arr, int start, int mid, int end) {
    vector<int> LR;
    int Left = start, Right = mid + 1;
    while(Left <= mid && Right <= end) {
        if(arr[Left] <= arr[Right])
            LR.push_back(arr[Left++]);
        else
            LR.push_back(arr[Right++]);
    }
    while(Left <= mid)
        LR.push_back(arr[Left++]);
    while(Right <= end)
        LR.push_back(arr[Right++]);
    for(int k = start; k <= end; k++) 
        arr[k] = LR[k - start];
}
int merge_sort(vector<int> &arr, int start, int end) {
    int mid = (start + end) / 2;
    if(start < end) {
        merge_sort(arr, start, mid);
        merge_sort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
    return 0;
}
int main() {
    vector<int> arr {95, 45, -12, 34, 0, 1, 24, -32, 54};
    merge_sort(arr, 0, arr.size() - 1);
    for(auto it : arr) {
        cout<<it<<" ";
    }
    return 0;
}