#ifndef CONSOLE_H
#define CONSOLE_H

void ScreenInit(void);
void ScreenFlipping(void);
void ScreenClear(void);
void ScreenRelease(void);
void ScreenPrint(int x, int y, char* string);

#endif // CONSOLE_H
