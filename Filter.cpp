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
        0, 1, 2, 1, 0,
        1, 1, 2, 1, 1,
        2, 2, 2, 2, 2,
        1, 1, 2, 1, 1,
        0, 1, 2, 1, 0
    };
    for (size_t i=0; i<m.size(); i++)
    {
        m[i] /= 30;
    }
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

