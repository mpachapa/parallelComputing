#include <iostream>
#include <thread>

//minion thread call
void minion(int i){
 	std::cout<<"Hello! I am Minion "<<i<<"!\n";
}
//overlord thread call
void overlord(){
  std::cout<<"Hello Minions! I am the Overlord!\n";
}


int main (int argc, char** argv) {
  if (argc < 2) {
    std::cerr<<"usage: "<<argv[0]<<" <nbminions>\n";
    return -1;
  }
//extracting the passed value
  int numOf = atoi(argv[1]);
  
//initalization of the minion thread
    for (int i = 1; i<=numOf; i++){
	std::thread t1(minion, i);  
  	t1.join();
  }
//initalization of the overlord thread
  std::thread t3(overlord);
  t3.join();
  
  return 0;
}
