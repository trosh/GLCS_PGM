#ifndef __PIXELS_HPP__
#define __PIXELS_HPP__

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Pixel.hpp"

namespace pixmap
{
    class Pixels
    {
      private:
        std::vector<Pixel> cont_;
      public:
        Pixels();
        Pixels(int);
        Pixels(const std::vector<Pixel> &);
        Pixels(const std::vector<float> &);
        Pixel operator()(size_t) const;
        Pixel & operator()(size_t);
    };
}

#endif // __PIXELS_HPP__

