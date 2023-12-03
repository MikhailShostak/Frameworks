#include <LegacyFoundation.hpp>

PUBLIC_API_EXPORT const Array<uint8_t> &getAsset(const String &identifier);
PUBLIC_API_EXPORT void RegisterStaticAsset(const char *identifier, const std::uint8_t *data, size_t size);
