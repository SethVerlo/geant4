// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4gsdeta.cc,v 1.2 1999/05/07 04:16:14 lockman Exp $
// GEANT4 tag $Name: geant4-00-01 $
//
#include "G3toG4.hh"
#include "G3DetTable.hh"

void PG4gsdeta(RWCString tokens[])
{
    // fill the parameter containers
    G3fillParams(tokens,PTgsdeta);

    // interpret the parameters
    G4String chset = Spar[0];
    G4String chdet = Spar[1];
    G4String chali = Spar[2];
    G4int nwhi = Ipar[0];
    G4int nwdi = Ipar[1];

    G4gsdeta(chset,chdet,chali,nwhi,nwdi);
}

void G4gsdeta(G4String chset, G4String chdet, G4String,
              G4int nwhi, G4int nwdi)
{
    G4int idtyp = G3Det.GetID(chset, chdet);
    // just associate another sensitive detector structure with
    // the volume chdet
    G4gsdetv(chset, chdet, idtyp, nwhi, nwdi);
}