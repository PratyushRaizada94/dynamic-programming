#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memo[1000][1000];

int subset_sum(int arr[], int W, int n){
	if (W==0){
		return 0;
	}
	if (n==0){
		return 1;
	}
	if(memo[n][W]!=-1){
		return memo[n][W];
	}
	if (arr[n-1]<=W){
		int soln1 = subset_sum(arr, W, n-1);
		int soln2 = subset_sum(arr, W-arr[n-1], n-1);
		if (soln1 == 0 || soln2 == 0){
			memo[n][W]=0;
		}
		return memo[n][W];
	}
	else{
		return subset_sum(arr, W, n-1);
	}
}

int main(void){
	int arr[] = {1,5,6,12};
	int i, j, n=4;

	int arr_sum = 0;

	for(i=0;i<n;i++){
		arr_sum+=arr[i];
	}

	if(arr_sum%2==1){
		printf("Equal sum partitions not possible\n");
		return 0;
	}

	int sum=arr_sum/2;
	// Initialize the array

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

	if (subset_sum(arr, sum, 5)==0){
		printf("Equal sum partitions possible!\n");
	}
	else{
		printf("Equal sum partitions not possible!\n");
	}

	return 0;
}
