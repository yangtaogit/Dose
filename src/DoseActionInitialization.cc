//
/// \file DoseActionInitialization.cc
/// \brief Implementation of the DoseActionInitialization class

#include "DoseActionInitialization.hh"
#include "DosePrimaryGeneratorAction.hh"
#include "DoseRunAction.hh"
#include "DoseEventAction.hh"
#include "DoseSteppingAction.hh"
#include "DoseDetectorConstruction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DoseActionInitialization::DoseActionInitialization
                          (DoseDetectorConstruction* detConstruction)
 : G4VUserActionInitialization(),
   fDetConstruction(detConstruction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DoseActionInitialization::~DoseActionInitialization()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DoseActionInitialization::BuildForMaster() const
{
  DoseRunAction* runAction = new DoseRunAction;
  SetUserAction(runAction);
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DoseActionInitialization::Build() const
{
  SetUserAction(new DosePrimaryGeneratorAction);

  DoseRunAction* runAction = new DoseRunAction;
  SetUserAction(runAction);
  
  DoseEventAction* eventAction = new DoseEventAction(runAction);
  SetUserAction(eventAction);
  
  SetUserAction(new DoseSteppingAction(fDetConstruction,eventAction));
}  

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
