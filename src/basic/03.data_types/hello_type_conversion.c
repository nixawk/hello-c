#include <stdio.h>

// Conversions can occur explicitly as the result of a cast or implicitly
// as required by an operation. Although conversions are generally
// required for the correct execution of a program, they can also lead
// to lost or misinterpreted data. Conversion of an operand value to a
// compatible type causes no change to the value or the representation.

// The C integer conversion rules define how C compilers handle conversions.
// These rules include integer promotions, integer conversion rank, and the
// usual arithmetic conversions. The intent of the rules is to ensure that
// the conversions result in the same numerical values and that these values
// minimize surprises in the rest of the computation. Prestandard C usually
// preferred to preserve signedness of the type.

// Integer Conversion Rank

// Every integer type has an integer conversion rank that determines how
// conversions are performed. The ranking is based on the concept that each
// integer type contains at least as many bits as the types ranked below it.
// The following rules for determining integer conversion rank are defined
// in the C Standard, subclause 6.3.1.1 [ISO/IEC 9899:2011]

// Usual Arithmetic Conversions

// The usual arithmetic conversions are rules that provide a mechanism
// to yield a common type when both operands of a binary operator are
// balanced to a common type or the second and third operands of the
// conditional operator (? :) are balanced to a common type.
// Conversions involve two operands of different types, and one or both
// operands may be converted. Many operators that accept arithmetic operands
// perform conversions using the usual arithmetic conversions. After
// integer promotions are performs on both operands, the following
// rules are applied to the promoted operands:

// 1. If both operands have the same type, no further conversion is needed.
// 2. If both operands are of the same integer type (signed or unsigned),
//    the operands with the type of lesser integer conversion rank is
//    converted to the type of the operand with greater rank.
// 3. If the operand that has unsigned integer type has rank greater than
//    or equal to the rank of the type of the other operand, the operand
//    with signed integer type is converted to the type of the operand
//    with unsigned integer type.
// 4. If the type of the operand with signed integer type can represent
//    all of the values of the type of the operand with unsigned integer
//    type, the operand with unsigned integer type is converted to the
//    type of the operand with signed integer type.
// 5. Otherwise, both operands are converted to the unsigned integer
//    type corresponding to the type of the operand with signed integer type.

// --------------------------------------------------------

// 1. Implicit Type Conversion (Automatic Type Conversion)

// - Done by the compiler on its own, without any external trigger from
//   the user.

// - Generally takes place when in an expression more than one data type
//   is present. In such condition type conversion (type promotion) takes
//   place to avoid lose of data.

// - All the data types of the variables are upgraded to the data type
//   of the variable with largest data type.

      // bool -> char -> short int -> int ->
      // unsigned int -> long -> unsigned ->
      // long long -> float -> double -> long double

// - It is possible for implicit conversions to lose information,
//   signs can be lost (when signed is implicity converted to unsigned)
//   , and overflow can occur (when long long is implicity converted to
//   float).

// 2. Explicit Type Conversion

// - This process is also called type casting and it is user defined.

      // (type) expression

void type_conversion(void)
{
	unsigned int x = -1;
	int y = ~0;

	// When comparing signed with unsigned, the compiler converts
	// the signed value to unsigned.

	(x == y) ? printf("Equal\n") : printf("Not equal\n");
}

int main(void)
{
	type_conversion();
	return 0;
}

/*

$ ./a.out
Equal

*/

/*

(gdb) disassemble 
Dump of assembler code for function type_conversion:
   0x000055555555464a <+0>: push   rbp
   0x000055555555464b <+1>: mov    rbp,rsp
   0x000055555555464e <+4>: sub    rsp,0x10
   0x0000555555554652 <+8>: mov    DWORD PTR [rbp-0x8],0xffffffff
   0x0000555555554659 <+15>:    mov    DWORD PTR [rbp-0x4],0xffffffff
   0x0000555555554660 <+22>:    mov    eax,DWORD PTR [rbp-0x4]
=> 0x0000555555554663 <+25>:    cmp    DWORD PTR [rbp-0x8],eax
   0x0000555555554666 <+28>:    jne    0x55555555467b <type_conversion+49>
   0x0000555555554668 <+30>:    lea    rdi,[rip+0xb5]        # 0x555555554724
   0x000055555555466f <+37>:    mov    eax,0x0
   0x0000555555554674 <+42>:    call   0x555555554520 <printf@plt>
   0x0000555555554679 <+47>:    jmp    0x55555555468c <type_conversion+66>
   0x000055555555467b <+49>:    lea    rdi,[rip+0xa9]        # 0x55555555472b
   0x0000555555554682 <+56>:    mov    eax,0x0
   0x0000555555554687 <+61>:    call   0x555555554520 <printf@plt>
   0x000055555555468c <+66>:    nop
   0x000055555555468d <+67>:    leave  
   0x000055555555468e <+68>:    ret 

*/

// https://www.geeksforgeeks.org/c-language-2-gq/data-types-gq/
// https://www.geeksforgeeks.org/type-conversion-c/
// https://en.wikipedia.org/wiki/Type_conversion#Implicit_type_conversion
// https://wiki.sei.cmu.edu/confluence/display/c/INT02-C.+Understand+integer+conversion+rules
