#include <cstdlib>
#include "logger.h"

void print(int value) {
  INF("Print: %i", value);
}

int myatoi(char* c){
  printf("%c", *(c+1));
  int i = 0;
  int s = 0;
  while((*(c+i)) != '\0'){
    s = s*10 + (*(c+i) - '0');
    i++;
  }
  
  return s;
}



int main(int argc, char** argv) {
  DBG("[Lesson 2]: Functions 1");

  if (argc < 2) {
    ERR("Invalid number of input parameters!");
    return 1;
  }

  int value = std::atoi(argv[1]);
  //print(value);
  INF("Value from std::atoi: %i", value);

  //print(value);
  INF("Value from myatoi: %i", value);

  DBG("[Lesson 1]: Functions 1 [END]");
  return 0;
}
