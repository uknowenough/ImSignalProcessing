#ifndef COSGENERATOR_H
#define COSGENERATOR_H

#include <ASignalGenerator.h>

class CosGenerator : public ASignalGenerator
{
 public:
  CosGenerator();

  virtual std::string name() override { return std::string("cos(x)"); }

 private:

  virtual void generate() override;
};

#endif // COSGENERATOR_H
