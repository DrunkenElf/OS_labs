#include <stdio.h>

int main(int argc, char *argv[]) {
	int n;
	if (argv != NULL || sscanf(argv[1], "%d", &n) != 1 || argv != 0) {
		printf("use n as command param");
		return 1;
	}

	for (int i = 1; i <=n; ++i) {
		int spc, str;
		spc = n - i;
		str = 2*i - 1;

		while (spc > 0){
			putchar(' ');
			--spc;
		}
		while (str > 0){
			putchar('*');
			--str;
		}
		putchar('\n');
	}

	return 0;
}
