#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int t[1000][1000]; 

int knapsack(int wt[], int vl[], int W, int n){
    // Write base condition, in such a way that it is the response to the minimum input
    if( W == 0 || n == 0)
        return 0;
    if(t[W][n]!=-1)
        return t[W][n];
    if(W>=wt[n-1]){
        t[W][n] = max(vl[n-1] + knapsack(wt, vl, W - wt[n-1], n-1), knapsack(wt, vl, W, n-1));
        return t[W][n];
    }
    else{
        t[W][n] = knapsack(wt, vl, W, n-1);
        return t[W][n];
    }
}
int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T = 0;
    scanf("%d",&T);
    int res[T];
    int i = 0, j=0;
    for(i=0;i<T;i++){
        memset(t, -1, sizeof(t));
        int W,n;
        scanf("%d %d", &W, &n);
        int wt[n];
        int vl[n];
        for(j=0;j<n;j++){
            scanf("%d %d", &wt[j], &vl[j]);
        }
        res[i] = knapsack(wt, vl, W, n);
    }
    for(i=0;i<T;i++){
        printf("%d\n", res[i]);
    }
    // for(i=0;i<10;i++){
    //     for(j=0;j<10;j++){
    //         printf("%d ", t[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}
