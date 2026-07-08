#include<iostream>
using namespace std;
void insertionsort(int a[],int n)
{
for(int i=0;i<n;i++)
{
    int j=i;
    while(j>0 && a[j-1]>a[j])
    {
        int temp=a[j];
        a[j]=a[j-1];
        a[j-1]=temp;
        j--;
    }
}
}

    int main()
{
    int n;
    cout<<"enter the n"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter the array"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertionsort(a,n);
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
