#include <stdio.h>
#include <string.h>

void add(char *a, char *b, char *c)
{
	int i, j, m, n;
	long sum, carry;
	m = strlen(a) - 1;
	n = strlen(b) - 1;
	for(i = 0; i <= m; ++i)
		a[i] -= '0';
	for(i = 0; i <= n; ++i)
		b[i] -= '0';
	carry = 0;
	if(m > n){
		c[m + 2] = '\0';
		for(i = m, j = n; j >= 0; --i, --j){
			sum = a[i] + b[j] + carry;
			c[i + 1] = sum % 10 + '0';
			carry = sum / 10;
		}
		for(; i >= 0; --i){
			sum = a[i] + carry;
			c[i + 1] = sum % 10 + '0';
			carry = sum / 10;
		}
		if((c[0] = carry + '0') == '0')
			c[0] = ' ';
	} else {
		c[n + 2] = '\0';
		for(i = m, j = n; i >= 0; --i, --j){
			sum = a[i] + b[j] + carry;
			c[j + 1] = sum % 10 + '0';
			carry = sum / 10;
		}
		for(; j >= 0; --j){
			sum = b[j] + carry;
			c[j + 1] = sum % 10 + '0';
			carry = sum / 10;
		}
		if((c[0] = carry + '0') == '0')
			c[0] = ' ';
	}
}

int main()
{
	char a[100], b[100], c[101];
	puts("input one :");
	gets(a);
	puts("input another:");
	gets(b);
	add(a, b, c);
	puts("answer:");
	puts(c);
	return 0;
}
