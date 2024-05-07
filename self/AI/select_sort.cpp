#include <bits/stdc++.h>

using namespace std;

void selection_sort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_indx = i;
        
        for (int j = i + 1; j < n; j++)
        {
            if (arr[min_indx] >arr[j])
            {
                min_indx = j;
            }
        }

        if (min_indx != i)
        {
            swap(arr[min_indx],arr[i]);
        }
    }
}


int main(){

int n;
    cin>>n;
    int arr[n];
    cout<<" enter the array:"<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    selection_sort(arr, n);


    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}