#include "AMeta.h"

Array<void(*)()> &GetGlobalCalls()
{
    static Array<void(*)()> calls;
    return calls;
}
