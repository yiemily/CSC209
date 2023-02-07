#include <stdio.h>
#include <stdlib.h>

/*
 * Write a a small C program called phone.c that uses scanf to read two values 
 * from standard input. The first is a 10 character string and the second is an 
 * integer. The program takes no command-line arguments.
 *
 * If the integer is -1, the program prints the full string to stdout. If the 
 * integer i is between 0 and 9, the program prints only the corresponding character 
 * (i.e., at index i) from the string to stdout. In both of these cases the program 
 * returns 0.
 *
 * If the integer is less than -1 or greater than 9, the program prints the message 
 * "ERROR" to stdout and returns 1.
 *
 * Sample usage:
 * $ gcc -Wall -std=gnu99 -g -o phone phone.c
 * $ ./phone
 * (User input) 4161234567 3
 * (Return) 1
 * $ ./phone
 * 4161234567 -1
 * 4161234567
 * $ ./phone
 * 4161234567 9 
 * 7
 * $ ./phone
 * 4161234567 10
 * ERROR
 */

int main() {
	char phone[11];
	int user_input;

	scanf("%s", phone);
	scanf("%d", &user_input);

	if (user_input == -1) {
		printf("%s\n", phone);
		return 0;

	} else if (user_input >= 0 && user_input <= 9) {
		printf("%c\n", phone[user_input]);
		return 0;	

	} else {
		printf("ERROR\n");
		return 1;

	}

}

