#include <iostream>
#include <vector>

using namespace std;


void merge(vector<int> &arr,int start,int mid,int end){
    vector<int> left,right;

    for(int i=start;i<mid;i++){
        left.push_back(arr[i]);
    }
    for(int j=mid;j<end;j++){
        right.push_back(arr[j]);
    }
    int num_left=0,num_right=0,k=start;
    while(num_left<left.size() && num_right<right.size()){
        if(left[num_left]<right[num_right]){
            arr[k]=left[num_left];
            num_left++;
        }
        else{
            arr[k]=right[num_right];
            num_right++;
        }
        k++;
    }
    while(num_left<left.size()){
        arr[k]=left[num_left];
        k++;num_left++;
    }
    while(num_right<right.size()){
        arr[k]=right[num_right];
        k++;num_right++;
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid= (right+left)/2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid+1, right+1);
    }
}


int main() {
    vector<int> arr;
    int input,length;
    cout<<"Enter the size of the array: ";
    cin>>length;
    cout<<"Enter the numbers";
    for(int i=0;i<length;i++){
        cin>>input;
        arr.push_back(input);
    }
    cout<<"Before sorting: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    mergeSort(arr, 0, length - 1);
    cout<<"after  sorting: ";
    for (int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    return 0;
}
