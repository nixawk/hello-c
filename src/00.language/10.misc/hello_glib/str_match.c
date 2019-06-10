#include <stdio.h>
#include <glib.h>

/**
 * @brief Matches a string against a pattern.
 *
 * @param[in] string  String to match.
 * @param[in] pattern Pattern to match against.
 * @param[in] icase   Case insensitivity enabled.
 *
 * @return 1 if it matches. 0 otherwise.
 */
int
str_match (const gchar *string, const gchar *pattern, int icase)
{
	gboolean res;
	GPatternSpec *patt = NULL;

	if (icase)
	{
		patt = g_pattern_spec_new (g_ascii_strdown (pattern, -1));
		res = g_pattern_match_string (patt, g_ascii_strdown (string, -1));
	}
	else
	{
		patt = g_pattern_spec_new (pattern);
		res = g_pattern_match_string (patt, string);
	}
	g_pattern_spec_free (patt);
	return res;
}

int
main(int argc, char *argv[])
{
	printf("%d\n", str_match("helloworld", "HELLOWORLD", 1)); /* 1 */
	printf("%d\n", str_match("helloworld", "HELLOWORLD", 0)); /* 0 */
	return 0;
}

/* https://github.com/greenbone/openvas-scanner/blob/9da86e8367ad8b548fdd51314b77309f5b3b6491/misc/strutils.c#L31 */