#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

void get_password(char *password, size_t size) {
    struct termios oldt, newt;

    // Get termio information of standard input 
    // file descriptor 0 into oldt structure
    // aka Save the old terminal state
    if (tcgetattr(STDIN_FILENO, &oldt) != 0) {
        perror("tcgetattr");
        return;
    }

    newt = oldt;
    /*
    c_lflag
    ~ECHO = ~ is negation

    flag  000000011111110000000
    ECHO  000000001000000000000
    ~ECHO 111111110111111111111

    flag  000000011111110000000
&   ~ECHO 111111110111111111111
    res   000000010111110000000


    */
    newt.c_lflag &= ~ECHO; //Turn the ECHO bit off

    // Update the termio structure with the OFF'ed ECHO bit
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &newt) != 0) {
        perror("tcsetattr");
        return;
    }

    // Prompt and get the password
    printf("Enter password: ");
    if (fgets(password, size, stdin) == NULL) {
        printf("\nError reading password\n");
    }

    // Restore terminal !!!!
    // If not done, we will not see anything typed on the screen
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &oldt);
    printf("\n");

    /*
    Newline = \n (Line Feed)
    OR
      \r + \n
      carriage return

      I am typing something  <ENTER>

      CR + LF is replaced by LF
    */
    // Remove trailing newline if present
    size_t len = strlen(password);
    if (len > 0 && password[len - 1] == '\n') {
        password[len - 1] = '\0';
    }
}

int main() {
    char password[100];
    get_password(password, sizeof(password));

    printf("You entered: %s\n", password);

    return 0;
}

