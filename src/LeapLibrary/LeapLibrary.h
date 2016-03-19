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

protected:
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

  struct entrypoint_name {
    template<typename T>
    entrypoint_name(const char* name, T*& pfn) :
      name(name),
      ppfn(reinterpret_cast<void**>(&pfn))
    {}

    const char* name;
    void** ppfn;
  };

  /// <summary>
  /// Utility method, loads all of the specified name and function pairs
  /// </summary>
  /// <remarks>
  /// Each of the passed load requests will be non-null on successful return.  If some entrypoints
  /// are missing, this function will throw an exception.
  /// </remarks>
  void LoadAll(std::initializer_list<entrypoint_name> names) const {
    for(const entrypoint_name& name : names) {
      *name.ppfn = Find(name.name);
      if(!*name.ppfn)
        throw std::runtime_error(std::string{ "Failed to find entrypoint " } + name.name);
    }
  }
};
