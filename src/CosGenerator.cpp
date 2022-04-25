#include "CosGenerator.h"

#include "algorithms/FFTButterfly.h"

CosGenerator::CosGenerator()
    : ASignalGenerator(Type::kCos)
{

}

void CosGenerator::generate()
{
  if (size_ <= 0)
    return;

  for (size_t i = 0; i < size_; ++i) {
    double w = 2 * M_PI * f_ / fd_; // относительная круговая частота
    xs_[i] = i;
    ys_[i] = a_ * cos(w * xs_[i]);

    signal_[i].real(ys_[i]);
  }

  FFTButterfly::FourierTransform(signal_.data(), spectrum_.data(), size_,
                                 FFTButterfly::Direction::kDirect);

  for (size_t i = 0; i < size_; ++i) {
    xsp_[i] = i;
    ysp_[i] = std::abs(spectrum_[i]);
  }
}
