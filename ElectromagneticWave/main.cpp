#include "WaveViewer.h"
#include "FreeSpaceFDTD.h"
#include "WaveguideFDTD.h"

int main()
{
    //FreeSpaceFDTD g(MODE::TRANSVERSE_ELECTRIC, 100, 100, 5.0E-7, 512, 512, 10, 10, 1, 10);
    //g.render(1000, 1000);


    WaveguideFDTD x(MODE::TRANSVERSE_ELECTRIC, 100, 100, 5.0E-7, 512, 512);
    x.render(1000, 1000);
}