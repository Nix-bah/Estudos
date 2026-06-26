#include <stdio.h>

int maior(int v[], int n) {
    if (n == 1)
        return v[0];

    int m = maior(v + 1, n - 1);

    if (v[0] > m)
        return v[0];
    else
        return m;
}

int main() {
    int v[5];

    printf("Digite 5 numeros:\n");
    for (int i = 0; i < 5; i++)
        scanf("%d", &v[i]);

    printf("Maior elemento: %d\n", maior(v, 5));

    return 0;
}