#include<bits/stdc++.h>
#include<vector>
using namespace std;

void swap(vector<int>& arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void bubble(vector<int> &num)
{
int n=num.size();
for(int i=0;i<n-1;i++)
{
for (int j=0;j<n-i-1;j++)
{
if(num[j]>num[j+1])
{
swap(num[j],num[j+1]);
}
}
}
cout<<"sorted array using bubble sort: "<<endl;
for(int k=0;k<n;k++)
{
cout<<num[k]<<" ";
}
cout<<endl;

}

void insertion(vector<int> &num)
{
int n=num.size();
int j;
for(int i=1;i<n;i++)
{
j=i;
while(j>0 && num[j]<num[j-1])
{
swap(num[j],num[j-1]);
j=j-1;
}
}
cout<<"sorted array using insertion sort: "<<endl;
for(int k=0;k<n;k++)
{
cout<<num[k]<<" ";
}
cout<<endl;

}

void selection(vector<int> &num)
{
int n=num.size(),min;
for(int i=0;i<n-1;i++)
{
min=i;
for(int j=i+1;j<n;j++)
{
if(num[j]<num[min])
{
min =j;
}
}
swap(num[i],num[min]);
 }
cout<<"sorted array using selection sort: "<<endl;
for(int k=0;k<n;k++)
{
cout<<num[k]<<" ";
}
cout<<endl;
}

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i + 1;
}

void quickSort(vector<int>& arr,int low,int high) 
{
    int n=arr.size();
    if (low < high) {
        int p = partition(arr, low, high);
        quickSort(arr, low, p - 1);
        quickSort(arr, p + 1, high);
    }
}

void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1);
    vector<int> R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }
    int i = 0;
    int j = 0;
    int k = l;
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
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int l, int r) {
    int n=arr.size();
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
    cout << "Sorted Array using merge Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellSort(vector<int>& arr) {
    int n = arr.size();
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
    cout << "Sorted Array using Shell Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void countSort(vector<int>& arr) {
    int n = arr.size();
    vector<int> count(1001, 0);
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i < 1001; i++) {
        count[i] += count[i - 1];
    }

    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--) {
        result[--count[arr[i]]] = arr[i];
    }

    arr = result;
    cout << "Sorted Array using Count Sort: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}


void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> count(10, 0);
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }
    vector<int> result(n);
    for (int i = n - 1; i >= 0; i--) {
        result[--count[(arr[i] / exp) % 10]] = arr[i];
    }
    arr = result;
}

void radixSort(vector<int>& arr) {
    int n = arr.size();
    auto max_it = std::max_element(arr.begin(), arr.end());
    int maxx = *max_it;

    for (int exp = 1; maxx / exp > 0; exp *= 10) { 
        countingSort(arr, exp);
    }

    cout << "Sorted Array using Radix Sort: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
vector<int> nums;
cout<<"Enter size"<<"\n";
int n,x;
cin>>n;
cout<<"Start entering elements"<<endl;
for(int i=0;i<n;i++)
{
cin>>x;
nums.push_back(x);
}
cout<<"menu\n1.bubble\n2.insertion\n3.selection\n4.quick\n5.Merge\n6.shell\n7.count\n8.radix\nenter choice:  ";
int i;
cin>>i;
switch(i)
{
case 1:
bubble(nums);
break;
case 2:
insertion(nums);
break;
case 3:
selection(nums);
break;
case 4:
quickSort(nums,0,n-1);
cout<<"sorted array using quick sort: "<<endl;
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
break;
case 5:
mergeSort(nums,0,n-1);
break;
case 6:
shellSort(nums);
break;
case 7:
countSort(nums);
break;
case 8:
radixSort(nums);
break;
}
}