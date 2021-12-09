#include <mpi.h>
#include <unistd.h>
#include <iostream>

int main(int argc, char*argv[]) {
	char hostname[256];
  	hostname[255] = '\0';
  	gethostname(hostname, 255);
	
	MPI_Init(&argc,&argv);

	int i;
	int P;
	
	MPI_Comm_size(MPI_COMM_WORLD, &P);
	MPI_Comm_rank(MPI_COMM_WORLD, &i);
		std::cout<<"I am process "<< i <<" out of "<< P <<". I am running on machine: "<< hostname <<"\n";


	MPI_Finalize();
}
