#include "stdafx.h"
#include "LeapLibrary.h"

LeapLibrary::LeapLibrary(std::string&& libname) :
  libname(std::move(libname))
{}
