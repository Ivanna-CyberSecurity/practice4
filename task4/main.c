#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <unistd.h>

int main() {
    // Get information about the current user by UID
    uid_t user_id = getuid();
    struct passwd *user_info = getpwuid(user_id);

    if (user_info) {
        printf("Information about the current user by UID:\n");
        printf("Username: %s\n", user_info->pw_name);
        printf("Full name: %s\n", user_info->pw_gecos);
    } else {
        perror("Error retrieving user information by UID");
    }

    // Get information about the "root" user by username
    const char *root_username = "root";
    user_info = getpwnam(root_username);

    if (user_info) {
        printf("\nInformation about the 'root' user by username:\n");
        printf("Username: %s\n", user_info->pw_name);
        printf("Full name: %s\n", user_info->pw_gecos);
    } else {
        perror("Error retrieving user information for the 'root' user by username");
    }

    return 0;
}