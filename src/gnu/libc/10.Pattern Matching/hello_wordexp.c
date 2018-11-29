#include <wordexp.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int expand_and_execute(const char *program, const char **options)
{
	wordexp_t result;
	pid_t pid;
	int status, i;

	/* Expand the string for the program to run */
	switch (wordexp(program, &result, 0)) {
	case 0:		/* Successful */
		break;

	case WRDE_NOSPACE:
		/* If the error was WORD_NOSPACE, then perhaps part of
		   the result was allocated */
		wordfree(&result);

	default:		/* Some other error */
		return -1;
	}

	/* Expand the strings specified for the arguments */
	for (i = 0; options[i] != NULL; i++) {
		if (wordexp(options[i], &result, WRDE_APPEND)) {
			wordfree(&result);
			return -1;
		}
	}

	/* process */
	pid = fork();
	switch (pid) {
	case -1:
		status = -1;

	case 0:
		execv(result.we_wordv[0], result.we_wordv);
		exit(EXIT_FAILURE);

	default:
		if (waitpid(pid, &status, 0) != pid)
			status = -1;
	}

	wordfree(&result);
	return status;
}

// https://www.gnu.org/software/libc/manual/html_node/Calling-Wordexp.html#Calling-Wordexp
// https://www.gnu.org/software/libc/manual/html_node/Wordexp-Example.html#Wordexp-Example
