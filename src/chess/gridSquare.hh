/**
 * @file gridSquare.hh
 * @author Brandon Coffey
 * @brief 
 * @date 2020-06-22
 */

#ifndef CHESS_GRIDSQUARE_HH
#define CHESS_GRIDSQUARE_HH

#include <SDL2/SDL_video.h>
#include <sdl_wrapper/render/renderer.hh>
namespace chess
{
/**
 * @brief 
 * 
 */
class GridSquare
{
public:
    GridSquare(int x, int y, SDL_Color c, bool e);
    void display(sdl::render::Renderer &rr, int size, int xDisplacement, int yDisplacement);
private:
    int xPos, yPos;
    SDL_Color color;
    bool enabled;
};
}

#endif // CHESS_GRIDSQUARE_HH