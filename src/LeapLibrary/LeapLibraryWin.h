#pragma once
#include "LeapLibrary.h"

class LeapLibraryWin:
  public LeapLibrary
{
public:
  LeapLibraryWin(std::string&& libname);
  ~LeapLibraryWin(void);

private:
  HMODULE m_hLib;

public:
  // Base class overrides:
  entrypoint Find(const char* name) const override;
};
