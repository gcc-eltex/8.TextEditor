#include "./headers/shared.h"

int main()
{
	char buf[128];
	int key = 1;
	win_init("testf.c");

	while((key = getch()) != 27)
	{
		switch(key)
		{
			case KEY_RIGHT:
				action_mvright();
			break;
			case KEY_LEFT:
				action_mvleft();
			break;
			case KEY_DOWN:
				action_mvdown();
			break;
			case KEY_UP:
				action_mvup();
			break;
			case KEY_BACKSPACE:
				action_backspace();
			break;
			default:
				action_insert((char)key);
			break;
		}
	}

	win_destroy();
	return 0;
}