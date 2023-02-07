#include <stdio.h>
#include <stdlib.h>

int populate_array(int, int *);
int check_sin(int *);


int main(int argc, char **argv) {
    // TODO: Verify that command line arguments are valid.
    if (argc != 2) {
        return 2;
    }

    // TODO: Parse arguments and then call the two helpers in sin_helpers.c
    // to verify the SIN given as a command line argument.
    int sin_num = strtol(argv[1], NULL, 10);
    int sin_arr[9];

    populate_array(sin_num, sin_arr);

    if (check_sin(sin_arr) == 1) {
        printf("Invalid SIN\n");
        return 1;
    } 

    printf("Valid SIN\n");
    return 0;
}
