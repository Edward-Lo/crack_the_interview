#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *mymemmove(void *dest, void *src, size_t count)
{
	/* ----------------------------------------
	 *
	 * CASE 1 : From (SRC) < To (DEST)
	 * +--+---------------------+--+
	 * |  | 					|  |
	 * +--+---------------------+--+
	 * ^  ^
	 * |  |
	 * From To
	 */

	 char *p1 = (char *)dest, *p2 = (char *)src;
	 
	 // detect overlap
	 p2 += count - 1;
	 while(p2 != src && p2-- != dest);

	 if(p2 != src) {	// overlap
	 	p2 = src;
	 	p1 += count;
		p2 += count;

		while(count--) {
			*--p1 = *--p2;
		}
	 }
	 else {
		while(count--) {
			*p1++ = *p2++;
		}
	 }
}

int main(void)
{
	char *p1, *p2;
	p1 = (char *)malloc(20);
	memset(p1, '\0', 20);
	sprintf(p1, "%s", "ABCDEF");

	p2 = p1 + 2;

	printf("===before===\n");
	printf("p1 = %s\n", p1);
	printf("p2 = %s\n", p2);

	mymemmove(p2, p1, 6);
	printf("===after===\n");
	printf("p1 = %s\n", p1);
	printf("p2 = %s\n", p2);

	p2 = p1 + 4;
	mymemmove(p1, p2, 4);
	printf("===after===\n");
	printf("p1 = %s\n", p1);
	printf("p2 = %s\n", p2);

	return 0;
}
