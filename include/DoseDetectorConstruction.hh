//
/// \file DoseDetectorConstruction.hh
//

#ifndef DoseDetectorConstruction_h
#define DoseDetectorConstruction_h 1

#include "G4VUserDetectorConstruction.hh"
#include "globals.hh"

class G4VPhysicalVolume;
class G4LogicalVolume;

/// Detector construction class to define materials and geometry.

class DoseDetectorConstruction : public G4VUserDetectorConstruction
{
  public:
    DoseDetectorConstruction();
    virtual ~DoseDetectorConstruction();

    virtual G4VPhysicalVolume* Construct();
    
    // const G4VPhysicalVolume* GetHeadPV() const;
    // const G4VPhysicalVolume* GetNeckPV() const;
    // const G4VPhysicalVolume* GetChestPV() const;
    // const G4VPhysicalVolume* GetArmLPV() const;
    // const G4VPhysicalVolume* GetArmRPV() const;
    // const G4VPhysicalVolume* GetLegLPV() const;
    // const G4VPhysicalVolume* GetLegRPV() const;


  protected:

    G4VPhysicalVolume*  fHeadPV;
    G4VPhysicalVolume*  fNeckPV;
    G4VPhysicalVolume*  fChestPV;
    G4VPhysicalVolume*  fArmLPV;
    G4VPhysicalVolume*  fArmRPV;
    G4VPhysicalVolume*  fLegLPV;
    G4VPhysicalVolume*  fLegRPV;
    
};

// inline const G4VPhysicalVolume* DoseDetectorConstruction::GetHeadPV() const { return fHeadPV; }
// inline const G4VPhysicalVolume* DoseDetectorConstruction::GetNeckPV() const { return fNeckPV; }
// inline const G4VPhysicalVolume* DoseDetectorConstruction::GetChestPV() const { return fChestPV; }
// inline const G4VPhysicalVolume* DoseDetectorConstruction::GetArmLPV() const { return fArmLPV; }
// inline const G4VPhysicalVolume* DoseDetectorConstruction::GetArmRPV() const { return fArmRPV; }
// inline const G4VPhysicalVolume* DoseDetectorConstruction::GetLegLPV() const { return fLegLPV; }
// inline const G4VPhysicalVolume* DoseDetectorConstruction::GetLegRPV() const { return fLegRPV; }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

