#include "Engine/Engine.h"

void Arcane::Engine::Initialize()
{
    Window::InitializeGLFW();
    m_Window.Create(800, 600, "Arcane Engine");
}

void Arcane::Engine::Run()
{
    for (auto& layer : m_LayerStack)
        layer->Create();

    m_Window.Show();
    while (m_Window.IsOpen())
    {
        Window::PollEvents();

        for (auto& layer : m_LayerStack)
            layer->Update();
    }

    for (auto& layer : m_LayerStack)
        layer->Destroy();
}

void Arcane::Engine::Terminate()
{
    for (auto& layer : m_LayerStack)
        delete layer;
    
    m_Window.Destroy();
    Window::TerminateGLFW();
}

Arcane::Engine* Arcane::Engine::Instance()
{
    static Engine s_Instance;
    return &s_Instance;
}
