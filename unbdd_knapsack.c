#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define MAX(a,b) (a>b)?a:b

int ubd_knapsack(int capacity,int no_ele,int *val_vec,int *wt_vec)
{
    int arr[capacity+1];
    memset(arr,0,sizeof(arr));
    for(int i=0;i<(capacity+1);i++)
    {
        for(int j=0;j<no_ele;j++)
        {
            if(wt_vec[j] <= i)//if i can accomadate wt_vec[j]
            {
                arr[i]=MAX(arr[i-1],arr[i-wt_vec[j]]+val_vec[j]);
            }
        }
    }
    return arr[capacity];
}


int main()
{
    int capacity,no_ele,*wt_vec,*val_vec,opt_val ,*selection_vec;
    printf("Enter sack capacity : " );
    scanf("%d",&capacity);
    printf("Enter no. of elements : " );
    scanf("%d",&no_ele);
    wt_vec=(int *)malloc(no_ele*sizeof(int));
    assert(wt_vec != NULL);
    val_vec=(int *)malloc(no_ele*sizeof(int));
    assert(val_vec!=NULL);
    selection_vec=(int *)malloc(no_ele*sizeof(int));
    assert(selection_vec!=NULL);
    printf("Enter wt_vec: " );
    for(int i=0;i<no_ele;i++)
        scanf("%d", &wt_vec[i]);
    printf("Enter val_vec: " );
    for(int i=0;i<no_ele;i++)
        scanf("%d", &val_vec[i]);
    opt_val=ubd_knapsack(capacity,no_ele,val_vec,wt_vec);
    printf("Optimal value of knapsack: %d\n", opt_val);
    /*printf("selection_vec : " );
    for(int i=0;i<no_ele;i++)
        printf("%d\t", selection_vec[i]);*/
    return 0;
}
