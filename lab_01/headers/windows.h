#ifndef _WINDOWS_H_

#define _WINDOWS_H_

#include "settings_windows.h"
#include "projections.h"
#include "clicked.h"
#include "paint.h"

#include "constants.h"
#include "struct.h"

void create_windows();

void signal_connect(GtkBuilder *builder, GtkWidget *window);

#endif