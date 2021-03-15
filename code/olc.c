#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <windows.h>

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef int32 bool32;

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef float real32;
typedef double real64;

#define TRUE 1
#define FALSE 0

enum PIXEL_TYPE
{
	PIXEL_SOLID = 0x2588,
	PIXEL_HIGH = 0x2580,
	PIXEL_LOW = 0x2584,
};

// Global Variables
int Running = FALSE;
short ScreenWidth = 160;
short ScreenHeight = 90;
int fontw = 8;
int fonth = 8;

void Draw(wchar_t *buffer, int x, int y, wchar_t c)
{
	if (x >= 0 && x < ScreenWidth && y >= 0 && y < ScreenHeight)
	{
		buffer[y * ScreenWidth + x] = c;
    }
}

void Clip(int x, int y)
{
	if (x < 0) x = 0;
	if (x >= ScreenWidth) x = ScreenWidth;
	if (y < 0) y = 0;
	if (y >= ScreenHeight) y = ScreenHeight;
}

void Fill(wchar_t *buffer, int x1, int y1, int x2, int y2, wchar_t c)
{
	Clip(x1, y1);
	Clip(x2, y2);
	for (int x = x1; x < x2; x++)
		for (int y = y1; y < y2; y++)
        Draw(buffer, x, y, c);
}

int main(int argc, char *argv)
{
	HANDLE  hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	DWORD dwBytesWritten = 0;
    
	// Change console visual size to a minimum so ScreenBuffer can shrink
	// below the actual visual size
	SMALL_RECT WindowSize = { 0, 0, 1, 1 };
	SetConsoleWindowInfo(hConsole, TRUE, &WindowSize);
    
	// Set the size of the screen buffer
	COORD coordInit = { ScreenWidth, ScreenHeight };
	SetConsoleScreenBufferSize(hConsole, coordInit);
    
	// Assign screen buffer to the console
	SetConsoleActiveScreenBuffer(hConsole);
	
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = fontw;
	cfi.dwFontSize.Y = fonth;
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
    
	//wcscpy_s(cfi.FaceName, L"Lucida Console"); // TODO: Can't get this to work!
	wcscpy(cfi.FaceName, L"Lucida Console");
    
	f (!SetCurrentConsoleFontEx(hConsole, FALSE, &cfi))
	{
        OutputDebugStringA("Failed to set console font");
	}
    
	// Get screen buffer info and check the maximum allowed window size.
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	if (!GetConsoleScreenBufferInfo(hConsole, &csbi))
	{
		OutputDebugStringA("No Screenbuffer loaded");
	}
	if (ScreenHeight > csbi.dwMaximumWindowSize.Y)
	{
		OutputDebugStringA("Screen Height / Font Height Too Big");
	}
	if (ScreenWidth > csbi.dwMaximumWindowSize.X)
	{
		OutputDebugStringA("Screen Width / Font Width Too Big");
	}
    
	// Set Console Window Size
	WindowSize.Right = ScreenWidth -1;
	WindowSize.Bottom = ScreenHeight -1;
	SetConsoleWindowInfo(hConsole, TRUE, &WindowSize);
    
	// Allocate memory for the buffer
	wchar_t *buffer = malloc(ScreenWidth*ScreenHeight * sizeof(wchar_t));
    
	SetConsoleTitle(L"Console Engine");
    
	// Hide the cursor
	CONSOLE_CURSOR_INFO cursor;
	BOOL result;
	cursor.dwSize = 1;
	cursor.bVisible = FALSE;
	result = SetConsoleCursorInfo(hConsole, &cursor);
    
	// Coords for the console screen buffer
	COORD coordXY;
	coordXY.X = 0;
	coordXY.Y = 0;
	
    Running = TRUE;
	
	while (Running)
	{
		// Clear screen
		for (int i = 0; i < ScreenWidth * ScreenHeight; i++)
        {
            buffer[i] = L' ';
        }
		
        // Use Sleep() for now
		Sleep(16);
		
        // Draw state
		Draw(buffer, 42, 10, PIXEL_HIGH);
		Draw(buffer, 44, 10, PIXEL_LOW);
		Draw(buffer, 46, 10, 'A');
        
		Fill(buffer, 0, 15, 20, 30, PIXEL_SOLID);
        
		// Display frame
		buffer[ScreenWidth * ScreenHeight - 1] = '\0';
		WriteConsoleOutputCharacter(hConsole, (LPCTSTR)buffer, ScreenWidth * ScreenHeight, coordXY, &dwBytesWritten);
    }
    
	free(buffer);
    
	return 0;
}