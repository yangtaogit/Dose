#include <TFile.h>
#include <TTree.h>
#include <RtypesCore.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>

void test(){


    TFile *rootfile1 = new TFile("Dose_50cm.root");

    TTree *mytree1 = (TTree *)rootfile1->Get("Dose");

    Double_t aEventID;
    Double_t aEdep_total;
    Double_t aEdep_head, aEdep_neck,aEdep_chest,aEdep_arm_l,aEdep_arm_r,aEdep_leg_l,aEdep_leg_r;
    Double_t aHead_center_x, aHead_center_y, aHead_center_z;
    Double_t aChest_center_x, aChest_center_y, aChest_center_z;
    Double_t aParticle_momentum_x, aParticle_momentum_y, aParticle_momentum_z;

    mytree1->SetBranchAddress("Edep_total", &aEdep_total);
    mytree1->SetBranchAddress("Edep_head", &aEdep_head);
    mytree1->SetBranchAddress("Edep_neck", &aEdep_neck);
    mytree1->SetBranchAddress("Edep_chest", &aEdep_chest);
    mytree1->SetBranchAddress("Edep_arm_l", &aEdep_arm_l);
    mytree1->SetBranchAddress("Edep_arm_r", &aEdep_arm_r);
    mytree1->SetBranchAddress("Edep_leg_l", &aEdep_leg_l);
    mytree1->SetBranchAddress("Edep_leg_r", &aEdep_leg_r);

    mytree1->SetBranchAddress("Head_center_x", &aHead_center_x);
    mytree1->SetBranchAddress("Head_center_y", &aHead_center_y);
    mytree1->SetBranchAddress("Head_center_z", &aHead_center_z);
    mytree1->SetBranchAddress("Chest_center_x", &aChest_center_x);
    mytree1->SetBranchAddress("Chest_center_y", &aChest_center_y);
    mytree1->SetBranchAddress("Chest_center_z", &aChest_center_z);

    mytree1->SetBranchAddress("Particle_momentum_x", &aParticle_momentum_x);
    mytree1->SetBranchAddress("Particle_momentum_y", &aParticle_momentum_y);
    mytree1->SetBranchAddress("Particle_momentum_z", &aParticle_momentum_z);

    Double_t energy_bin = 100;

    TH1F *ah1 = new TH1F("Edep_total", "Energy deposition in Body", energy_bin, 0., 0.7);
    TH1F *ah2 = new TH1F("Edep_head", "Energy deposition in Head", energy_bin, 0., 0.7);
    TH1F *ah3 = new TH1F("Edep_neck", "Energy deposition in Neck", energy_bin, 0., 0.7);
    TH1F *ah4 = new TH1F("Edep_chest", "Energy deposition in Chest", energy_bin, 0., 0.7);
    TH1F *ah5 = new TH1F("Edep_arm_l", "Energy deposition in Left Arm", energy_bin, 0., 0.7);
    TH1F *ah6 = new TH1F("Edep_arm_r", "Energy deposition in Right Arm", energy_bin, 0., 0.7);
    TH1F *ah7 = new TH1F("Edep_leg_l", "Energy deposition in Left Leg", energy_bin, 0., 0.7);
    TH1F *ah8 = new TH1F("Edep_leg_r", "Energy deposition in Eight Leg", energy_bin, 0., 0.7);
    TH1F *ah9 = new TH1F("Head_center_x", "The Center of Energy deposition of Head on X direction", 300, -600., 600.);
    TH1F *ah10 = new TH1F("Head_center_y", "The Center of Energy deposition of Head on Y direction", 300, -600., 600.);
    TH1F *ah11 = new TH1F("Head_center_z", "The Center of Energy deposition of Head on Z direction", 300, -600., 600.);
    TH1F *ah12 = new TH1F("Chest_center_x", "The Center of Energy deposition of Chest on X direction", 300, -600., 600.);
    TH1F *ah13 = new TH1F("Chest_center_y", "The Center of Energy deposition of Chest on Y direction", 300, -600., 600.);
    TH1F *ah14 = new TH1F("Chest_center_z", "The Center of Energy deposition of Chest on Z direction", 300, -600., 600.);
    TH1F *ah15 = new TH1F("Particle_momentum_x", "The primary particle momentum Px", 100, -1., 1.);
    TH1F *ah16 = new TH1F("Particle_momentum_y", "The primary particle momentum Py", 100, -1., 1.);
    TH1F *ah17 = new TH1F("Particle_momentum_z", "The primary particle momentum Pz", 100, -1., 1.);

    for(Int_t ai=0 ; ai<mytree1->GetEntries() ; ai++){

        mytree1->GetEntry(ai);

        ah1->Fill(aEdep_total);
        ah2->Fill(aEdep_head);
        ah3->Fill(aEdep_neck);
        ah4->Fill(aEdep_chest);
        ah5->Fill(aEdep_arm_l);
        ah6->Fill(aEdep_arm_r);
        ah7->Fill(aEdep_leg_l);
        ah8->Fill(aEdep_leg_r);
        ah9->Fill(aHead_center_x);
        ah10->Fill(aHead_center_y);
        ah11->Fill(aHead_center_z);
        ah12->Fill(aChest_center_x);
        ah13->Fill(aChest_center_y);
        ah14->Fill(aChest_center_z);
        ah15->Fill(aParticle_momentum_x);
        ah16->Fill(aParticle_momentum_y);
        ah17->Fill(aParticle_momentum_z);
    }

    TFile *rootfile2 = new TFile("Dose_100cm.root");

    TTree *mytree2 = (TTree *)rootfile2->Get("Dose");

    Double_t bEventID;
    Double_t bEdep_total;
    Double_t bEdep_head, bEdep_neck,bEdep_chest,bEdep_arm_l,bEdep_arm_r,bEdep_leg_l,bEdep_leg_r;
    Double_t bHead_center_x, bHead_center_y, bHead_center_z;
    Double_t bChest_center_x, bChest_center_y, bChest_center_z;
    Double_t bParticle_momentum_x, bParticle_momentum_y, bParticle_momentum_z;

    mytree2->SetBranchAddress("Edep_total", &bEdep_total);
    mytree2->SetBranchAddress("Edep_head", &bEdep_head);
    mytree2->SetBranchAddress("Edep_neck", &bEdep_neck);
    mytree2->SetBranchAddress("Edep_chest", &bEdep_chest);
    mytree2->SetBranchAddress("Edep_arm_l", &bEdep_arm_l);
    mytree2->SetBranchAddress("Edep_arm_r", &bEdep_arm_r);
    mytree2->SetBranchAddress("Edep_leg_l", &bEdep_leg_l);
    mytree2->SetBranchAddress("Edep_leg_r", &bEdep_leg_r);

    mytree2->SetBranchAddress("Head_center_x", &bHead_center_x);
    mytree2->SetBranchAddress("Head_center_y", &bHead_center_y);
    mytree2->SetBranchAddress("Head_center_z", &bHead_center_z);
    mytree2->SetBranchAddress("Chest_center_x", &bChest_center_x);
    mytree2->SetBranchAddress("Chest_center_y", &bChest_center_y);
    mytree2->SetBranchAddress("Chest_center_z", &bChest_center_z);

    mytree2->SetBranchAddress("Particle_momentum_x", &bParticle_momentum_x);
    mytree2->SetBranchAddress("Particle_momentum_y", &bParticle_momentum_y);
    mytree2->SetBranchAddress("Particle_momentum_z", &bParticle_momentum_z);


    TH1F *bh1 = new TH1F("Edep_total", "Energy deposition in Body", energy_bin, 0., 0.7);
    TH1F *bh2 = new TH1F("Edep_head", "Energy deposition in Head", energy_bin, 0., 0.7);
    TH1F *bh3 = new TH1F("Edep_neck", "Energy deposition in Neck", energy_bin, 0., 0.7);
    TH1F *bh4 = new TH1F("Edep_chest", "Energy deposition in Chest", energy_bin, 0., 0.7);
    TH1F *bh5 = new TH1F("Edep_arm_l", "Energy deposition in Left Arm", energy_bin, 0., 0.7);
    TH1F *bh6 = new TH1F("Edep_arm_r", "Energy deposition in Right Arm", energy_bin, 0., 0.7);
    TH1F *bh7 = new TH1F("Edep_leg_l", "Energy deposition in Left Leg", energy_bin, 0., 0.7);
    TH1F *bh8 = new TH1F("Edep_leg_r", "Energy deposition in Eight Leg", energy_bin, 0., 0.7);
    TH1F *bh9 = new TH1F("Head_center_x", "The Center of Energy deposition of Head on X direction", 300, -600., 600.);
    TH1F *bh10 = new TH1F("Head_center_y", "The Center of Energy deposition of Head on Y direction", 300, -600., 600.);
    TH1F *bh11 = new TH1F("Head_center_z", "The Center of Energy deposition of Head on Z direction", 300, -600., 600.);
    TH1F *bh12 = new TH1F("Chest_center_x", "The Center of Energy deposition of Chest on X direction", 300, -600., 600.);
    TH1F *bh13 = new TH1F("Chest_center_y", "The Center of Energy deposition of Chest on Y direction", 300, -600., 600.);
    TH1F *bh14 = new TH1F("Chest_center_z", "The Center of Energy deposition of Chest on Z direction", 300, -600., 600.);
    TH1F *bh15 = new TH1F("Particle_momentum_x", "The primary particle momentum Px", 100, -1., 1.);
    TH1F *bh16 = new TH1F("Particle_momentum_y", "The primary particle momentum Py", 100, -1., 1.);
    TH1F *bh17 = new TH1F("Particle_momentum_z", "The primary particle momentum Pz", 100, -1., 1.);

    for(Int_t bi=0 ; bi<mytree2->GetEntries() ; bi++){

        mytree2->GetEntry(bi);

        bh1->Fill(bEdep_total);
        bh2->Fill(bEdep_head);
        bh3->Fill(bEdep_neck);
        bh4->Fill(bEdep_chest);
        bh5->Fill(bEdep_arm_l);
        bh6->Fill(bEdep_arm_r);
        bh7->Fill(bEdep_leg_l);
        bh8->Fill(bEdep_leg_r);
        bh9->Fill(bHead_center_x);
        bh10->Fill(bHead_center_y);
        bh11->Fill(bHead_center_z);
        bh12->Fill(bChest_center_x);
        bh13->Fill(bChest_center_y);
        bh14->Fill(bChest_center_z);
        bh15->Fill(bParticle_momentum_x);
        bh16->Fill(bParticle_momentum_y);
        bh17->Fill(bParticle_momentum_z);

    }

    TCanvas *c1 = new TCanvas("c1","c1", 2000, 2000);
    TCanvas *c2 = new TCanvas("c2","c2", 3000, 1000);
    TCanvas *c3 = new TCanvas("c3","c3", 3000, 500);

    c1->Divide(2,4);
    c2->Divide(3,2);
    c3->Divide(3,1);


    c1->cd(1);
    ah1->GetXaxis()->SetTitle("Energy (MeV)");
    ah1->GetXaxis()->CenterTitle();
    ah1->GetYaxis()->SetTitle("Events");
    ah1->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    ah1->Draw();
    bh1->SetLineColor(kRed);
    bh1->Draw("SAME");

    c1->cd(2);
    ah2->GetXaxis()->SetTitle("Energy (MeV)");
    ah2->GetXaxis()->CenterTitle();
    ah2->GetYaxis()->SetTitle("Events");
    ah2->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    ah2->Draw();
    bh2->SetLineColor(kRed);
    bh2->Draw("SAME");

    c1->cd(3);
    ah3->GetXaxis()->SetTitle("Energy (MeV)");
    ah3->GetXaxis()->CenterTitle();
    ah3->GetYaxis()->SetTitle("Events");
    ah3->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    ah3->Draw();
    bh3->SetLineColor(kRed);
    bh3->Draw("SAME");

    c1->cd(4);
    ah4->GetXaxis()->SetTitle("Energy (MeV)");
    ah4->GetXaxis()->CenterTitle();
    ah4->GetYaxis()->SetTitle("Events");
    ah4->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    ah4->Draw();
    bh4->SetLineColor(kRed);
    bh4->Draw("SAME");

    c1->cd(5);
    ah5->GetXaxis()->SetTitle("Energy (MeV)");
    ah5->GetXaxis()->CenterTitle();
    ah5->GetYaxis()->SetTitle("Events");
    ah5->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    ah5->Draw();
    bh5->SetLineColor(kRed);
    bh5->Draw("SAME");

    c1->cd(6);
    ah6->GetXaxis()->SetTitle("Energy (MeV)");
    ah6->GetXaxis()->CenterTitle();
    ah6->GetYaxis()->SetTitle("Events");
    ah6->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    ah6->Draw();
    bh6->SetLineColor(kRed);
    bh6->Draw("SAME");

    c1->cd(7);
    ah7->GetXaxis()->SetTitle("Energy (MeV)");
    ah7->GetXaxis()->CenterTitle();
    ah7->GetYaxis()->SetTitle("Events");
    ah7->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    ah7->Draw();
    bh7->SetLineColor(kRed);
    bh7->Draw("SAME");

    c1->cd(8);
    ah8->GetXaxis()->SetTitle("Energy (MeV)");
    ah8->GetXaxis()->CenterTitle();
    ah8->GetYaxis()->SetTitle("Events");
    ah8->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    ah8->Draw();
    bh8->SetLineColor(kRed);
    bh8->Draw("SAME");


    c2->cd(1);
    ah9->GetXaxis()->SetTitle("X_{center of energy}(mm)");
    ah9->GetXaxis()->CenterTitle();
    ah9->GetYaxis()->SetTitle("Events");
    ah9->GetYaxis()->CenterTitle();
    ah9->Draw();
    bh9->SetLineColor(kRed);
    bh9->Draw("SAME");

    c2->cd(2);
    ah10->GetXaxis()->SetTitle("Y_{center of energy}(mm)");
    ah10->GetXaxis()->CenterTitle();
    ah10->GetYaxis()->SetTitle("Events");
    ah10->GetYaxis()->CenterTitle();
    ah10->Draw();
    bh10->SetLineColor(kRed);
    bh10->Draw("SAME");

    c2->cd(3);
    ah11->GetXaxis()->SetTitle("Z_{center of energy}(mm)");
    ah11->GetXaxis()->CenterTitle();
    ah11->GetYaxis()->SetTitle("Events");
    ah11->GetYaxis()->CenterTitle();
    ah11->Draw();
    bh11->SetLineColor(kRed);
    bh11->Draw("SAME");

    c2->cd(4);
    ah12->GetXaxis()->SetTitle("X_{center of energy}(mm)");
    ah12->GetXaxis()->CenterTitle();
    ah12->GetYaxis()->SetTitle("Events");
    ah12->GetYaxis()->CenterTitle();
    ah12->Draw();
    bh12->SetLineColor(kRed);
    bh12->Draw("SAME");

    c2->cd(5);
    ah13->GetXaxis()->SetTitle("Y_{center of energy}(mm)");
    ah13->GetXaxis()->CenterTitle();
    ah13->GetYaxis()->SetTitle("Events");
    ah13->GetYaxis()->CenterTitle();
    ah13->Draw();
    bh13->SetLineColor(kRed);
    bh13->Draw("SAME");


    c2->cd(6);
    ah14->GetXaxis()->SetTitle("Z_{center of energy}(mm)");
    ah14->GetXaxis()->CenterTitle();
    ah14->GetYaxis()->SetTitle("Events");
    ah14->GetYaxis()->CenterTitle();
    ah14->Draw();
    bh14->SetLineColor(kRed);
    bh14->Draw("SAME");


    c3->cd(1);
    ah15->GetXaxis()->SetTitle("momentum (MeV)");
    ah15->GetXaxis()->CenterTitle();
    ah15->GetYaxis()->SetTitle("Events");
    ah15->GetYaxis()->CenterTitle();
    ah15->Draw();
    bh15->SetLineColor(kRed);
    bh15->Draw("SAME");

    c3->cd(2);
    ah16->GetXaxis()->SetTitle("momentum (MeV)");
    ah16->GetXaxis()->CenterTitle();
    ah16->GetYaxis()->SetTitle("Events");
    ah16->GetYaxis()->CenterTitle();
    ah16->Draw();
    bh16->SetLineColor(kRed);
    bh16->Draw("SAME");

    c3->cd(3);
    ah17->GetXaxis()->SetTitle("momentum (MeV)");
    ah17->GetXaxis()->CenterTitle();
    ah17->GetYaxis()->SetTitle("Events");
    ah17->GetYaxis()->CenterTitle();
    ah17->Draw();
    bh17->SetLineColor(kRed);
    bh17->Draw("SAME");

    c1->SaveAs("Edep.png");
    c2->SaveAs("Ecenter.png");
    c3->SaveAs("pp.png");

}