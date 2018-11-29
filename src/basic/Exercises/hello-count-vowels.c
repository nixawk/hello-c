// Count Vowels

// Enter a string and the program counts the number of vowels in the text.
// For added complexity have it report a sum of each vowel fount

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct vowel_count {
	int a;
	int e;
	int i;
	int o;
	int u;
} vowel_count_t;

bool is_vowel(char ch)
{
	switch (ch) {
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
		return true;
	default:
		return false;
	}
}

vowel_count_t count_vowel(char *str)
{
	int i, c;
	vowel_count_t vct;

	vct.a = 0;
	vct.e = 0;
	vct.i = 0;
	vct.o = 0;
	vct.u = 0;

	for (i = 0; i < strlen(str); i++) {
		c = tolower(str[i]);	// lower && upper
		if (c == 'a')
			vct.a++;
		else if (c == 'e')
			vct.e++;
		else if (c == 'i')
			vct.i++;
		else if (c == 'o')
			vct.o++;
		else if (c == 'u')
			vct.u++;
	}

	return vct;
}

void print_vowel_cnt(char *str)
{
	int i, c = 0;
	vowel_count_t vct;

	// method 1
	vct = count_vowel(str);

	printf("{'a': %d, 'e': %d, 'i': %d, 'o': %d, 'u': %d, 'cnt': %d}\n",
	       vct.a, vct.e, vct.i, vct.o, vct.u,
	       vct.a + vct.e + vct.i + vct.o + vct.u);

	// method 2
	// for (i = 0; i < strlen(str); i++)
	// {
	//     if (is_vowel(tolower(str[i])))
	//         c++;
	// }
	// printf("{'total': %d}\n", c);

}

int main(int argc, char *argv[])
{
	int i;

	if (argc < 2) {
		printf("Usage: %s <str1> <str2> ...\n", argv[0]);
		return -1;
	}

	for (i = 1; i < argc; i++) {
		printf("[%s]\n", argv[i]);
		print_vowel_cnt(argv[i]);
	}

	return 0;
}

/*

$ ./a.out this is a demo string
[this]
{'a': 0, 'e': 0, 'i': 1, 'o': 0, 'u': 0, 'cnt': 1}
[is]
{'a': 0, 'e': 0, 'i': 1, 'o': 0, 'u': 0, 'cnt': 1}
[a]
{'a': 1, 'e': 0, 'i': 0, 'o': 0, 'u': 0, 'cnt': 1}
[demo]
{'a': 0, 'e': 1, 'i': 0, 'o': 1, 'u': 0, 'cnt': 2}
[string]
{'a': 0, 'e': 0, 'i': 1, 'o': 0, 'u': 0, 'cnt': 1}

*/
