#include <stdio.h>
#include <stdlib.h>


// TODO: Implement a helper named check_permissions that matches the prototype below.
int check_permissions(char *required_perm, char *file_perm) { 

    char dash = 45;
    char d = 100;

    if (file_perm[0] == d) {
        return 1;
    }

    for (int i = 0; i < 9; i++) {
        if (required_perm[i] != dash && required_perm[i] != file_perm[i + 1]) {
                return 1;
            }
    }
    return 0;
}


// $ count_large 1000 rwx------
// -rwx------  1 reid  staff    1734 Jun 22 14:52 prog
// permissions link_count owner group size data time filename

int main(int argc, char** argv) {
    if (!(argc == 2 || argc == 3)) {
        fprintf(stderr, "USAGE: count_large size [permissions]\n");
        return 1;
    }

    // TODO: Process command line arguments.

    // TODO: Call check_permissions as part of your solution to count the files to
    // compute and print the correct value.

    int min_size = strtol(argv[1], NULL, 10);
    char *required_perm_ptr;
    required_perm_ptr = argv[2];
    //printf("%s\n", required_perm);
    

    char file_perm[11];
    int size = 0;
    int count = 0;
    char d = 100;
 
    scanf("%*s %*d");

    while (scanf("%s %*d %*s %*s %d %*s %*d %*s %*s", file_perm, &size) != EOF) {
        //printf("%s\n", file_perm);
        //printf("%d\n", size);
        if (argc == 2) {
            if (size > min_size && file_perm[0] != d) {
                //printf("%d\n", size);
                //printf("%d\n", min_size);
                count += 1;
            }
        }

        if (argc == 3) {
            //printf("%s\n", file_perm);
            //printf("%s\n", required_perm);
            if (size > min_size &&
                check_permissions(required_perm_ptr, file_perm) == 0) {
                count += 1;
                //printf("%s\n", file_perm);
            }
            
        }
    } 

    printf("%d\n", count);

    return 0;
}
