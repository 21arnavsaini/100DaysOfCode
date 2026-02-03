#include <stdio.h>
#define MAX_SIZE 100

int main() {
    int n;
    scanf("%d", &n);
    int arr[MAX_SIZE];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int pos;
    scanf("%d", &pos);
    int x;
    scanf("%d", &x);
    for(int i = n; i >= pos; i--) {
        arr[i] = arr[i-1];
    }
    arr[pos-1] = x;
    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
