#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *s = malloc(1);

	free(s);
	printf("First free ok\n");
	free(s);
	printf("Second free ok ?\n");
}
