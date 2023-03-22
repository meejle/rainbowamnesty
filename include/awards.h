#ifndef GUARD_AWARDS_H
#define GUARD_AWARDS_H

#include "main.h"

void Task_OpenAwardsFromStartMenu(u8 taskId);
void Awards_Init(MainCallback callback);

// Medal graphics
#define MEDAL_UNKNOWN 0
#define MEDAL_DUMMY 1

#endif // GUARD_AWARDS_H
