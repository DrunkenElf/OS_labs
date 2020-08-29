#include <stdio.h>
#include <string.h>

int main(void) {
	char s[99];

	if (fgets(s, 99, stdin) != NULL) {
		for (int i = strlen(s) - 1; i >=0 ; --i) 
			printf("%c",s[i]);
		return 0;
	}

	return 1; 	
}