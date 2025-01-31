1#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void scanRadarIP(char *ipAddress) {
    char command[100];
    
    // Prepare the ping command for the system
    sprintf(command, "ping -c 4 %s", ipAddress);  // For Unix-based systems (Linux/Mac)

    // If you're on Windows, change it to:
    // sprintf(command, "ping -n 4 %s", ipAddress);

    printf("Pinging radar system at IP address: %s\n", ipAddress);
    
    // Execute the ping command using system()
    int result = system(command);
    
    // Check result and provide feedback
    if (result == 0) {
        printf("Radar system at %s is reachable.\n", ipAddress);
    } else {
        printf("Radar system at %s is unreachable.\n", ipAddress);
    }
}

int main() {
    char ipAddress[50];

    // Request IP address input from the user
    printf("Enter the IP address of the Radar system to monitor:");
    fgets(ipAddress, sizeof(ipAddress), stdin);
    
    // Remove newline character that fgets might leave in the string
    ipAddress[strcspn(ipAddress, "\n")] = '\0';

    // Scan the IP address
    scanRadarIP(ipAddress);

    return 0;
}
