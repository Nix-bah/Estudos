#include <stdio.h>
#include <string.h>

void inverter(char s[], int ini, int fim) {
    if (ini >= fim)
        return;

    char aux = s[ini];
    s[ini] = s[fim];
    s[fim] = aux;

    inverter(s, ini + 1, fim - 1);
}

int main() {
    char s[100];

    printf("Digite uma palavra: ");
    scanf("%s", s);

    inverter(s, 0, strlen(s) - 1);

    printf("String invertida: %s\n", s);

    return 0;
}