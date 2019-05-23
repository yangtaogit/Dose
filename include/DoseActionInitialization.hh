//
/// \file DoseActionInitialization.hh
//

#ifndef DoseActionInitialization_h
#define DoseActionInitialization_h 1

#include "G4VUserActionInitialization.hh"

/// Action initialization class.

class DoseDetectorConstruction;

class DoseActionInitialization : public G4VUserActionInitialization
{
  public:
    DoseActionInitialization( DoseDetectorConstruction* );
    virtual ~DoseActionInitialization();

    virtual void BuildForMaster() const;
    virtual void Build() const;

  private:
    DoseDetectorConstruction* fDetConstruction;

};

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
