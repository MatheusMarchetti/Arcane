#pragma once
#include <cstdint>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>

namespace utl
{
	template<typename T>
	using vector = std::vector<T>;

	template<typename Key, typename Value>
	using map = std::map<Key, Value>;

	template<typename Key, typename Value>
	using unordered_map = std::unordered_map<Key, Value>;

	template<typename T>
	using set = std::set<T>;

	template<typename T>
	using unordered_set = std::unordered_set<T>;

	template<typename T>
	using unique_ptr = std::unique_ptr<T>;

	template<typename T, typename... Args>
	unique_ptr<T> make_unique(Args&&... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template<typename T>
	using shared_ptr = std::shared_ptr<T>;

	template<typename T, typename... Args>
	shared_ptr<T> make_shared(Args&&... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}
}