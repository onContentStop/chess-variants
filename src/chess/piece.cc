#include "piece.hh"
#include <stdexcept>

namespace chess
{
Piece::Piece(PieceFactory &factory, const std::set<sdl::primitives::Point> &validMoves, const PieceImages &images,
             SDL_Color color)
    : color(color), hasCrown_(false), validMoves(validMoves), images(images), factory(factory)
{
}
void Piece::giveCrown()
{
    if (!hasCrown_)
    {
        hasCrown_ = true;
    }
    else
    {
        throw std::runtime_error("giving crown to piece with crown");
    }
}
void Piece::takeCrown()
{
    if (hasCrown_)
    {
        hasCrown_ = false;
    }
    else
    {
        throw std::runtime_error("taking crown from piece without crown");
    }
}
bool Piece::hasCrown() const
{
    return hasCrown_;
}
} // namespace chess
