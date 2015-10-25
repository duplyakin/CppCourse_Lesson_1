#include <cstdio>

//int global_variable = 1; --- использутеся только в main

int main(int argc, char** argv) {  // main block
  printf("[Lesson 1]: Visibility scope 5\n");
  
  int global_variable = 1;

  int local_variable = 2;
  //bool boolean_expression = true; ---- используется только в блоке 2
  
  {  // block 1
    int local_variable = 3;
    printf("[Block    1]: Global variable = %i, Local variable = %i\n", global_variable, local_variable);
    
    bool boolean_expression = true;
    if (boolean_expression) {  // block 2
      int local_variable = 4;
      printf("[Block    2]: Global variable = %i, Local variable = %i\n", global_variable, local_variable);
    }  // block 2

  }  // end block 1

  printf("[Main Block]: Global variable = %i, Local variable = %i\n", global_variable, local_variable);

  printf("[Lesson 1]: Visibility scope 5 [END]\n\n");
  return 0;
}  // end main block

