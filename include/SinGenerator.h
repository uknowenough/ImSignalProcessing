#ifndef SINGENERATOR_H
#define SINGENERATOR_H

#include "ASignalGenerator.h"

class SinGenerator : public ASignalGenerator
{
 public:
  SinGenerator();

  virtual std::string name() override { return std::string("sin(x)"); }

 private:

  virtual void generate() override;
};

#endif // SINGENERATOR_H
