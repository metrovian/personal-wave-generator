#include "WaveViewer.h"
#include "FreeSpaceFDTD.h"
#include "PlanarWaveguideFDTD.h"
#include "BraggReflectorFDTD.h"
#include "SquareDDA.h"
#include "LineDDA.h"

int main()
{
    //FreeSpaceFDTD g(MODE::TRANSVERSE_ELECTRIC, 100, 100, 5.0E-7, 500, 500, 50, 50, 10);
    //g.render(1000, 1000);

    //PlanarWaveguideFDTD x(MODE::TRANSVERSE_ELECTRIC, 100, 100, 5.0E-7, 500, 500);
    //x.render(1000, 1000);

    //BraggReflectorFDTD x(MODE::TRANSVERSE_ELECTRIC, 100, 100, 5.0E-7, 500, 500);
    //x.render(1000, 1000);

    LineDDA s(100, 100, 500, 500);
    s.render(1000, 1000);
}