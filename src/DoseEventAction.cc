//
/// \file DoseEventAction.cc
//

#include "DoseEventAction.hh"
#include "DoseRunAction.hh"
#include "DoseAnalysis.hh"

#include "G4Event.hh"
#include "G4RunManager.hh"
#include "G4ThreeVector.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DoseEventAction::DoseEventAction(DoseRunAction* runAction)
: G4UserEventAction(),
  fRunAction(runAction)
{} 

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DoseEventAction::~DoseEventAction()
{}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DoseEventAction::BeginOfEventAction(const G4Event* event)
{    
    G4int eventID = event->GetEventID();
    G4cout << "\n---> Begin of event: " << eventID << G4endl;

    edep_total=0.;
    edep_head=0., edep_neck=0., edep_chest=0.;
    edep_arm_l=0., edep_arm_r=0.;
    edep_leg_l=0., edep_leg_r=0.;

    x_head=0, y_head=0, z_head=0;
    x_chest=0, y_chest=0, z_chest=0;

    x_EdepC_head=0, y_EdepC_head=0, z_EdepC_head=0;
    x_EdepC_chest=0, y_EdepC_chest=0, z_EdepC_chest=0;

    //Note : Only one particle emits per event
    primary_direction = event->GetPrimaryVertex(event->GetNumberOfPrimaryVertex()-1)->GetPrimary()->GetMomentumDirection();
    // px = event->GetPrimaryVertex(0)->GetPrimary()->GetPx();
    // py = event->GetPrimaryVertex(0)->GetPrimary()->GetPy();
    // pz = event->GetPrimaryVertex(0)->GetPrimary()->GetPz();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DoseEventAction::EndOfEventAction(const G4Event* event)
{   
    G4int eventID = event->GetEventID();

    x_head = x_EdepC_head/edep_head;
    y_head = y_EdepC_head/edep_head;
    z_head = z_EdepC_head/edep_head;

    x_chest = x_EdepC_head/edep_chest;
    y_chest = y_EdepC_head/edep_chest;
    z_chest = z_EdepC_head/edep_chest;

    auto analysisManager = G4AnalysisManager::Instance();
    analysisManager->FillNtupleDColumn(0, eventID);

    analysisManager->FillNtupleDColumn(1, edep_total);
    analysisManager->FillNtupleDColumn(2, edep_head);
    analysisManager->FillNtupleDColumn(3, edep_neck);
    analysisManager->FillNtupleDColumn(4, edep_chest);
    analysisManager->FillNtupleDColumn(5, edep_arm_l);
    analysisManager->FillNtupleDColumn(6, edep_arm_r);
    analysisManager->FillNtupleDColumn(7, edep_leg_l);
    analysisManager->FillNtupleDColumn(8, edep_leg_r);

    analysisManager->FillNtupleDColumn(9, x_head);
    analysisManager->FillNtupleDColumn(10, y_head);
    analysisManager->FillNtupleDColumn(11, z_head);

    analysisManager->FillNtupleDColumn(9, x_chest);
    analysisManager->FillNtupleDColumn(10, y_chest);
    analysisManager->FillNtupleDColumn(11, z_chest);

    analysisManager->FillNtupleDColumn(12, primary_direction[0]);
    analysisManager->FillNtupleDColumn(13, primary_direction[1]);
    analysisManager->FillNtupleDColumn(14, primary_direction[2]);

    analysisManager->AddNtupleRow();


    G4cout << "\n---> End of event: " << eventID << G4endl;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
