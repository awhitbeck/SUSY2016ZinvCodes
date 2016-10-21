#include<vector>
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"
//#include "ReadTree.cc"
#include "ReadTree2016V10.cc"
#include <stdio.h>


void Ztonunu(){

     TChain* tZinv = new TChain("tree");
     tZinv->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_signal/tree_ZJetsToNuNu_HT-100to200.root");
     tZinv->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_signal/tree_ZJetsToNuNu_HT-200to400.root");
     tZinv->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_signal/tree_ZJetsToNuNu_HT-400to600.root");
     tZinv->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_signal/tree_ZJetsToNuNu_HT-600to800.root");
     tZinv->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_signal/tree_ZJetsToNuNu_HT-800to1200.root");
     tZinv->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_signal/tree_ZJetsToNuNu_HT-1200to2500.root");
     tZinv->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_signal/tree_ZJetsToNuNu_HT-2500toInf.root");

     ReadTree Zinv(tZinv);


   TFile *f=new TFile("InputSkimZinv2016_V10.root","RECREATE");     

     TTree *T=new TTree("SimpleTree","RA2PhotonTree");



     double evWeight;
     double puWeight;
     double HT;
     double MHT;
     int NJets;
     int BJets;
     double BTagSF;
    

     T->Branch("evWeight",&evWeight);
     T->Branch("puWeight",&puWeight);
     T->Branch("HT",&HT);
     T->Branch("MHT",&MHT);
     T->Branch("NJets",&NJets);
     T->Branch("BJets",&BJets);
     T->Branch("BTagSF",&BTagSF);

     double HTcut=300;
     double MHTcut=250;
     double NJetscut=2;
     double BJetscut=0;
     double PhotonPtcut=100;


     int maxEvents_Zinv=tZinv->GetEntries();
     cout<<"maxEventsZinv: "<<maxEvents_Zinv<<endl;

     for(int iEv=0;iEv<maxEvents_Zinv;iEv++){//Looping over Zinv MC///////////////////////////////////////
     tZinv->GetEntry(iEv);
     if(iEv % 50000==0){cout<<"Event no Zinv : "<<iEv<<endl;}

      bool passFilters=false;

    if( Zinv.HBHENoiseFilter==1 && Zinv.HBHEIsoNoiseFilter==1 && Zinv.eeBadScFilter==1 && Zinv.EcalDeadCellTriggerPrimitiveFilter==1  && Zinv.NVtx > 0 && Zinv.JetID ){passFilters=true;}




     if(  Zinv.MHT > MHTcut && Zinv.HT > HTcut && Zinv.NJets>= NJetscut  && Zinv.BTags >= BJetscut && passFilters==true ){//Filling Yield(N_Obsereved) in Zinv
       HT=Zinv.HT;
       MHT=Zinv.MHT;
       NJets=Zinv.NJets;
       BJets=Zinv.BTags;
      // BTagSF=Zinv.btagSF();
       //cout<<""<<Zinv.btagSF()<<endl;
       evWeight=Zinv.Weight;
       puWeight=Zinv.puWeight;

      T->Fill();

      }//Filling Yield(N_Obsereved) in Zinv



     }//Lopping over Zinv MC//////////////////////////////////////////////////////////




  f->Write();














}
