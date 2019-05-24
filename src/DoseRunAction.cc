
//
/// \file DoseRunAction.cc
//

#include "DoseRunAction.hh"
#include "DosePrimaryGeneratorAction.hh"
#include "DoseDetectorConstruction.hh"
#include "DoseAnalysis.hh"

#include "G4RunManager.hh"
#include "G4Run.hh"
#include "G4AccumulableManager.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4LogicalVolume.hh"
#include "G4SystemOfUnits.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DoseRunAction::DoseRunAction()
: G4UserRunAction(),
  fTotalEdep(0.)
{ 
  // set printing event number per each event
  G4RunManager::GetRunManager()->SetPrintProgress(1);


  // Create analysis manager
  // The choice of analysis technology is done via selectin of a namespace
  // in DoseAnalysis.hh
  auto analysisManager = G4AnalysisManager::Instance();
  G4cout << "Using " << analysisManager->GetType() << G4endl;
  analysisManager->SetVerboseLevel(1);
  analysisManager->SetNtupleMerging(true);
  // Note: merging ntuples is available only with Root output

  // Creating ntuple
  analysisManager->CreateNtuple("Dose", "Energe deposition in human body");
  analysisManager->CreateNtupleDColumn("EventID");

  analysisManager->CreateNtupleDColumn("edep_total");
  analysisManager->CreateNtupleDColumn("edep_head");
  analysisManager->CreateNtupleDColumn("edep_neck");
  analysisManager->CreateNtupleDColumn("edep_chest");
  analysisManager->CreateNtupleDColumn("edep_arm_l");
  analysisManager->CreateNtupleDColumn("edep_arm_r");
  analysisManager->CreateNtupleDColumn("edep_leg_l");
  analysisManager->CreateNtupleDColumn("edep_leg_r");

  analysisManager->CreateNtupleDColumn("head_center_x");
  analysisManager->CreateNtupleDColumn("head_center_y");
  analysisManager->CreateNtupleDColumn("head_center_z");
  analysisManager->CreateNtupleDColumn("chest_center_x");
  analysisManager->CreateNtupleDColumn("chest_center_y");
  analysisManager->CreateNtupleDColumn("chest_center_z");
  analysisManager->CreateNtupleDColumn("particle_direction_x");
  analysisManager->CreateNtupleDColumn("particle_direction_y");
  analysisManager->CreateNtupleDColumn("particle_direction_z");
  analysisManager->FinishNtuple();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DoseRunAction::~DoseRunAction()
{
  delete G4AnalysisManager::Instance();
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DoseRunAction::BeginOfRunAction(const G4Run* run)
{ 
  G4cout << "### Run " << run->GetRunID() << " start." << G4endl;
  
  // Get analysis manager
  auto analysisManager = G4AnalysisManager::Instance();

  // Open an output file
  G4String fileName = "Dose";
  analysisManager->OpenFile(fileName);

  // inform the runManager to save random number seed
  G4RunManager::GetRunManager()->SetRandomNumberStore(false);

  // reset accumulables to their initial values
  G4AccumulableManager* accumulableManager = G4AccumulableManager::Instance();
  accumulableManager->Reset();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

void DoseRunAction::EndOfRunAction(const G4Run* run)
{
  G4int nofEvents = run->GetNumberOfEvent();
  if (nofEvents == 0) {
    G4cout << "nofEvents = " << nofEvents << G4endl;
    return;
  }

  auto analysisManager = G4AnalysisManager::Instance();
  analysisManager->Write();
  analysisManager->CloseFile();

}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

// void DoseRunAction::AddEdep(G4double fTotalEdep)
// {
  
// }


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

