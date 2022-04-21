#include "algorithms/FFTButterfly.h"

FFTButterfly::FFTButterfly()
{

}

void FFTButterfly::FourierTransform(std::complex<double> *signal,
                                    std::complex<double> *spectrum,
                                    int size, Direction type)
{
  using std::complex;

  int typeTransform = 0;
  if (type == Direction::kDirect)
    typeTransform = -1;
  else
    typeTransform = 1;
  //
  //
  //
  int M = log2(size); // Количество слоев
  //
  // Декомпозиция
  //
  std::complex<double> *tSignalA = new std::complex<double>[size];
  std::complex<double> *tSignalB = new std::complex<double>[size];

  for (int i = 0; i < size; i++)
    tSignalA[i] = signal[i];

  int N = 0;
  for (int k = 0; k < M; k++) {
    if (k != 0)
      N = size / pow(2, k);
    else
      N = size;
    int c = N / 2;
    for (int w = 0; w < pow(2, k); w++) {
      int j = N * w;
      for (int i = w * N; i < (N + w * N); i++) {
        if (i % 2 == 0)
          tSignalB[j] = tSignalA[i];
        else {
          tSignalB[j + c] = tSignalA[i];
          j++;
        }
      }
    }

    for (int i = 0; i < size; i++)
      tSignalA[i] = tSignalB[i];
  }
  //
  // Синтез
  //
  std::complex<double> *pSpectrumTemp = new complex<double>[size];

  for (int i = 0; i < size; i++)
    spectrum[i] = tSignalA[i];

  for (int k = M - 1; k > -1; k--) {
    if (k != 0)
      N = size / pow(2, k);
    else
      N = size;
    int c = N / 2;
    for (int w = 0; w < pow(2, k); w++) {
      for (int i = w * N; i < (c + w * N); i++) {
        complex<double> pTemp(cos(typeTransform * (2 * M_PI / N * i)), sin(typeTransform * (2 * M_PI / N * i)));
        pSpectrumTemp[i] = spectrum[i] + pTemp * spectrum[i + c];
        pSpectrumTemp[i + c] = spectrum[i] - pTemp * spectrum[i + c];
      }
    }

    for (int i = 0; i < size; i++)
      spectrum[i] = pSpectrumTemp[i];
  }

  delete[] tSignalA;
  delete[] tSignalB;
  delete[] pSpectrumTemp;
}
