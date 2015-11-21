#ifndef __PIXMAP_HPP__
#define __PIXMAP_HPP__

#include <iostream>
#include <fstream>
#include <tuple>
#include <vector>
#include <string>
#include "Pixel.hpp"
#include "Pixels.hpp"

typedef std::pair<int, int> Pos;

namespace pixmap
{
    class Pixmap
    {
      private:
        Pos size_;
        Pixels pixels_;
      public:
        Pixmap()
        {}
        Pixmap(const Pos    & size,
               const Pixels & pixels)
        : size_(size)
        , pixels_(pixels) {}
        //Pixmap(Pos && size,
        //       Pixels && pixels)
        //: size_(std::move(size))
        //, pixels_(std::move(pixels)) {}
        Pixmap(const Pixmap &) = default;
        Pixmap Convolution(
                const Pixmap &,
                const int mpi_nproc=1) const;
        friend std::ostream &
        operator<<(std::ostream &,
           const pixmap::Pixmap &);
    };
    std::ostream &
    operator<<(std::ostream &,
       const pixmap::Pixmap &);
};

#endif // __PIXMAP_HPP__

