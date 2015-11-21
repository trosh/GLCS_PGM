#include "PixPara.hpp"

void pixmap::Init(int * argcp, char * (* argvp[]))
{
    MPI_Init(argcp, argvp);
    MPI_Comm_size(MPI_COMM_WORLD, &NP);
    MPI_Comm_rank(MPI_COMM_WORLD, &PN);
}

void pixmap::Finalize()
{
    MPI_Finalize();
}

