#include <stdio.h>

#include "task_manager.h"

int task_manager(event_s &event, const int command)
{
	int err = OK;
	static figure_s *figure = create_figure(); // (x, y, z, 1)
											   // освобождать.
											   //data , command, struct. (?)
											   // figures/figure.txt
	switch (command)
	{
	case MOVING:
		err = function_moving(figure, event.args);
		break;
	case ROTATE:
		err = function_rotate(figure, event.args);
		break;
	case SCALE:
		err = function_scale(figure, event.args);
		break;
	case LOAD_FILE:
		err = fill_figure(&figure, event.file_name);
		break;
	case UPDATE_PROJECTIONS:
		err = update_projections(event.projections, figure);
		break;
	case FILL_PROJECTIONS:
		err = fill_projections(event.projections, figure);
		break;
	case QUIT:
		destruct_all(figure, event.projections);
		break;
	default: // конец.
		err = ERROR_COMMAND;
		break;
	}

	return err;
}