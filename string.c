/*
name: Devon Maguire
sbuid: 109284550
*/
#include "hw8.h"
#include <stdio.h>

size_t hw_strlen (const char *str) {
	if (str != NULL) {
		size_t len = 0;
		while (*str != '\0') {
			len++;
			str++;
		}
		return len;
	}
	else
		return 0;
}

int hw_strcmp (const char *str1, const char *str2) {
	int run = 1;
	int answer = 0;
	if (str1 != NULL && str2 != NULL) {
		while (run) {
			if (*str1 == *str2 && *str1 != '\0' && *str2 !='\0') {
				str1++;
				str2++;
			}
			else if (*str2 == '\0' && *str1 == '\0') {
				answer = answer + 1;
				run = 0;
			}
			else if (*str1 == '\0' || *str2 != '\0')
				run = 0;
		}
	}
	return answer;
}

char* hw_strncpy (char *dst, const char *src, size_t n) {
	size_t dstlen = 0;
	if (src != NULL && n > 0) {
		while (dstlen < n) {
			if (*src == '\0') {
				*dst = '\0';
				dst++;
				dstlen++;
			}
			else {
				*dst = *src;
				src++;
				dst++;
				dstlen++;
			}
		}
	}
	return dst;
}

int hw_indexof (const char *str, char c) {
	int index;
	if (str != NULL) {
		for (index = 0; *str != '\0'; index++, str++) {
			if (*str == c)
				return index;
		}
	}
	return -1;
}

void hw_reversestr (char *str) {
	char *ptr1, *ptr2;
	ptr1 = str;
	ptr2 = str;
	char n;
	if (str != NULL) {
		while (*ptr1 != '\0') {
			ptr1++;
		}
		ptr1--;
		while (ptr1 > ptr2) {
			n = *ptr1;
			*ptr1 = *ptr2;
			*ptr2 = n;
			ptr1--;
			ptr2++;
		}
	}
}

int hw_equalsIgnoreCase (const char *str1, const char *str2) { // medium
	int run = 1;
	int answer = 0;
	if (str1 != NULL && str2 != NULL) {
		while (run) {
			if (*str1 == *str2 && *str1 != '\0' && *str1 !='\0') { // checks if chars are equal
				str1++;
				str2++;
			}
			else if (*str1 == '\0' && *str2 != '\0') {
				return 0;
			}
			else if (*str2 == '\0' && *str1 != '\0') {
				return 0;
			}
			else if (*str1 + 32 == *str2 || *str2 + 32 == *str1) { // tests if chars are equal ignoring case
				str1++;
				str2++;
			}
			else if (*str2 == '\0' && *str1 == '\0') {
				answer = answer + 1;
				run = 0;
			}
			else if (*str1 == '\0' || *str2 != '\0')
				run = 0;
		}
	}
	return answer;
	return 1;
}

void hw_replaceall (char *str, const char *pattern, char replacement) {
	int count = 0;
	if (str != NULL && pattern != NULL) {
		while (*str != '\0') {
			while (*pattern != '\0') {
				if (*str == *pattern)
					*str = replacement;
				pattern++;
				count++;
			}
			pattern -= count;
			count = 0;
			str++;
		}
	}
}

char* hw_expandtabs (const char *str, size_t tabsize) {
	char *ptr2, *ptr3;
	const char *ptr1;
	ptr1 = NULL;
	ptr2 = NULL;
	ptr3 = NULL;
	int n, t = 0;
	if (str != NULL) {
		ptr1 = str;
		t = 0;
		for (n = 0; n < hw_strlen(ptr1); n++, ptr1++) {
			if (*ptr1 == '\t')
				t++;
		}
		ptr1 = str;
		ptr2 = (char *) malloc(sizeof(char) * hw_strlen(str) + (int)tabsize * t);
		ptr3 = ptr2;
		for (n = 0; *ptr1 != '\0'; ptr1++) {
			if (*ptr1 == '\t') {
				t = 0;
				while (t < (int)tabsize) {
					*ptr3 = ' ';
					t++;
					ptr3++;
				}
			}
			else {
				*ptr3 = *ptr1;
				ptr3++;
			}
		}
		*ptr3 = '\0';
	}
	return ptr2;
}

char** hw_split (const char *str, char c) { // hard
	const char *ptr1;
	ptr1 = NULL;
	ptr1 = str;
	char **dst;
	dst = NULL;
	char *ptr2, *ptr3, *ptr4;
	ptr2 = NULL;
	int n = 1, row = 0, a = 0;
	char temp;
	if (str != NULL) {
		while (*ptr1 != '\0') {
			if (*ptr1 == c)
				row++;
			ptr1++;
		}
		if (hw_strlen(str) == row) {
			return dst;
		}
		dst = (char **) malloc(sizeof(char**) * row + 1);
		ptr2 = (char *) malloc(sizeof(char*) * hw_strlen(str) + 1);
		*dst = ptr2;
		ptr4 = ptr2;
		ptr3 = (char *) str;
		while (a < hw_strlen(str)) {
			if (*ptr3 == c) {
				*(dst+n) = (ptr4 + 1);
				temp = '\0';
				n++;
			}
			else {
				temp = *ptr3;
			}
			ptr3++;
			*ptr4 = temp;
			a++;
			ptr4++;
		}
		*(dst+row+1) = NULL;
	}
	return dst;
}

int hw_findAndReplace (char **dst, const char *str, const char *find_str, const char* replace_str) {
	const char *ptr, *findPtr;
	char *answer = NULL, *ptr2;
	ptr = str;
	findPtr = find_str;
	int m, o = 0, n = 0, c = 0;
	if (str != NULL && dst != NULL && find_str != NULL && replace_str != NULL) {
		while (*ptr != '\0') {
			if (*ptr == *find_str) {
				while (c < hw_strlen(findPtr)) {
					if (*ptr == *findPtr) {
						m = 1;
						ptr++;
						findPtr++;
						c++;
					}
					else {
						m = 0;
						ptr++;
						findPtr++;
						break;
					}
				}
				ptr -= o;
				if (m == 1) {
					o++;
				}
			}
			c = 0;
			findPtr = find_str;
			ptr++;
		}

		answer = (char *) malloc(sizeof(char) * hw_strlen(str) - (o * (hw_strlen(find_str) + hw_strlen(replace_str))));
		ptr = str;
		char *myPtr;
		char *replaceStr;
		ptr2 = answer;
		findPtr = find_str;
		n = 0;
		c = 0;
		while (*ptr != '\0') {
			replaceStr = (char*) replace_str;
			myPtr = (char*) ptr;
			if (*myPtr == *findPtr) {
				c = 0;
				findPtr = find_str;
				while (c < hw_strlen(findPtr)) {
					if (*myPtr == *findPtr) {
						m = 1;
						myPtr++;
						findPtr++;
						ptr++;
						c++;
					}
					else {
						m = 0;
						ptr++;
						break;
					}
				}
				replaceStr = (char*) replace_str;
				if (m == 1) {
					c = 0;
					while (c < hw_strlen(replace_str)) {
						*ptr2 = *replaceStr;
						ptr2++;
						replaceStr++;
						c++;
					}
					ptr += hw_strlen(find_str)-1;
				}
				else {
					*ptr2 = *ptr;
					ptr2++;
					ptr++;
				}
			}
			else {
				*ptr2 = *ptr;
				ptr2++;
				ptr++;
				replaceStr = (char*) replace_str;
			}
		}
	}
	*dst = answer;
	return o;
}