#include <chrono>
#include <fstream>
#include <sstream>
#include <vector> 
#include <thread>
#include <chrono>

#include "Dictionary.cpp"
#include "MyHashtable.cpp"

//thread function
void doingWork () {
	std::cout<<"work";
}

//Tokenize a string into individual word, removing punctuation at the
//end of words
std::vector<std::vector<std::string>> tokenizeLyrics(const std::vector<std::string> files) {
  std::vector<std::vector<std::string>> ret;

  for(auto filename : files) {
    //std::cout<<"reading "<<filename<<"\n";
    std::vector<std::string> my_vect;
    std::ifstream in (filename);

    std::string line;

    //For each line
    while (getline(in, line, '\n')) {
      //Skip all like starting with [
      if (line[0] == '[')
        continue;

      std::stringstream ssline (line);
      //For all words
      while (ssline) {
        std::string word;
        ssline >> word;
        if (ssline) {
          //remove punctuation at the end of word
          while (word.length() > 0
                 && std::ispunct(word[word.length() - 1])) {
            word.pop_back();
          }
          my_vect.push_back(word);
        }
      }
    }
    //std::cout<<"read "<<my_vect.size()<<" words\n";
    ret.push_back(my_vect);
  }
  return ret;
}


int main(int argc, char **argv)
{
  if (argc < 4) {
    std::cerr<<"usage: ./main <sources> <testword> <threshold>"<<std::endl;
    return -1;
  }
  //starting timer
  auto start = std::chrono::system_clock::now();

  // Parse Command Line
  std::string source = argv[1];
  std::string testWord = argv[2];
  int32_t thresholdCount = std::stoi(argv[3]);

  // Obtain List of Files
  std::vector<std::string> files;
  std::ifstream in (source);
  std::string line;
  while (getline(in, line, '\n')) {
    files.push_back(line);
  }

  // Tokenize Lyrics
  auto wordmap = tokenizeLyrics(files);

  MyHashtable<std::string, int> ht;
  Dictionary<std::string, int>& dict = ht;

  // write code here
  int word = 1;
  for(int i = 0; i < wordmap.size(); i++){
	std::thread t1(doingWork);	
	for(int j = 0; j < wordmap[i].size(); j++){	
 		//std::cout<< wordmap[i][j] << " ";
		word++;
	}
	t1.join();
	std::cout<<"the count for word is "<< word <<"\n";
  }	
// whatever proper mutex placement means
// make plots
// answer final question in a readable file





  // Check Hash Table Values 
  
/* (you can uncomment, but this must be commented out for tests)
  for (auto it : dict) {
    if (it.second > thresholdCount)
      std::cout << it.first << " " << it.second << std::endl;
  }
  */

  //ending timer
  auto stop = std::chrono::system_clock::now();  
  auto tTime = std::chrono::duration_cast<std::chrono::duration<double>>(stop - start).count();
  	//Printing of time elapsed
	float totalTime = tTime;
  	std::cerr<<totalTime;

  // Do not touch this, need for test cases
  std::cout << ht.get(testWord) << std::endl;


  return 0;
}

