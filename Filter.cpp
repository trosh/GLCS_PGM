#include "Filter.hpp"

pixmap::Pixmap
pixmap::Filter::EdgeDetect::matrix() const
{
    std::vector<float> m = {
        -1, -1, -1,
        -1,  8, -1,
        -1, -1, -1
    };
    return Pixmap(Pos(3, 3), Pixels(m));
}

pixmap::Pixmap
pixmap::Filter::Blur::matrix() const
{
    std::vector<float> m = {
        0.0f   , 1.0f/30, 2.0f/30, 1.0f/30, 0.0f   ,
        1.0f/30, 1.0f/30, 2.0f/30, 1.0f/30, 1.0f/30,
        2.0f/30, 2.0f/30, 2.0f/30, 2.0f/30, 2.0f/30,
        1.0f/30, 1.0f/30, 2.0f/30, 1.0f/30, 1.0f/30,
        0.0f   , 1.0f/30, 2.0f/30, 1.0f/30, 0.0f
    };
    return Pixmap(Pos(5, 5), Pixels(m));
}

pixmap::Pixmap
pixmap::Filter::Sharpen::matrix() const
{
    std::vector<float> m = {
        -1, -1, -1,
        -1,  9, -1,
        -1, -1, -1
    };
    return Pixmap(Pos(3, 3), Pixels(m));
}

