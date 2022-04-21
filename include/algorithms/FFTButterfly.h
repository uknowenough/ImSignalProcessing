#ifndef FFTBUTTERFLY_H
#define FFTBUTTERFLY_H

#include <complex>

class FFTButterfly
{
 public:
  enum class Direction {
    kDirect = 0,
    kInverse
  };

 public:
  FFTButterfly();

  void FourierTransform(std::complex<double> *signal, std::complex<double> *spectrum, int size, Direction type);
};

#endif // FFTBUTTERFLY_H
