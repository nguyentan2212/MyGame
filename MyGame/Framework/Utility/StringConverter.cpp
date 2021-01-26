#include "StringConverter.h"

namespace ultility
{
#pragma warning(push)

#pragma warning(disable: 4996)    // the following converters were declared deprecated in C++-17

	std::wstring StringConverter::s2ws(const std::string& str)
	{
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.from_bytes(str);
	}

	std::string StringConverter::ws2s(const std::wstring& wstr)
	{
		using convert_typeX = std::codecvt_utf8<wchar_t>;
		std::wstring_convert<convert_typeX, wchar_t> converterX;

		return converterX.to_bytes(wstr);
	}

	const wchar_t* StringConverter::s2lpcws(const std::string& str)
	{
		return s2ws(str).c_str();
	}
#pragma warning(pop)
}
