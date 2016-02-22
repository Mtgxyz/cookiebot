#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include "cookiebot_conf.h"
#include <module_storage.hpp>
int main (int argc, char *argv[])
{
#ifdef USE_GZIP
  printf("I use GZip\n");
#endif
#ifdef USE_BZIP2
  printf("I use BZip2\n");
#endif
#ifdef USE_XZ
  printf("I use XZ\n");
#endif
  std::cout << getModuleStorage("test.gz") << std::endl;
  return 0;
}
