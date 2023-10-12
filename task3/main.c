#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc == 2) {
        // Видалення змінної оточення
        const char *var_name = argv[1];
        if (unsetenv(var_name) != 0) {
            perror("Error deleting environment variable");
            return 1;
        }
    } else {
        // Видалення всіх змінних оточення
        if (clearenv() != 0) {
            perror("Failed to delete all environment variables");
            return 1;
        }
    }

    // Виведення поточного оточення
    extern char **environ;
    for (char **env = environ; env != NULL && *env != NULL; env++) {
        printf("%s\n", *env);
    }

    return 0;
}