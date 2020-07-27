#include <stdio.h>

int strncasecmp(const char *s1, const char *s2, size_t len)
{
	unsigned char c1, c2;
	if(!len) {
		return 0;
	}

	do {
		c1 = *s1++;
		c2 = *s2++;
		if(!c1 || !c2) {
			break;
		}
		if(c1 == c2) {
			continue;
		}
		c1 = tolower(c1);
		c2 = tolower(c2);
		if(c1 != c2) {
			break;
		}
	}while(--len);
	return (int)c1-(int)c2;
}

int strcasecmp(const char *s1, const char *s2)
{
	int c1, c2;
	do {
		c1 = tolower(*s1++);
		c2 = tolower(*s2++);
	}while(c1 == c2 && c1 != '\0');
	return c1-c2;
}

char *strcpy(char *dest, const char *src)
{
	char *tmp = dest;
	while((*dest++ = *src++) != '\0') {
		/* wait until copy the string */
	}
	return tmp;
}

char *strncpy(char *dest, const char *src, size_t count)
{
	char *tmp = dest;
	while(count) {
		if((*tmp = *src) != '\0') {
			src++;
		}
		tmp++;
		count--;
	}
	*tmp = '\0';
	return dest;
}

char *strcat(char *dest, const char *src)
{
	char *tmp = dest;
	while(*dest) {
		dest++;
	}
	while((*dest++ = *src++) != '\0') {
		/* wait till copied the concatenated string */
	}
	return tmp;
}

char *strncat(char *dest, const char *src, size_t count)
{
	char *tmp = dest;
	if(count) {
		while(*dest) {
			dest++;
		}
		while((*dest++ = *src++) != '\0') {
			if(--count == 0) {
				*dest = '\0';
				break;
			}
		}
	}
	return tmp;
}

int strcmp(const char *cs, const char *ct)
{
	unsigned char c1, c2;
	while(1) {
		c1 = *cs++;
		c2 = *ct++;
		if(c1 != c2)
			return c1<c2? -1 : 1;
		if(!c1)
			break;
	}
	return 0;
}

int strncmp(const char *cs, const char *ct)
{
	unsigned char c1, c2;
	while(count) {
		c1 = *cs++;
		c2 = *ct++;
		if(c1 != c2)
			return c1<c2? -1 : 1;
		if(!c1)
			break;
		count--;
	}
	return 0;
}

char *strchr(const char *s, int c)
{
	for(; *s != (char)c; ++s) {
		if(*s == '\0') {
			return NULL;
		}
	}
	return (char *s);
}

char *strchrnul(const char *s, int c)
{
	while(*s && *s != (char)c) {
		s++;
	}
	return (char *)s;
}

char *strrchr(const char *s, int c)
{
	const char *last = NULL;
	do {
		if(*s == (char)c) {
			last = s;
		}
	}while(*s++);
	return (char *)last;
}

char *skip_spaces(const char *str)
{
	while(isspace(*str)) {
		++str;
	}
	return (char *)str;
}

char *strim(char *s)
{
	size_t size;
	char *end;

	size = strlen(s);
	if(!size) {
		return s;
	}

	end = s + size - 1;
	while(end >= s && isspace(*end)) {
		end--;
	}
	*(end + 1) = '\0';

	return skip_spaces(s);
}

size_t strlen(const char *s)
{
	const char *sc;
	for(sc = s; *sc != '\0'; ++sc) {
		/* nothing */
		;
	}
	return sc - s;
}




