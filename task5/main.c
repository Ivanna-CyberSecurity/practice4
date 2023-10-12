#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    char hostname[256];
    struct utsname system_info;

    // Get the computer's hostname
    if (gethostname(hostname, sizeof(hostname)) == 0) {
        printf("Computer hostname: %s\n", hostname);
    } else {
        perror("Error getting computer hostname");
    }

    // Get information about the computer
    if (uname(&system_info) == 0) {
        printf("Computer information:\n");
        printf("System: %s\n", system_info.sysname);
        printf("Kernel release: %s\n", system_info.release);
        printf("Version: %s\n", system_info.version);
        printf("Machine model: %s\n", system_info.machine);
    } else {
        perror("Error getting computer information");
    }

    return 0;
}