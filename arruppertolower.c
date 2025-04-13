#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter an uppercase string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = str[i] + 32; // Convert to lowercase
        }
    }

    printf("The lowercase string is: %s", str);

    return 0;
}