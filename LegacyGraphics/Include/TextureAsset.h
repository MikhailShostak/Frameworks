#pragma once

#include <LegacyFoundation.hpp>
#include <LegacyImages.hpp>
#include <LegacyAssets.hpp>

#include "Texture.gen.h"

struct PUBLIC_API_EXPORT TextureAsset
{
    ::SharedReference<Legacy::Graphics::Texture> load(const char *path) const
    {
        ::SharedReference<Legacy::Graphics::Texture> texture;

        APathInfo pathInfo(path);
        if (!pathInfo.isExists())
        {
            return texture;
        }

        APixmap pixmap = APixmapLoader::getInstance().load(pathInfo.path());
        if (pixmap.getBufferSize() == 0)
        {
            return texture;
        }

        texture = std::make_shared<Legacy::Graphics::Texture>();
        texture->setPixmap(pixmap);
        return texture;
    }

    ::SharedReference<Legacy::Graphics::Texture> load(const Array<uint8_t> &buffer) const
    {
        ::SharedReference<Legacy::Graphics::Texture> texture;

        APixmap pixmap = APixmapLoader::getInstance().decompress(buffer);
        if (pixmap.getBufferSize() == 0)
        {
            return texture;
        }

        texture = std::make_shared<Legacy::Graphics::Texture>();
        texture->setPixmap(pixmap);
        return texture;
    }
};
