CXX=mpic++
LD=mpic++


hello:

hellowait:

run128: hello
	mpirun -np 128 --oversubscribe ./hello

run8: hello
	mpirun -np 8 --oversubscribe ./hello

run4: hello
	mpirun -np 4 ./hello

run4log: hello
	mpirun -np 4 --output-filename something ./hello

runwait4log: hellowait
	mpirun -np 4 --output-filename something ./hellowait
