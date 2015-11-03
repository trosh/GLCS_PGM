#ifndef __FILTER_HPP__
#define __FILTER_HPP__

#include <vector>
#include "Pixmap.hpp"
#include "Pixels.hpp"

namespace pixmap
{
    namespace Filter
    {
        class Filter
        {
          public:
            virtual Pixmap matrix() const = 0;
        };
        class EdgeDetect
        : public Filter
        {
          public:
            Pixmap matrix() const;
        };
        class Sharpen
        : public Filter
        {
          public:
            Pixmap matrix() const;
        };
        class Blur
        : public Filter
        {
          public:
            Pixmap matrix() const;
        };
    }
}

#endif // __FILTER_HPP__

