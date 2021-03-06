#ifndef GAPSFILLEDWHITENOISESYSTEM_H
#define GAPSFILLEDWHITENOISESYSTEM_H

#include <queue>
#include <boost/shared_ptr.hpp>

#include "whitenoisesystem.h"
#include "whitenoisesystemparameters.h"
#include "gapsfilledwhitenoisesystemparameters.h"

///A gaps-filled white noise system is a system that does not have a measurement every timestep.
///Instead, it has for example 1 measurement and then 4 non-measurements (which is a gap of 5)
///During the 4 non-measurements the 1 measurement is repeated
struct GapsFilledWhiteNoiseSystem : public WhiteNoiseSystem
{
  ///Obtain the gaps-filled white noise system parameters
  const boost::shared_ptr<const GapsFilledWhiteNoiseSystemParameters>& GetGapsFilledWhiteNoiseSystemParameters() const
    { return m_parameters; }

  ///Obtain the type as an enum
  WhiteNoiseSystemType GetType() const { return WhiteNoiseSystemType::gaps_filled; }

  ///Obtain the version of this class
  static const std::string GetVersion();

  ///Obtain the version history of this class
  static const std::vector<std::string> GetVersionHistory();

  ///Update reality, that is, let the real system (i.e. reality) go to its next state
  void GoToNextState(const boost::numeric::ublas::vector<double>& input);

  ///Measure a value from this system with normally distributed noise
  const boost::numeric::ublas::vector<double> Measure() const;

  ///Peek what the real value is
  const boost::numeric::ublas::vector<double>& PeekAtRealState() const;

  private:
  ///GapsFilledWhiteNoiseSystem must be created with a GapsFilledWhiteNoiseSystemFactory
  GapsFilledWhiteNoiseSystem(const boost::shared_ptr<const WhiteNoiseSystemParameters>& white_noise_system_parameters);
  friend class GapsFilledWhiteNoiseSystemFactory;

  ///Can only be deleted by boost::checked_delete
  ~GapsFilledWhiteNoiseSystem() {}
  friend void boost::checked_delete<>(GapsFilledWhiteNoiseSystem*);

  ///The last successfull measurement
  mutable boost::numeric::ublas::vector<double> m_last_measument;

  ///The gaps-filled white noise system parameters
  const boost::shared_ptr<const GapsFilledWhiteNoiseSystemParameters> m_parameters;

  ///The current timestep: zero denotes a measurement will be done
  mutable int m_timestep;

  #ifndef NDEBUG
  ///Test this class
  static void Test();
  #endif
};


#endif // GAPSFILLEDWHITENOISESYSTEM_H
