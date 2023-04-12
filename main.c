#include <stdio.h>
#include <stdlib.h>

#include "storage.h"

int main(int argc, char* argv[], char *envp[]){
  int rc = EXIT_SUCCESS;
  fprintf(stdout, "%s: hello world!\n", argv[0]);

  //void* address;
  if(storage_create("kouros.storage", 0x1000) != 0) rc = EXIT_FAILURE;
  //storage_open("kouros.storage", address, 0x1000);

  return rc;
}