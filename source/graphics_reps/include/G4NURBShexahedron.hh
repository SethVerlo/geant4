// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4NURBShexahedron.hh,v 1.3 1999/05/19 08:33:39 stesting Exp $
// GEANT4 tag $Name: geant4-00-01 $
//
// Hexa hedron builder prototype
// OC 17 9 96

#include "G4NURBS.hh"

#include "G4ThreeVector.hh"


#ifndef __C_G4NURBShexahedron__

#define __C_G4NURBShexahedron__ 1 

class	G4NURBShexahedron : public G4NURBS
	{
	
	// imagine the hexahedron is just a box, then
	// the eight corners must be given in the following order :
	//  DX  DY -DZ
	// -DX  DY -DZ
	// -DX -DY -DZ
	//  DX -DY -DZ
	//  DX  DY  DZ 
	// -DX  DY  DZ
	// -DX -DY  DZ
	//  DX -DY  DZ
 	// (ie, with Oz pointing to you, Ox on the right, Oy on the top:
	//  from the rear, from the upper right corner to the lower one
	// in anticlockwise sens, then the same for front side)

	public:
	  G4NURBShexahedron(const G4ThreeVector Corners [8]);
	  virtual G4Visible&  operator = (const G4Visible& right);
	  virtual G4VVisPrim& operator = (const G4VVisPrim& right);
	  const char*	Whoami() const;
	};

#endif
// end of __C_G4NURBShexahedron__



