#include <iostream>
#include <cmath>
#include <cstdlib>
#include <chrono>
#include <stdio.h>


#ifdef __cplusplus
extern "C" {
#endif

float f1(float x, int intensity);
float f2(float x, int intensity);
float f3(float x, int intensity);
float f4(float x, int intensity);

#ifdef __cplusplus
}
#endif
  
int main (int argc, char* argv[]) {
  //starting timer
  auto start = std::chrono::system_clock::now();
  //defining local variables
  char* file; int funcID = 0; double a = 0; 
  double b = 0; double n = 0; double intensity = 0;
  //collecting the arguments
  while (argc < 6) {
    	std::cerr<<argv[argc];
    	argc++;	
  }
  //assigning local variables
	file = argv[0];
	funcID = atoi(argv[1]);
	a = atof(argv[2]);
	b = atof(argv[3]);
	n = atof(argv[4]);
	intensity = atof(argv[5]);

  //Calculations
	float total = 0.0;
	float sum = 0.0;
	for (int i=0;i<n;i++){
		total = (a+(i+.5)*((b-a)/n));
		//Selecting which function to calculate 
		if (funcID == 1) sum += f1(total,intensity);
		if (funcID == 2) sum += f2(total,intensity);
		if (funcID == 3) sum += f3(total,intensity);
		if (funcID == 4) sum += f4(total,intensity);
	}
	total = sum*((b-a)/n);
	std::cout<<total;
			
  //ending timer
  auto stop = std::chrono::system_clock::now();  
  auto tTime = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count();
  	//Printing of time elapsed
	float totalTime = tTime;
  	std::cerr<<totalTime;
	
  return 0;
}
