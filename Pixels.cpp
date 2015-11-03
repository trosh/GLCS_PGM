#include "Pixels.hpp"

pixmap::Pixels::Pixels() {}

pixmap::Pixels::Pixels(int size)
: cont_(size)
{}

pixmap::Pixels::Pixels(const std::vector<Pixel> & v)
: cont_(v)
{}

pixmap::Pixels::Pixels(const std::vector<float> & v)
{
    cont_.resize(v.size());
    for (size_t i=0; i<v.size(); i++)
    {
        cont_[i] = {v[i], v[i], v[i]};
    }
}

pixmap::Pixel pixmap::Pixels::operator()(size_t n) const
{
    if (n < 0
     || n >= cont_.size())
    {
        std::cout << "index = " << n << std::endl;
        throw std::range_error("Bad Pixels index (const)");
    }
    return cont_[n];
}

pixmap::Pixel & pixmap::Pixels::operator()(size_t n)
{
    if (n < 0
     || n >= cont_.size())
    {
        std::cout << "index = " << n << std::endl;
        throw std::range_error("Bad Pixels index");
    }
    return cont_[n];
}

