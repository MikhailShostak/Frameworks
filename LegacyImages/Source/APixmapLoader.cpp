#include "APixmapLoader.h"
#include "APixmap.h"

#include "stb_image.c"

void APixmapLoader::save(const APath &path, const APixmap &pixmap) const
{

}

APixmap APixmapLoader::load(const APath &path) const
{
    for(const typename Map<String, SharedReference<APixmapFormat>>::value_type &pair : formats)
    {
        if(pair.second->isValid(path))
        {
            return pair.second->load(path);
        }
    }
    return APixmap();
}

Array<uint8_t> APixmapLoader::compress(const APixmap &pixmap, const String &extention) const
{
    return Array<uint8_t>();
}

APixmap APixmapLoader::decompress(const Array<uint8_t> &buffer) const
{
    for(const typename Map<String, SharedReference<APixmapFormat>>::value_type &pair : formats)
    {
        if(pair.second->isValid(buffer))
        {
            return pair.second->decompress(buffer);
        }
    }
    return APixmap();
}
