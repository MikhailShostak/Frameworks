#include "ASingleton.h"

Map<size_t, void *> *&ASingletonStorage::getSingletonsData()
{
    static Map<size_t, void *> *singletons = nullptr;
    return singletons;
}
