#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int memo[1000][1000];

int subset_sum(int arr[], int W, int n, int part1, int part2, int diff, int *min){
	
	if (W==0){
		return 0;
	}
	if (n==0){
		//printf("diff = %d, part1=%d, part2=%d", diff, part1, part2);
		if (diff<*min){
			*min=diff;
		}
		//printf(", min=%d\n", *min);
		return 1;
	}
	if(memo[n][W]!=-1){
		return memo[n][W];
	}
	if (arr[n-1]<=W){
		int soln1 = subset_sum(arr, W, n-1, part1, part2, diff, min);
		int diff1 = abs(part1 - arr[n-1] - part2 - arr[n-1]);

		int soln2 = subset_sum(arr, W-arr[n-1], n-1, part1 - arr[n-1], part2 + arr[n-1], diff1, min);
		if (soln1 == 0 || soln2 == 0){
			memo[n][W]=0;
		}
		return memo[n][W];
	}
	else{
		return subset_sum(arr, W, n-1, part1, part2, diff, min);
	}
}

int main(void){
	int arr[] = {1, 11, 5, 6};
	int i, j, n=4;
	int arr_sum = 23;

	// Initialize the array

	for(i=0;i<n+1;i++){
		for(j=0;j<arr_sum+1;j++){
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

	int *min = (int*) malloc(sizeof(int));
	*min = arr_sum;

	subset_sum(arr, arr_sum, n, arr_sum, 0, arr_sum, min);
	printf("Minimun subset difference possible is %d\n", *min);
	return 0;
}
