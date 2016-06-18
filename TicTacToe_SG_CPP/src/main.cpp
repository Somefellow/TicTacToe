#include "../Human.h"
#include "../Computer.h"

int main()
{
	open_graphics_window("You will not win!", 600, 600);
	Board CurrentBoard;

	while (!window_close_requested() && !CurrentBoard.GameOver())
    {
        process_events();

		clear_screen(ColorWhite);
		CurrentBoard.Draw();

		if (mouse_clicked(mouse_button(LEFT_BUTTON)))
		{
			int lHumanMove = Human::MakeMove(CurrentBoard);

			if (lHumanMove != -1)
			{
				CurrentBoard.MakeMove(lHumanMove, 1);

				if (CurrentBoard.FullBoard()) break;

				int lComputerMove = Computer::MakeMove(CurrentBoard);

				if (lComputerMove != -1)
				{
					CurrentBoard.MakeMove(lComputerMove, -1);
				}
				else
				{
					throw std::exception("Computer couldn't make a move!");
				}
			}
		}

		refresh_screen(60);
	}

    release_all_resources();
    return 0;
}
