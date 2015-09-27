#ifndef STRING_H
#define STRING_H
#include <stdlib.h>

/**
 * Calculates the length of a '\0' terminated string.
 * (the null character is not part of the length)
 * @param str Pointer to a '\0' terminated string.
 * @return Returns the length of the string. 
 */
size_t hw_strlen(const char *str);

/**
 * Determines if two strings are exactly equal to each other.
 * @param str1 Pointer to a '\0' terminated string.
 * @param str2 Pointer to a '\0' terminated string.
 * @return Returns 1 if equal, else 0.
 */
int hw_strcmp(const char *str1, const char *str2);

/**
 * Copies the string from src into dst.
 * @param dest Buffer to copy into.
 * @param src String to copy.
 * @param n Non-negative maximum about of bytes that can be copied from src.
 * @return Returns the dst pointer.
 */
char* hw_strncpy(char *dst, const char *src, size_t n);

/**
 * Finds the index of the character c in the string.
 * @param str A `\0` terminated string to search.
 * @param c Character to search for.
 * @return Returns the index of the first occurrence of the character 
 * if it exists, else -1.
 */
int hw_indexof(const char *str, char c);

/**
 * Reverse the contents of the string.
 * @param str Pointer to a `\0` terminated string.
 */
void hw_reversestr(char *str);

/**
 * Determines if two strings are equal to each other ignoring the case.
 * @param str1 Pointer to a `\0` terminated string.
 * @param str2 Pointer to a `\0` terminated string.
 * @return Returns 1 if the strings are equal, else 0.
 */
int hw_equalsIgnoreCase(const char *str1, const char *str2);

/**
 * Replace all characters in the pattern with another symbol.
 * @param str String to replace values that match the pattern.
 * @param pattern Array of characters to search and replace for.
 * @param replacement Character to replace with. 
 */
void hw_replaceall(char *str, const char *pattern, char replacement);

/**
 * Searches a string for '\t' characters and replaces them with spaces.
 * @param str A '\0' terminated string to search tabs for.
 * @param tabsize The number of spaces to replace a tab with.
 * @return A dynamically allocated '\0' terminated string
 * If the operation fails it should return NULL.
 */
char* hw_expandtabs(const char *str, size_t tabsize);

/**
 * Splits on a character c and stores the pointers to the each separate
 * token in the return value.
 * @param str String to split.
 * @param c Character to search the string and split on.
 * @return Returns a 2D array containing the split tokens. 
 * If the operation fails it should return NULL.
 */
char** hw_split(const char *str, char c);

/**
 * Find and replace all occurrences of find_str in str with replace_str. Note find_str 
 * and replace_str can be of varying lengths, and not necessarily the same length.
 * @param str A '\0' character terminated string
 * @param find_str A '\0' character terminated string to search for
 * @param replace_str A '\0' character terminated string to replace with
 * @param dst Place to store new string.
 * @return Returns the number of find_str's replaced
 */
int hw_findAndReplace(char **dst, const char *str, const char *find_str, const char* replace_str);

#endif
