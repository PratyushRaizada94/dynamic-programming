#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int arr[] = {1,3,7,8,10};
	int sum = 29, i, j, n=5;

	// Initialize the array

	int memo[n+1][sum+1];

	for(i=0;i<n+1;i++){
		for(j=0;j<sum+1;j++){
			if(i==0){
				memo[i][j] = 1;
			}
			if(j==0){
				memo[i][j] = 0;
			}
			if(i!=0 && j!=0){
				memo[i][j] = -1;
			}
		}
	}

	printf("Initialized\n");

	for(i=0;i<n+1;i++){
		for(j=0;j<sum+1;j++){
			printf("%d ", memo[i][j]);
		}
		printf("\n");
	}	

	for(i=1; i<n+1; i++){
		for(j=1; j<sum+1; j++){

			if(arr[n-i]<=sum){
				int soln1 = memo[i-1][j-arr[i-1]];
				int soln2 = memo[i-1][j];
				if (soln1==0 || soln2==0){
					memo[i][j] = 0;
				}
				else{
					memo[i][j] = 1;
				}
			}
			else{
				memo[i][j] = memo[i-1][j];
			}
		}
	}

	printf("Result\n");

	for(i=0;i<n+1;i++){
		for(j=0;j<sum+1;j++){
			printf("%d ", memo[i][j]);
		}
		printf("\n");
	}

	if (memo[n][sum]==0){
		printf("Subset possible!\n");
	}
	else{
		printf("Sum not possible!\n");
	}

	return 0;
}
