#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_map
{
	int	x;
	int	y;
	int	value;
}				t_map;

int main()
{
	t_map *map;

	map = malloc(sizeof(t_map));
	printf("%p\n",map);
	free(map);
	printf("%p\n",map);
	// int r = 256;
	// int g = 256;
	// int b = 256;
	// int result;
	// int result1;

	// result = (r << 16 | g << 8 | b);
	// printf("%d\n", result);
	// result1 = r;
	// result1 = (result << 8) + g;
	// result1 = (result << 8) + b;
	// printf("%d\n", result1);
}
