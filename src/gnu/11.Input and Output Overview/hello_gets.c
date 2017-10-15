#include <stdio.h>


// char * gets (char *s)

// The function gets reads characters from the stream stdin up to the next newline character, 
// and stores them in the string s. The newline character is discarded (note that this differs 
// from the behavior of fgets, which copies the newline character into the string). If gets 
// encounters a read error or end-of-file, it returns a null pointer; otherwise it returns s.

// Warning: The gets function is very dangerous because it provides no protection 
// against overflowing the string s. The GNU C Library includes it for compatibility only. 
// You should always use fgets or getline instead. To remind you of this, 
// the linker (if using GNU ld) will issue a warning whenever you use gets.

void
gets_usage(void)
{
    char *s = NULL;

    if (gets(s) != NULL)
    {
        printf("%s\n", s);
    }
}


int
main(void)
{
    gets_usage();  /* warning: this program uses gets(), which is unsafe. */
    return 0;
}


// https://www.gnu.org/software/libc/manual/html_node/Line-Input.html#Line-Input