#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin>>arr[i];
    }

    int a = count(arr, arr + n, 1);
    int b = count(arr, arr + n, 2);
    int c = count(arr, arr + n, 3);

    for(int i = 0; i < a; i++){
        cout<<1<< " ";
    }
    for(int i = 0; i < b; i++){
        cout<<2<<" ";
    }
    for(int i = 0; i < c; i++){
        cout<<3<<" ";
    }
    
    return 0;
}
