#pragma once
#include "Engine/Layer.h"

namespace Arcane
{
	class RuntimeLayer : public ILayer
	{
	public:
		RuntimeLayer() = default;
		~RuntimeLayer() override = default;

		void Create() override;
		void Update() override;
		void Destroy() override;
	};
}
