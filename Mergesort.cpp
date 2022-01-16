#include<iostream>
using namespace std;
void merge(int arr1[],int l,int m,int r)
{
    int i=l,j=m+1,k=l;
    int temp[12];
    while(i<=m && j<=r)
    {
        if(arr1[i]<arr1[j])
        {
            temp[k]=arr1[i];
            i++;
            k++;
        }
        else
        {
            temp[k]=arr1[j];
            j++;
            k++;
        }
    }
    while(i<=m)
    {
        temp[k]=arr1[i];
        i++;
        k++;
    }
    while(j<=r)
    {
        temp[k]=arr1[j];
        j++;
        k++;
    }
    for(int a=l;a<=r;a++)
    {
        arr1[a]=temp[a];
    }
}
void MergeSort(int arr[],int left,int right)
{
    if(left<right)
    {
        int middle=(left+right)/2;
        MergeSort(arr,left,middle);
        MergeSort(arr,middle+1,right);
        merge(arr,left,middle,right);
    }
}
int main()
{
    int arr[12]={9,7,3,6,2,1,4,10,5,43,90,0};
    cout<<"Befor Mergesort: "<<endl;
    for(int i=0;i<12;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    MergeSort(arr,0,11);
    cout<<"After MergeSort: "<<endl;
    for(int i=0;i<12;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}