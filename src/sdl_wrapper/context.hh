/**
 * @file context.hh
 * @author Kyle Coffey (kylecoffey1999@gmail.com)
 * @brief Contains a wrapper for initializing and deinitializing
 * SDL and its systems.
 * @date 2020-06-21
 */

#ifndef SDL_WRAPPER_SDL_CONTEXT_HH
#define SDL_WRAPPER_SDL_CONTEXT_HH

#include <sdl_wrapper/video/context.hh>

/**
 * @namespace sdl
 * @brief The namespace under which all SDL wrapper classes and functions exist.
 *
 */
namespace sdl
{
/**
 * @brief An RAII wrapper for SDL's initialization and
 * deinitialization.
 */
class Context
{
  public:
    /**
     * @brief Construct a new SDLContext object. Constructing
     * this object results in a call to SDL_Init(0).
     *
     */
    Context();
    ~Context();

    /// no copy constructors
    Context(const Context &) = delete;
    /// no copy assignment
    Context &operator=(const Context &) = delete;

    /**
     * @brief copy constructor
     *
     * @param other the object to move from
     */
    Context(Context &&other) noexcept;
    /**
     * @brief copy assignment operator
     *
     * @param other the object to move from
     * @return the object being moved to, for correctness
     */
    Context &operator=(Context &&other) noexcept;

    /**
     * @brief Initialize the SDL video subsystem
     *
     * @return video::Context an object representing the active state of the subsystem
     */
    video::Context initVideo();

  private:
    /**
     * @brief Describes whether this SDL context should quit SDL on destruction
     *
     */
    bool active;
};
} // namespace sdl

#endif // SDL_WRAPPER_SDL_CONTEXT_HH