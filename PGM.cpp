#include "PGM.hpp"

pixmap::Pixmap pixmap::PGM::read(const std::string & filename)
{
    if (PN != 0) return o;
    std::ifstream file(filename, std::ios::in);
    if ( ! file.is_open() )
    {
        std::cerr << "cannot open " << filename << std::endl;
    }
    int x, y, max;
    std::string magic;
    file >> magic >> x >> y >> max;
    max++;
    Pos size(x, y);
    Pixels pixels(x*y);
    if (magic == "P2")
    {
        for (int i=0; i<x*y; i++)
        {
            int g;
            file >> g;
            float fg = static_cast<float>(g) / max;
            pixels(i) = {fg, fg, fg};
        }
    }
    else if (magic == "P3")
    {
        for (int i=0; i<x*y; i++)
        {
            int r, g, b;
            file >> r >> g >> b;
            float fr = static_cast<float>(r) / max;
            float fg = static_cast<float>(g) / max;
            float fb = static_cast<float>(b) / max;
            pixels(i) = {fr, fg, fb};
        }
    }
    else
    {
        throw std::runtime_error("Bad PGM magic number");
    }
    file.close();
    return Pixmap(size, pixels);
}

