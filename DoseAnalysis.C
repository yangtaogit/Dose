#include <TFile.h>
#include <TTree.h>
#include <RtypesCore.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>

void DoseAnalysis(){


    TFile *rootfile = new TFile("Dose_50cm.root");

    TTree *mytree = (TTree *)rootfile->Get("Dose");

    Double_t EventID;
    Double_t Edep_total;
    Double_t Edep_head, Edep_neck,Edep_chest,Edep_arm_l,Edep_arm_r,Edep_leg_l,Edep_leg_r;
    Double_t Head_center_x, Head_center_y, Head_center_z;
    Double_t Chest_center_x, Chest_center_y, Chest_center_z;
    Double_t Particle_momentum_x, Particle_momentum_y, Particle_momentum_z;

    mytree->SetBranchAddress("Edep_total", &Edep_total);
    mytree->SetBranchAddress("Edep_head", &Edep_head);
    mytree->SetBranchAddress("Edep_neck", &Edep_neck);
    mytree->SetBranchAddress("Edep_chest", &Edep_chest);
    mytree->SetBranchAddress("Edep_arm_l", &Edep_arm_l);
    mytree->SetBranchAddress("Edep_arm_r", &Edep_arm_r);
    mytree->SetBranchAddress("Edep_leg_l", &Edep_leg_l);
    mytree->SetBranchAddress("Edep_leg_r", &Edep_leg_r);

    mytree->SetBranchAddress("Head_center_x", &Head_center_x);
    mytree->SetBranchAddress("Head_center_y", &Head_center_y);
    mytree->SetBranchAddress("Head_center_z", &Head_center_z);
    mytree->SetBranchAddress("Chest_center_x", &Chest_center_x);
    mytree->SetBranchAddress("Chest_center_y", &Chest_center_y);
    mytree->SetBranchAddress("Chest_center_z", &Chest_center_z);

    mytree->SetBranchAddress("Particle_momentum_x", &Particle_momentum_x);
    mytree->SetBranchAddress("Particle_momentum_y", &Particle_momentum_y);
    mytree->SetBranchAddress("Particle_momentum_z", &Particle_momentum_z);

    Double_t energy_bin = 100;

    TH1F *h1 = new TH1F("Edep_total", "Energy deposition in Body", energy_bin, 0., 0.7);
    TH1F *h2 = new TH1F("Edep_head", "Energy deposition in Head", energy_bin, 0., 0.7);
    TH1F *h3 = new TH1F("Edep_neck", "Energy deposition in Neck", energy_bin, 0., 0.7);
    TH1F *h4 = new TH1F("Edep_chest", "Energy deposition in Chest", energy_bin, 0., 0.7);
    TH1F *h5 = new TH1F("Edep_arm_l", "Energy deposition in Left Arm", energy_bin, 0., 0.7);
    TH1F *h6 = new TH1F("Edep_arm_r", "Energy deposition in Right Arm", energy_bin, 0., 0.7);
    TH1F *h7 = new TH1F("Edep_leg_l", "Energy deposition in Left Leg", energy_bin, 0., 0.7);
    TH1F *h8 = new TH1F("Edep_leg_r", "Energy deposition in Eight Leg", energy_bin, 0., 0.7);

    TH1F *h9 = new TH1F("Head_center_x", "The Center of Energy deposition of Head on X direction", 300, -600., 600.);
    TH1F *h10 = new TH1F("Head_center_y", "The Center of Energy deposition of Head on Y direction", 300, -600., 600.);
    TH1F *h11 = new TH1F("Head_center_z", "The Center of Energy deposition of Head on Z direction", 300, -600., 600.);

    TH1F *h12 = new TH1F("Chest_center_x", "The Center of Energy deposition of Chest on X direction", 300, -600., 600.);
    TH1F *h13 = new TH1F("Chest_center_y", "The Center of Energy deposition of Chest on Y direction", 300, -600., 600.);
    TH1F *h14 = new TH1F("Chest_center_z", "The Center of Energy deposition of Chest on Z direction", 300, -600., 600.);

    TH1F *h15 = new TH1F("Particle_momentum_x", "The primary particle momentum Px", 100, -1., 1.);
    TH1F *h16 = new TH1F("Particle_momentum_y", "The primary particle momentum Py", 100, -1., 1.);
    TH1F *h17 = new TH1F("Particle_momentum_z", "The primary particle momentum Pz", 100, -1., 1.);

    for(Int_t i=0 ; i<mytree->GetEntries() ; i++){

        mytree->GetEntry(i);

        h1->Fill(Edep_total);
        h2->Fill(Edep_head);
        h3->Fill(Edep_neck);
        h4->Fill(Edep_chest);
        h5->Fill(Edep_arm_l);
        h6->Fill(Edep_arm_r);
        h7->Fill(Edep_leg_l);
        h8->Fill(Edep_leg_r);
        h9->Fill(Head_center_x);
        h10->Fill(Head_center_y);
        h11->Fill(Head_center_z);
        h12->Fill(Chest_center_x);
        h13->Fill(Chest_center_y);
        h14->Fill(Chest_center_z);
        h15->Fill(Particle_momentum_x);
        h16->Fill(Particle_momentum_y);
        h17->Fill(Particle_momentum_z);

    }

    TCanvas *c1 = new TCanvas("c1","c1", 2000, 2000);
    TCanvas *c2 = new TCanvas("c2","c2", 3000, 1000);
    TCanvas *c3 = new TCanvas("c3","c3", 3000, 500);

    c1->Divide(2,4);
    c2->Divide(3,2);
    c3->Divide(3,1);


    c1->cd(1);
    h1->GetXaxis()->SetTitle("Energy (MeV)");
    h1->GetXaxis()->CenterTitle();
    h1->GetYaxis()->SetTitle("Events");
    h1->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    h1->Draw();

    c1->cd(2);
    h2->GetXaxis()->SetTitle("Energy (MeV)");
    h2->GetXaxis()->CenterTitle();
    h2->GetYaxis()->SetTitle("Events");
    h2->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    h2->Draw();

    c1->cd(3);
    h3->GetXaxis()->SetTitle("Energy (MeV)");
    h3->GetXaxis()->CenterTitle();
    h3->GetYaxis()->SetTitle("Events");
    h3->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    h3->Draw();

    c1->cd(4);
    h4->GetXaxis()->SetTitle("Energy (MeV)");
    h4->GetXaxis()->CenterTitle();
    h4->GetYaxis()->SetTitle("Events");
    h4->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    h4->Draw();

    c1->cd(5);
    h5->GetXaxis()->SetTitle("Energy (MeV)");
    h5->GetXaxis()->CenterTitle();
    h5->GetYaxis()->SetTitle("Events");
    h5->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    h5->Draw();

    c1->cd(6);
    h6->GetXaxis()->SetTitle("Energy (MeV)");
    h6->GetXaxis()->CenterTitle();
    h6->GetYaxis()->SetTitle("Events");
    h6->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    h6->Draw();

    c1->cd(7);
    h7->GetXaxis()->SetTitle("Energy (MeV)");
    h7->GetXaxis()->CenterTitle();
    h7->GetYaxis()->SetTitle("Events");
    h7->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    h7->Draw();

    c1->cd(8);
    h8->GetXaxis()->SetTitle("Energy (MeV)");
    h8->GetXaxis()->CenterTitle();
    h8->GetYaxis()->SetTitle("Events");
    h8->GetYaxis()->CenterTitle();
    gPad->SetLogy();
    h8->Draw();


    c2->cd(1);
    h9->GetXaxis()->SetTitle("X_{center of energy}(mm)");
    h9->GetXaxis()->CenterTitle();
    h9->GetYaxis()->SetTitle("Events");
    h9->GetYaxis()->CenterTitle();
    h9->SetLineColor(kRed);
    h9->Draw();

    c2->cd(2);
    h10->GetXaxis()->SetTitle("Y_{center of energy}(mm)");
    h10->GetXaxis()->CenterTitle();
    h10->GetYaxis()->SetTitle("Events");
    h10->GetYaxis()->CenterTitle();
    h10->SetLineColor(kRed);
    h10->Draw();

    c2->cd(3);
    h11->GetXaxis()->SetTitle("Z_{center of energy}(mm)");
    h11->GetXaxis()->CenterTitle();
    h11->GetYaxis()->SetTitle("Events");
    h11->GetYaxis()->CenterTitle();
    h11->SetLineColor(kRed);
    h11->Draw();

    c2->cd(4);
    h12->GetXaxis()->SetTitle("X_{center of energy}(mm)");
    h12->GetXaxis()->CenterTitle();
    h12->GetYaxis()->SetTitle("Events");
    h12->GetYaxis()->CenterTitle();
    h12->SetLineColor(kRed);
    h12->Draw();

    c2->cd(5);
    h13->GetXaxis()->SetTitle("Y_{center of energy}(mm)");
    h13->GetXaxis()->CenterTitle();
    h13->GetYaxis()->SetTitle("Events");
    h13->GetYaxis()->CenterTitle();
    h13->SetLineColor(kRed);
    h13->Draw();

    c2->cd(6);
    h14->GetXaxis()->SetTitle("Z_{center of energy}(mm)");
    h14->GetXaxis()->CenterTitle();
    h14->GetYaxis()->SetTitle("Events");
    h14->GetYaxis()->CenterTitle();
    h14->SetLineColor(kRed);
    h14->Draw();


    c3->cd(1);
    h15->GetXaxis()->SetTitle("momentum (MeV)");
    h15->GetXaxis()->CenterTitle();
    h15->GetYaxis()->SetTitle("Events");
    h15->GetYaxis()->CenterTitle();
    h15->SetLineColor(kBlack);
    h15->Draw();

    c3->cd(2);
    h16->GetXaxis()->SetTitle("momentum (MeV)");
    h16->GetXaxis()->CenterTitle();
    h16->GetYaxis()->SetTitle("Events");
    h16->GetYaxis()->CenterTitle();
    h16->SetLineColor(kBlack);
    h16->Draw();

    c3->cd(3);
    h17->GetXaxis()->SetTitle("momentum (MeV)");
    h17->GetXaxis()->CenterTitle();
    h17->GetYaxis()->SetTitle("Events");
    h17->GetYaxis()->CenterTitle();
    h17->SetLineColor(kBlack);
    h17->Draw();

    c1->SaveAs("Edep.png");
    c2->SaveAs("Ecenter.png");
    c3->SaveAs("pp.png");

}