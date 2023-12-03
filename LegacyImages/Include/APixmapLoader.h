#pragma once

#include <LegacyFoundation.hpp>

#include "APixmapFormat.h"

#include "Formats/APngFormat.h"

class PUBLIC_API_EXPORT APixmapLoader final : public ASingleton<APixmapLoader>
{
    Map<String, SharedReference<APixmapFormat>> formats;
public:

    APixmapLoader()
    {
        registerFormat<APngFormat>("png");
    }

    template<typename PixmapFormatType>
    void registerFormat(const String &name) { formats.insert({ name, std::make_shared<PixmapFormatType>() }); }

    APixmap load(const APath &path) const;
    void save(const APath &path, const APixmap &pixmap) const;

    Array<uint8_t> compress(const APixmap &pixmap, const String &extention) const;
    APixmap decompress(const Array<uint8_t> &buffer) const;
};
