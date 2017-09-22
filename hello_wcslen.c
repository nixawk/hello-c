#include <stdio.h>
#include <wchar.h>

// size_t strlen (const char *s)
// size_t wcslen (const wchar_t *ws)

// size_t strnlen (const char *s, size_t maxlen)
// size_t wcsnlen (const wchar_t *ws, size_t maxlen)

void
wchar_array_length(void)
{
    wchar_t string[32] = L"hello, world";

    printf("wcslen(array) = %ld\n", wcslen(string));  // x64: 12 bytes
    printf("sizeof(array) = %ld\n", sizeof(string));  // x64: 128 bytes
}


void
wchat_pointer_length(void)
{
    wchar_t string[32] = L"hello, world";
    wchar_t *ptr = string;

    printf("wcslen(ptr) = %ld\n", wcslen(ptr));    // x64: 12 bytes
    printf("sizeof(ptr) = %ld\n", sizeof(ptr));    // x64: 8 bytes
    printf("sizeof(*ptr) = %ld\n", sizeof(*ptr));  // x64: 4 bytes * *
}


int
main(void)
{
    wchar_array_length();
    wchat_pointer_length();
}

// https://www.gnu.org/software/libc/manual/html_node/String-Length.html#String-Length
// https://stackoverflow.com/questions/11287213/what-is-a-wide-character-string-in-c-language