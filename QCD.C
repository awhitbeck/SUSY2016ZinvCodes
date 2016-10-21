#include<vector>
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"
//#include "ReadTree.cc"
#include <stdio.h>
#include "ReadTree2016V10.cc"

void QCD(){

  //reading QCD MC
     TChain* tQCD = new TChain("tree");
     tQCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_GJet_CleanVars/tree_QCD_HT-200to300.root");
     tQCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_GJet_CleanVars/tree_QCD_HT-300to500.root");
     tQCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_GJet_CleanVars/tree_QCD_HT-500to700.root");
     tQCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_GJet_CleanVars/tree_QCD_HT-700to1000.root");
     tQCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_GJet_CleanVars/tree_QCD_HT-1000to1500.root");
     tQCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_GJet_CleanVars/tree_QCD_HT-1500to2000.root");
     tQCD->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_GJet_CleanVars/tree_QCD_HT-2000toInf.root");


     ReadTree QCD(tQCD);


   TFile *f=new TFile("InputSkimQCD2016_V10.root","RECREATE");     

     TTree *T=new TTree("SimpleTree","RA2PhotonTree");



     double evWeight;
     double HT;
     double MHT;
     int NJets;
     int BJets;
     double PhotonPt;
     double PhotonEta;

     T->Branch("evWeight",&evWeight);
     T->Branch("HT",&HT);
     T->Branch("MHT",&MHT);
     T->Branch("NJets",&NJets);
     T->Branch("BJets",&BJets);
     T->Branch("PhotonPt",&PhotonPt);
     T->Branch("PhotonEta",&PhotonEta);

     double HTcut=300;
     double MHTcut=250;
     double NJetscut=2;
     double BJetscut=0;
     double PhotonPtcut=200;


     int maxEvents_QCD=tQCD->GetEntries();
     cout<<"maxEventsQCD: "<<maxEvents_QCD<<endl;
     for(int iEv=0;iEv<maxEvents_QCD;iEv++){//Looping over QCD MC
     tQCD->GetEntry(iEv);
     if(iEv % 1000000==0){cout<<"Event no QCD : "<<iEv<<endl;}

      bool passFilters=false;

    if( QCD.HBHENoiseFilter==1 && QCD.HBHEIsoNoiseFilter==1 && QCD.eeBadScFilter==1 && QCD.EcalDeadCellTriggerPrimitiveFilter==1  && QCD.NVtx > 0 && QCD.JetID ){passFilters=true;}




     int index=QCD.Photons->size();
     if( QCD.MHT > MHTcut && QCD.HT > HTcut && QCD.NJets>= NJetscut && QCD.Photons->at(0).Pt() > PhotonPtcut && QCD.BTags >= BJetscut && index >0 && QCD.Photons_nonPrompt->at(0) ==1 && QCD.DeltaPhi1> 0.5 && QCD.DeltaPhi2>0.5 && QCD.DeltaPhi3>0.3 && QCD.DeltaPhi4>0.3 && passFilters==true){//Filling Yield(N_Obsereved) in QCD MC



       HT=QCD.HT;
       MHT=QCD.MHT;
       NJets=QCD.NJets;
       BJets=QCD.BTags;
       evWeight=QCD.Weight;
       PhotonPt=QCD.Photons->at(0).Pt();
       PhotonEta=QCD.Photons->at(0).Eta();



      T->Fill();



      }//Filling Yield(N_Obsereved) in QCD MC




     }//Looping over QCD MC




    f->Write();











}
