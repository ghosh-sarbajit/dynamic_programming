#include <stdio.h>
#include <string.h>
#include <string.h>
#define MAX(a,b) (a>b)?a:b
int lcs(char *, char *, char *);

int main()
{
	int k=0;
	char str1[100],str2[100],str3[100];
	printf("Enter str1 : " );
	scanf("%[^\n]s",str1);
	getchar();
	//fgets(str1,99,stdin);
	printf("Enter str2 : " );
	scanf("%[^\n]s",str2);
	getchar();
	//fgets(str2,99,stdin);
	//puts(str1);
	//puts(str2);
	k=lcs(str1,str2,str3);
	printf("Length of largest common subseq is : %d\n", k);
	printf("Largest common sub-sequence is : %s\n", str3);
	return 0;
}

int lcs(char *str1,char *str2,char *str3)
{
	int m,n,length;
	m = strlen(str1) + 1;
	n = strlen(str2) + 1;
	//printf("%d %d\n", m,n);
	int arr[m][n];
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==0 || j==0)
				arr[i][j]=0;
			else if(str1[i-1]==str2[j-1])
				arr[i][j]= 1 + arr[i-1][j-1];
			else
				arr[i][j]= MAX(arr[i-1][j],arr[i][j-1]);
		}
	}
	/*printf("\n\n" );
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%5d", arr[i][j]);
		}
		printf("\n" );
	}*/
	length=arr[m-1][n-1] - 1;
	for(int i=m-1;i>=0;)
	{
		for(int j=n-1;j>=0;)
		{
			if(arr[i][j]==arr[i][j-1])
			{
				j--;

			}
			else if(arr[i][j]==arr[i-1][j])
			{
				i--;
			}
			else
			{
				i--;
				j--;
				str3[length]=str1[i];
				length--;
			}
		}
	}
	str3[arr[m-1][n-1]]='\0';
	return arr[m-1][n-1];
}
