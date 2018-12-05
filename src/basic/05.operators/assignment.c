void assignment(void)
{
	int a, b;

	a = 1;
	b = 2;
	a += b;
	a -= b;
	a *= b;
	a /= b;
	a %= b;
	a &= b;
	a |= b;
	a ^= b;
	a <<= b;
	a >>= b;
}

int main(void)
{
	assignment();
	return 0;
}
/* https://en.cppreference.com/w/c/language/expressions#Constants_and_literals */
