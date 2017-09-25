#include <stdio.h>


int main(void)
{
    typedef struct person {
        int age;
        int id;
    } employee;

    employee jack;
    employee *jack_copy;

    jack.id = 1;
    jack.age = 25;

    jack_copy = &jack;
    jack_copy->age = 28;

    printf("employee id  : %d\n", jack_copy->id);
    printf("employee age : %d\n", jack_copy->age);

    return 0;
}
