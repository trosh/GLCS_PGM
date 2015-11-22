#include "Pixmap.hpp"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

pixmap::Pixmap pixmap::Pixmap::__Convolution_master(
        const pixmap::Pixmap & filtermap) const
{
}

pixmap::Pixmap pixmap::Pixmap::__Convolution_worker(
        const pixmap::Pixmap & filtermap) const
{
}

pixmap::Pixmap pixmap::Pixmap::Convolution(
        const pixmap::Pixmap & filtermap) const
{
    /* PARALLEL */
    if (pixmap::Parallel::NP > 1)
        if (pixmap::Parallel::IsRoot)
            return __Convolution_master(filtermap);
        else
            return __Convolution_worker(filtermap);
    /* SEQUENTIAL */
    int w = size_.first;
    int h = size_.second;
    Pixels result(w*h);
    int fw = filtermap.size_.first;
    int fh = filtermap.size_.second;
    const Pixels & filter = filtermap.pixels_;
#pragma omp parallel for schedule(static)
    for (int y=0; y<h; y++)
    for (int x=0; x<w; x++)
    {
        float red   = 0.0f;
        float green = 0.0f;
        float blue  = 0.0f;
        for (int fy=0; fy<fh; fy++)
        for (int fx=0; fx<fw; fx++)
        {
            int ix = (x - fw/2 + fx + w) % w;
            int iy = (y - fh/2 + fy + h) % h;
            red   += pixels_(iy* w + ix).r
                   * filter (fy*fw + fx).r;
            green += pixels_(iy* w + ix).g
                   * filter (fy*fw + fx).g;
            blue  += pixels_(iy* w + ix).b
                   * filter (fy*fw + fx).b;
        }
        result(y*w+x) = {
                MIN(1, MAX(0, red)),
                MIN(1, MAX(0, green)),
                MIN(1, MAX(0, blue))};
    }
    return Pixmap(size_, result);
}


std::ostream &
pixmap::operator<<(std::ostream & o, const pixmap::Pixmap & map)
{
    if (PN != 0) return o;
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

