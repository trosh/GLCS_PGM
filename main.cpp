#include <iostream>
#include "Filter.hpp"
#include "Pixmap.hpp"
#include "PixPara.hpp"
#include "PGM.hpp"

int main(int argc, char * argv[])
{
    pixmap::Parallel::Init(&argc, &argv); /* REQUIRED, ACCORDING TO DOC */
    if (argc != 2)
    {
        if (pixmap::Parallel::IsRoot)
            std::cout << "[\033[31mERROR\033[0m] "
                      << "usage : main FILE" << std::endl;
        pixmap::Parallel::Abort();
    }
    pixmap::PGM PGMReader;
    pixmap::Pixmap img = PGMReader.read(argv[1]);
    pixmap::Pixmap img_blur = img.Convolution(pixmap::Filter::Blur(), 4);
    pixmap::Pixmap img_sharp = img.Convolution(pixmap::Filter::Sharpen());
    //pixmap::Pixmap img_edgedetect
    //= img.Convolution<pixmap::Filter::EdgeDetectTL>();
    if (pixmap::Parallel::IsRoot)
    {
        std::string input;
        std::cout << "\033[7mPRESS ANY KEY FOR ORIGINAL\033[0m\n";
        getchar();
        std::cout << img      << std::endl;
        std::cout << "\033[7mPRESS ANY KEY FOR BLURRED\033[0m\n";
        getchar();
        std::cout << img_blur << std::endl;
        std::cout << "\033[7mPRESS ANY KEY FOR SHARPENED\033[0m\n";
        getchar();
        std::cout << img_sharp << std::endl;
    }
    pixmap::Parallel::Finalize(); /* REQUIRED, ACCORDING TO DOC */
    return EXIT_SUCCESS;
}

