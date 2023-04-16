#include "config.h"

config * config::cptr  = nullptr;

config* config::get(){    
        if (cptr == nullptr)
        {
          cptr = new config();
        }
        return cptr;
}