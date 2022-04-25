#ifndef SIGNALGENERATOR_H
#define SIGNALGENERATOR_H

#include <vector>
#include <complex>

class ASignalGenerator
{
 public:
  enum class Type {
    kSin = 0,
    kCos
  };

 public:
  ASignalGenerator(Type type);

  virtual std::string name() = 0;

  ///
  /// Setter / Getter
  ///

  virtual void setSize(int size);
  int size() const { return size_; }

  virtual void setAmplitude(double amplitude);
  double amplitude() const { return a_; }

  virtual void setSignalFreq(double freq);
  double signalFreq() const { return f_; }

  virtual void setSamplingFreq(double freq);
  double samplingFreq() const { return fd_; }

  const std::vector<std::complex<double>>& signal() const { return signal_; }
  const std::vector<std::complex<double>>& spectrum() const { return spectrum_; }

  const std::vector<float>& signal_x() const { return xs_; }
  const std::vector<float>& signal_y() const { return ys_; }

  const std::vector<float>& spectrum_x() const { return xsp_; }
  const std::vector<float>& spectrum_y() const { return ysp_; }


 private:

  virtual void generate() = 0;

 protected:
  //! Type of generated signal
  Type type_;
  //! Array size
  int size_ = 0;
  //! Signal amplitude
  double a_;
  //! Signal frequency
  double f_;
  //! Sampling frequency
  double fd_;
  //! Signal
  std::vector<std::complex<double>> signal_;

  std::vector<float> xs_, ys_;
  //! Spectrum
  std::vector<std::complex<double>> spectrum_;

  std::vector<float> xsp_, ysp_;
};

#endif // SIGNALGENERATOR_H
