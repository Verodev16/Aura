#pragma once
#include "Exception.hpp"

namespace Aura
{
	template<class T> class UniquePtr
	{
	private:
		T* ptr = nullptr;
		
		Exception ex = Exception::None;
	public:
		inline constexpr const bool operator==(Exception e) const noexcept
		{
			return ex == e;
		}

		inline constexpr UniquePtr(T value) noexcept : ptr(new T(value))
		{
			if (ptr == nullptr)
				ex = Exception::HeapAllocation;
		}

		inline ~UniquePtr() noexcept
		{
			delete ptr;
		}

		inline constexpr T operator->() const noexcept
		{
			return *ptr;
		}

		inline constexpr T operator*() const noexcept
		{
			return *ptr;
		}

		inline constexpr const T* operator()() const noexcept
		{
			return ptr;
		}
	};
}