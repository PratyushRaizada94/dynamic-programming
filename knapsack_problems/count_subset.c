#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
	int arr[] = {2,3,5,6,8,10};
	int sum = 10, i, j, n=6;

	// Initialize the array

	int memo[n+1][sum+1];

	for(i=0;i<n+1;i++){
		for(j=0;j<sum+1;j++){
			if(i==0){
				memo[i][j] = 0;
			}
			if(j==0){
				memo[i][j] = 1;
			}
			if(i!=0 && j!=0){
				memo[i][j] = -1;
			}
		}
	}

	printf("Initialized\n");

	for(i=0;i<n+1;i++){
		for(j=0;j<sum+1;j++){
			printf("%d\t", memo[i][j]);
		}
		printf("\n");
	}	

	for(i=1; i<n+1; i++){
		for(j=1; j<sum+1; j++){

			if(arr[n-i]<=sum){
				int soln1 = memo[i-1][j-arr[i-1]];
				int soln2 = memo[i-1][j];
				memo[i][j] = soln1 + soln2;
			}
			else{
				memo[i][j] = memo[i-1][j];
			}
		}
	}

	printf("Result\n");

	int count = 0;

	for(i=0;i<n+1;i++){
		for(j=0;j<sum+1;j++){
			printf("%d\t", memo[i][j]);
		}
		printf("\n");
	}

	printf("Count of sequences with sum as '%d' is '%d'\n", sum, memo[n][sum]);

	return 0;
}
