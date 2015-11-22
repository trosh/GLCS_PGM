#include "PixPara.hpp"

void pixmap::Parallel::Init(int * argcp, char * (* argvp[]))
{
    MPI_Init(argcp, argvp);
    MPI_Comm_size(MPI_COMM_WORLD, &pixmap::Parallel::NP);
    MPI_Comm_rank(MPI_COMM_WORLD, &pixmap::Parallel::PN);
    pixmap::Parallel::IsRoot == (pixmap::Parallel::PN == 0);
}

void pixmap::Parallel::Finalize()
{
    MPI_Finalize();
}

void pixmap::Parallel::Abort()
{
    MPI_Abort(MPI_COMM_WORLD);
}
