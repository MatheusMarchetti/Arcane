#include "Core/Logging.h"
#include "Engine/Engine.h"
#include "Runtime/RuntimeLayer.h"

int main()
{
	auto logger = Arcane::Logger::Instance();
	logger->AttachLogSink<Arcane::ConsoleLogSink>();
	logger->AttachLogSink<Arcane::FileLogSink>();

	auto engine = Arcane::Engine::Instance();
	engine->AttachLayer<Arcane::RuntimeLayer>();

	engine->Initialize();
	engine->Run();
	engine->Terminate();
}