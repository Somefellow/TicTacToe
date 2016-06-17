#include <stdio.h>
#include "SwinGame.h"
#include "../Board.h"

int main()
{
	open_graphics_window("You will not win!", 600, 600);
	Board lBoard;

    do
    {
        process_events();

		clear_screen(ColorWhite);
		lBoard.Draw();

		if (mouse_clicked(mouse_button(LEFT_BUTTON)))
		{

		}

		refresh_screen(60);
	} while (!window_close_requested());

    release_all_resources();
    return 0;
}
