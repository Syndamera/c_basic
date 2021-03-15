#include <windows.h>

#define TRUE 1
#define FALSE 0

enum PIXEL_TYPE
{
    PIXEL_SOLID = 0x2588
};

enum COLOR
{
    WHITE = 0x000F
};

int width = 160;
int height = 90;
int fontw = 8;
int fonth = 8;

void Draw(wchar_t *buffer, int x, int y, short c, short color)
{
    if (x >= 0 && x < width && y >= 0 && y < height)
    {
        buffer[y * width + x] = c;
        //buffer[y * width + x].Char.UnicodeChar = c;
        //buffer[y * width + x].Attributes  = color;
    }
}

int main()
{
    DWORD dwBytesWritten = 0;
    HANDLE OriginalConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE ConsoleInput = GetStdHandle(STD_INPUT_HANDLE);
    if(Console == INVALID_HANDLE_VALUE)
    {
        printf("Error - Bad Handle");
    }
    
    SMALL_RECT WindowSize = {0, 0, 1, 1};
    SetConsoleWindowInfo(Console, TRUE, &WindowSize);
    COORD coord = { (short)width, (short)height };
    
    // TODO: Do error checks if not set
    SetConsoleScreenBufferSize(Console, coord);
    SetConsoleActiveScreenBuffer(Console);
    
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = fontw;
    cfi.dwFontSize.Y = fonth;
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    
    wcscpy(cfi.FaceName, L"Consolas");
    SetCurrentConsoleFontEx(Console, FALSE, &cfi);
    
    WindowSize.Right = (short)width - 1;
    WindowSize.Bottom = (short)height - 1;
    
    SetConsoleWindowInfo(Console, TRUE, &WindowSize);
    
    //SetConsoleMode(ConsoleInput, ENABLE_EXTENDED_FLAGS |
    //ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT);
    
    // CHAR_INFO to access Char.UnicodeChar & Attributes.
    wchar_t *Buffer = malloc(sizeof(wchar_t) * width * height);
    //CHAR_INFO *Buffer = memset(Buffer, 0, sizeof(CHAR_INFO) * width * height);
    
    COORD coordXY = {0};
    
    int Running = TRUE;
    while(Running)
    {
        // Clear the screen
        for(int i = 0; i < width * height; i++)
        {
            Buffer[i] = L' ';
        }
        
        // Draw the first room
        int Tilemap[9][16] =
        {
            {1,1,1,1,  1,1,1,0,  1,1,1,1,  1,1,1,1},
            {1,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,1},
            {1,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,1},
            {1,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,1},
            {0,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,0},
            {1,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,1},
            {1,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,1},
            {1,0,0,0,  0,0,0,0,  0,0,0,0,  0,0,0,1},
            {1,1,1,1,  1,1,1,0,  1,1,1,1,  1,1,1,1},
        };
        
        for(int row = 0; row < 9; row++)
        {
            for(int col = 0; col < 16; col++)
            {
                int TileID = Tilemap[row][col];
                
                if(TileID == 1)
                {
                    Draw(Buffer, row, col, L'#', WHITE);
                }
                else
                {
                    Draw(Buffer, row, col, L'.', WHITE);
                }
            }
        }
        // Render frame to screen
        WriteConsoleOutputCharacter(Console, (LPCTSTR)Buffer, width * height, coordXY, &dwBytesWritten);
    }
    
    free(Buffer);
    
    SetConsoleActiveScreenBuffer(OriginalConsole);
    
    return 0;
}