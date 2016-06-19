#include "Human.h"

int Human::MakeMove(Board aBoard)
{
	ALLEGRO_MOUSE_STATE state;
	al_get_mouse_state(&state);

	int lIndex = (state.y / 200 * 3) + (state.x / 200);

	if (aBoard.ValidMove(lIndex))
	{
		return lIndex;
	}
	else
	{
		return -1;
	}
}