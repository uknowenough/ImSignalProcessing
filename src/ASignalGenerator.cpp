#include "ASignalGenerator.h"

ASignalGenerator::ASignalGenerator(Type type)
    : type_(type)
{

}

void ASignalGenerator::setSize(int size)
{
  size_ = size;

  signal_.clear();
  signal_.resize(size_);

  spectrum_.clear();
  spectrum_.resize(size_);

  xs_.clear();
  xs_.resize(size_);

  ys_.clear();
  ys_.resize(size_);

  xsp_.clear();
  xsp_.resize(size_);

  ysp_.clear();
  ysp_.resize(size_);

  this->generate();
}

void ASignalGenerator::setAmplitude(double amplitude)
{
  a_ = amplitude;

  this->generate();
}

void ASignalGenerator::setSignalFreq(double freq)
{
  f_ = freq;

  this->generate();
}

void ASignalGenerator::setSamplingFreq(double freq)
{
  fd_ = freq;

  this->generate();
}
