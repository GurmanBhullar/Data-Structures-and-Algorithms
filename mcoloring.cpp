#include<bits/stdc++.h>
using namespace std;
int arr[1000][1000];

bool issafe(int i,int v,int color[],int n)
{
    for(int j=0;j<n;j++)
    {
        if(arr[v][j]==1 && color[j]==i)
        return false;
    }
    return true;

}

bool mcoloring(int n,int color[],int v)
{
    if(v==n)
    {
       // print(color);
        return true;
    }

    for(int i=1;i<=n;i++)
    {
        if(issafe(i,v,color,n))
        {
            color[v]=i;
            if(mcoloring(n,color,v+1))
            {
                return true;
            }
            color[v]=0;
        }
    }
    return false;

}

int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>arr[i][j];
        }
    }
    // int m;
    // cin>>m;
    int color[n];
    for(int i=0;i<n;i++)
    color[i]=0;
    int cnt=0;
    set<int> s;
    if(mcoloring(n,color,0))
    {
        
    for(int i=0;i<n;i++)
    {
        if(color[i]!=0)
        {
        s.insert(color[i]);
        }
        //cnt++;
    }
    
    cout<<s.size()<<endl;
    }
    // else
    // {
    //     cout<<"Not Possible"<<endl;
    // }
    
    return 0;
}
/*
5
0 1 1 1 0
1 0 0 1 0
1 0 0 0 1
1 1 0 0 1
0 0 1 1 0

4
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0

5
0 0 1 0 1
0 0 1 1 1
1 1 0 1 0
0 1 1 0 1
1 1 0 1 0

6
0 1 1 1 0 1
1 0 0 1 1 1 
1 0 0 1 0 0
1 1 1 0 1 0
0 1 0 1 0 1
1 1 0 0 1 0
*/