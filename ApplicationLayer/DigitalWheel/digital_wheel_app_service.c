#include <stdlib.h>
#include "instantiate.h"
#include "digital_wheel_app_service.h"

struct twoWheels
{
    digital_wheel wheel1;
    digital_wheel wheel2;
};


twoWheels DigitalWheelAppService_two_wheels_construct(int a, int b)
{
	INSTANTIATE(twoWheels);
	self->wheel1 = digital_wheel_construct(a, b);
	self->wheel2 = digital_wheel_construct(a, b);
	return self;
}

void DigitalWheelAppService_two_wheels_collect(twoWheels self)
{
	digital_wheel_collect(self->wheel1);
	digital_wheel_collect(self->wheel2);
}

void DigitalWheelAppService_two_wheels_initialize(twoWheels self)
{
	digital_wheel_initialize(self->wheel1);
	digital_wheel_initialize(self->wheel2);
}

bool DigitalWheelAppService_two_wheels_move(twoWheels self, int wheel_speed1, int wheel_speed2)
{
	bool sortie = true;
	for(int i = 0; i < wheel_speed1; i++)
	{
		if(!digital_wheel_move_to_next_position(self->wheel1))
			sortie = false;
		
	}
	for(int i = 0; i < wheel_speed2; i++)
	{
		if(!digital_wheel_move_to_next_position(self->wheel2))
			sortie = false;
	}

	return sortie;
}

//static void display(digital_wheel wheel, void (*f)(int));

void DigitalWheelAppService_two_wheels_display(twoWheels self, void (*f)(int))
{
	f(digital_wheel_get_current_position(self->wheel1));
	f(digital_wheel_get_current_position(self->wheel2));
}
