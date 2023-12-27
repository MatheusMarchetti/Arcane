#include "Engine/Engine.h"
#include "Core/Verify.h"

void Arcane::Engine::Initialize()
{
    m_Window.width = 1280;
    m_Window.height = 720;
    m_Window.name = "Arcane";
    
    m_Window.callbacks.closeFnc = []()
        {
            ARC_LOG("Close Fnc");
        };

    m_Window.callbacks.resizeFnc = [](int w, int h)
        {
            ARC_LOG("Resize Fnc: %i | %i", w, h);
        };

    m_Window.callbacks.keyFnc = [](int k, int s, int m)
        {
            ARC_LOG("Key Fnc: %i | %i | %i", k, s, m);
        };

    m_Window.callbacks.mouseFnc = [](int k, int s, int m)
        {
            ARC_LOG("Mouse Fnc: %i | %i | %i", k, s, m);
        };

    m_Window.callbacks.cursorFnc = [](double x, double y)
        {
            ARC_LOG("Cursor Fnc: %.2f | %.2f", x, y);
        };

    m_Window.callbacks.scrollFnc = [](double x, double y)
        {
            ARC_LOG("Scroll Fnc: %.2f | %.2f", x, y);
        };

    m_Window.callbacks.dropFnc = [](int count, const char** paths)
        {
            ARC_LOG("Drop Fnc: %i", count);

            for (int i = 0; i < count; i++)
            {
                ARC_LOG("Drop Fnc: \t%s", paths[i]);
            }
        };

    WindowManager::Intialize();
    WindowManager::Create(&m_Window);

    ARC_LOG("Engine Initialized");
}

void Arcane::Engine::Run()
{
    for (auto& layer : m_LayerStack)
    {
        layer->Create();
    }

    WindowManager::Show(&m_Window);
    while (WindowManager::IsOpen(&m_Window))
    {
        WindowManager::PollEvents();

        for (auto& layer : m_LayerStack)
            layer->Update();
    }

    for (auto& layer : m_LayerStack)
    {
        layer->Destroy();
    }
}

void Arcane::Engine::Terminate()
{
    for (auto& layer : m_LayerStack)
    {
        delete layer;
    }

    WindowManager::Destroy(&m_Window);
    WindowManager::Terminate();

    ARC_LOG("Engine Terminate");
}

Arcane::Engine* Arcane::Engine::Instance()
{
    static Engine s_Instance;
    return &s_Instance;
}
