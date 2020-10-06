#include<bits/stdc++.h>
using namespace std;

int ways(int n)
{
    if(n<0)
    return 0;

    if(n==0)
    return 1;

    return ways(n-1)+ways(n-2)+ways(n-3);

}

int main()
{
    int n;
    cin>>n;

    cout<<ways(n)<<endl;

    return 0;
}