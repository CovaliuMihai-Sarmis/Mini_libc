// SPDX-License-Identifier: BSD-3-Clause

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */

	char *ret = destination;

	while(*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return ret;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */

	char *ret = destination;

	while(len > 0 && *source != '\0') {
		*destination = *source;
		destination++;
		source++;
		len--;
	}
	while(len > 0){
		*destination = '\0';
		destination++;
		len--;
	}
	return ret;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */

	char *ret = destination;
	while(*destination != '\0') {
		destination++;
	}
	while(*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';

	return ret;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */

	char *ret = destination;

	while(*destination != '\0') {
		destination++;
	}
	while(len > 0 && *source != '\0') {
		*destination = *source;
		destination++;
		source++;
		len--;
	}
	*destination = '\0';
	return ret;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */

	while(*str1 != '\0' && *str2 != '\0') {
		if(*str1 != *str2) {
			return (unsigned char)*str1 - (unsigned char)*str2;
		}
		str1++;
		str2++;
	}
	if(*str1 != *str2) {
		return (unsigned char)*str1 - (unsigned char)*str2;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */

	while (*str1 != '\0' && *str2 != '\0' && len > 0) {
		if (*str1 != *str2) {
			return (unsigned char)*str1 - (unsigned char)*str2;
		}
		str1++;
		str2++;
		len--;
	}
	if(len == 0) {
		return 0;
	}
	if(*str1 != *str2) {
		return (unsigned char)*str1 - (unsigned char)*str2;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */

	while(*str != '\0') {
		if(*str == (char)c) {
			return (char *)str;
		}
		str++;
	}
	if ((char)c == '\0') {
        return (char *)str;
    }

	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
		char *last_occurrence = NULL;
		while(*str != '\0') {
			if(*str == (char)c) {
				last_occurrence = (char *)str;
			}
			str++;
		}
		if ((char)c == '\0') {
			return (char *)str;
		}
		return last_occurrence;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */

	if (*needle == '\0') {
		return (char *)haystack;
	}

	while(*haystack != '\0') {
		const char *h = haystack;
		const char *n = needle;

		while(*h != '\0' && *n != '\0' && *h == *n) {
			h++;
			n++;
		}

		if(*n == '\0') {
			return (char *)haystack;
		}

		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */

	if (*needle == '\0') {
		return (char *)haystack;
	}

	char *last_occurrence = NULL;
	while(*haystack != '\0') {
		const char *h = haystack;
		const char *n = needle;

		while(*h != '\0' && *n != '\0' && *h == *n){
			h++;
			n++;
		}

		if(*n == '\0') {
			last_occurrence = (char*)haystack;
		}

		haystack++;
	}
	return last_occurrence;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */

	char* d = (char*)destination;
	const char* s = (const char*)source;

	for(int i = 0; i < (int)num; i++){
		*d = *s;
		d++;
		s++;
	}

	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */

	unsigned char* d = (unsigned char*)destination;
	const unsigned char* s = (const unsigned char*)source;

	if(d > s && d < s + num){
		for(int i = (int)num; i > 0 ; i--){
			d[i-1] = s[i-1];
		}
	}else{
		for(int i = 0; i < (int)num; i++){
			d[i] = s[i];
		}
	}

	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	const unsigned char* pt1 = (const unsigned char*)ptr1;
	const unsigned char* pt2 = (const unsigned char*)ptr2;

	while(num > 0){
		if(*pt1 - *pt2 != 0){
			return *pt1 - *pt2;
		}
		pt1++;
		pt2++;
		num--;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	unsigned char* s = (unsigned char*)source;
	for(int i = 0; i < (int)num; i++){
		s[i] = (unsigned char)value;
	}
	return source;
}
