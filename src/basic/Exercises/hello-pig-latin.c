// Pig Latin
// Pig Latin is a game of alterations played on the English language game.
// To create the Pig Latin form of an English word the initial consonant
// sound is transposed to the end of the word and an at is affixed.
// (Ex: "banana" would yield "anana-bay").

// consonant sounds

    // bl br ch cl cr dr fl fr gl gr pl pr
    // sc sh sk sl sm sn sp st sw th tr tw
    // wh wr sch scr shr sph spl spr squ str thre

// vowel sounds

    // a e i o u

// Just work for lowercase characters

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool prefix(const char *pre, const char *str)
{
	return strncmp(pre, str, strlen(pre)) == 0;
}

char *get_consonant_cluster(char *str, char *consonant_clusters[], size_t cclen)
{
	char *consonant_cluster = NULL;
	size_t i;

	for (i = 0; i < cclen; i++) {
		if (prefix(consonant_clusters[i], str)) {
			consonant_cluster = consonant_clusters[i];
			break;
		}
	}

	return consonant_cluster;
}

char *get_consonant_cluster_2c(char *str)
{
	char *consonant_clusters[] = {
		"bl", "br", "ch", "cl", "cr", "dr", "fl", "fr",
		"gl", "gr", "pl", "pr", "sc", "sh", "sk", "sl",
		"sm", "sn", "sp", "st", "sw", "th", "tr", "tw",
		"wh", "wr",
	};
	size_t cclen =
	    sizeof(consonant_clusters) / sizeof(consonant_clusters[0]);

	return get_consonant_cluster(str,
				     consonant_clusters,
				     sizeof(consonant_clusters) /
				     sizeof(consonant_clusters[0])
	    );
}

char *get_consonant_cluster_3c(char *str)
{

	char *consonant_clusters[] = {
		"sch", "scr", "shr",
		"sph", "spl", "spr",
		"squ", "str", "thre"
	};

	return get_consonant_cluster(str,
				     consonant_clusters,
				     sizeof(consonant_clusters) /
				     sizeof(consonant_clusters[0])
	    );
}

bool is_vowel(char ch)
{
	switch (ch) {
	case 'a':
	case 'o':
	case 'e':
	case 'i':
	case 'u':
		return true;
	default:
		return false;
	}
}

void pig_latin(char *str)
{
	char *cc2ptr = NULL;
	char *cc3ptr = NULL;
	int cclen;

	if (is_vowel(*str)) {
		printf("%8s -> %s%s\n", str, str, "ay");
	} else {

		// string -> tring + s + ay
		{
			printf("%8s -> %s%c%s\n", str, str + 1, *str, "ay");
		}

		// string -> ring + st + ay
		cc2ptr = get_consonant_cluster_2c(str);
		if (cc2ptr != NULL)	// consonant clusters (multiple consonants that form one sound)
		{
			printf("%8s -> %s%s%s\n", str, str + strlen(cc2ptr),
			       cc2ptr, "ay");
		}
		// string -> ing + str + ay
		cc3ptr = get_consonant_cluster_3c(str);
		if (cc3ptr != NULL) {
			printf("%8s -> %s%s%s\n", str, str + strlen(cc3ptr),
			       cc3ptr, "ay");
		}
	}
}

int main(void)
{
	pig_latin("pig");
	pig_latin("latin");
	pig_latin("banana");
	pig_latin("happy");
	pig_latin("duck");
	pig_latin("me");

	pig_latin("eat");
	pig_latin("omelet");
	pig_latin("are");
	pig_latin("egg");
	pig_latin("explain");
	pig_latin("always");

	pig_latin("string");

	return 0;
}

/*

$ ./a.out
     pig -> igpay
   latin -> atinlay
  banana -> ananabay
   happy -> appyhay
    duck -> uckday
      me -> emay
     eat -> eatay
  omelet -> omeletay
     are -> areay
     egg -> eggay
 explain -> explainay
  always -> alwaysay
  string -> tringsay
  string -> ringstay
  string -> ingstray

*/

// https://en.wikipedia.org/wiki/Pig_Latin
// https://en.wikipedia.org/wiki/Vowel
// https://simple.wikipedia.org/wiki/Vowel
// https://en.wikipedia.org/wiki/Consonant_cluster
// http://www.enchantedlearning.com/consonantblends/
// https://stackoverflow.com/questions/4770985/how-to-check-if-a-string-starts-with-another-string-in-c
// https://stackoverflow.com/questions/1088622/how-do-i-create-an-array-of-strings-in-c
