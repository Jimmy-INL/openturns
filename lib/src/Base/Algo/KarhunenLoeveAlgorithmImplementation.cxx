//                                               -*- C++ -*-
/**
 *  @brief Karhunen-Loeve decomposition and projection
 *
 *  Copyright 2005-2016 Airbus-EDF-IMACS-Phimeca
 *
 *  This library is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

#include "openturns/PersistentObjectFactory.hxx"
#include "openturns/KarhunenLoeveAlgorithmImplementation.hxx"

BEGIN_NAMESPACE_OPENTURNS

CLASSNAMEINIT(KarhunenLoeveAlgorithmImplementation);

static const Factory<KarhunenLoeveAlgorithmImplementation> Factory_KarhunenLoeveAlgorithmImplementation;

/* Default constructor */
KarhunenLoeveAlgorithmImplementation::KarhunenLoeveAlgorithmImplementation()
  : PersistentObject()
  , covariance_()
  , threshold_(0.0)
  , result_()
{
  // Nothing to do
}

/* Default constructor */
KarhunenLoeveAlgorithmImplementation::KarhunenLoeveAlgorithmImplementation(const CovarianceModel & covariance,
									   const NumericalScalar threshold)
  : PersistentObject()
  , covariance_(covariance)
  , threshold_(threshold)
  , result_()
{
  // Nothing to do
}

/* Virtual constructor */
KarhunenLoeveAlgorithmImplementation * KarhunenLoeveAlgorithmImplementation::clone() const
{
  return new KarhunenLoeveAlgorithmImplementation(*this);
}

/* Threshold accessors */
NumericalScalar KarhunenLoeveAlgorithmImplementation::getThreshold() const
{
  return threshold_;
}

void KarhunenLoeveAlgorithmImplementation::setThreshold(const NumericalScalar threshold)
{
  threshold_ = threshold;
}

/* Covariance model accessors */
CovarianceModel KarhunenLoeveAlgorithmImplementation::getCovarianceModel() const
{
  return covariance_;
}

void KarhunenLoeveAlgorithmImplementation::setCovarianceModel(const CovarianceModel & covariance)
{
  covariance_ = covariance;
}

/* Result accessor */
KarhunenLoeveResult KarhunenLoeveAlgorithmImplementation::getResult() const
{
  return result_;
}

/* Compute the decomposition */
void KarhunenLoeveAlgorithmImplementation::run()
{
  throw NotYetImplementedException(HERE) << "In KarhunenLoeveAlgorithmImplementation::run()";
}

/* String converter */
String KarhunenLoeveAlgorithmImplementation::__repr__() const
{
  return OSS(true) << "class=" << getClassName()
		   << " covariance model=" << covariance_
		   << " threshold=" << threshold_
		   << " result=" << result_;
}

String KarhunenLoeveAlgorithmImplementation::__str__(const String & offset) const
{
  return __repr__();
}

/* Method save() stores the object through the StorageManager */
void KarhunenLoeveAlgorithmImplementation::save(Advocate & adv) const
{
  PersistentObject::save(adv);
  adv.saveAttribute("covariance_", covariance_);
  adv.saveAttribute("threshold_", threshold_);
  adv.saveAttribute("result_", result_);
}


/* Method load() reloads the object from the StorageManager */
void KarhunenLoeveAlgorithmImplementation::load(Advocate & adv)
{
  PersistentObject::load(adv);
  adv.loadAttribute("covariance_", covariance_);
  adv.loadAttribute("threshold_", threshold_);
  adv.loadAttribute("result_", result_);
}


END_NAMESPACE_OPENTURNS