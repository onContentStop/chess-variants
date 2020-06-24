#include "renderer.hh"
#include <sdl_wrapper/render/texture.hh>
#include <sdl_wrapper/sdl_exception.hh>
#include <sdl_wrapper/video/window.hh>

using std::optional;

namespace sdl::render
{

Renderer::Renderer(video::WeakWindow &window, int index, Uint32 flags)
    : WeakRenderer(SDL_CreateRenderer(window.getHandle(), index, flags))
{
    if (handle == nullptr)
    {
        throw SDLException("creating window renderer");
    }
}

Renderer::~Renderer()
{
    if (handle != nullptr)
    {
        SDL_DestroyRenderer(handle);
    }
}

Renderer::Renderer(Renderer &&other) : WeakRenderer(other.handle)
{
    other.handle = nullptr;
}

Renderer &Renderer::operator=(Renderer &&other)
{
    if (&other != this)
    {
        handle = other.handle;
        other.handle = nullptr;
    }
    return *this;
}

} // namespace sdl::render