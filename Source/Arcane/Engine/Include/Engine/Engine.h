#pragma once
#include "Core/Window.h"
#include "Engine/Layer.h"

#ifdef ARC_ENGINE_SHARED
#define ARC_ENGINE_API ARC_EXPORT
#else
#define ARC_ENGINE_API ARC_IMPORT
#endif // ARC_ENGINE_SHARED

namespace Arcane
{
	class ARC_ENGINE_API Engine
	{
	public:
		~Engine() = default;
		
		void Initialize();
		void Run();
		void Terminate();

		static Engine* Instance();

		template<typename T, typename... Args>
		void AttachLayer(Args&&... args)
		{
			m_LayerStack.emplace_back( new T(std::forward<Args>(args)...));
		}
	private:
		Engine() = default;

		Window m_Window;
		utl::vector< ILayer* > m_LayerStack;
	};
}
