#include <stdio.h>

void hack_c(void)
{
    printf("hacking c\n");
}

void hack_cpp(void)
{
   printf("hacking cpp\n");
}

void hack_java(void)
{
    printf("hacking java\n");
}

void hack_python(void)
{
    printf("hacking python\n");
}

int main(void)
{
    int choice;

    printf("1 ) c\n");
    printf("2 ) c++\n");
    printf("3 ) java\n");
    printf("4 ) python\n");

    printf("Please make a choice: ");
    scanf("%d", &choice);
    switch (choice) {
      case 1:
        hack_c();
        break;
      case 2:
        hack_cpp();
        break;
      case 3:
        hack_java();
        break;
      case 4:
        hack_python();
        break;
      default:
        printf("Please choose a valid number.\n");
    }

    return 0;
}
