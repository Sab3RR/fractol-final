#include "fractol.h"

int keypressed(int key, void *param)
{
	t_var *var;

	var = (t_var*)param;
	key == LEFT ? R += 30 / ZOOM : 0;
	key == RIGTH ? R -= 30 / ZOOM : 0;
	key == DOWN ? I -= 30 / ZOOM : 0;
	key == UP ? I += 30 / ZOOM : 0;
	key == F ? FREEZEJULIA = !FREEZEJULIA : 0;
	key == SCR ? COLOR += 12300 : 0;
	key == SCL ? COLOR -= 12300 : 0;
	if (key == RESETSPACE)
	{
		INIT4(ZOOM, 80, R, -2.5, I, -2.5, COLOR, 1);
	}
	key == ESC ? die(var) : 0;
	render(var);
	return (0);
}

int mousepressed(int button, int x, int y, void *param)
{
	t_var *var;

	var = (t_var *)param;
	if (button == WHEELUP || button == LEFTMOUSE)
	{
		ITERATIONS++;
		R = (x / ZOOM + R) - (x / (ZOOM * 1.2));
		I = (y / ZOOM + I) - (y / (ZOOM * 1.2));
		ZOOM *= 1.2;
		render(var);
	}
	else if (button == WHEELDOWN || button == RIGHTMOUSE)
	{
		ITERATIONS--;
		R = (x / ZOOM + R) - (x / (ZOOM / 1.2));
		I = (y / ZOOM + I) - (y / (ZOOM / 1.2));
		ZOOM /= 1.2;
		render(var);
	}
	return (0);
}
