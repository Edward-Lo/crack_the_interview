#include <stdio.h>
#include <limits.h>

int myatoi(const char *str)
{
	int ret = 0, minus = 0;

	if (!str)
		return LONG_MIN;

	if (*str == '-') {	// minus
		minus = 1;
		str++;
	}

	while (*str) {
		if (*str >= '0' && *str <= '9') {
			//printf("got char %c\n", *str);
			ret = ret * 10 + (*str - '0');
			str++;
		}
		else if (*str != '\n'){
			ret = LONG_MIN;
			break;
		}
	}

	if(minus)
		ret *= -1;

	return ret;
}

int main(int argc, char **argv)
{
	printf("We got %d\n", myatoi(argv[1]));
	return 0;
}
