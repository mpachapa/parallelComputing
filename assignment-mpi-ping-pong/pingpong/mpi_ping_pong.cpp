#include <mpi.h>
#include <iostream>

int main (int argc, char* argv[]) {

  if (argc < 2) {
    std::cerr<<"usage: mpirun "<<argv[0]<<" <value>"<<std::endl;
    return -1;
  }
	MPI_Init(&argc,&argv);
	// Find out rank, size
	MPI_Comm_rank(MPI_COMM_WORLD, &worldrank);
	MPI_Comm_size(MPI_COMM_WORLD, &worldsize);

	int number;
	if (worldrank == 0) {
    		number = atoi(argv[0]);
    		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	} else {
    		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		number++; number++;
		MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    	}
	MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  	std::cout<<number;

	MPI_Finalize();

  return 0;
}
