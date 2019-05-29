//
/// \file B1DetectorConstruction.cc
//

#include "DoseDetectorConstruction.hh"

#include "G4RunManager.hh"
#include "G4NistManager.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include "G4Sphere.hh"
#include "G4LogicalVolume.hh"
#include "G4PVPlacement.hh"
#include "G4SystemOfUnits.hh"
#include "G4RotationMatrix.hh"

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DoseDetectorConstruction::DoseDetectorConstruction()
: G4VUserDetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

DoseDetectorConstruction::~DoseDetectorConstruction()
{ }

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......

G4VPhysicalVolume* DoseDetectorConstruction::Construct()
{  
  // Get nist material manager
  G4NistManager* nist = G4NistManager::Instance();
  
  // Option to switch on/off checking of volumes overlaps
  //
  G4bool checkOverlaps = true;

 
                     
  //     
  // World
  // 
  G4double world_sizeXY = 500.*cm, world_sizeZ = 500.*cm;
  G4Material* world_mat = nist->FindOrBuildMaterial("G4_AIR");
 
  G4Box* solidWorld =    
    new G4Box("World",                    
        0.5*world_sizeXY, 0.5*world_sizeXY, 0.5*world_sizeZ); 
  G4LogicalVolume* logicWorld =                         
    new G4LogicalVolume(solidWorld,            
                        world_mat,            
                        "World");         

  G4RotationMatrix *rotBox = new G4RotationMatrix();
  rotBox->rotateX(90.*deg);

  G4VPhysicalVolume* physWorld =             
  new G4PVPlacement(0,              
                    G4ThreeVector(),
                    logicWorld,     
                    "World",        
                    0,              
                    false,          
                    0,              
                    checkOverlaps); 


  //     
  // Chest Shape 
  //
  G4double chest_sizeX = 12.*cm, chest_sizeY = 26.*cm,chest_sizeZ = 50.*cm;
  G4Material* chest_mat = nist->FindOrBuildMaterial("G4_WATER");
  G4ThreeVector chest_pos = G4ThreeVector(0, 0, 0);
               
  G4Box* solidChest =    
    new G4Box("Chest",                   
        0.5*chest_sizeX, 0.5*chest_sizeY, 0.5*chest_sizeZ); 
                      
  G4LogicalVolume* logicChest =                         
    new G4LogicalVolume(solidChest,         
                        chest_mat,          
                        "Chest");           

  fChestPV =              
  new G4PVPlacement(rotBox,                 
                    chest_pos,              
                    logicChest,             
                    "Chest",                
                    logicWorld,             
                    false,                  
                    0,                      
                    checkOverlaps);         



  //     
  // Arm Shape 
  //
  G4double arm_sizeX = 8.*cm, arm_sizeY = 6.*cm,arm_sizeZ = 60.*cm;
  G4Material* arm_mat = nist->FindOrBuildMaterial("G4_WATER");
  G4ThreeVector arm_pos_l = G4ThreeVector(0, -5.*cm, 16.*cm);
  G4ThreeVector arm_pos_r = G4ThreeVector(0, -5.*cm, -16.*cm);
               
  G4Box* solidArm =    
    new G4Box("Arm",                   
        0.5*arm_sizeX, 0.5*arm_sizeY, 0.5*arm_sizeZ); 
                      
  G4LogicalVolume* logicArm =                         
    new G4LogicalVolume(solidArm,  
                        arm_mat,   
                        "Arm");    

  fArmLPV = 
  new G4PVPlacement(rotBox,        
                    arm_pos_l,     
                    logicArm,      
                    "ArmL",         
                    logicWorld,    
                    false,         
                    0,             
                    checkOverlaps);

  fArmRPV = 
  new G4PVPlacement(rotBox,         
                    arm_pos_r,      
                    logicArm,       
                    "ArmR",          
                    logicWorld,     
                    false,          
                    0,              
                    checkOverlaps); 



  //     
  // Neck Shape 
  //
  G4Material* neck_mat = nist->FindOrBuildMaterial("G4_WATER");
  G4ThreeVector neck_pos = G4ThreeVector(0, 29.5*cm, 0);
  
  G4double innerRadiusOfTheNeck = 0.*cm;
  G4double outerRadiusOfTheNeck = 5.*cm;
  G4double hightOfTheNeck = 4.5*cm;
  G4double startAngleOfTheNeck = 0.*deg;
  G4double spanningAngleOfTheNeck = 360.*deg;

  G4Tubs* solidNeck =    
    new G4Tubs("Neck",
                innerRadiusOfTheNeck,
                outerRadiusOfTheNeck,
                hightOfTheNeck,
                startAngleOfTheNeck,
                spanningAngleOfTheNeck);  
                  
  G4LogicalVolume* logicNeck =            
    new G4LogicalVolume(solidNeck,        
                        neck_mat,         
                        "Neck");          

  fNeckPV =             
  new G4PVPlacement(rotBox,               
                    neck_pos,             
                    logicNeck,            
                    "Neck",               
                    logicWorld,           
                    false,                
                    0,                    
                    checkOverlaps);       


  //     
  // Head Shape 
  //

  G4Material* head_mat = nist->FindOrBuildMaterial("G4_WATER");
  G4ThreeVector head_pos = G4ThreeVector(0, 43.*cm, 0);

  G4double pRmin = 0.*cm;
  G4double pRmax = 9.*cm;
  G4double pSPhi = 0.*deg;
  G4double pDPhi = 360.*deg;
  G4double pSTheta = 0.*deg;
  G4double pDTheta = 360.*deg;

  G4Sphere* solidHead = 
    new G4Sphere("Head",
                  pRmin,
                  pRmax,
                  pSPhi,
                  pDPhi,
                  pSTheta,
                  pDTheta);

  G4LogicalVolume* logicHead =                           
    new G4LogicalVolume(solidHead,        
                        head_mat,         
                        "Head");          

  fHeadPV = 
  new G4PVPlacement(rotBox,               
                    head_pos,             
                    logicHead,            
                    "Head",               
                    logicWorld,           
                    false,                
                    0,                    
                    checkOverlaps);       


  //     
  // Leg Shape 
  //

  G4Material* leg_mat = nist->FindOrBuildMaterial("G4_WATER");
  G4ThreeVector leg_pos_l = G4ThreeVector(0, -66.*cm, -7.5*cm);
  G4ThreeVector leg_pos_r = G4ThreeVector(0, -66.*cm, 7.5*cm);
  
  G4double innerRadiusOfTheLeg = 0.*cm;
  G4double outerRadiusOfTheLeg = 5.5*cm;
  G4double hightOfTheLeg = 41.*cm;
  G4double startAngleOfTheLeg = 0.*deg;
  G4double spanningAngleOfTheLeg = 360.*deg;

  G4Tubs* solidLeg =    
    new G4Tubs("Leg",
                innerRadiusOfTheLeg,
                outerRadiusOfTheLeg,
                hightOfTheLeg,
                startAngleOfTheLeg,
                spanningAngleOfTheLeg);   
               
  G4LogicalVolume* logicLeg =             
    new G4LogicalVolume(solidLeg,         
                        leg_mat,          
                        "Leg");           

  fLegLPV =              
  new G4PVPlacement(rotBox,               
                    leg_pos_l,            
                    logicLeg,             
                    "LegL",                
                    logicWorld,           
                    false,                
                    0,                    
                    checkOverlaps);       

  fLegRPV = 
  new G4PVPlacement(rotBox,               
                    leg_pos_r,            
                    logicLeg,             
                    "LegR",                
                    logicWorld,           
                    false,                
                    0,                    
                    checkOverlaps);       


  //
  //always return the physical World
  //
  return physWorld;
}

//....oooOO0OOooo........oooOO0OOooo........oooOO0OOooo........oooOO0OOooo......
