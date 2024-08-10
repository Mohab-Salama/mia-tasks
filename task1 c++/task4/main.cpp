#include <iostream>

using namespace std;

int main()
{
     int x=0,y,k,n,i,j;
   scanf("%d",&n);
  int a[n];
  for(i=0;i<n;i++)
  {  scanf("%d",&a[i]);
    }
   for(k=0;k<n-1;k++){
    for(j=0;j<n-1;j++)
  {  if(a[j]>a[j+1])
  {  x=a[j];
    a[j]=a[j+1];
    a[j+1]=x;
   }
    }
     }
     y=a[n-1];
     printf("%d",y);
}
