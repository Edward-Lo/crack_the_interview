#include <stdio.h>
#include <string.h>

void reverse(char *p, size_t len)
{
	char *p1, *p2;
	if(!len)
		return;

	p1 = p;
	p2 = p + len - 1;

	while(p2 > p1) {
		char tmp = *p2;
		*p2-- = *p1;
		*p1++ = tmp;
	}
}

int main(void)
{
	char buf[10] = "Edward Lo";
	char *p1, *p2;
	reverse(buf, strlen(buf));
	printf("%s\n", buf);

	p1 = p2 = buf;
	while(p2 <= buf + strlen(buf)) {
		if(*p2 == ' ' || *p2 == '\0') {
			reverse(p1, p2 - p1);
			p1 = ++p2;
			continue;
		}
		p2++;
	}

	printf("%s\n", buf);
}
