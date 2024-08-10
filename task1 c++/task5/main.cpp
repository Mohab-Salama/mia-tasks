#include <iostream>

using namespace std;

int main()
{ int r=0,c=0,v=0,l=0,i=0,j=0;
 scanf("%d %d",&r,&c);
 int a[r][c];
 int vill[r][c];
for(i=0;i<r;i++)
{ for(j=0;j<c;j++)
{ scanf("%d",&a[i][j]);

}

}
for(i=0;i<r;i++)
{ for(j=0;j<c;j++)
{ scanf("%d",&vill[i][j]);

   }
      }
 for(i=0;i<r;i++)
 {  for(j=0;j<c;j++)
   {  if(a[i][j]>vill[i][j])
    { l++;
        }
    else if(a[i][j]<vill[i][j])
    { v++;
        }
    else
    {  v+=0;
       l+=0;
        }

 }
     }
   if(l>v)
   {
       printf("Justice League");
   }
    else if(l<v)
    {
         printf("Villains");
    }
    else
    {
      printf("Tie");
    }

}

