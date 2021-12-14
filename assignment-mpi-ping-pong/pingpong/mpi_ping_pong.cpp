#include <mpi.h>
#include <iostream>

int main (int argc, char* argv[]) {

  if (argc < 2) {
    std::cerr<<"usage: mpirun "<<argv[0]<<" <value>"<<std::endl;
    return -1;
  }
	MPI_Init(&argc,&argv);
	// Find out rank, size
	int worldrank;
	MPI_Comm_rank(MPI_COMM_WORLD, &worldrank);
	int worldsize;
	MPI_Comm_size(MPI_COMM_WORLD, &worldsize);

	int number;
	if (worldrank == 0) {
    		number = atoi(argv[0]);
		std::cout<<number<<"\n";
    		MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
	} else if (worldrank == 1) {
    		MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		number +=2;
		MPI_Send(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    	}
	MPI_Recv(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
  	std::cout<<number;

	MPI_Finalize();

  return 0;
}
