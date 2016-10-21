#include<iostream>
#include "ReadTree.cc"
#include "StackPlot.C"
#include "SetStyle.C"
//#include "ComputeBin2016.C"
using namespace std;


void ZinvNewNoBSF(){



   //Set Canvas Style
     TStyle *gStyle = new TStyle("gStyle","Style for P-TDR");
     SetStyle st;
     st.SetPars(gStyle);


     TChain* tZinv = new TChain("SimpleTree");
     tZinv->Add("InputSkimZinv2016_V10.root");
     ReadTree Zinv(tZinv);


     TChain* tGJets = new TChain("SimpleTree");
     tGJets->Add("InputSkimGJetsDR42016_V10.root");
    
     ReadTree GJets(tGJets);


     TChain* tQCD = new TChain("SimpleTree");
     tQCD->Add("InputSkimQCD2016_V10.root");
    
     ReadTree QCD(tQCD);


     TChain* tData = new TChain("SimpleTree");
     tData->Add("InputSkimData2016_V10.root");//inputSkimData2016_V8_2p6.root");//InputSkimData2016.root");
    
     ReadTree Data(tData);



     double Lumi=12906.25;//7635.91;//
     int nBinAN=40;
     double nBinANmax=40.5;
     TH1F *h_NZinv40bin=new TH1F("h_NZinv40bin","h_NZinv40bin",nBinAN,0.5,nBinANmax);
     h_NZinv40bin->Sumw2();

     TH1F *h_NZinv40bin_WB=new TH1F("h_NZinv40bin_WB","h_NZinv40bin_WB",nBinAN,0.5,nBinANmax);
     h_NZinv40bin_WB->Sumw2();


     TH1F *h_NZinv40bin_WOB=new TH1F("h_NZinv40bin_WOB","h_NZinv40bin_WOB",nBinAN,0.5,nBinANmax);
     h_NZinv40bin_WOB->Sumw2();
     


     TH1F *h_NZinv40binP=new TH1F("h_NZinv40binP","h_NZinv40binP",nBinAN,0.5,nBinANmax);
     h_NZinv40binP->Sumw2();

    
     

     TH1F *h_NGJets40binEB=new TH1F("h_NGJets40binEB","h_NGJets40binEB",nBinAN,0.5,nBinANmax);
       h_NGJets40binEB->Sumw2();

     TH1F *h_NGJets40binEC=new TH1F("h_NGJets40binEC","h_NGJets40binEC",nBinAN,0.5,nBinANmax);
     h_NGJets40binEC->Sumw2();


     TH1F *h_NGJets40binEB_Wtd=new TH1F("h_NGJets40binEB_Wtd","h_NGJets40binEB_Wtd",nBinAN,0.5,nBinANmax);
       h_NGJets40binEB_Wtd->Sumw2();

     TH1F *h_NGJets40binEC_Wtd=new TH1F("h_NGJets40binEC_Wtd","h_NGJets40binEC_Wtd",nBinAN,0.5,nBinANmax);
     h_NGJets40binEC_Wtd->Sumw2();





     TH1F *h_NGJets40bin=new TH1F("h_NGJets40bin","h_NGJets40bin",nBinAN,0.5,nBinANmax);
     h_NGJets40bin->Sumw2();     

     TH1F *h_NGJets40bin_WOB=new TH1F("h_NGJets40bin_WOB","h_NGJets40bin_WOB",nBinAN,0.5,nBinANmax);
     h_NGJets40bin_WOB->Sumw2();


     TH1F *h_NQCD40binEB=new TH1F("h_NQCD40binEB","h_NQCD40binEB",nBinAN,0.5,nBinANmax);
       h_NQCD40binEB->Sumw2();


     TH1F *h_NQCD40binEC=new TH1F("h_NQCD40binEC","h_NQCD40binEC",nBinAN,0.5,nBinANmax);
     h_NQCD40binEC->Sumw2();



     TH1F *ZinvEstimate=new TH1F("ZinvEstimate","ZinvEstimate",nBinAN,0.5,nBinANmax);


      TH1F *h_Ndata40binEB=new TH1F("h_Ndata40binEB","h_Ndata40binEB",nBinAN,0.5,nBinANmax);
   
      TH1F *h_Ndata40binEC=new TH1F("h_Ndata40binEC","h_Ndata40binEC",nBinAN,0.5,nBinANmax);



     h_NZinv40bin->Sumw2();
     h_NGJets40bin->Sumw2();


    TH1F *hpu=new TH1F("hpu","hpu",40,0,2);


    for(int iz=0;iz<tZinv->GetEntries();iz++){// Zinv MC
      tZinv->GetEntry(iz);  

   
      if( Zinv.BJets==0 && Zinv.MHT > 300 && Zinv.HT > 300 && Zinv.NJets>=3  && Zinv.BinNumber() > -1){
        h_NZinv40bin->Fill(Zinv.BinNumber(),Zinv.puWeight*Zinv.evWeight*Lumi/1.23);

        h_NZinv40bin_WOB->Fill(Zinv.BinNumber(),Zinv.puWeight*Zinv.evWeight*Lumi);

        h_NZinv40bin_WB->Fill(Zinv.BinNumber(),Zinv.puWeight*Zinv.evWeight*Lumi/1.23);

        h_NZinv40binP->Fill(Zinv.BinNumber(),Zinv.puWeight*Zinv.evWeight*Lumi);


         }      



      }//Zinv MC



     double EBtrigger[40]={0.98692,0.98692,0.98692,0.98347,0.98347,0.98347,0.97952,0.97952,0.96992 ,0.96992,
0.98692,0.98692,0.98692,0.98347,0.98347,0.98347,0.97952,0.97952,0.96992 ,0.96992,
0.98692,0.98692,0.98692,0.98347,0.98347,0.98347,0.97952,0.97952,0.96992 ,0.96992,
0.98692,0.98692,0.98692,0.98347,0.98347,0.98347,0.97952,0.97952,0.96992 ,0.96992 };
     

     double ECtrigger[40]={0.94825,0.94825,0.94825,0.93808,0.93808,0.93808,0.96579,0.96579,1.00,1.00,
0.94825,0.94825,0.94825,0.93808,0.93808,0.93808,0.96579,0.96579,1.00,1.00,
0.94825,0.94825,0.94825,0.93808,0.93808,0.93808,0.96579,0.96579,1.00,1.00,
0.94825,0.94825,0.94825,0.93808,0.93808,0.93808,0.96579,0.96579,1.00,1.00};




    for(int i=0;i<tGJets->GetEntries();i++){// GJets MC
      tGJets->GetEntry(i);
           

      if( GJets.BJets==0 && GJets.PhotonPt > 200. && GJets.MHT > 300 && GJets.HT > 300 && GJets.NJets >=3 && GJets.BinNumber() > -1){//Batgs=0

       //cout<<"Weight: "<<GJets.evWeight*Lumi<<endl;

        double Weight=GJets.evWeight*Lumi;  

      


      //cout<<"puWeight: "<<GJets.puWeight<<endl;

      hpu->Fill(GJets.puWeight);


       if(fabs(GJets.PhotonEta) < 1.444){

        h_NGJets40binEB->Fill(GJets.BinNumber(),GJets.puWeight*Weight);//GJets.evWeight*Lumi/2);

        h_NGJets40bin->Fill(GJets.BinNumber(),GJets.puWeight*Weight*EBtrigger[GJets.BinNumber()-1]);//GJets.evWeight*Lumi/2);

        h_NGJets40bin_WOB->Fill(GJets.BinNumber(),GJets.puWeight*Weight*EBtrigger[GJets.BinNumber()-1]);


        h_NGJets40binEB_Wtd->Fill(GJets.BinNumber(),GJets.puWeight*Weight*EBtrigger[GJets.BinNumber()-1]);
       


          }   

     if(fabs(GJets.PhotonEta)> 1.566 && fabs(GJets.PhotonEta) < 2.5){

        h_NGJets40binEC->Fill(GJets.BinNumber(),GJets.puWeight*Weight);//GJets.evWeight*Lumi/2);

        h_NGJets40bin->Fill(GJets.BinNumber(),GJets.puWeight*Weight*ECtrigger[GJets.BinNumber()-1]);//GJets.evWeight*Lumi/2);

        h_NGJets40binEC_Wtd->Fill(GJets.BinNumber(),GJets.puWeight*Weight*ECtrigger[GJets.BinNumber()-1]);
        
        h_NGJets40bin_WOB->Fill(GJets.BinNumber(),GJets.puWeight*Weight*ECtrigger[GJets.BinNumber()-1]);

        }


          }//Batg=0



      }//GJets MC




    for(int i=0;i<tQCD->GetEntries();i++){// QCD MC
      tQCD->GetEntry(i);
      
         

      if( QCD.BJets==0 && QCD.PhotonPt > 200 && QCD.MHT > 300 && QCD.HT >300 && QCD.NJets >=3 && QCD.BinNumber()> -1){


      if(fabs(QCD.PhotonEta) < 1.444){

        h_NQCD40binEB->Fill(QCD.BinNumber(),QCD.evWeight*Lumi);

          }   

     if(fabs(QCD.PhotonEta)> 1.566 && fabs(QCD.PhotonEta) < 2.5){

        h_NQCD40binEC->Fill(QCD.BinNumber(),QCD.evWeight*Lumi);


        }



          }



      }//QCD MC


    int NumPh=0;

    
     int maxEvents_Data=tData->GetEntries();
     for(int iEv=0;iEv<maxEvents_Data;iEv++){//Data
     tData->GetEntry(iEv);
     if(iEv % 1000000==0){cout<<"Event no Data : "<<iEv<<endl;}

     
     

     if(  Data.BJets==0 && Data.MHT > 300 && Data.HT > 300 && Data.NJets>=3 && Data.BinNumber() > -1 && Data.PhotonPt > 200 ){//Btags==0

      NumPh++;
      if(fabs(Data.PhotonEta) < 1.444){

        h_Ndata40binEB->Fill(Data.BinNumber());

          }   

     if(fabs(Data.PhotonEta)> 1.566 && fabs(Data.PhotonEta) < 2.5){

        h_Ndata40binEC->Fill(Data.BinNumber());


        }


        }//Batgs==0

      



    
     }//Data


   cout<<"Num Photon: "<<NumPh<<endl;


     TPaveText *tpav1 = new TPaveText(0.1956522,0.6247818,0.729097,0.8970332,"brNDC");

    tpav1->SetBorderSize(0);
    tpav1->SetFillStyle(0);
    tpav1->SetTextAlign(11);
    tpav1->SetTextFont(42);
    tpav1->SetTextSize(0.04);
    tpav1->AddText("H_{T} >300");
    tpav1->AddText("#gamma p_{T} > 200 ");
    tpav1->AddText("N_{jets} >=3");
    tpav1->AddText("H_{T}^{miss}>300");
    tpav1->AddText("N_{b-jets}=0");
    //tpav1->AddText("#Delta #Phi_{1,2,3,4}>(0.5,0.5,0.3,0.3)");

    TPaveText *pCMS1 = new TPaveText(0.132107,0.9308003,0.8327759,0.9923583,"brNDC");

    pCMS1->SetBorderSize(0);
    pCMS1->SetFillStyle(0);
    pCMS1->SetTextAlign(11);
    pCMS1->SetTextFont(42);
    pCMS1->SetTextSize(0.04);
    pCMS1->AddText("CMS #it{Preliminary}                      #sqrt{s}= 13 TeV");

  
     TCanvas *cZgammaR=new TCanvas("cZGammaR","cZGammaR");
     TH1F *h_ZgR = (TH1F*)h_NZinv40bin->Clone("h_ZgR");
     h_ZgR->GetYaxis()->SetTitle("R_{Z/#gamma}");
     h_ZgR->GetXaxis()->SetTitle("bin number");
     h_ZgR->Sumw2();

     h_ZgR->Divide(h_NGJets40bin);


     cZgammaR->cd();
     h_ZgR->Draw("hist");
     h_ZgR->Draw("E2");
     tpav1->Draw();
     pCMS1->Draw();



     cZgammaR->SaveAs("ZgammaRatioWOSF.png");
     cZgammaR->SaveAs("ZgammaRatioWOSF.pdf");
     cZgammaR->SaveAs("ZgammaRatioWOSF.gif");
     cZgammaR->SaveAs("ZgammaRatioWOSF.eps");


    TH1F *hRZGamma=(TH1F*)h_ZgR->Clone("hRZGamma");
  
     for(int irz=1;irz<41;irz++){
      if(hRZGamma->GetBinContent(irz)==0){
          
        hRZGamma->SetBinContent(irz,0.45);
        hRZGamma->SetBinError(irz,0.2);

           }


          }



     TH1F *hDR =new TH1F("hDR","hDR",nBinAN,0.5,nBinANmax);
     TH1F *hDRerrUp =new TH1F("hDRerrUp","hDRerrUp",nBinAN,0.5,nBinANmax);
     TH1F *hDRerrLow =new TH1F("hDRerrLow","hDRerrLow",nBinAN,0.5,nBinANmax);

     TH1F *hEBPurity=new TH1F("hEBPurity","hEBPurity",nBinAN,0.5,nBinANmax);
     TH1F *hECPurity=new TH1F("hECPurity","hECPurity",nBinAN,0.5,nBinANmax);
     
     TH1F *hEBfrag=new TH1F("hEBfrag","hEBfrag",nBinAN,0.5,nBinANmax);
     TH1F *hECfrag=new TH1F("hECfrag","hECfrag",nBinAN,0.5,nBinANmax); 



     


     TH1F *h_DataSimEB = (TH1F*)h_Ndata40binEB->Clone("h_DataSimEB");
     
     TH1F *h_DataSimEC = (TH1F*)h_Ndata40binEC->Clone("h_DataSimEC");
   

     TH1F *h_DataSimEBforErr = (TH1F*)h_NGJets40binEB->Clone("h_DataSimEBforErr");
     
     TH1F *h_DataSimECforErr = (TH1F*)h_NGJets40binEC->Clone("h_DataSimECforErr");
     
     h_DataSimEBforErr->Scale((1/h_DataSimEBforErr->Integral())*h_Ndata40binEB->Integral());
     h_DataSimECforErr->Scale((1/h_DataSimECforErr->Integral())*h_Ndata40binEC->Integral());







       




        double DRerUp[40];
        double DRerLow[40];

    for(int ittt=0;ittt<40;ittt++){DRerUp[ittt]=0;}
    for(int itt=0;itt<40;itt++){DRerLow[itt]=0;}

        
    //cout<<"test1 "<<endl;



      for(int idr=1;idr<41;idr++){
         hDR->SetBinContent(idr,1);
         hDRerrUp->SetBinContent(idr,DRerUp[idr-1]);
         hDRerrLow->SetBinContent(idr,DRerLow[idr-1]);

             }


   // cout<<"test2 "<<endl;



     double EBpurity[40]={0.9556,0.9556,0.9556,0.9708,0.9708,0.9708,0.9875,0.9875,0.9875,0.9875,
0.9556,0.9556,0.9556,0.9708,0.9708,0.9708,0.9875,0.9875,0.9875,0.9875,
0.9556,0.9556,0.9556,0.9708,0.9708,0.9708,0.9875,0.9875,0.9875,0.9875,
0.9556,0.9556,0.9556,0.9708,0.9708,0.9708,0.9875,0.9875,0.9875,0.9875};

     double EBpurityErr[40]={0.0359,0.0359,0.0359,0.0237,0.0237,0.0237,0.0118,0.0118,0.0118,0.0118,
0.0359,0.0359,0.0359,0.0237,0.0237,0.0237,0.0118,0.0118,0.0118,0.0118,
0.0359,0.0359,0.0359,0.0237,0.0237,0.0237,0.0118,0.0118,0.0118,0.0118,
0.0359,0.0359,0.0359,0.0237,0.0237,0.0237,0.0118,0.0118,0.0118,0.0118};

     double ECpurity[40]={0.8747,0.8747,0.8747,0.904,0.904,0.904,0.9467,0.9467,0.9467,0.9467,
0.8747,0.8747,0.8747,0.904,0.904,0.904,0.9467,0.9467,0.9467,0.9467,
0.8747,0.8747,0.8747,0.904,0.904,0.904,0.9467,0.9467,0.9467,0.9467,
0.8747,0.8747,0.8747,0.904,0.904,0.904,0.9467,0.9467,0.9467,0.9467};

     double ECpurityErr[40]={0.0246,0.0246,0.0246,0.0281,0.0281,0.0281,0.0330,0.0330,0.0330,0.0330,
0.0246,0.0246,0.0246,0.0281,0.0281,0.0281,0.0330,0.0330,0.0330,0.0330,
0.0246,0.0246,0.0246,0.0281,0.0281,0.0281,0.0330,0.0330,0.0330,0.0330,
0.0246,0.0246,0.0246,0.0281,0.0281,0.0281,0.0330,0.0330,0.0330,0.0330};

           



     for(int ip=1;ip<41;ip++){

     hEBPurity->SetBinContent(ip,EBpurity[ip-1]);
     hEBPurity->SetBinError(ip,EBpurityErr[ip-1]);
     hECPurity->SetBinContent(ip,ECpurity[ip-1]);
     hECPurity->SetBinError(ip,ECpurityErr[ip-1]);

        }

   //cout<<"test2 "<<endl;




   ////////////////////////////////////////////////////////////////////////////
  ///////////////////////////////////////////////////////////////////////////


   int nBinAN=40;


   int totalDataevents=0;
   int totalGJetsMCevents=0;

    const Int_t NumBins= 40;
    double binNumber[40];
    double YieldEstimated[40];
    double YieldErrUp_Estimated[40];
    double YieldErrLow_Estimated[40];

    double YieldPredMC[40];
    double YieldErrUp_PredMC[40];
    double YieldErrLow_PredMC[40];

    double XErrLow[40];
    double XErrUp[40];


    double ZgRwSF[40];
    double ZgRwSF_sys_ErrUp[40];
    double ZgRwSF_sys_ErrLow[40];
    double ZgRwSF_stat_Err[40];

   //cout<<"test3 "<<endl;
    
    for(int ibin=1;ibin<(nBinAN+1);ibin++){//loop over bin error calculation


       double SF=0.99;
       double SFup=1.04;
       double SFlow=0.94;
       double ZgRcentral=hRZGamma->GetBinContent(ibin)/SF;
       double ZgRup=hRZGamma->GetBinContent(ibin)/SFup;
       double ZgRlow=hRZGamma->GetBinContent(ibin)/SFlow;

       double ZgRcorelErrup=fabs(ZgRcentral-ZgRlow);
       double ZgRcorelErrlow=fabs(ZgRcentral-ZgRup);

       double ZgRsymErr=0.5*(sqrt((ZgRcorelErrup*ZgRcorelErrup)+(ZgRcorelErrlow*ZgRcorelErrlow)));
       double ZgRcorel_Rel_Errup=ZgRcorelErrup/ZgRcentral;
       double ZgRcorel_Rel_Errlow=ZgRcorelErrlow/ZgRcentral;

       

       //double ZgRcorelErr=sqrt((ZgRcorelErrup*ZgRcorelErrup)+(ZgRcorelErrlow*ZgRcorelErrlow));

       double ZgRuncorelErr=hRZGamma->GetBinError(ibin)/SF;

       double ZgRuncorel_Rel_Err=ZgRuncorelErr/ZgRcentral;
   
       double ZgRsymErrStat=hRZGamma->GetBinError(ibin)/SF;//h_ZgR->GetBinError(ibin);
       
       double ZgRallSymErr=sqrt((ZgRsymErr*ZgRsymErr)+(ZgRsymErrStat*ZgRsymErrStat));

       

       
       //important lines to be changed
       double ZgR=ZgRcentral;
       
       double ZgRerr=ZgRallSymErr;
   
       double ZgRerrUp=sqrt((ZgRcorelErrup*ZgRcorelErrup)+(ZgRuncorelErr*ZgRuncorelErr));
       double ZgRerrLow=sqrt((ZgRcorelErrlow*ZgRcorelErrlow)+(ZgRuncorelErr*ZgRuncorelErr));
     

       ////////////////////////////////////barrel starts
       int EBobs=h_DataSimEB->GetBinContent(ibin);
       double EBobsErr=h_DataSimEB->GetBinError(ibin);     

       double pEB=hEBPurity->GetBinContent(ibin);
       double pEBerr=hEBPurity->GetBinError(ibin);
       double pEB_Rel_err=pEBerr/pEB;


       int ECobs=h_DataSimEC->GetBinContent(ibin);
       double ECobsErr=h_DataSimEC->GetBinError(ibin);

       double pEC=hECPurity->GetBinContent(ibin);
       double pECerr=hECPurity->GetBinError(ibin);       
       double pEC_Rel_err=pECerr/pEC;

       double f=0.92;
       double ferr=0.0;
       double f_Rel_err=ferr/f;

      // double YieldTotal=ZgR*(EBobs*pEB+ECobs*pEC)*f;


      //cout<<"test1 "<<endl;



       int Nobserved=EBobs+ECobs;

       
       double totalPurity=0;
       double totalPurityErr=0;
       double totalPurity_Rel_Err=0;
       
       double ZinvMCYield=h_NZinv40binP->GetBinContent(ibin);
       double ZinvMCYieldErr=h_NZinv40binP->GetBinError(ibin);
       double ZinvMCYield_Rel_Err=ZinvMCYieldErr/ZinvMCYield;

     double DR=1.0;
     double DRup=hDRerrUp->GetBinContent(ibin);
     double DRlow=hDRerrLow->GetBinContent(ibin);
     double DRabsUp=hDRerrUp->GetBinContent(ibin)*DR;
     double DRabsLow=hDRerrLow->GetBinContent(ibin)*DR;

     






       double YieldTotal=ZgR*(EBobs*pEB+ECobs*pEC)*f*DR;
       double YieldTotalDR=ZgR*(EBobs*pEB+ECobs*pEC)*f*DR;






          double YieldErr_StatUp=0;
          double YieldErr_StatLow=0;
 
          double YieldErr_Rel_StatUp=0;
          double YieldErr_Rel_StatLow=0;



          double YieldErr_SysUp=0;
          double YieldErr_SysLow=0;

         

          double YieldErr_Rel_SysUp=0;
          double YieldErr_Rel_SysLow=0;





          double NobsErr=sqrt(Nobserved);


        totalDataevents=totalDataevents+Nobserved;





       if(Nobserved !=0){
          totalPurity=((EBobs*pEB+ECobs*pEC)*f)/Nobserved;
          double totalPurity1=((EBobs*pEB+ECobs*pEC))/Nobserved;
          double totalPurityErr1=(EBobs*pEBerr+ECobs*pECerr)/Nobserved;
          double totalPurityErr2=ferr;
          totalPurityErr=sqrt((totalPurityErr1*totalPurityErr1*f*f)+(totalPurityErr2*totalPurityErr2*totalPurity1*totalPurity1));
          totalPurity_Rel_Err=totalPurityErr/totalPurity;


          //cout<<"EB err : "<<pEBerr<<endl;
          //cout<<"EC err : "<<pECerr<<endl;







         ////////////////////with DR



         ///////////////////stat error calculation
         

        


        YieldErr_SysUp=Nobserved*sqrt((DR*totalPurity*ZgRerrUp)*(DR*totalPurity*ZgRerrUp) + (DR*ZgR*totalPurityErr)*(DR*ZgR*totalPurityErr) + (totalPurity*ZgR*DRabsUp)*(totalPurity*ZgR*DRabsUp));


      YieldErr_SysLow=Nobserved*sqrt((DR*totalPurity*ZgRerrLow)*(DR*totalPurity*ZgRerrLow) + (DR*ZgR*totalPurityErr)*(DR*ZgR*totalPurityErr) + (totalPurity*ZgR*DRabsLow)*(totalPurity*ZgR*DRabsLow));


         YieldErr_StatUp=DR*ZgR*totalPurity*(sqrt(Nobserved));
         YieldErr_StatLow=DR*ZgR*totalPurity*(sqrt(Nobserved));




        YieldErr_Rel_SysUp=YieldErr_SysUp/YieldTotal;
        YieldErr_Rel_SysLow=YieldErr_SysLow/YieldTotal;
        YieldErr_Rel_StatUp=YieldErr_StatUp/YieldTotal;
        YieldErr_Rel_StatLow=YieldErr_StatLow/YieldTotal;



     

         // cout<<"DR : "<<DR<<endl;
         // cout<<"DRabsup : "<<DRabsUp<<endl;
         // cout<<"total purity : "<<totalPurity<<endl;
         // cout<<"total purity Err "<<totalPurityErr<<endl;
         // cout<<"ZgR : "<<ZgR<<endl;
         // cout<<"ZgR Err : "<<ZgRerrUp<<endl;   
         // cout<<"Nobs: "<<Nobserved<<endl;
   





  


         



        //////////////////////stat error calculation



           }
        if(Nobserved ==0){

          double NobservedNew=h_DataSimEBforErr->GetBinContent(ibin)+h_DataSimECforErr->GetBinContent(ibin);
          NobsErr=sqrt(NobservedNew);
          double EBobsNew=h_DataSimEBforErr->GetBinContent(ibin);
          double ECobsNew=h_DataSimECforErr->GetBinContent(ibin);

          if(EBobsNew==0 && ECobsNew==0){
           
           EBobsNew=0.1;
           ECobsNew=0.1;
           NobservedNew=0.2;
           }

         

          totalPurity=((EBobsNew*pEB+ECobsNew*pEC)*f)/NobservedNew;
          
          double totalPurity1=((EBobsNew*pEB+ECobsNew*pEC))/NobservedNew;
           //if(ibin==24){cout<<"Total : "<<totalPurity<<endl;}

          double totalPurityErr1=(EBobsNew*pEBerr+ECobsNew*pECerr)/NobservedNew;
          double totalPurityErr2=ferr;
          totalPurityErr=sqrt((totalPurityErr1*totalPurityErr1*f*f)+(totalPurityErr2*totalPurityErr2*totalPurity1*totalPurity1));
          totalPurity_Rel_Err=totalPurityErr/totalPurity;


          double YieldTotalNew=ZgR*(EBobsNew*pEB+ECobsNew*pEC)*f*DR;


          //////////////////////////////////// with DR
          

           /////////////////////////////with DR


          //////////////////////////stat error calculation
         

       YieldErr_SysUp=NobservedNew*sqrt((DR*totalPurity*ZgRerrUp)*(DR*totalPurity*ZgRerrUp) + (DR*ZgR*totalPurityErr)*(DR*ZgR*totalPurityErr) + (totalPurity*ZgR*DRabsUp)*(totalPurity*ZgR*DRabsUp));


      YieldErr_SysLow=NobservedNew*sqrt((DR*totalPurity*ZgRerrLow)*(DR*totalPurity*ZgRerrLow) + (DR*ZgR*totalPurityErr)*(DR*ZgR*totalPurityErr) + (totalPurity*ZgR*DRabsLow)*(totalPurity*ZgR*DRabsLow));


         YieldErr_StatUp=DR*ZgR*totalPurity*(1.8);
         YieldErr_StatLow=DR*ZgR*totalPurity*(0.);


        YieldErr_Rel_SysUp=YieldErr_SysUp/YieldTotalNew;
        YieldErr_Rel_SysLow=YieldErr_SysLow/YieldTotalNew;
        YieldErr_Rel_StatUp=YieldErr_StatUp/YieldTotalNew;
        YieldErr_Rel_StatLow=YieldErr_StatLow/YieldTotalNew;

 

        //////////////////////////stat error calculation



           }


 
    double YieldTotalErrorUp=sqrt((YieldErr_SysUp*YieldErr_SysUp)+(YieldErr_StatUp*YieldErr_StatUp));
    double YieldTotalErrorLow=sqrt((YieldErr_SysLow*YieldErr_SysLow)+(YieldErr_StatLow*YieldErr_StatLow));     

   

 
     ZgRwSF[ibin-1]=ZgR;
     ZgRwSF_sys_ErrUp[ibin-1]=ZgRcorelErrup;
     ZgRwSF_sys_ErrLow[ibin-1]=ZgRcorelErrlow;
     ZgRwSF_stat_Err[ibin-1]=ZgRuncorelErr;
      
      
      binNumber[ibin-1]=ibin;
      YieldEstimated[ibin-1]=YieldTotal;
      YieldErrUp_Estimated[ibin-1]=YieldTotalErrorUp;
      YieldErrLow_Estimated[ibin-1]=YieldTotalErrorLow;
  
      YieldPredMC[ibin-1]=ZinvMCYield;
      YieldErrUp_PredMC[ibin-1]=ZinvMCYieldErr;
      YieldErrLow_PredMC[ibin-1]=ZinvMCYieldErr;
      XErrLow[ibin-1]=0.5;
      XErrUp[ibin-1]=0.5;    



     double GJetsMC=0;
     double GJetsMCEB=h_NGJets40binEB->GetBinContent(ibin);
     double GJetsMCEC=h_NGJets40binEC->GetBinContent(ibin);
     double GJetsMCEBerr=h_NGJets40binEB->GetBinError(ibin);
     double GJetsMCECerr=h_NGJets40binEC->GetBinError(ibin);

     

     double GJetsMCEB_Wtd=h_NGJets40binEB_Wtd->GetBinContent(ibin);
     double GJetsMCEC_Wtd=h_NGJets40binEC_Wtd->GetBinContent(ibin);


     double GJetsMC=GJetsMCEB+GJetsMCEC;
     double GJetsMCerr=sqrt((GJetsMCEBerr)*(GJetsMCEBerr)+(GJetsMCECerr)*(GJetsMCECerr));

     totalGJetsMCevents=totalGJetsMCevents+h_NGJets40bin->GetBinContent(ibin);

     
printf(" %i : %4.1f( %4.3f)|%4.1f |%4.1f |%i |%i| %4.3f(%4.3f) |%i| %4.3f(%4.3f) |%4.3f(%4.3f,+%4.3f-%4.3f) |%4.3f(%4.3f) |%4.3f(%4.3f)| %4.3f(+%4.3f-%4.3f)| %4.3f(+%4.3f-%4.3f,+%4.3f-%4.3f)",ibin,GJetsMC,GJetsMCerr,GJetsMCEB_Wtd,GJetsMCEC_Wtd,Nobserved, EBobs,pEB,pEB_Rel_err,ECobs,pEC,pEC_Rel_err, ZgR,ZgRuncorel_Rel_Err,ZgRcorel_Rel_Errup,ZgRcorel_Rel_Errlow,f,f_Rel_err,totalPurity,totalPurity_Rel_Err,DR,DRup,DRlow,YieldTotal,YieldErr_Rel_StatUp,YieldErr_Rel_StatLow,YieldErr_Rel_SysUp,YieldErr_Rel_SysLow);


//printf(" %i :%i |%i| %4.3f(%4.3f) |%i| %4.3f(%4.3f) |%4.3f(%4.3f,+%4.3f-%4.3f) |%4.3f(%4.3f) |%4.3f(%4.3f)| %4.3f(+%4.3f-%4.3f)| %4.3f(+%4.3f-%4.3f,+%4.3f-%4.3f)",ibin,Nobserved, EBobs,pEB,pEBerr,ECobs,pEC,pECerr, ZgR,ZgRuncorelErr,ZgRcorelErrup,ZgRcorelErrlow,f,ferr,totalPurity,totalPurityErr,DR,DRabsUp,DRabsLow,YieldTotal,YieldErr_StatUp,YieldErr_StatLow,YieldErr_SysUp,YieldErr_SysLow);


cout<<endl;
     

      
     // double Percent=(int)round(100*(YieldTotalErr/YieldTotal));

      
      double maxErrorYield=2;//max(YieldErrWithStatUp,YieldErrWithStatLow);
      ZinvEstimate->SetBinContent(ibin,YieldTotal);
      ZinvEstimate->SetBinError(ibin,maxErrorYield);

       /////////////////endcap ends

        

       }//loop over bin error calculation




   cout<<"total Single photon events: "<<totalDataevents<<endl;
   cout<<"total GJets MC events: "<<totalGJetsMCevents<<endl;
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

   TLegend *legP = new TLegend(0.2173913,0.2478185,0.5167224,0.4363002,NULL,"brNDC");
      legP->SetBorderSize(0);
      legP->SetTextFont(62);
      legP->SetTextSize(0.03);
      legP->SetLineColor(1);
      legP->SetLineStyle(1);
      legP->SetLineWidth(3);
      legP->SetFillColor(0);
      legP->SetFillStyle(1001);


   TPaveText *tpa = new TPaveText(0.5056522,0.6247818,0.829097,0.8970332,"brNDC");

      tpa->SetBorderSize(0);
      tpa->SetFillStyle(0);
      tpa->SetTextAlign(11);
      tpa->SetTextFont(42);
      tpa->SetTextSize(0.04);
      tpa->AddText("H_{T} >300");
      tpa->AddText("N_{jets} #geq 3");
      tpa->AddText("H_{T}^{miss}>300");
      tpa->AddText("N_{b-jets}=0");
      tpa->AddText("#Delta #Phi_{1,2,3,4}>(0.5,0.5,0.3,0.3)");

   TPaveText *pCMS = new TPaveText(0.132107,0.9308003,0.8327759,0.9923583,"brNDC");

      pCMS->SetBorderSize(0);
      pCMS->SetFillStyle(0);
      pCMS->SetTextAlign(11);
      pCMS->SetTextFont(42);
      pCMS->SetTextSize(0.04);
      pCMS->AddText("CMS #it{Preliminary}       2.3 fb^{-1} #sqrt{s}= 13 TeV");






   TCanvas *cPredVsEstimated = new TCanvas("estvspred","estvspred");
     
       TPad *pad1 = new TPad("pad1", "pad1", 0., 0.3, 1, 1.0);
       pad1->SetBottomMargin(0); // Upperand lower plot are joined
       pad1->Draw();             // Draw the upper pad: pad1
       gPad->Update();
       pad1->cd();               // pad1 becomes the current pad
       gPad->DrawFrame(0.5, 0.01, 40.5, 2000, "PredVsEst;ith Bin;Events");
       gPad->SetLogy();
     
     TGraphAsymmErrors *gr_estimated = new TGraphAsymmErrors(NumBins,binNumber,YieldEstimated,XErrLow,XErrUp,YieldErrLow_Estimated,YieldErrUp_Estimated);
     gr_estimated->SetTitle("Estimated");
     gr_estimated->SetMarkerColor(4);
     gr_estimated->SetLineColor(4);
     gr_estimated->SetMarkerStyle(21);
     

     TGraphAsymmErrors *gr_mcPred = new TGraphAsymmErrors(NumBins,binNumber,YieldPredMC,XErrLow,XErrUp,YieldErrLow_PredMC,YieldErrUp_PredMC);
     gr_mcPred->SetTitle("MC predicted");
     gr_mcPred->SetMarkerColor(2);
     gr_mcPred->SetLineColor(2);
     gr_mcPred->SetMarkerStyle(8);


      legP->AddEntry(gr_mcPred,"Z#rightarrow #nu#nu MC","P");
      
      legP->AddEntry(gr_estimated,"Prediction from #gamma +jets","P");

    


     char TMgname1[100];
     TMultiGraph *TMg_1D[2];
     for(int k0=0;k0<2;k0++){
     sprintf(TMgname1,"TMg_1D%i",k0);
     TMg_1D[k0]=new TMultiGraph();
      }
     for(int j0=0;j0<2;j0++){
     TMg_1D[j0]->SetMinimum(0.01);
     TMg_1D[j0]->SetMaximum(2000);
      }
      
    TMg_1D[0]->SetTitle(" ;ith Bin ; Events ");

    TMg_1D[0]->Add(gr_mcPred);
    TMg_1D[0]->Add(gr_estimated);


    
    TMg_1D[0]->Draw("AP");
    TMg_1D[0]->GetXaxis()->SetLimits(0.5,40.5); 
   
    tpa->Draw();
    pCMS->Draw();
    legP->Draw();


   TGaxis *axis = new TGaxis( -5, 20, -5, 220, 20,220,510,"");
       axis->SetLabelFont(43); // Absolute font size in pixel (precision 3)
       axis->SetLabelSize(15);
       axis->Draw();



  cPredVsEstimated->cd();

      TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
      pad2->SetTopMargin(0);
      pad2->SetBottomMargin(0.2);
      pad2->SetGridy(); // vertical grid
      pad2->Draw();
      pad2->cd();       // pad2 becomes the current pad


   TH1F *h3 = (TH1F*)h_NZinv40binP->Clone("h3");
   h3->SetLineColor(kBlack);
   h3->SetMinimum(0);  // Define Y ..
   h3->SetMaximum(4); // .. range
   h3->Sumw2();
   h3->SetStats(0);      // No statistics on lower plot
   h3->Divide(ZinvEstimate);
   h3->SetMarkerStyle(21);
   h3->SetMarkerColor(1);
   h3->Draw("ep");       // Draw the r
   h3->GetXaxis()->SetTitle("ith Bin"); // Remove the ratio title

   // Y axis ratio plot settings
   h3->GetYaxis()->SetTitle("Zinv/Pred");
   h3->GetYaxis()->SetNdivisions(505);

   h3->GetYaxis()->SetTitleSize(20);
   h3->GetYaxis()->SetTitleFont(43);
   h3->GetYaxis()->SetTitleOffset(1.55);
   h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   h3->GetYaxis()->SetLabelSize(15);

   // X axis ratio plot settings
   h3->GetXaxis()->SetTitleSize(20);
   h3->GetXaxis()->SetTitleFont(43);
   h3->GetXaxis()->SetTitleOffset(3.);
   h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   h3->GetXaxis()->SetLabelSize(15);


     cPredVsEstimated->SaveAs("PredVsEstimated.png");
     cPredVsEstimated->SaveAs("PredVsEstimated.gif");
     cPredVsEstimated->SaveAs("PredVsEstimated.pdf");
     cPredVsEstimated->SaveAs("PredVsEstimated.eps");

















 //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////








   TCanvas *cpu=new TCanvas("cpu","cpu");

    hpu->Draw();
    cpu->SaveAs("puWeight.png");



     /*

      TCanvas *c[10];

      DataMC plot;   

      plot.plotHist(h_Ndata40binEB,h_NGJets40binEB,h_NQCD40binEB,c[0],"EB","Data","MC","Bin_number-EB");
   
      plot.plotHist(h_Ndata40binEC,h_NGJets40binEC,h_NQCD40binEC,c[1],"EE","Data","MC","Bin_number-EE");

     */

    
























}
