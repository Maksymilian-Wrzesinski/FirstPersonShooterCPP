// FirstPersonShooter.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <Windows.h>

using namespace std;


int nScreenWidth = 120;
int nScreenHeight = 40;

float fPlayerX = 8.0f;
float fPlayerY = 8.0f;
float fPlayerA = 0.0f;

int nMapHeight = 16;
int nMapWidth = 16;

float fFOV = 3.14 / 4.0;
float fDepth = 16.0f;


int main()
{
    //Screen Buffer
    wchar_t* screen = new wchar_t[nScreenWidth * nScreenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    wstring map;

    map += L"################";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"####.......#####";
    map += L"################";

    //Gaming loop
    while (true) {

        for (int x = 0; x < nScreenWidth; x++) {
            //calculate angle for each ray projected for each column
            float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;

            float fDistanceToWall = 0;
            bool bHitWall = false;

            float fEyeX = sinf(fRayAngle); // Unit vector for ray in player space
            float fEyeY = cosf(fRayAngle);

            while (!bHitWall && fDistanceToWall < fDepth) {

                fDistanceToWall += 0.1f;

                int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
                int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

                // Test if ray is out of bounds
                if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
                {
                    bHitWall = true;			// Just set distance to maximum depth
                    fDistanceToWall = fDepth;
                }
                else{
                    if (map[nTestY * nMapWidth + nTestX] == '#') {
                        bHitWall = true;
                        fDistanceToWall = fDepth;
                    }
                        
            }
        }

        // Calculate distance to ceiling and floor
        int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
        int nFloor = nScreenHeight - nCeiling;

        // Shader walls based on distance
       // short nShade = ' ';
       // if (fDistanceToWall <= fDepth / 4.0f)			nShade = 0x2588;	// Very close	
       // else if (fDistanceToWall < fDepth / 3.0f)		nShade = 0x2593;
       // else if (fDistanceToWall < fDepth / 2.0f)		nShade = 0x2592;
       // else if (fDistanceToWall < fDepth)				nShade = 0x2591;
       // else											nShade = ' ';		// Too far away

       // if (bBoundary)		nShade = ' '; // Black it out

        for (int y = 0; y < nScreenHeight; y++)
        {
            // Each Row
            if (y <= nCeiling)
                screen[y * nScreenWidth + x] = ' ';
            else if (y > nCeiling && y <= nFloor)
                screen[y * nScreenWidth + x] = '#';
            else // Floor
                screen[y * nScreenWidth + x] = ' ';
          //  {
                // Shade floor based on distance
          //      float b = 1.0f - (((float)y - nScreenHeight / 2.0f) / ((float)nScreenHeight / 2.0f));
           //     if (b < 0.25)		nShade = '#';
           //     else if (b < 0.5)	nShade = 'x';
           //     else if (b < 0.75)	nShade = '.';
           //     else if (b < 0.9)	nShade = '-';
           //     else				nShade = ' ';
           //     screen[y * nScreenWidth + x] = nShade;
            }
        }

        // Display Frame
        screen[nScreenWidth * nScreenHeight - 1] = '\0';
        WriteConsoleOutputCharacter(hConsole, screen, nScreenWidth * nScreenHeight, { 0,0 }, &dwBytesWritten);
    }

    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
