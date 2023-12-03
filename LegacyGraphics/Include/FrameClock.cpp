#include "FrameClock.h"

FrameClock &GetGraphicsClock()
{
    static FrameClock GraphicsClock;
    return GraphicsClock;
}
