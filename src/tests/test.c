#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void	*ft_memset(void *s, int c, size_t n);

int main()
{
	char **mat;
	int height = 3;
	char *s1 = "first";
	char *s2 = "second";
	char *s3 = "third";

	mat = malloc(sizeof(char *) * height);
	if (!mat)
		return 1;
//	for (int i = 0; i < height; i++)
//		printf("%p\n", mat[i]);
	ft_memset(mat, 0, 3 * sizeof(char *));
	for (int i = 0; i < height; i++)
		printf("%p\n", mat[i]);
	mat[0] = s1;
	mat[1] = s2;
	mat[2] = s3;
//	for (int i = 0; i < height; i++)
//		printf("%p -> \"%s\"\n", mat[i], mat[i]);
	for (int i = 0; i < height; i++)
		free(mat[i]);
	free(mat);
}
