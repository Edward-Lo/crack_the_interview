#include <stdio.h>

#define true	1
#define false	0

int wildcard(char *str, char *p)
{
	while(*str) {
		switch(*p) {
			case '*':
				while(*++p == '*');
				if(!*p)
					return true;
				while(*str) {
					printf("str = %c, p = %c\n", *str, *p);
					//if(wildcard(p, str++) == true) {
					if(wildcard(str++, p) == true) {
						return true;
					}
				}
				return false;
			default:
				if(*str != *p)
					return false;
				break;
		}
		str++;
		p++;
	}

	while(*p == '*')
		p++;
	return !*p;
}

int main(void)
{
	if(wildcard("hereheroherr", "*hero*"))
		printf("True\n");
	else
		printf("False\n");

	return 0;
}
