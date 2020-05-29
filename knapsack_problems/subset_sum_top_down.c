#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int main(void){
	int arr[] = {2,3,7,8,10};
	int sum = 60, i, j, n=5;

	int t[n+1][sum+1];
	
	for(i=0; i<=n; i++){
		for(j=0; j<=sum; j++){
			if(j!=0){
				t[i][j]=1;
			}
			else{
				t[i][j] = 0;
			}
		}
	}

	
	for(i=0; i<=n; i++){
		for(j=0; j<=sum; j++){
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
	printf("Initialization done\n");
	int found = 1;

	for (i = 0; i <=n; i++){
		for(j=1; j <=sum; j++){
			if(arr[n-i]<=j){
				//printf("i-1=%d, sum-arr[n-i]=%d, i=%d, j=%d\n",i-1 ,sum-arr[n-i], i, j);
	 			int soln1 = t[i-1][j-arr[n-i]];
	 			int soln2 = t[i-1][j];
	 			//printf("soln1=%d, soln2=%d\n", soln1, soln2 );
				if (soln1 == 0 || soln2 == 0){
					//printf("1-----Found here (i,j) = %d,%d\n", i, j);
					t[i][j] = 0;
				}
				else{
					t[i][j] = 1;
				}
			}
			else{
				t[i][j] = t[i - 1][sum];
				if(t[i][j]==0){
					//printf("2-----Found here \n");
				}
			}
		}
	}

	printf("Result\n");
	for(i=0; i<=n; i++){
		for(j=0; j<=sum; j++){
			printf("%d ",t[i][j]);
		}
		printf("\n");
	}
	found = t[n][sum];
	if (found==0){
		printf("Subset possible\n");
	}
	else{
		printf("Subset not possible\n");
	}

	return 0;
}
