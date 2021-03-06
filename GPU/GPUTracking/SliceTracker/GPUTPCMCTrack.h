//**************************************************************************\
//* This file is property of and copyright by the ALICE Project            *\
//* ALICE Experiment at CERN, All rights reserved.                         *\
//*                                                                        *\
//* Primary Authors: Matthias Richter <Matthias.Richter@ift.uib.no>        *\
//*                  for The ALICE HLT Project.                            *\
//*                                                                        *\
//* Permission to use, copy, modify and distribute this software and its   *\
//* documentation strictly for non-commercial purposes is hereby granted   *\
//* without fee, provided that the above copyright notice appears in all   *\
//* copies and that both the copyright notice and this permission notice   *\
//* appear in the supporting documentation. The authors make no claims     *\
//* about the suitability of this software for any purpose. It is          *\
//* provided "as is" without express or implied warranty.                  *\
//**************************************************************************

/// \file GPUTPCMCTrack.h
/// \author Sergey Gorbunov, Ivan Kisel, David Rohr

#ifndef GPUTPCMCTRACK_H
#define GPUTPCMCTRACK_H

#include "GPUTPCDef.h"

class TParticle;

/**
 * @class GPUTPCMCTrack
 * store MC track information for GPUTPCPerformance
 */
class GPUTPCMCTrack
{
 public:
  GPUTPCMCTrack();
  GPUTPCMCTrack(const TParticle* part);

  void SetTPCPar(float X, float Y, float Z, float Px, float Py, float Pz);

  int PDG() const { return fPDG; }
  const double* Par() const { return fPar; }
  const double* TPCPar() const { return fTPCPar; }
  double P() const { return fP; }
  double Pt() const { return fPt; }

  int NHits() const { return mNHits; }
  int NMCPoints() const { return fNMCPoints; }
  int FirstMCPointID() const { return fFirstMCPointID; }
  int NReconstructed() const { return fNReconstructed; }
  int Set() const { return fSet; }
  int NTurns() const { return fNTurns; }

  void SetP(float v) { fP = v; }
  void SetPt(float v) { fPt = v; }
  void SetPDG(int v) { fPDG = v; }
  void SetPar(int i, double v) { fPar[i] = v; }
  void SetTPCPar(int i, double v) { fTPCPar[i] = v; }
  void SetNHits(int v) { mNHits = v; }
  void SetNMCPoints(int v) { fNMCPoints = v; }
  void SetFirstMCPointID(int v) { fFirstMCPointID = v; }
  void SetNReconstructed(int v) { fNReconstructed = v; }
  void SetSet(int v) { fSet = v; }
  void SetNTurns(int v) { fNTurns = v; }

 protected:
  int fPDG;            //* particle pdg code
  double fPar[7];      //* x,y,z,ex,ey,ez,q/p
  double fTPCPar[7];   //* x,y,z,ex,ey,ez,q/p at TPC entrance (x=y=0 means no information)
  double fP, fPt;      //* momentum and transverse momentum
  int mNHits;          //* N TPC clusters
  int fNMCPoints;      //* N MC points
  int fFirstMCPointID; //* id of the first MC point in the points array
  int fNReconstructed; //* how many times is reconstructed
  int fSet;            //* set of tracks 0-OutSet, 1-ExtraSet, 2-RefSet
  int fNTurns;         //* N of turns in the current sector
};

#endif // GPUTPCMCTrack
