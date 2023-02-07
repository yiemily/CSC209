#include <stdio.h>
#include <stdlib.h>

int main() {
	char phone[11];
	int user_input;
	int return_value = 0;

	scanf("%s", phone);

	while (scanf("%d", &user_input) != EOF) {
		if (user_input == -1) {
			printf("%s\n", phone);
		} else if (user_input >= 0 && user_input <=9) {
			printf("%c\n", phone[user_input]);
		} else {
			printf("ERROR\n");
			return_value = 1;
		}
	}
	return return_value;
}
