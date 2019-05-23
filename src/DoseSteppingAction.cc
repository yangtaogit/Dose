//
/// \file DoseSteppingAction.cc
//

#include "DoseSteppingAction.hh"
#include "DoseEventAction.hh"
#include "DoseDetectorConstruction.hh"

#include "G4Step.hh"
#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4LogicalVolume.hh"
#include "DoseDetectorConstruction.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DoseSteppingAction::DoseSteppingAction( const DoseDetectorConstruction* detectorConstruction,
                                        DoseEventAction* eventAction)
: G4UserSteppingAction(),
  fDetConstruction(detectorConstruction),
  fEventAction(eventAction)
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DoseSteppingAction::~DoseSteppingAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DoseSteppingAction::UserSteppingAction(const G4Step* step)
{
  
  G4double edep = step->GetTotalEnergyDeposit();
  G4StepPoint* point_pre  = step->GetPreStepPoint() ;
  G4StepPoint* point_post = step->GetPostStepPoint() ;
  G4ThreeVector point_in  = point_pre->GetPosition();
  G4ThreeVector point_out = point_post->GetPosition();
   
  auto volume = step->GetPreStepPoint()->GetTouchableHandle()->GetVolume();
  auto volume_name = volume->GetName();

  fEventAction->RecordTotal(edep);

  if( volume_name == "Head"){

    fEventAction->RecordHead(edep,
                                 point_in[0], point_in[1], point_in[2],
                                 point_out[0], point_out[1],point_out[2]);

  }

  if( volume_name == "Chest"){
    fEventAction->RecordChest(edep,
                                 point_in[0], point_in[1], point_in[2],
                                 point_out[0], point_out[1],point_out[2]);
  }

  if( volume_name == "Neck"){
    fEventAction->RecordNeck(edep);
  }

  if( volume_name == "ArmL"){
    fEventAction->RecordArmL(edep);
  }

  if( volume_name == "ArmR"){
    fEventAction->RecordArmR(edep);
  }
 
  if( volume_name == "LegL"){
    fEventAction->RecordLegL(edep);
  }

  if( volume_name == "LegR"){
    fEventAction->RecordLegR(edep);
  }
  


}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

