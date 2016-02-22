
#define CHUNK 16384
#include <module_storage.hpp>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "cookiebot_conf.h"
#include <iostream>
#if USE_GZIP == ON
#include <zlib.h>
#endif
auto getModuleStorage(std::string filename) -> std::string {
  std::string::size_type idx;
  idx = filename.rfind('.');

  if(idx != std::string::npos)
  {
      std::string extension = filename.substr(idx+1);
#if USE_GZIP == ON
      if(extension=="gz") {
        FILE *out;
        out=fopen(filename.substr(0,idx).c_str(), "wb");
        struct gzFile_s *file = gzopen(filename.c_str(),"rb");
        size_t len=1024*1024;
        gzrewind(file);
        uint8_t *buf=new uint8_t[len];
        gzread(file, (void*)buf, len);
        std::cout << buf << std::endl;
        fwrite((void*)buf, len, 1, out);
        gzclose(file);
        fclose(out);
        delete[] buf;
        return filename.substr(0,idx);
      }
#endif
      return filename;
  }
  else
  {
      return nullptr;
  }
}
