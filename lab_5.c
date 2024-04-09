#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define M 10
#define N 10
void arr_in(int arr[M][N], int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("arr[%d][%d] = ", i+1, j+1);
            scanf_s("%d", &arr[i][j]);
            if (arr[i][j] * 10 % 10 != 0) {
                printf("\nERROR\n");
                exit(1);
            }
        }
    }
}
void arr_out(int arr[M][N], int m, int n) {
    printf("\nMatrix:\n");

    for (int i = 0; i < m; i++) {
        printf("\t|");
        for (int j = 0; j < n; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("|\n");
    }
    printf("\n");
}

int find_max_el(int arr[M][N], int m, int n) {
    int sum = 0;
    int min_sum = pow(10, 6);
    int mx = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sum += abs(arr[j][i]);
        }
        if (min_sum >= sum) {
            min_sum = sum;
            mx = i;
        }
        sum = 0;
    }
    int max_el = -1 * pow(10, 6);
    for (int i = 0; i < m; i++) {
        if (max_el < arr[i][mx]) {
            max_el = arr[i][mx];
        }
    }
    printf("Last min collum = %d\n", mx + 1);
    printf("Min sum collum = %d\n", min_sum);
    printf("Max element = %d\n", max_el);
}
void res(int a) {
    int m, n, arr[M][N];
    printf("Input m and n: ");
    scanf_s("%d %d", &m, &n);
    if (m > 1 && n > 1 && m<11 &&n<11) {
        arr_in(arr, m, n); 
        arr_out(arr, m, n); 
        find_max_el(arr, m, n); 
    }
    else {
        printf("\nERROR\n");
    }
}
void main() {
    res(1);
}
