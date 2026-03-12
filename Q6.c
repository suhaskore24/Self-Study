#include <stdio.h>

typedef enum {RED,GREEN,YELLOW} state;

void traffic_fsm(state s)
{
    switch(s)
    {
        case RED:
            printf("RED\n");
            break;

        case GREEN:
            printf("GREEN\n");
            break;

        case YELLOW:
            printf("YELLOW\n");
            break;
    }
}

int main()
{
    state s = RED;

    traffic_fsm(s);
    s = GREEN;
    traffic_fsm(s);
    s = YELLOW;
    traffic_fsm(s);
}
