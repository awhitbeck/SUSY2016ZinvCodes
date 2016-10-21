#include<vector>
#include "TH1.h"
#include "TH2.h"
#include "TFile.h"
#include "TCanvas.h"
#include "TString.h"
#include "TDirectory.h"
#include "ReadTree2016V10.cc"
#include <stdio.h>


void SinglePhotonLDP(){


  //reading Single photon Data
     TChain* tData = new TChain("tree");
     tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV9/tree_GJetLDP_CleanVars/tree_SinglePhoton_2016B.root");
     
     tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV9/tree_GJetLDP_CleanVars/tree_SinglePhoton_2016C.root");

    tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV9/tree_GJetLDP_CleanVars/tree_SinglePhoton_2016D.root");
 
    tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_GJet_CleanVars/tree_SinglePhoton_2016E.root");

    tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_GJet_CleanVars/tree_SinglePhoton_2016F.root");


   tData->Add("root://cmseos.fnal.gov//store/user/lpcsusyhad/SusyRA2Analysis2015/Skims/Run2ProductionV10/tree_GJet_CleanVars/tree_SinglePhoton_2016G.root");






    ReadTree Data(tData);



     TFile *f=new TFile("InputSkimDataLDP2016_V10.root","RECREATE");     

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
     double PhotonPtcut=200.;



     int maxEvents_Data=tData->GetEntries();
     for(int iEv=0;iEv<maxEvents_Data;iEv++){//Data
     tData->GetEntry(iEv);
     if(iEv % 1000000==0){cout<<"Event no Data : "<<iEv<<endl;}


     int index=Data.Photons->size();


     if( Data.MHT > MHTcut && Data.HT > HTcut && Data.NJets>= NJetscut && Data.Photons->at(0).Pt() > PhotonPtcut && Data.BTags>= BJetscut && index >0 ){//Filling Yield(N_Obsereved) in Data
            bool PassTrigger=false;
            bool PassFilters=false;


      if(Data.globalTightHalo2016Filter==1 && Data.HBHENoiseFilter==1 && Data.HBHEIsoNoiseFilter==1 && Data.eeBadScFilter==1 && Data.EcalDeadCellTriggerPrimitiveFilter==1 && Data.BadChargedCandidateFilter && Data.BadPFMuonFilter && Data.JetID && Data.NVtx > 0){PassFilters=true;}




         for(unsigned int itr=0;itr<Data.TriggerNames->size();itr++){

             if(Data.TriggerNames->at(itr).find("HLT_Photon175_v") !=string::npos  && Data.TriggerPass->at(itr)==1){
                PassTrigger=true;


               }

              }


        if(PassTrigger==true && PassFilters==true){//trigger


       HT=Data.HT;
       MHT=Data.MHT;
       NJets=Data.NJets;
       BJets=Data.BTags;
       //evWeight=Data.Weight;
       PhotonPt=Data.Photons->at(0).Pt();
       PhotonEta=Data.Photons->at(0).Eta();



      T->Fill();


       } // trigger pass

      

         }//Filling Yield(N_Obsereved) in Data



     }//Data 



    f->Write();











}
