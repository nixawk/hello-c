/*
 * Lookup and name spaces
 *
 * When an identifier is encountered in a C program, a lookup is performed to
 * locate the declaration that introduced that identifier and that is currently
 * in scope. C allows more than one declaration for the same identifer to be in
 * scope simultaneously if these identifiers belong to different categories, 
 * called name spaces:
 *
 *     1) Label name space: all identifiers declared as labels.
 *     2) Tag names: all identifiers declared as name of structs, unions and
 *        enumerated types. Note that all three kinds of tags share one name
 *        space.
 *     3) Member names: all identifiers declared members of any one struct
 *        or union. Every struct and union introduces its own name space of
 *        this kind.
 *     4) All other identifiers, called ordinary identifiers to distinguish
 *        from (1-3)(function names, object names, typedef names, enumeration
 *        constants).
 *
 * At the point of lookup, the name space of an identifier is determined by
 * the manner in which it is used:
 *
 *     1) identifier appearing as the operand of goto statement is lookep up
 *        in the label name space.
 *     2) identifier that follows the keyword struct, union, or enum is looked
 *        up in the tag name space.
 *     3) identifier that follows the member access or member access through
 *        pointer operator is looked up in the name space of member of the
 *        type determined by the left-hand operand of the member access
 *        operator.
 *     4) all other identifier are looked up in the name space of ordinary
 *        identifier.
 * */

#include <stdio.h>

void namespace_label(void)
{
	int i = 0;

label:

	if (i < 2) {
		i++;
		goto label;
	} else {
		printf("lookup label namespace: %d\n", i);	/* i = 2 */
	}

}

void namespace_tag(void)
{
	enum { A, B, C };

	printf("lookup tag namespace: %d\n", C);
}

void namespace_member(void)
{
	struct {
		int x;
		int y;
	} member = { x: 5, y:6 };

	printf("lookup member names: %d\n", member.x);
}

int main(void)
{
	namespace_label();
	namespace_tag();
	namespace_member();
	return 0;
}

/* https://en.cppreference.com/w/c/language/name_space */
