// Check if Palindrome
// Checks if the string entered by the user is a palindrome. That is
// that is reads the same forwards as backwards like "racecar"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void swap(char *, char *);
void reverse(char *);
bool is_prefix(char *, char *);
bool is_palindrome(char *);

void
swap(char *s1, char *s2)
{
    *s1 ^= *s2;
    *s2 ^= *s1;
    *s1 ^= *s2;
}

void
reverse(char *s)
{
    int i, l;

    for (i = 0, l = strlen(s); i < l / 2; i++)
    {
        swap(s + i, s + l - 1 - i);
    }
}

bool
is_prefix(char *s, char *p)
{
    return strncmp(s, p, strlen(p)) == 0;  // p -> prefix
}

bool
is_palindrome(char *s)
{
    char *copystr = NULL;

    if (s == NULL)
    {
        perror("palindrome: nullptr");
        return false;
    }

    copystr = strdup(s);
    if (copystr == NULL)
    {
        perror("palindrome: strdup");
        return false;
    }

    reverse(copystr);
    return is_prefix(s, copystr);
}

int
main(void)
{
    is_palindrome("abc") ? printf("yes\n") : printf("no\n");
    is_palindrome("aba") ? printf("yes\n") : printf("no\n");

    return 0;
}
