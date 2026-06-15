#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>

#define PORT 8080

int main(void) {
    int sock = 0;
    struct sockaddr_in serv_addr;
    char buffer[1024] = {0};

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address/ Address not supported \n");
        return -1;
    }

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    printf("Connected to server. Type messages:\n");

    fd_set readfds;

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        FD_SET(sock, &readfds);

        int max_sd = sock > STDIN_FILENO ? sock : STDIN_FILENO;

        int activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);

        if (activity < 0) {
            printf("select error\n");
            break;
        }

        if (FD_ISSET(STDIN_FILENO, &readfds)) {
            if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
                send(sock, buffer, strlen(buffer), 0);
            }
        }

        if (FD_ISSET(sock, &readfds)) {
            int valread = read(sock, buffer, 1024);
            if (valread == 0) {
                printf("Server disconnected\n");
                break;
            }
            buffer[valread] = '\0';
            printf("Received: %s", buffer);
        }
    }

    close(sock);
    return 0;
}
