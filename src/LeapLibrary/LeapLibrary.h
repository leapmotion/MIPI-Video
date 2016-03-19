#pragma once
#include <memory>
#include <string>

/// <summary>
/// Represents a library loaded by the system
/// </summary>
class LeapLibrary {
public:
  LeapLibrary(std::string&& libname);
  virtual ~LeapLibrary(void) = default;

  /// <summary>
  /// Loads a library with the given name
  /// </summary>
  /// <returns>
  /// The newly opened library, or nullptr if the library was not found
  /// </returns>
  static std::unique_ptr<LeapLibrary> New(const char* libname);

private:
  std::string libname;

public:
  struct entrypoint {
    void* ptr;

    template<typename T>
    operator T*(void) const {
      return static_cast<T*>(ptr);
    }
  };

  /// <summary>
  /// Finds an entrypoint with the specified name
  /// </summary>
  /// <returns>
  /// The address, or nullptr if it was not found
  /// </returns>
  virtual entrypoint Find(const char* name) const = 0;
};
