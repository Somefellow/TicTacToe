#include <stdio.h>

#include "Computer.h"
#include "Human.h"

int main(int argc, char** argv)
{
	ALLEGRO_DISPLAY* display = NULL;
	ALLEGRO_EVENT_QUEUE* event_queue = NULL;

	if (!al_init())
	{
		fprintf(stderr, "failed to initialise allegro!\n");
		return -1;
	}

	if (!al_init_primitives_addon())
	{
		fprintf(stderr, "failed to initialise primitives addon!\n");
		return -1;
	}

	display = al_create_display(WINDOW_SIZE, WINDOW_SIZE);
	al_set_window_title(display, "You will not win!");
	if (!display)
	{
		fprintf(stderr, "failed to create display!\n");
		return -1;
	}

	event_queue = al_create_event_queue();
	if (!event_queue)
	{
		fprintf(stderr, "failed to create event_queue!\n");
		al_destroy_display(display);
		return -1;
	}

	if (!al_install_mouse())
	{
		fprintf(stderr, "failed to install mouse!\n");
		al_destroy_display(display);
		return -1;
	}

	al_register_event_source(event_queue, al_get_display_event_source(display));

	Board CurrentBoard;

	while (!CurrentBoard.GameOver())
	{
		al_clear_to_color(COLOR_WHITE);
		CurrentBoard.Draw();
		al_flip_display();

		ALLEGRO_EVENT ret_event;

		ALLEGRO_TIMEOUT timeout;
		al_init_timeout(&timeout, 0.06);

		bool get_event = al_wait_for_event_until(event_queue, &ret_event, &timeout);

		if (get_event && ret_event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			printf("Close\n");
			break;
		}

		ALLEGRO_MOUSE_STATE state;
		al_get_mouse_state(&state);

		if (al_mouse_button_down(&state, 1))
		{
			printf("Move\n");

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
					fprintf(stderr, "failed to make move!\n");
					return -1;
				}
			}
		}
	}

	al_destroy_display(display);
	al_destroy_event_queue(event_queue);

	return 0;
}