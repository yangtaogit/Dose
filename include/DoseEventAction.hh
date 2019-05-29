//
/// \file DoseEventAction.hh
/// \brief Definition of the DoseEventAction class

#ifndef DoseEventAction_h
#define DoseEventAction_h 1

#include "G4UserEventAction.hh"
#include "globals.hh"

class DoseRunAction;
class G4Event;

/// Event action class
///

class DoseEventAction : public G4UserEventAction
{
  public:
    DoseEventAction(DoseRunAction* runAction);
    virtual ~DoseEventAction();

    virtual void BeginOfEventAction(const G4Event* event);
    virtual void EndOfEventAction(const G4Event* event);

    void RecordTotal(G4double edep);

    void RecordHead(G4double edep, 
		G4double point_in_x, G4double point_in_y, G4double point_in_z,
		G4double point_out_x, G4double point_out_y, G4double point_out_z);

    void RecordChest(G4double edep, 
		G4double point_in_x, G4double point_in_y, G4double point_in_z,
		G4double point_out_x, G4double point_out_y, G4double point_out_z);

    void RecordNeck(G4double edep);
    void RecordArmL(G4double edep);
    void RecordArmR(G4double edep);
    void RecordLegL(G4double edep);
    void RecordLegR(G4double edep);

  private:
    DoseRunAction* fRunAction;

    G4double px=0, py=0, pz=0;

    G4double edep_total=0.;
    G4double edep_head=0., edep_neck=0., edep_chest=0.;
    G4double edep_arm_l=0., edep_arm_r=0.;
    G4double edep_leg_l=0., edep_leg_r=0.;

    G4double x_head=0, y_head=0, z_head=0;
    G4double x_chest=0, y_chest=0, z_chest=0;

    G4double x_EdepC_head=0, y_EdepC_head=0, z_EdepC_head=0;
    G4double x_EdepC_chest=0, y_EdepC_chest=0, z_EdepC_chest=0;
};


inline void DoseEventAction::RecordTotal(G4double edep) {
    
    edep_total += edep; 

}

inline void DoseEventAction::RecordHead(G4double edep,
                G4double point_in_x, G4double point_in_y, G4double point_in_z,
                G4double point_out_x, G4double point_out_y, G4double point_out_z) {
    
    edep_head += edep; 

    x_EdepC_head += edep*(point_out_x+point_in_x)/2;
    y_EdepC_head += edep*(point_out_y+point_in_y)/2;
    z_EdepC_head += edep*(point_out_z+point_in_z)/2;

}

inline void DoseEventAction::RecordChest(G4double edep,
                G4double point_in_x, G4double point_in_y, G4double point_in_z,
                G4double point_out_x, G4double point_out_y, G4double point_out_z) {
    
    edep_chest += edep; 

    x_EdepC_chest += edep*(point_out_x+point_in_x)/2;
    y_EdepC_chest += edep*(point_out_y+point_in_y)/2;
    z_EdepC_chest += edep*(point_out_z+point_in_z)/2;

}

inline void DoseEventAction::RecordNeck(G4double edep) {
    
    edep_neck += edep; 

}

inline void DoseEventAction::RecordArmL(G4double edep) {
    
    edep_arm_l += edep; 

}

inline void DoseEventAction::RecordArmR(G4double edep) {
    
    edep_arm_r += edep; 

}

inline void DoseEventAction::RecordLegL(G4double edep) {
    
    edep_leg_l += edep; 

}

inline void DoseEventAction::RecordLegR(G4double edep) {
    
    edep_leg_r += edep; 

}


//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

#endif

    
