#include <stdio.h>


void func3(int p3)
{
    int local3 = 30;

    printf("\n--- Inside func3 ---\n");
    printf("Address of parameter p3 : %p\n", (void*)&p3);
    printf("Address of local3       : %p\n", (void*)&local3);
    printf("Return address          : %p\n", __builtin_return_address(0));
}


void func2(int p2)
{
    int local2 = 20;

    printf("\n--- Inside func2 ---\n");
    printf("Address of parameter p2 : %p\n", (void*)&p2);
    printf("Address of local2       : %p\n", (void*)&local2);
    printf("Return address          : %p\n", __builtin_return_address(0));

    func3(300);
}


void func1(int p1)
{
    int local1 = 10;

    printf("\n--- Inside func1 ---\n");
    printf("Address of parameter p1 : %p\n", (void*)&p1);
    printf("Address of local1       : %p\n", (void*)&local1);
    printf("Return address          : %p\n", __builtin_return_address(0));

    func2(200);
}

int main()
{
    int main_local = 5;

    printf("\n--- Inside main ---\n");
    printf("Address of main_local   : %p\n", (void*)&main_local);

    func1(100);

    return 0;
}
