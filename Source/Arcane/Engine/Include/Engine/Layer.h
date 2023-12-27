#pragma once
#include "Core/base.h"

#ifdef ARC_ENGINE_SHARED
#define ARC_ENGINE_API ARC_EXPORT
#else
#define ARC_ENGINE_API ARC_IMPORT
#endif // ARC_ENGINE_SHARED

namespace Arcane
{
	class ARC_ENGINE_API ILayer
	{
	public:
		ILayer() = default;
		virtual ~ILayer() = default;

		virtual void Create() {}
		virtual void Update() {}
		virtual void Destroy() {}
	};
}