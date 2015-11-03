#include <iostream>
#include "Filter.hpp"
#include "Pixmap.hpp"
#include "PGM.hpp"

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
    pixmap::Pixmap img_sharp;
    img_blur = img.Convolution(pixmap::Filter::Blur(), 4);
    img_sharp = img.Convolution(pixmap::Filter::Sharpen());
    std::string input;
    std::cout << "\033[7mPRESS ANY KEY FOR ORIGINAL\033[0m" << std::endl;
    getchar();
    std::cout << img      << std::endl;
    std::cout << "\033[7mPRESS ANY KEY FOR BLURRED\033[0m" << std::endl;
    getchar();
    std::cout << img_blur << std::endl;
    std::cout << "\033[7mPRESS ANY KEY FOR SHARPENED\033[0m" << std::endl;
    getchar();
    std::cout << img_sharp << std::endl;
    return 0;
}

