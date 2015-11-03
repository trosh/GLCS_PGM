#ifndef __CONVOLUTION_HPP__
#define __CONVOLUTION_HPP__

#include "Pixmap.hpp"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

template<typename T>
pixmap::Pixmap pixmap::Convolution(const pixmap::Pixmap & map)
{
    const Pos    & size   = map.size_;
    const Pixels & pixels = map.pixels_;
    int w = size.first;
    int h = size.second;
    Pixels result(w*h);
    T F;
    Pixmap filtermap = F.matrix();
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
            red   += pixels(iy* w + ix).r
                   * filter(fy*fw + fx).r;
            green += pixels(iy* w + ix).g
                   * filter(fy*fw + fx).g;
            blue  += pixels(iy* w + ix).b
                   * filter(fy*fw + fx).b;
        }
        result(y*w+x) = {
                MIN(1, MAX(0, red)),
                MIN(1, MAX(0, green)),
                MIN(1, MAX(0, blue))};
    }
    return Pixmap(size, result);
}

#endif // __CONVOLUTION_H__

