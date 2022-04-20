#pragma once

#include <variant>

template<typename... Types>
using Union = std::variant<Types...>;
