#pragma once
#include "Singleton.h"

template <typename T>
class Logger : public Singleton<Logger>
{
public:
  void WriteToLog() {}
private:
  friend class Singleton<Logger>;
  Logger() = default;
};
