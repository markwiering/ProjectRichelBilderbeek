#ifndef ALPHABETAGAMMAFILTER_H
#define ALPHABETAGAMMAFILTER_H

struct AlphaBetaGammaFilter
{
  AlphaBetaGammaFilter(
    const double alpha = 0.1 ,
    const double beta  = 0.01,
    const double gamma = 0.001,
    const double dt    = 1.0
  );

  double Estimate(const double measurement);

  private:
  double m_acceleration;
  const double m_alpha;
  const double m_beta;
  const double m_dt;
  const double m_gamma;
  double m_position;
  double m_velocity;
};

#endif // ALPHABETAGAMMAFILTER_H