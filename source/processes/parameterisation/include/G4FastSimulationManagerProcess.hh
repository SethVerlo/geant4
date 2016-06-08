// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4FastSimulationManagerProcess.hh,v 1.3 1999/04/28 10:06:39 mora Exp $
// GEANT4 tag $Name: geant4-00-01 $
//
// 
//---------------------------------------------------------------
//
//  G4FastSimulationManagerProcess.hh
//
//  Description:
//    The process that triggers parameterised simulations
//    if any.
//
//  History:
//  Feb 98: Parallel geometry sensitivity. MoraDeFreitas.
//  Oct 97: "Fast" replaces "Parameterisation" in class/method names. 
//          (release B.00 for parameterisation). MoraDeFreitas.
//  Aug 97: First implementation. Verderi && MoraDeFreitas.
//  Apr 98: modified for new particle change.  H.Kurashige
//
//---------------------------------------------------------------


#ifndef G4FastSimulationManagerProcess_h
#define G4FastSimulationManagerProcess_h 1

#include <rw/tpordvec.h>

#include "globals.hh"
#include "G4VProcess.hh"
#include "G4FastSimulationManager.hh"
#include "G4Step.hh"
#include "G4Navigator.hh"
#include "G4PropagatorInField.hh"
#include "G4VTouchable.hh"
#include "G4TouchableHistory.hh"
#include "G4VPhysicalVolume.hh"
#include "G4VParticleChange.hh"

//------------------------------------------
//
//        G4FastSimulationManagerProcess class
//
//------------------------------------------
class G4FastSimulationManagerProcess : public G4VProcess
{
public:

  //------------------------
  // Constructor/Destructor
  //------------------------
  
  G4FastSimulationManagerProcess(const G4String& 
				 processName = 
				 "G4FastSimulationManagerProcess",
				 G4ProcessType
				 theType = fParameterisation);
  virtual ~G4FastSimulationManagerProcess();
  
  //--------------------------------------------------------------
  //     Process interface
  //--------------------------------------------------------------

  void StartTracking();
  
  //---------------------------------------------------
  // GetPhysicalInteractionLength() and DoIt() methods:
  //---------------------------------------------------
  
  G4double PostStepGetPhysicalInteractionLength(const G4Track& track,
						G4double   previousStepSize,
						G4ForceCondition* condition);
  
  G4VParticleChange* PostStepDoIt(const G4Track& ,const G4Step& );

  //------------------------------------------------------------------------
  // GetPhysicalInteractionLength() and DoIt() methods for AtRest particles:
  //------------------------------------------------------------------------
  
  G4double AtRestGetPhysicalInteractionLength(
					      const G4Track& ,
					      G4ForceCondition* 
					      );

  G4VParticleChange* AtRestDoIt(
			       const G4Track& ,
			       const G4Step&
			       );


  // -- no operation in AlongStepDoIt --
  G4double AlongStepGetPhysicalInteractionLength(
						 const G4Track&,
						 G4double  ,
						 G4double  ,
						 G4double&,
						 G4GPILSelection*
						 );
  G4VParticleChange* AlongStepDoIt(
				  const G4Track& ,
				  const G4Step& 
				  );


private:
  // When trigged, the *fFastSimulationManager holds
  // the pointer used to call the DoIt() method.
  G4FastSimulationManager* fFastSimulationManager;
  G4bool                   fFastSimulationTrigger;
  // this G4VParticleChange is used only when the safety limites the Step.
  G4VParticleChange aDummyParticleChange;
  G4ParticleChange xParticleChange;

  // Flags that the track is starting
  G4bool fStartTracking;

  // -------------------------------
  // Navigation in the Ghost World:
  // -------------------------------
  // Current parallel "ghost" world, related Navigator
  // and touchable history:
  G4VPhysicalVolume*   fGhostWorld;
  G4Navigator          fGhostNavigator;
  G4TouchableHistory*  fGhostTouchable;
  G4bool               fUpdateGhostTouchable;
  G4bool               fOutOfGhostWorld;
  // Isotropic safety value to the next ghost volume
  // and allowed Step length:
  G4double             fGhostSafety,
                       fGhostStepLength;
  // Navigation with field:
  G4PropagatorInField* fGhostFieldPropagator;
  G4double             fParticleCharge;
  G4bool               fFieldExertsForce;

  // Tracking Navigation used in PostStep, in case of mag-field:
  G4Navigator          fTrackingNavigator;
  G4TouchableHistory   fTrackingHistory;

  // ******************************************************
  // ******************************************************
  //
  //  For TESTS:
  //
  // ******************************************************
  // ******************************************************
public:
  G4double GetPreSafety() {return fPreSafety;}
  G4double GetPreLinearSafety() {return fPreLinearSafety;}
  G4double GetSafety() {return fGhostSafety;}
  G4double GetLinearSafety() {return fGhostStepLength;}
  void Verbose() const;
private:
  G4double fPreSafety, fPreLinearSafety;
};

#endif