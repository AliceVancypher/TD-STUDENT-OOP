#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "digital_wheel_app_service.h"
static void f(int v)
{
    printf("[%d]", v);
}

static void display(twoWheels two_wheels)
{
    printf("<");
    DigitalWheelAppService_two_wheels_display(two_wheels, f);
    printf(">\n");
}
int main(int argc, char **argv)
{
    int start = 0, end = 9, speed1 = 1, speed2 = 2;
    bool sortie = true;
    printf("Entrez le debut et la fin des roues : ");
    scanf("%d", &start);
    scanf("%d", &end);
    printf("Entrez la vitesse de la roue 1 et la vitesse de la roue 2 : ");
    scanf("%d", &speed1);
    scanf("%d", &speed2);

    twoWheels two_wheels = DigitalWheelAppService_two_wheels_construct(start, end);
    DigitalWheelAppService_two_wheels_initialize(two_wheels);
    display(two_wheels);

    while (sortie)
    {
        sortie = DigitalWheelAppService_two_wheels_move(two_wheels, speed1, speed2);
        display(two_wheels);
    }
    
    
}