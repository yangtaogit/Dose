//
/// \file DoseSteppingAction.hh
/// \brief Definition of the DoseSteppingAction class

#ifndef DoseSteppingAction_h
#define DoseSteppingAction_h 1

#include "G4UserSteppingAction.hh"
#include "globals.hh"
#include "DoseDetectorConstruction.hh"

class DoseEventAction;
class G4Step;


/// Stepping action class
/// 

class DoseSteppingAction : public G4UserSteppingAction
{
  public:
    DoseSteppingAction( const DoseDetectorConstruction* detectorConstruction,
                        DoseEventAction* eventAction);
    virtual ~DoseSteppingAction();

    // method from the base class
    virtual void UserSteppingAction(const G4Step*);

  private:
    const DoseDetectorConstruction* fDetConstruction;
    DoseEventAction*  fEventAction;
};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif
