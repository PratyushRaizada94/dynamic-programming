#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int T = 0;
    scanf("%d",&T);
    int res[T];
    int i = 0, j=0, x;
    for(x=0;x<T;x++){
        
        int W,n;
        scanf("%d %d", &W, &n);
        int t[n+1][W+1];
        int wt[n];
        int vl[n];
        for(j=0;j<n;j++){
            scanf("%d %d", &wt[j], &vl[j]);
        }
        for (i = 0; i < n; i++){
            for(j=0; j < W; j++){
                if(i==0 || j==0){
                    t[i][j] = 0;
                }
            }
        }
        for (i = 1; i <=n; i++){
            for(j=1; j <=W; j++){
                if(j>=wt[n-i]){
                    t[i][j] = max(vl[n-i] + t[i-1][j - wt[n-i]], t[i-1][j]);
                }
                else{
                    t[i][j] = t[i-1][j];
                }
            }
        }
        // for (i = 0; i <= n; i++){
        //     for(j=0; j <= W; j++){        
        //             printf("%d ", t[i][j]);
        //     }
        //     printf("\n");
        // }
        res[x] = t[n][W];
    }
    for(i=0;i<T;i++){
        printf("%d\n", res[i]);
    }
    return 0;
}
