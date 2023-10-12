#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Using: %s \n", argv[0]);
        return 1;
    }

    const char *var_name = argv[1];
    char *var_value = getenv(var_name);

    if (var_value) {
        printf("%s=%s\n", var_name, var_value);
    } else {
        printf("Environment variable with name %s not found.\n", var_name);
    }

    return 0;
}