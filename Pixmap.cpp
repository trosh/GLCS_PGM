#include "Pixmap.hpp"

std::ostream &
pixmap::operator<<(std::ostream & o, const pixmap::Pixmap & map)
{
    o << map.size_.first << "x" << map.size_.second << std::endl;
    for (int y=0; y<map.size_.second-1; y+=2)
    {
        for (int x=0; x<map.size_.first; x++)
        {
            const auto pixel1 = map.pixels_(y*map.size_.first+x);
            int r1 = static_cast<int>(24*pixel1.r);
            int g1 = static_cast<int>(24*pixel1.g);
            int b1 = static_cast<int>(24*pixel1.b);
            const auto pixel2 = map.pixels_((y+1)*map.size_.first+x);
            int r2 = static_cast<int>(24*pixel2.r);
            int g2 = static_cast<int>(24*pixel2.g);
            int b2 = static_cast<int>(24*pixel2.b);
            /* TOP */
            if (r1 == g1
             && r1 == b1) /* GREY */
            {
                o << "\033[38;5;"
                  << 232 + r1 << "m";
            }
            else /* COLOR */
            {
                o << "\033[38;5;"
                  << 16 + 36*(r1/4) + 6*(g1/4) + (b1/4)
                  << "m";
            }
            /* BOTTOM */
            if (r2 == g2
             && r2 == b2) /* GREY */
            {
                o << "\033[48;5;"
                  << 232 + r2 << "m";
            }
            else /* COLOR */
            {
                o << "\033[48;5;"
                  << 16 + 36*(r2/4) + 6*(g2/4) + (b2/4)
                  << "m";
            }
            o << "▀";
        }
        o << "\033[0m" << std::endl;
    }
    if (map.size_.second % 2 == 1)
    {
        int y = map.size_.second - 1;
        for (int x=0; x<map.size_.first; x++)
        {
            const auto pixel = map.pixels_(y*map.size_.first+x);
            int r = static_cast<int>(24*pixel.r);
            int g = static_cast<int>(24*pixel.g);
            int b = static_cast<int>(24*pixel.b);
            /* TOP */
            if (r == g
             && r == b) /* GREY */
            {
                o << "\033[38;5;"
                  << 232 + r << "m";
            }
            else /* COLOR */
            {
                o << "\033[38;5;"
                  << 16 + 36*(r/4) + 6*(g/4) + (b/4)
                  << "m";
            }
            /* BOTTOM */
            o << "\033[40m▀";
        }
        o << "\033[0m" << std::endl;
    }
    return o;
}

