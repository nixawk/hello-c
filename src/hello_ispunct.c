#include <ctype.h>
#include <stdio.h>

/*

int ispunct(int c)

checks whether the passed character is a punctuation character.
A punctutation character is any graphic character (as in isgraph) that is not alphanumeric (as in isalnum)

This is a set of

 ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~


*/

int main(void)
{
    printf("%d\n", ispunct('a'));  // false
    printf("%d\n", ispunct('&'));  // true
    printf("%d\n", ispunct(' '));  // false
    printf("%d\n", ispunct('\t')); // false
    return 0;
}
