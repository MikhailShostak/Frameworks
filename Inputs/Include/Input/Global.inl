#pragma once

namespace Input
{

using CallbackType = std::function<bool(const Event &event)>;

inline Int4 Swizzle(uint8_t X, uint8_t Y = 1, uint8_t Z = 2, uint8_t W = 3) { return { X, Y, Z, W }; }

}
