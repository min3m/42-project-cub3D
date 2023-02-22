#include <stdio.h>

int main()
{
	int r = 256;
	int g = 256;
	int b = 256;
	int result;
	int result1;

	result = (r << 16 | g << 8 | b);
	printf("%d\n", result);
	result1 = r;
	result1 = (result << 8) + g;
	result1 = (result << 8) + b;
	printf("%d\n", result1);
}
