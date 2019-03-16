#include "headers/header.h"

int main() {

    /* Main part */
    main_menu();

    /* Returning value */
    return 0;
}

/* Functions definitions */
void prt_ln(void) {

    /* Final output */
    printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n");
}

void no_cmd(void) {

    /* Final output */
    printf("| menu: no such command!                                     |\n");
}

int quit_m(void) {

    /* Initializing variables */
    int junk;

    /* Main part */
    if ((junk = getchar()) == 'u') {
        if ((junk = getchar()) == 'i') {
            if ((junk = getchar()) == 't') {
                if ((junk = getchar()) == '\n') {
                    return -1;
                } else {
                    no_cmd();
                    while ((junk = getchar()) != '\n')
                        ;
                    return 0;
                }
            } else {
                no_cmd();
                if (junk == '\n') {
                    return 0;
                } else {
                    while ((junk = getchar()) != '\n');
                    return 0;
                }
            }
        } else {
            no_cmd();
            if (junk == '\n') {
                return 0;
            } else {
                while ((junk = getchar()) != '\n');
                return 0;
            }
        }
    } else {
        no_cmd();
        if (junk == '\n') {
            return 0;
        } else {
            while ((junk = getchar()) != '\n');
            return 0;
        }
    }
}

int menu2(int *n) {

    /* Initializing variables */
    int func, junk;

    /* I/O flow */
    while (1) {
        printf(" ––––––––––––––––––––––––––––––––––––––––––––––––––––––––––––\n"
"|                                                            |\n"
"|                      >> ProCalc <<                         |\n"
"|                                                            |\n"
"|  >> Chose the type of a calculator:                        |\n"
"|                                                            |\n"
"|       1) Keyboard-typed goods                              |\n"
"|       2) Pseudo-randomly generated goods                   |\n"
"|       3) Containment of a text file                        |\n"
"|                                                            |\n"
"|       >> Type \"quit\" to terminate this program <<          |\n"
"|                                                            |\n");
        printf("| Answer: ");
        func = getchar();
        prt_ln();
        if (isdigit(func) && func >= '1' && func <= '3') {
            func -= '0';
            if ((junk = getchar()) != '\n') {
                while ((junk = getchar()) != '\n')
                    ;
                no_cmd();
                continue;
            }
            menu2_5(n);
            return func;
        } else if (func == 'q') {
            if (quit_m()) {
                return -1;
            } else {
                continue;
            }
        } else {
            no_cmd();
            while ((junk = getchar()) != '\n')
                ;
            continue;
        }
    }

}