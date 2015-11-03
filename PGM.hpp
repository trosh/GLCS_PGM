#ifndef __PGM_HPP__
#define __PGM_HPP__

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include "Pixels.hpp"
#include "Pixmap.hpp"

namespace pixmap
{
    class PGM /* or PBM */
    {
      public:
        Pixmap read(const std::string &);
    };
}

#endif // __PGM_HPP__

