#ifndef __PIXPARA_HPP__
#define __PIXPARA_HPP__

#include "Pixmap.hpp"
#include <mpi.h>

namespace pixmap
{
    static int NP;
    static int PN;
    void Init(int * argcp, char * (* argvp[]));
    void Finalize();
}

#endif // __PIXPARA_HPP__

