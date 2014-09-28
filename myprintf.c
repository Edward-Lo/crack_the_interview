#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void convert(int num, int base)
{
	static char *buf[50];
	size_t len = 1;
	int i = num;
	char *p;
	while(i /= base)
		len++;
	buf[len] = '\0';

	//printf("len = %d\n", len);
	i = num;
	p = (char *)&buf[len-1];
	do
	{
		*p-- = "0123456789abcdef"[num % base];
	}while(num /= base);

	for(p = (char *)buf; *p; p++)
		putchar(*p);
}

void myprintf(char *fmt, ...)
{
	va_list arg;
	char *p, *s;
	int i;
	unsigned int u;

	va_start(arg, fmt);
	//printf("fmt = %s, len = %d\n", fmt, strlen(fmt));

	for(p = fmt; *p != '\0'; p++) {
		if(*p != '%') {
			putchar(*p);
			continue;
		}

		p++;

		switch(*p) {
			case 'c':
				i = va_arg(arg, int);
				putchar(i);
				break;
			case 's':
				s = va_arg(arg, char *);
				//puts(s);
				while(*s != '\0') {
					putchar(*s);
					s++;
				}
				break;
			case 'd':
			case 'u':
				i = va_arg(arg, int);
				if(i < 0)
					putchar('-');
				convert(i, 10);
				break;
			case 'o':
				i = va_arg(arg, int);
				if(i < 0)
					putchar('-');
				convert(i, 8);
				break;
			case 'x':
				i = va_arg(arg, int);
				if(i < 0)
					putchar('-');
				convert(i, 16);
				break;
			case '%':
				putchar('%');
				break;
		}
	}

	va_end(arg);
}

int main(void)
{
	myprintf("Test from %s, he is no.%d\n", "Edward Lo", 1);
	return 0;
}
