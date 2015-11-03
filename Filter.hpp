#ifndef __FILTER_HPP__
#define __FILTER_HPP__

#include <vector>
#include "Pixmap.hpp"
#include "Pixels.hpp"

namespace pixmap
{
    namespace Filter
    {
        Pixmap EdgeDetect();
        Pixmap Sharpen();
        Pixmap Blur();
    }
}

#endif // __FILTER_HPP__

