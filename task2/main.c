#include <stdio.h>
#include <stdlib.h>

int main() {
    // Set the environment variable
    if (setenv("MY_VARIABLE_NAME", "my_variable_value", 1) != 0) {
        perror("Error setting environment variable");
        return 1;
    }

    // Check and print the environment variable value
    const char *var_name = "MY_VARIABLE_NAME";
    const char *var_value = getenv(var_name);
    
    if (var_value) {
        printf("%s=%s\n", var_name, var_value);
    } else {
        printf("Environment variable with name %s not found.\n", var_name);
    }

    return 0;
}