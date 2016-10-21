#include<iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include "TLorentzVector.h"
#include<vector>
#include "TTree.h"
using namespace std;

class ReadTree {

public :

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.
  // Declaration of leaf types
  
   Double_t HT;
   Double_t MHT;
   Int_t NJets;
   Int_t BJets;
   Double_t BTagSF;
   Double_t PhotonPt;
   Double_t PhotonEta;
   Double_t evWeight;
   Double_t puWeight;
   // List of branches
   TBranch        *b_HT;   //!
   TBranch        *b_MHT;   //!
   TBranch        *b_NJets;   //!
   TBranch        *b_BJets;   //!
   TBranch        *b_PhotonPt;   //!
   TBranch        *b_PhotonEta;   //!
   TBranch        *b_evWeight;   //!
   TBranch        *b_puWeight;
   TBranch        *b_BTagSF;

  ReadTree(TTree *tree);

   virtual ~ReadTree();

   
   int BinNumber();
   int BinNumberQCD();
   int BinNumberTroy();


};

ReadTree::~ReadTree()

{

   if (!fChain) return;

   delete fChain->GetCurrentFile();

}

 ReadTree::ReadTree(TTree *tree)

{


fChain=tree;
   
   
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("MHT", &MHT, &b_MHT);
   fChain->SetBranchAddress("NJets", &NJets, &b_NJets);
   fChain->SetBranchAddress("BJets", &BJets, &b_BJets);
   fChain->SetBranchAddress("PhotonPt", &PhotonPt, &b_PhotonPt);
   fChain->SetBranchAddress("PhotonEta", &PhotonEta, &b_PhotonEta);
   fChain->SetBranchAddress("evWeight", &evWeight, &b_evWeight);
   fChain->SetBranchAddress("BTagSF", &BTagSF, &b_BTagSF);
   fChain->SetBranchAddress("puWeight", &puWeight, &b_puWeight);

}



int ReadTree::BinNumber(){//bin number


int HTMHTbin=-1;
int NJetbin=-1;



if(HT>300 && HT<500 && MHT>300 && MHT < 350){

HTMHTbin=1;
}

if(HT>500 && HT<1000 && MHT>300 && MHT < 350){

HTMHTbin=2;
}

if(HT>1000 && HT<5000 && MHT>300 && MHT < 350){

HTMHTbin=3;
}



if(HT>350 && HT<500 && MHT>350 && MHT < 500){

HTMHTbin=4;
}

if(HT>500 && HT<1000 && MHT>350 && MHT < 500){

HTMHTbin=5;
}

if(HT>1000 && HT<5000 && MHT>350 && MHT < 500){

HTMHTbin=6;
}

if(HT>500 && HT<1000 && MHT>500 && MHT < 750){

HTMHTbin=7;
}


if(HT>1000 && HT<5000 && MHT>500 && MHT < 750){

HTMHTbin=8;
}



if(HT>750 && HT<1500 && MHT>750 && MHT < 5000){

HTMHTbin=9;
}

if(HT>1500 && HT<5000 && MHT>750 && MHT < 5000){

HTMHTbin=10;
}

if(NJets >= 3 && NJets <=4 ){

NJetbin=0;
}

if(NJets >=5 && NJets <=6){

NJetbin=1;
}

if(NJets >=7 && NJets <=8){

NJetbin=2;
}

if(NJets>= 9){

NJetbin=3;
}


if(NJetbin== -1 || HTMHTbin == -1){
return -1;
}


return 10*NJetbin+HTMHTbin;



}//bin number

/////////////////////////////////////////////////////////

int ReadTree::BinNumberQCD(){//bin number


int HTMHTbin=-1;
int NJetbin=-1;



if(HT>300 && HT<500 && MHT>250 && MHT < 300){

HTMHTbin=1;
}

if(HT>500 && HT<1000 && MHT>250 && MHT < 300){

HTMHTbin=2;
}

if(HT>1000 && HT<5000 && MHT>250 && MHT < 300){

HTMHTbin=3;
}



if(NJets >= 3 && NJets <=4 ){

NJetbin=0;
}

if(NJets >=5 && NJets <=6){

NJetbin=1;
}

if(NJets >=7 && NJets <=8){

NJetbin=2;
}

if(NJets>= 9){

NJetbin=3;
}


if(NJetbin== -1 || HTMHTbin == -1){
return -1;
}


return 3*NJetbin+HTMHTbin;



}//bin number





int ReadTree::BinNumberTroy(){//bin number


int HTMHTbin=-1;
int NJetbin=-1;



if(HT>300 && HT<500 && MHT>300 && MHT < 350){

HTMHTbin=1;
}

if(HT>500 && HT<1000 && MHT>300 && MHT < 350){

HTMHTbin=2;
}

if(HT>1000 && HT<5000 && MHT>300 && MHT < 350){

HTMHTbin=3;
}



if(HT>350 && HT<500 && MHT>350 && MHT < 500){

HTMHTbin=4;
}

if(HT>500 && HT<1000 && MHT>350 && MHT < 500){

HTMHTbin=5;
}

if(HT>1000 && HT<5000 && MHT>350 && MHT < 500){

HTMHTbin=6;
}

if(HT>500 && HT<1000 && MHT>500 && MHT < 750){

HTMHTbin=7;
}


if(HT>1000 && HT<5000 && MHT>500 && MHT < 750){

HTMHTbin=8;
}



if(HT>750 && HT<1500 && MHT>750 && MHT < 5000){

HTMHTbin=9;
}

if(HT>1500 && HT<5000 && MHT>750 && MHT < 5000){

HTMHTbin=10;
}





if(NJets ==3){

NJetbin=0;
}

if(NJets ==4){

NJetbin=1;
}

if(NJets ==5){

NJetbin=2;
}

if(NJets ==6){

NJetbin=3;
}

if(NJets ==7){

NJetbin=4;
}


if(NJets ==8){

NJetbin=5;
}


if(NJets>= 9){

NJetbin=7;
}







if(NJetbin== -1 || HTMHTbin == -1){
return -1;
}


return 10*NJetbin+HTMHTbin;



}//bin number















