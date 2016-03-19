#include "stdafx.h"
#include "LeapLibraryWin.h"

LeapLibraryWin::LeapLibraryWin(std::string&& libname) :
  LeapLibrary(std::move(libname))
{
  m_hLib = LoadLibrary(this->libname.c_str());
  if (!m_hLib)
    throw std::runtime_error("Could not find the specified library");
}

LeapLibraryWin::~LeapLibraryWin(void) {
  if (m_hLib)
    FreeLibrary(m_hLib);
}

std::unique_ptr<LeapLibrary> LeapLibrary::New(const char* libname) {
  try {
    return std::unique_ptr<LeapLibrary> { new LeapLibraryWin{ libname } };
  }
  catch (...) {
    return nullptr;
  }
}

LeapLibrary::entrypoint LeapLibraryWin::Find(const char* name) const {
  return{ GetProcAddress(m_hLib, name) };
}
