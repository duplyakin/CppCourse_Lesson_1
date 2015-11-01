#include <cstdio>
#include <cstring>
#include "logger.h"

/* Stack */
// ----------------------------------------------------------------------------
int head = 0;
int stack[SIZE];

void push(int i) {
  if (head == SIZE) {
    ERR("Stack overflow!");
    return;
  }

  stack[head++] = i;
}

void pop() {
  if (head == 0) {
    ERR("Stack underflow!");
    return;
  }

  --head;
}

void printStack() {
  for (int i = 0; i < head; ++i) {
    printf("%i ", stack[i]);
  }
  printf("\n");
}

int* maxInStack() {
  int* max = nullptr; 

  for (int i=0; i<head; ++i) {
    if (i==0) {
      max = &stack[0];
    }
    if (stack[i]>(*max)) {
      max = &stack[i];
    }
  }
  return max;
}

/* Interface */
// ----------------------------------------------------------------------------
const char* PUSH = "push";
const char* POP = "pop";
const char* PRINT = "print";
const char* MAXINSTACK = "max";
const char* EXIT = "exit";

bool evaluate(char* command) {
  if (strcmp(PUSH, command) == 0) {// если строки совпадают, то возвращаем 0
    int value = 0;
    printf("value = ");
    scanf("%i", &value);
    push(value);
  } else if (strcmp(POP, command) == 0) {
    pop();
  } else if (strcmp(PRINT, command) == 0) {
    printStack();
  } else if (strcmp(MAXINSTACK, command) == 0) {
    int* max = maxInStack();
    if (max == nullptr) {
      ERR("Stack is empty!");    
    } else {
      printf("Max = %d", *max);
      printf("\n"); 
    } 
  } else if (strcmp(EXIT, command) == 0) {
    return false;
  } else {
    WRN("Undefined command: %s", command);
  }
  return true;
}

/* Main */
// ----------------------------------------------------------------------------
int main(int argc, char** argv) {
  DBG("[Lesson 1]: Arrays 8");

  char command[5];
  do {
    scanf("%s", command);
  } while (evaluate(command));

  DBG("[Lesson 1]: Arrays 8 [END]");
  return 0;
}
