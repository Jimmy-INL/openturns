//                                               -*- C++ -*-
/**
 *  @brief The Triangular distribution
 *
 *  Copyright 2005-2019 Airbus-EDF-IMACS-Phimeca
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
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with this library.  If not, see <http://www.gnu.org/licenses/>.
 *
 */
#ifndef OPENTURNS_TRIANGULAR_HXX
#define OPENTURNS_TRIANGULAR_HXX

#include "openturns/OTprivate.hxx"
#include "openturns/ContinuousDistribution.hxx"

BEGIN_NAMESPACE_OPENTURNS

/**
 * @class Triangular
 *
 * The Triangular distribution.
 */
class OT_API Triangular
  : public ContinuousDistribution
{
  CLASSNAME
public:

  /** Default constructor */
  Triangular();

  /** Parameters constructor */
  Triangular(const Scalar a,
             const Scalar m,
             const Scalar b);


  /** Comparison operator */
  Bool operator ==(const Triangular & other) const;
protected:
  Bool equals(const DistributionImplementation & other) const;
public:

  /** String converter */
  String __repr__() const;
  String __str__(const String & offset = "") const;



  /* Interface inherited from Distribution */

  /** Virtual constructor */
  virtual Triangular * clone() const;

  /** Get one realization of the Triangular distribution */
  Point getRealization() const;

  /** Get the DDF of the Triangular distribution */
  using ContinuousDistribution::computeDDF;
  Point computeDDF(const Point & point) const;

  /** Get the PDF of the Triangular distribution */
  using ContinuousDistribution::computePDF;
  Scalar computePDF(const Scalar scalar) const;
  Scalar computePDF(const Point & point) const;

  /** Get the CDF of the Triangular distribution */
  using ContinuousDistribution::computeCDF;
  Scalar computeCDF(const Scalar scalar) const;
  Scalar computeCDF(const Point & point) const;

  /** Get the characteristic function of the distribution, i.e. phi(u) = E(exp(I*u*X)) */
  Complex computeCharacteristicFunction(const Scalar x) const;
  Complex computeLogCharacteristicFunction(const Scalar x) const;

  /** Get the PDFGradient of the Triangular distribution */
  using ContinuousDistribution::computePDFGradient;
  Point computePDFGradient(const Point & point) const;

  /** Get the CDFGradient of the Triangular distribution */
  using ContinuousDistribution::computeCDFGradient;
  Point computeCDFGradient(const Point & point) const;

  /** Compute the entropy of the distribution */
  Scalar computeEntropy() const;

  /** Get the roughness, i.e. the L2-norm of the PDF */
  Scalar getRoughness() const;

  /** Get the standard deviation of the distribution */
  Point getStandardDeviation() const;

  /** Get the skewness of the distribution */
  Point getSkewness() const;

  /** Get the kurtosis of the distribution */
  Point getKurtosis() const;

  /** Get the raw moments of the standardized distribution */
  Point getStandardMoment(const UnsignedInteger n) const;

  /** Get the standard representative in the parametric family, associated with the standard moments */
  Distribution getStandardRepresentative() const;

  /** Parameters value accessors */
  void setParameter(const Point & parameter);
  Point getParameter() const;

  /** Parameters description accessor */
  Description getParameterDescription() const;

  /** Check if the distribution is elliptical */
  Bool isElliptical() const;

  /* Interface specific to Triangular */

  /** A accessor */
  void setAMB(const Scalar a,
              const Scalar m,
              const Scalar b);
  Scalar getA() const;

  /** M accessor */
  Scalar getM() const;

  /** B accessor */
  Scalar getB() const;

  /** Get the PDF singularities inside of the range - 1D only */
  Point getSingularities() const;

  /** Method save() stores the object through the StorageManager */
  void save(Advocate & adv) const;

  /** Method load() reloads the object from the StorageManager */
  void load(Advocate & adv);


protected:

private:

  /** Compute the mean of the distribution */
  void computeMean() const;

  /** Compute the covariance of the distribution */
  void computeCovariance() const;

  /** Get the quantile of the Triangular distribution */
  Scalar computeScalarQuantile(const Scalar prob,
                               const Bool tail = false) const;

  /** Compute the numerical range of the distribution given the parameters values */
  void computeRange();

  /** The main parameter set of the distribution */
  Scalar a_;
  Scalar m_;
  Scalar b_;

}; /* class Triangular */


END_NAMESPACE_OPENTURNS

#endif /* OPENTURNS_TRIANGULAR_HXX */
