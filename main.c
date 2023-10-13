 #include <stdio.h>
#include <string.h>


typedef struct {
    char username[50];
    char password[50];
} User;

void signUp(User *users, int *userCount) {
    if (*userCount == 10) {
        printf("Maximum user limit reached.\n");
        return;
    }

    User newUser;

    printf("Enter username: ");
    scanf("%s", newUser.username);

    printf("Enter password: ");
    scanf("%s", newUser.password);
    for (int i = 0; i < *userCount; i++) {
        if (strcmp(users[i].username, newUser.username) == 0) {
            printf("Username already exists. Please choose a different username.\n");

            return;
        }
    }

    users[*userCount] = newUser;
    (*userCount)++;

    printf("Registration successful.\n");

}

int login(User *users, int userCount) {
    char username[50];
    char password[50];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].username, username) == 0 && strcmp(users[i].password, password) == 0) {
            printf("Login successful.\n");

            return 1;
        }
    }

    printf("Invalid username or password.\n");

    return 0;
}

int main() {
    User users[10];
    int userCount = 0;

    int loggedIn = 0;

    int choice;
    do {
        printf("1- Sign up\n");
        printf("2- Login\n");
        printf("your choice: ");
        scanf("%d", &choice);


        switch (choice) {
            case 1:
                signUp(users, &userCount);
                break;
            case 2:
                loggedIn = login(users, userCount);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3 && !loggedIn);

    return 0;
}
