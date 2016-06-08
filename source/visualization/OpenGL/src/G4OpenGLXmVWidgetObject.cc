// This code implementation is the intellectual property of
// the RD44 GEANT4 collaboration.
//
// By copying, distributing or modifying the Program (or any work
// based on the Program) you indicate your acceptance of this statement,
// and all its terms.
//
// $Id: G4OpenGLXmVWidgetObject.cc,v 1.2 1999/01/09 16:23:47 allison Exp $
// GEANT4 tag $Name: geant4-00-01 $
//
//Virtual base class for all Motif widgets.

#ifdef G4VIS_BUILD_OPENGLXM_DRIVER

#include "G4OpenGLXmVWidgetObject.hh"

G4OpenGLXmVWidgetObject::G4OpenGLXmVWidgetObject ()
{}

G4OpenGLXmVWidgetObject::~G4OpenGLXmVWidgetObject ()
{}

G4OpenGLXmViewer* G4OpenGLXmVWidgetObject::GetView ()
{
  return pView;
}

void G4OpenGLXmVWidgetObject::ProcesspView () 
{
  cmap = pView->cmap;
  depth = pView->vi->depth;
  visual = pView->vi->visual;
  borcol = pView->borcol;
  bgnd = pView->bgnd;
  top = pView->toplevel;
}

#endif