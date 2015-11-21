#include <iostream>
#include "Filter.hpp"
#include "Pixmap.hpp"
#include "PixPara.hpp"
#include "PGM.hpp"

int main(int argc, char * argv[])
{
    pixmap::Init(&argc, &argv); /* REQUIRED, ACCORDING TO DOC */
    if (argc != 2)
    {
        std::cout << "[\033[31mERROR\033[0m] "
                  << "usage : main FILE" << std::endl;
        return 1;
    }
    pixmap::PGM PGMReader;
    pixmap::Pixmap img = PGMReader.read(argv[1]);
    pixmap::Pixmap img_blur = img.Convolution(pixmap::Filter::Blur(), 4);
    pixmap::Pixmap img_sharp = img.Convolution(pixmap::Filter::Sharpen());
    pixmap::Pixmap img_edgedetect = img.Convolution<pixmap::Filter::EdgeDetectTL>();
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
    voidpixmap::Finalize(); /* REQUIRED, ACCORDING TO DOC */
    return 0;
}

