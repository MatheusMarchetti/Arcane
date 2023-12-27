#include "Engine/Engine.h"
#include "Runtime/RuntimeLayer.h"

int main()
{
	auto engine = Arcane::Engine::Instance();

	engine->AttachLayer<Arcane::RuntimeLayer>();

	engine->Initialize();
	engine->Run();
	engine->Terminate();
}