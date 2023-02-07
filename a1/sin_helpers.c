// TODO: Implement populate_array
/*
 * Convert a 9 digit int to a 9 element int array.
 */
int populate_array(int sin, int *sin_array) {
    /* This function takes an integer and an integer array as its arguments, and
    returns an integer. This function's job is to populate the given integer array
    so that it contains the 9 digits of the given integer, in the same order as in
    the integer. The function must return 0 when it completes successfully, and 
    1 if the given integer is not 9 digits. */


    int digit_count = 0;
    int sin_copy = sin; // Make a copy of sin

    // Count the number of digits
    while (sin_copy != 0) {
        digit_count += 1;
        sin_copy = sin_copy / 10;
    }

    // Return 1 if the given integer is not 9 digits or begins with zero
    if (digit_count != 9 || sin < 100000000)  {
        return 1;
    }

    // Populate the given array
    for (int i = 8; i >= 0; i --) {
        sin_array[i] = sin % 10;
        sin = sin / 10;
    }
    return 0;
}


// TODO: Implement check_sin
/*
 * Return 0 if the given sin_array is a valid SIN, and 1 otherwise.
 */
int check_sin(int *sin_array) {

    int luhn_arr[9] = {1 ,2, 1, 2, 1, 2, 1, 2, 1}; 
    int product = 0;
    int sum = 0;

    for (int i = 0; i < 9; i++) {
        product = luhn_arr[i] * sin_array[i]; // Multiply every second digit by 2

        if (product >= 10) {
            product = 1 + (product % 10);
        } 
        sum += product;
    }

    if (sum % 10 == 0) {
        return 0;
    }
    return 1;
}
