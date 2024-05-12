void InsertSort(int a[],int n)
 {
     int i,j;
     for(i=1;i<n;i++)
     {
         j=i-1;
         a[i]=temp;
         while(a[j]>temp&&j>=0)
         {
             a[j+1]=a[j];
             j--;
         }
         a[j+1]=temp;
     }
 }
