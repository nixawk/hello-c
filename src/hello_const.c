/*
const: const can be used to declare constant variables. Constant variable are variables which
when initialized, can't change their value. Or in other words, the value assigned to them is
unmodifiable.
*/

int
main(void)
{
    const int i = 0;
    //  i = 1;  // error: assignment of read-only variable ‘i’
    return 0;
}