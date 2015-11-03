#include <iostream>
#include "Filter.hpp"
#include "Pixmap.hpp"
#include "PGM.hpp"
#include "Convolution.hpp"

int main(int argc, char * argv[])
{
    if (argc != 2)
    {
        std::cout << "[\033[31mERROR\033[0m] "
                  << "usage : main FILE" << std::endl;
        return 1;
    }
    pixmap::PGM PGMReader;
    pixmap::Pixmap img = PGMReader.read(argv[1]);
    pixmap::Pixmap img_blur;
    pixmap::Pixmap img_edge;
    img_blur = pixmap::Convolution<pixmap::Filter::Blur>(img);
    img_edge = pixmap::Convolution<pixmap::Filter::EdgeDetect>(img);
    std::string input;
    std::cout << "\033[7mPRESS KEY FOR ORIGINAL\033[0m" << std::endl;
    getchar();
    std::cout << img      << std::endl;
    std::cout << "\033[7mPRESS KEY FOR BLURRED\033[0m" << std::endl;
    getchar();
    std::cout << img_blur << std::endl;
    std::cout << "\033[7mPRESS KEY FOR EDGED\033[0m" << std::endl;
    getchar();
    std::cout << img_edge << std::endl;
    return 0;
}

