#include <stdio.h>
 
#define MAX 100
 
int main()
{
    int arr[MAX],n;
    int i,j,temp;
     
    printf("Enter total number of elements: ");
    scanf("%d",&n);
     
    /*Read array*/
    printf("Enter array elements: \n");
    for(i=0; i<n; i++)
    {
        printf("Enter element %3d: ",i+1);
        scanf("%d",&arr[i]);
    }
     
    /*sort elements in Ascending Order*/
    for(i=0; i<n-1; i++)
    {
        //for(j=0; j<(n-i-1); j++)
        {
            if(arr[i]>arr[i+1])
            {
                temp=arr[i];
                arr[j]=arr[i+1];
                arr[i+1]=temp;
            }
        }
    }
 
    printf("Array elements in Ascending Order:\n");
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
     
    printf("\n");
         
    /*sort elements in Descending Order*/
    for(i=0; i<(n-1); i++)
    {
      //  for(i=0; i<(n-i-1); i++)
       // {
            if(arr[i]<arr[i+1])
            {
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
            }
    }
 
    printf("Array elements in Descending Order:\n");
    for(i=0; i<n; i++)
        printf("%d ",arr[i]);
     
    printf("\n");
     
    return 0;
}
