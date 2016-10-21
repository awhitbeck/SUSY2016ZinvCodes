#include<vector>
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"
#include "ReadTree.cc"
#include <stdio.h>


void GJetsLDP(){


   //reading the GJets MC
     TChain* tGJets = new TChain("tree");
     tGJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV9/tree_GJetLDP_CleanVars/tree_GJets_DR-0p4_HT-100to200.root");
     tGJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV9/tree_GJetLDP_CleanVars/tree_GJets_DR-0p4_HT-200to400.root");
     tGJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV9/tree_GJetLDP_CleanVars/tree_GJets_DR-0p4_HT-400to600.root");
     tGJets->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV9/tree_GJetLDP_CleanVars/tree_GJets_DR-0p4_HT-600toInf.root");
     ReadTree GJets(tGJets);



     TFile *f=new TFile("InputSkimGJetsDR4LDP2016_V9.root","RECREATE");     

     TTree *T=new TTree("SimpleTree","RA2PhotonTree");



     Double_t evWeight;
     Double_t HT;
     Double_t MHT;
     Int_t NJets;
     Int_t BJets;
     Double_t PhotonPt;
     Double_t PhotonEta;

     T->Branch("evWeight",&evWeight);
     T->Branch("HT",&HT);
     T->Branch("MHT",&MHT);
     T->Branch("NJets",&NJets);
     T->Branch("BJets",&BJets);
     T->Branch("PhotonPt",&PhotonPt);
     T->Branch("PhotonEta",&PhotonEta);

     double HTcut=300;
     double MHTcut=250;
     double NJetscut=3;
     double BJetscut=0;
     double PhotonPtcut=200;


     TH1F *h=new TH1F("h","h",100,200,2500);



     int maxEvents_GJets=tGJets->GetEntries();
     cout<<"maxEventsGJets: "<<maxEvents_GJets<<endl;
     for(int iEv=0;iEv<maxEvents_GJets;iEv++){//Looping over GJets MC///////////////////////////////////////
     tGJets->GetEntry(iEv);
   

     if(iEv % 1000000==0){cout<<"Event no GJets : "<<iEv<<endl;}
     
          
     int index=GJets.Photons->size();
    

     if(GJets.MHT > MHTcut && GJets.HT > HTcut && GJets.NJets>= NJetscut && GJets.Photons->at(0).Pt() > 100. && GJets.BTags >= BJetscut && index >0 && GJets.photon_nonPrompt->at(0) !=1  ){//Filling Yield(N_Obsereved) in GJets MC

       HT=GJets.HT;
       MHT=GJets.MHT;
       NJets=GJets.NJets;
       BJets=GJets.BTags;
       evWeight=GJets.Weight;
       PhotonPt=GJets.Photons->at(0).Pt();
       PhotonEta=GJets.Photons->at(0).Eta();



       T->Fill();





     }////Filling Yield(N_Obsereved) in GJets MC



      }//Looping over GJets MC/////// 




     f->Write();









}
