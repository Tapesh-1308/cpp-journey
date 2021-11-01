#include <iostream>
#include <limits.h>

using namespace std;

int kadane(int a[], int n)
    {
        int currSum = 0;
        int maxSum = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            currSum += a[i];
            if (currSum < 0)
            {
                currSum = 0;
            }
            maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }

bool pairsum(int arr[], int n, int k){
    int low = 0;
    int high = n-1;

    while(low<high){
        if(arr[low]+arr[high] == k){
            cout<<low<<" "<<high<<endl;
            return true;
        }
        else if(arr[low]+arr[high] > k){
            high--;
        }
        else{
            low++;
        }
    }
    
    return false;
        
}

int main()
{
    // Max Number of an array
    /* int mx = -999999999;

    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
        cout<<mx<<" ";
    } */

    // Sum of subarrays
    /* int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int curr = 0;

    for (int i = 0; i < n; i++) {
        curr = 0;
        for (int j = i; j < n; j++) {
            curr += arr[j];
            cout << curr << endl;
        }
        
    } */

    // Longest arithmetic subarrays - GOOGLE KICKSTART QUES
    /* int n;
    cin>>n;

    int arr[n];

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int ans = 2;
    int pd = arr[1] - arr[0];
    int j = 2;
    int curr = 2;

    while(j<n){
        if(pd == arr[j] - arr[j-1]){
            curr++;
        }
        else{
            pd = arr[j] - arr[j-1];
            curr = 2;
        }
            ans = max(ans, curr);
        j++;
    }
    cout<<ans<<endl; */

    // Record Breaking - GOOGLE KICKSTART QUES
    /* int n;
    cin >> n;

    int arr[n + 1];
    arr[n] = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (n == 0)
    {
        cout << 1;
        return 0;
    }

    int ans = 0;
    int mx = -1;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mx && arr[i] > arr[i + 1])
        {
            ans++;
        }
        mx = max(mx, arr[i]);
    }

    cout << ans << endl; */

    //First Repeating Element
    /* int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    const int N = 1e5 + 2;
    int idx[N];
    for (int i = 0; i < N; i++)
    {
        idx[i] = -1;
    }

    int minidx = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (idx[arr[i]] != -1)
        {
            minidx = min(minidx, idx[arr[i]]);
        }
        else
        {
            idx[arr[i]] = i;
        }
    }

    if (minidx == INT_MAX)
    {
        cout << "-1" << endl;
    }
    else
    {
        cout << minidx + 1 << endl;
    } */

    //Subarray with given sum
    /* int n, s;
    cin>>n>>s;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int i=0, j=0, st=0-1, en=-1, sum=0;

    while(j<n && sum+a[j] <= s){
        sum += a[j];
        j++;
    }

    if(sum == s){
        cout<< i+1 <<" "<< j;
        return 0;
    }

    while (j<n)
    {
        sum += a[j];
        while(sum > s){
            sum -= a[i];
            i++;
        }
        if(sum == s){
            st = i+1;
            en = j+1;
            break;
        }
        j++;
    }
    cout<< st <<" "<< en; */

    //Smallest Missing Number
    /* int n;
    cin>>n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    const int N = 1e5 + 2;
    bool check[N];

    for (int i = 0; i < N; i++)
    {
        check[i] = 0;
    }
    
    for (int i = 0; i < n; i++)
    {
        if(a[i] >= 0){
            check[a[i]] = 1;
        }
    }
    
    int ans = -1;
    for (int i = 1; i < N; i++)
    {
        if(check[i] == false){
            ans = i;
            break;
        }
    }
    cout<<ans; */

    //Find all subarrays in given array
    /* int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << a[k] << " ";
            }
            cout << endl;
        }
    } */

    //Maximum sum of subarray METHOD - 1 // Time Complexity O(n^3)
    /* int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int maxSum = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            maxSum = max(maxSum, sum);
        }
    }

    cout<<maxSum; */

    //Maximum sum of subarray METHOD - 2 // Time Complexity O(n^2)
    /* int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int currSum[n+1];
    currSum[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        currSum[i] = currSum[i-1] + a[i-1];
    }
    

    int maxSum = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
        {
            sum = currSum[i] - currSum[j];
            maxSum = max(sum, maxSum);
        }
    }

    cout<<maxSum; */

    //Maximum sum of subarray METHOD - 3 // Time Complexity O(n) \\ kadane's Algo
    /* int n;
    cin >> n;

    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int currSum = 0;
    int maxSum = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        currSum +=  a[i];
        if(currSum<0){
            currSum = 0;
        }
        maxSum = max(maxSum, currSum);
    }

    cout<<maxSum; */

    //Maximum Circular subaray
    /* int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int wrapsum;
    int nonwrapsum;
    nonwrapsum = kadane(arr, n);

    int totalsum = 0;
    for (int i = 0; i < n; i++)
    {
        totalsum += arr[i];
        arr[i] = -arr[i];
    }

    wrapsum = totalsum + kadane(arr, n);
    cout<<max(wrapsum, nonwrapsum)<<endl; */
    
    //Pair Sum
    /* int arr[] = {2, 5 , 8 , 10, 12, 13, 14, 25};
    int k = 25;
    cout<<pairsum(arr, 8 , k)<<endl; */
    
    return 0;
}