#include <stdio.h>

char *strcpy_array(char *s, const char *t)
{
	/* strcpy using array version */
	int i = 0;
	while(t[i] != '\0') {
		s[i] = t[i];
		i++;
	}
	s[i] = '\0';
	return 0;
}

char *strcpy_pointers(char *s, const char *t)
{
	/* strcpy using pointer version */
	while(*t != '\0') {
		*s = *t;
		s++;
		t++;
	}
	*s = '\0';
	return 0;
}

char *strcat_array(char *s, const char *t)
{
	/* strcat using array version */
	int i = 0, j = 0;
	while(s[i] != '\0') {
		i++;
	}
	while(t[j] != '\0') {
		s[i] = t[j];
		i++;
		j++;
	}
	s[i] = '\0';
	return 0;
}

char *strcat_pointers(char *dest, const char *src)
{
	/* strcat using pointer version */
	char *temp = dest;
	//while(*dest != '\0') {
	while(*dest) {
		dest++;
	}
	/*dest++;
	while(*src != '\0') {
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';*/
	while((*dest++ = *src++) != '\0') {
		;
	}

	return dest;
}

int strcmp_array(const char *s, const char *t)
{
	/* strcmp using array notation */
	int i = -1;
	do {
		i++;

	}while((t[i] == s[i]) && (t[i] != '\0'));
	return (t[i] - s[i]);
}

int strcmp_pointers(const char *s, const char *t)
{
	while(*s == *t && *t != '\0') {
		s++;
		t++;
	}
	return *t - *s;
}

char *strchr_pointers(char *string)
{
	while(*string != 'z') {
		if(*string == '\0') {
			return NULL;
		}
		string++;
	}
	return string;
}

int main()
{
	char b[30], a[30] = "Embedded is great";
	printf("strings a and b:%s\t%s\n", a, b);
	//strcpy_array(b, a);
	printf("strings a and b:%s\t%s\n", a, b);
	strcpy_pointers(b, a);
	printf("strings a and b:%s\t%s\n", a, b);
	printf("\n");

	char c[50] = "Embedded is great", d[20] = "Also greatest";
	printf("strings c and d:%s\t%s\n", c, d);
	//strcat_array(c, d);
	printf("strings c and d:%s\t%s\n", c, d);
	strcat_pointers(c, d);
	printf("strings c and d:%s\t%s\n", c, d);
	printf("\n");

	char e[10] = "ball", f[10] = "bell";
	//printf("string comparison between %s and %s:%d\n", e, f, strcmp_array(e, f));
	printf("string comparison between %s and %s:%d\n", e, f, strcmp_pointers(e, f));

	char g[20] = "Embedded systems";
	printf("strchr demonstration and it will print when it found letter s:%s\n", strchr_pointers(g));
	

	return 0;
}
	
