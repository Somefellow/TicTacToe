#include "Human.h"

int Human::MakeMove(Board aBoard)
{
	int lIndex = ((int)mouse_position().y / 200 * 3) + ((int)mouse_position().x / 200);

	if (aBoard.ValidMove(lIndex))
	{
		return lIndex;
	}
	else
	{
		return -1;
	}
}
