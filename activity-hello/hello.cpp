#include <unistd.h>
#include <iostream>
int main () {
  char hostname[256];
  hostname[255] = '\0';
  gethostname(hostname, 255);
  std::cout<<"Hostname: "<<hostname<<"\n";
  std::string s = "hello world\n";
  std::cout<<s;
  
  return 0;
}
