#ifndef __PIXPARA_HPP__
#define __PIXPARA_HPP__

#include "Pixmap.hpp"
#include <mpi.h>

namespace pixmap
{
    namespace Parallel
    {
        int NP; /* NUMBER OF PROCESSES */
        int PN; /* PROCESS NUMBER */
        bool IsRoot; /* SELF-EXPLANATORY */
        void Init(int * argcp, char * (* argvp[]));
        void Finalize();
        void Abort();
    }
}

#endif // __PIXPARA_HPP__

