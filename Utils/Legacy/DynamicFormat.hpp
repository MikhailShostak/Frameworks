#pragma once

#include <fmt/format.h>
#include <fmt/chrono.h>
#include <fmt/ostream.h>
#include <fmt/ranges.h>

namespace fmt
{
	template<typename T>
	inline dynamic_format_arg_store<format_context> args(const T &map)
	{
		dynamic_format_arg_store<format_context> store;
		for(const auto &pair : map)
		{
			store.push_back(arg(pair.first, pair.second));
		}
		return store;
	}
	
	template<typename T>
	inline dynamic_format_arg_store<format_context> args(const std::reference_wrapper<T> &map)
	{
		dynamic_format_arg_store<format_context> store;
		for(const auto &pair : map)
		{
			store.push_back(std::cref(arg(pair.first, pair.second)));
		}
		return store;
	}
}
