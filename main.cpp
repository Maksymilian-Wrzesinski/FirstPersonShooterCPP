#include <iostream>
//#include <x86intrin.h>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>

#include <stdio.h>
//#include <Windows.h>
#include <windows.h>


using namespace std;

int nScreenWidth = 120;
int nScreenHeight = 40;

float fPlayerX = 0.0f;
float fPlayerY = 0.0f;
float fPlayerA = 0.0f;

int mapHeight = 16;
int mapWidth = 16;

float fFOV = 3.14 / 4.0;

int main()
{
	//Screen Buffer
    wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    wstring map;

    map+=L"################";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"####.......#####";
    map+=L"################";

    //Gaming loop
    while(true){

        for (int x=0; x<nScreenWidth;x++){
            //calculate angle for each ray projected for each column
            float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x/(float)nScreenWidth)* fFOV;
        }



    // Display Frame
    screen[nScreenWidth*nScreenHeight -1] = '\0';
    WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
    }
	return 0;
}
