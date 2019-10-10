    #include <bits/stdc++.h>
    using namespace std;

    int witnessTallPeople(int *arr, int n)
    {
        int maxCount = 0;
        for(int i = n - 1; i >= 0; i--){
            if(arr[i-1] > arr[i]){
                maxCount++;
            }
        }
        return (maxCount+1);
    }

    int main()
    {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        cout << witnessTallPeople(arr, n) << endl;
        return 0;
    }
