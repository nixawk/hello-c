#include <time.h>
#include <stdio.h>

/*

char *asctime(const struct tm *timeptr);

returns a pointer to a string which represents the day and time of the structure struct timeptr.

*/

int main(void)
{
	struct tm t;

	t.tm_sec = 10;		/* seconds, range 0 to 59 */
	t.tm_min = 10;		/* minutes, range 0 to 59 */
	t.tm_hour = 6;		/* hours, range 0 to 23 */
	t.tm_mday = 25;		/* day of the month, range 1 to 31 */
	t.tm_mon = 2;		/* month, range 0 to 11 */
	t.tm_year = 89;		/* the number of years since 1900 */
	t.tm_wday = 6;		/* day of the week, range 0 to 6 */

	puts(asctime(&t));

	return 0;
}
