#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#define MAX(a,b) (a>b)?a:b


int knapsack(int capacity,int no_ele,int *wt_vec,
                            int *val_vec,int *selection_vec)
{
    int kc=(capacity + 1);
    int ke=(no_ele + 1);
    int arr[ke][kc];
    // calculation of array
    for(int i=0;i<=ke;i++)
    {
        for(int j=0;j<=kc;j++)
        {
            if(i==0 || j==0)
            {
                arr[i][j]=0;
            }
            else
            {
                if((j - wt_vec[i-1] >= 0))
                {
                    arr[i][j]=MAX(val_vec[i-1]+arr[i-1][j-wt_vec[i-1]],
                                    arr[i-1][j]);
                }
                else
                {
                    arr[i][j]=arr[i-1][j];
                }
            }
        }
    }
    printf("\n\n" );
    printf("Tabulation:\n" );
	for(int i=0;i<ke;i++)
	{
		for(int j=0;j<kc;j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n" );
	}
    // calculation of selection_vec
    int num1 = arr[no_ele][capacity];
    int num2 = capacity;
    for(int i=no_ele; i>0 && num1>0;i--)
    {
        if(num1==arr[i-1][num2])
        {
            selection_vec[i-1]=0;
            continue;
        }
        else
        {
            selection_vec[i-1]=1;
            num1=num1-val_vec[i-1];
            num2=num2-wt_vec[i-1];
        }
    }
    return arr[no_ele][capacity];
}

int main()
{
    int capacity,no_ele,*wt_vec,*val_vec,opt_val,*selection_vec;
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
    opt_val=knapsack(capacity,no_ele,wt_vec,val_vec,selection_vec);
    printf("Optimal value of knapsack: %d\n", opt_val);
    printf("selection_vec : " );
    for(int i=0;i<no_ele;i++)
        printf("%d\t", selection_vec[i]);
    return 0;
}
