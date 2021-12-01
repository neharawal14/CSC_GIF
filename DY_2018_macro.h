//////////////////////////////////////////////////////////
// this class has been automatically generated on
// Wed Sep 22 10:00:04 2021 by ROOT version 6.24/04
// from TTree passedEvents/passedEvents
// found on file: DY_2018.root
//////////////////////////////////////////////////////////

#ifndef DY_2018_macro_h
#define DY_2018_macro_h
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooGaussian.h"
#include "RooConstVar.h"
#include "RooHistPdf.h"
#include "RooPolynomial.h"
#include "RooAbsArg.h"
#include "RooPlot.h"
#include "TRatioPlot.h"
#include "RooAddPdf.h"
#include "RooFitResult.h"
#include "TAxis.h"
#include "TH1.h"
using namespace RooFit ;
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class DY_2018_macro {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        GENmass2l;
   Double_t        genLep_pt1;
   Double_t        genLep_pt2;
   Double_t        genLep_eta1;
   Double_t        genLep_eta2;
   Double_t        genLep_phi1;
   Double_t        genLep_phi2;
   Int_t           NInt;
   Int_t           NVtx;
   Double_t        PvX;
   Double_t        PvY;
   Double_t        PvZ;
   Double_t        BsX;
   Double_t        BsY;
   Double_t        BsZ;
   Double_t        massZ;
   Double_t        massZErr;
   Double_t        massZ_FSR;
   Double_t        massZErr_FSR;
   Double_t        massZ_single_BS;
   Double_t        massZ_vtx;
   Double_t        massZ_vtx_FSR;
   Double_t        massZErr_vtx;
   Double_t        massZErr_vtx_FSR;
   Double_t        massZ_vtxChi2;
   Double_t        massZ_vtx_BS;
   Double_t        massZ_vtx_BS_FSR;
   Double_t        massZErr_vtx_BS;
   Double_t        massZErr_vtx_BS_FSR;
   Double_t        massZ_vtxChi2_BS;
   Double_t        PvX1;
   Double_t        PvX2;
   Double_t        PvY1;
   Double_t        PvY2;
   Double_t        PvZ1;
   Double_t        PvZ2;
   Double_t        BsX1;
   Double_t        BsX2;
   Double_t        BsY1;
   Double_t        BsY2;
   Double_t        BsZ1;
   Double_t        BsZ2;
   Double_t        muonPV_x1;
   Double_t        muonPV_y1;
   Double_t        muonPV_z1;
   Double_t        muonPV_x2;
   Double_t        muonPV_y2;
   Double_t        muonPV_z2;
   Double_t        pT1_FromMuonBestTrack;
   Double_t        pT2_FromMuonBestTrack;
   Double_t        eta1_FromMuonBestTrack;
   Double_t        eta2_FromMuonBestTrack;
   Double_t        phi1_FromMuonBestTrack;
   Double_t        phi2_FromMuonBestTrack;
   Double_t        pT1_genFromReco;
   Double_t        pT2_genFromReco;
   Double_t        pT1;
   Double_t        pT2;
   Double_t        eta1;
   Double_t        eta2;
   Double_t        phi1;
   Double_t        phi2;
   Double_t        m1;
   Double_t        m2;
   Double_t        pT_FSR1;
   Double_t        pT_FSR2;
   Double_t        eta_FSR1;
   Double_t        eta_FSR2;
   Double_t        phi_FSR1;
   Double_t        phi_FSR2;
   Double_t        m_FSR1;
   Double_t        m_FSR2;
   Double_t        Tracker1;
   Double_t        Tracker2;
   Double_t        single_BS_pT1;
   Double_t        single_BS_pT2;
   Double_t        single_BS_eta1;
   Double_t        single_BS_eta2;
   Double_t        single_BS_phi1;
   Double_t        single_BS_phi2;
   Double_t        single_BS_m1;
   Double_t        single_BS_m2;
   Double_t        vtx_pT1;
   Double_t        vtx_pT2;
   Double_t        vtx_eta1;
   Double_t        vtx_eta2;
   Double_t        vtx_phi1;
   Double_t        vtx_phi2;
   Double_t        vtx_m1;
   Double_t        vtx_m2;
   Double_t        vtx_BS_pT1;
   Double_t        vtx_BS_pT2;
   Double_t        vtx_BS_eta1;
   Double_t        vtx_BS_eta2;
   Double_t        vtx_BS_phi1;
   Double_t        vtx_BS_phi2;
   Double_t        vtx_BS_m1;
   Double_t        vtx_BS_m2;
   Double_t        vtx_pT_FSR1;
   Double_t        vtx_pT_FSR2;
   Double_t        vtx_eta_FSR1;
   Double_t        vtx_eta_FSR2;
   Double_t        vtx_phi_FSR1;
   Double_t        vtx_phi_FSR2;
   Double_t        vtx_m_FSR1;
   Double_t        vtx_m_FSR2;
   Double_t        vtx_BS_pT_FSR1;
   Double_t        vtx_BS_pT_FSR2;
   Double_t        vtx_BS_eta_FSR1;
   Double_t        vtx_BS_eta_FSR2;
   Double_t        vtx_BS_phi_FSR1;
   Double_t        vtx_BS_phi_FSR2;
   Double_t        vtx_BS_m_FSR1;
   Double_t        vtx_BS_m_FSR2;
   Double_t        d0BS1;
   Double_t        d0BS2;
   Double_t        d0BS_vtx_BS1;
   Double_t        d0BS_vtx_BS2;
   Int_t           Id1;
   Int_t           Id2;
   Double_t        pterr1;
   Double_t        pterr2;
   Double_t        pterr1_VX;
   Double_t        pterr2_VX;
   Double_t        pterr1_VX_BS;
   Double_t        pterr2_VX_BS;
   Double_t        weight;
   Int_t           nFSRPhotons;

   // List of branches
   TBranch        *b_GENmass2l;   //!
   TBranch        *b_genLep_pt1;   //!
   TBranch        *b_genLep_pt2;   //!
   TBranch        *b_genLep_eta1;   //!
   TBranch        *b_genLep_eta2;   //!
   TBranch        *b_genLep_phi1;   //!
   TBranch        *b_genLep_phi2;   //!
   TBranch        *b_NInt;   //!
   TBranch        *b_NVtx;   //!
   TBranch        *b_PvX;   //!
   TBranch        *b_PvY;   //!
   TBranch        *b_PvZ;   //!
   TBranch        *b_BsX;   //!
   TBranch        *b_BsY;   //!
   TBranch        *b_BsZ;   //!
   TBranch        *b_massZ;   //!
   TBranch        *b_massZErr;   //!
   TBranch        *b_massZ_FSR;   //!
   TBranch        *b_massZErr_FSR;   //!
   TBranch        *b_massZ_single_BS;   //!
   TBranch        *b_massZ_vtx;   //!
   TBranch        *b_massZ_vtx_FSR;   //!
   TBranch        *b_massZErr_vtx;   //!
   TBranch        *b_massZErr_vtx_FSR;   //!
   TBranch        *b_massZ_vtxChi2;   //!
   TBranch        *b_massZ_vtx_BS;   //!
   TBranch        *b_massZ_vtx_BS_FSR;   //!
   TBranch        *b_massZErr_vtx_BS;   //!
   TBranch        *b_massZErr_vtx_BS_FSR;   //!
   TBranch        *b_massZ_vtxChi2_BS;   //!
   TBranch        *b_PvX1;   //!
   TBranch        *b_PvX2;   //!
   TBranch        *b_PvY1;   //!
   TBranch        *b_PvY2;   //!
   TBranch        *b_PvZ1;   //!
   TBranch        *b_PvZ2;   //!
   TBranch        *b_BsX1;   //!
   TBranch        *b_BsX2;   //!
   TBranch        *b_BsY1;   //!
   TBranch        *b_BsY2;   //!
   TBranch        *b_BsZ1;   //!
   TBranch        *b_BsZ2;   //!
   TBranch        *b_muonPV_x1;   //!
   TBranch        *b_muonPV_y1;   //!
   TBranch        *b_muonPV_z1;   //!
   TBranch        *b_muonPV_x2;   //!
   TBranch        *b_muonPV_y2;   //!
   TBranch        *b_muonPV_z2;   //!
   TBranch        *b_pT1_FromMuonBestTrack;   //!
   TBranch        *b_pT2_FromMuonBestTrack;   //!
   TBranch        *b_eta1_FromMuonBestTrack;   //!
   TBranch        *b_eta2_FromMuonBestTrack;   //!
   TBranch        *b_phi1_FromMuonBestTrack;   //!
   TBranch        *b_phi2_FromMuonBestTrack;   //!
   TBranch        *b_pT1_genFromReco;   //!
   TBranch        *b_pT2_genFromReco;   //!
   TBranch        *b_pT1;   //!
   TBranch        *b_pT2;   //!
   TBranch        *b_eta1;   //!
   TBranch        *b_eta2;   //!
   TBranch        *b_phi1;   //!
   TBranch        *b_phi2;   //!
   TBranch        *b_m1;   //!
   TBranch        *b_m2;   //!
   TBranch        *b_pT_FSR1;   //!
   TBranch        *b_pT_FSR2;   //!
   TBranch        *b_eta_FSR1;   //!
   TBranch        *b_eta_FSR2;   //!
   TBranch        *b_phi_FSR1;   //!
   TBranch        *b_phi_FSR2;   //!
   TBranch        *b_m_FSR1;   //!
   TBranch        *b_m_FSR2;   //!
   TBranch        *b_Tracker1;   //!
   TBranch        *b_Tracker2;   //!
   TBranch        *b_single_BS_pT1;   //!
   TBranch        *b_single_BS_pT2;   //!
   TBranch        *b_single_BS_eta1;   //!
   TBranch        *b_single_BS_eta2;   //!
   TBranch        *b_single_BS_phi1;   //!
   TBranch        *b_single_BS_phi2;   //!
   TBranch        *b_single_BS_m1;   //!
   TBranch        *b_single_BS_m2;   //!
   TBranch        *b_vtx_pT1;   //!
   TBranch        *b_vtx_pT2;   //!
   TBranch        *b_vtx_eta1;   //!
   TBranch        *b_vtx_eta2;   //!
   TBranch        *b_vtx_phi1;   //!
   TBranch        *b_vtx_phi2;   //!
   TBranch        *b_vtx_m1;   //!
   TBranch        *b_vtx_m2;   //!
   TBranch        *b_vtx_BS_pT1;   //!
   TBranch        *b_vtx_BS_pT2;   //!
   TBranch        *b_vtx_BS_eta1;   //!
   TBranch        *b_vtx_BS_eta2;   //!
   TBranch        *b_vtx_BS_phi1;   //!
   TBranch        *b_vtx_BS_phi2;   //!
   TBranch        *b_vtx_BS_m1;   //!
   TBranch        *b_vtx_BS_m2;   //!
   TBranch        *b_vtx_pT_FSR1;   //!
   TBranch        *b_vtx_pT_FSR2;   //!
   TBranch        *b_vtx_eta_FSR1;   //!
   TBranch        *b_vtx_eta_FSR2;   //!
   TBranch        *b_vtx_phi_FSR1;   //!
   TBranch        *b_vtx_phi_FSR2;   //!
   TBranch        *b_vtx_m_FSR1;   //!
   TBranch        *b_vtx_m_FSR2;   //!
   TBranch        *b_vtx_BS_pT_FSR1;   //!
   TBranch        *b_vtx_BS_pT_FSR2;   //!
   TBranch        *b_vtx_BS_eta_FSR1;   //!
   TBranch        *b_vtx_BS_eta_FSR2;   //!
   TBranch        *b_vtx_BS_phi_FSR1;   //!
   TBranch        *b_vtx_BS_phi_FSR2;   //!
   TBranch        *b_vtx_BS_m_FSR1;   //!
   TBranch        *b_vtx_BS_m_FSR2;   //!
   TBranch        *b_d0BS1;   //!
   TBranch        *b_d0BS2;   //!
   TBranch        *b_d0BS_vtx_BS1;   //!
   TBranch        *b_d0BS_vtx_BS2;   //!
   TBranch        *b_Id1;   //!
   TBranch        *b_Id2;   //!
   TBranch        *b_pterr1;   //!
   TBranch        *b_pterr2;   //!
   TBranch        *b_pterr1_VX;   //!
   TBranch        *b_pterr2_VX;   //!
   TBranch        *b_pterr1_VX_BS;   //!
   TBranch        *b_pterr2_VX_BS;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_nFSRPhotons;   //!

   DY_2018_macro(TTree *tree=0);
   virtual ~DY_2018_macro();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);

   // classes  and varaibles declared further apart from base macro
  

   public:
    // variables
    double pi = TMath::Pi();    
    bool debug_base = false;
    bool analyze_pT = true;
    bool smearing = true;
    bool debug_pT = true; 
    bool debug_entries = true; 
    bool combine = true; 
    bool plotting_on = true; 
    
    TRandom3 *random = new TRandom3(); 
    double smear_value1; 
    double smear_value2; 
    TLorentzVector genLep1, genLep2, genZ;
    double massZ_reconstruct;
    double mass_mu = 0.105658;
    TString saving_path = "/afs/cern.ch/user/n/nrawal/work/DY_analysis/program_analysis/pt_analysis/plots_smearing_1percent/";
    double pt_list_mean[10] = {7.5,22.5,35,45,55,65,82.5,100,120,165};
    double pt_list[11] = {0,15,30,40,50,60,75,90,110,130,200};
    TString bin_number_pt[10] = {"1st","2nd","3rd","4th","5th","6th","7th","8th","9th","10th"};

    // to count the number of entries in each pT bin
    double n_positive_bin[10];
    double n_negative_bin[10];
    double n_positive_bin_smear[10];
    double n_negative_bin_smear[10];
    // counting total number of entries
    double total_entries_positive, total_entries_negative,  total_entries_positive_smear,  total_entries_negative_smear;   
    // to evaluate the mean value of all pT distribution 
    ofstream myfile_mean_pT , myfile_n_entries;
    std::pair<double,double> mean_sigma_Zmass;
    std::pair<double,double> mean_sigma_Zmass_DSCB;
    std::pair<double,double> mean_sigma_Zmass_smear;
    std::pair<double,double> mean_sigma_Zmass_DSCB_smear;
    std::pair<double,double> mean_sigma_positive_pt[10];
    std::pair<double,double> mean_sigma_negative_pt[10];
    std::pair<double,double> mean_sigma_positive_reco_pt[10];
    std::pair<double,double> mean_sigma_negative_reco_pt[10];

    double mean_positive_pt[10];
    double sigma_positive_pt[10];
    double mean_negative_pt[10];
    double sigma_negative_pt[10];

    double mean_positive_reco_pt[10];
    double sigma_positive_reco_pt[10];
    double mean_negative_reco_pt[10];
    double sigma_negative_reco_pt[10];

    double mean_pT_positive[10], mean_pT_negative[10], mean_pT_positive_smear[10], mean_pT_negative_smear[10];

    double diff_Zmass_positive_gen_reco[10];
    double diff_Zmass_negative_gen_reco[10];

    TH1D * hist_gen_pT1 = new TH1D("hist_gen_pT1", " Gen pT of first lepton " , 800,0,200);
    TH1D * hist_gen_pT2 = new TH1D("hist_gen_pT2", " Gen pT of second lepton " , 800,0,200);
    TH1D * hist_id1 = new TH1D("hist_id1", " id  of first lepton " , 30,-15,15);
    TH1D * hist_id2 = new TH1D("hist_id2", " id  of second lepton " , 30,-15,15);
    TH1D * hist_gen_Zmass = new TH1D("hist_gen_Zmass"," Gen Z mass",600,60,120); 
    
    TH1D * hist_gen_positive_mu = new TH1D("hist_gen_positive_mu", " Gen pT (#mu^{+}) " , 800,0,200);
    TH1D * hist_id_positive_mu = new TH1D("hist_id_positive_mu", " id (#mu^{+}) " , 15,0,15);
   
    TH1D * hist_gen_negative_mu = new TH1D("hist_gen_negative_mu", " Gen pT (#mu^{-}) " , 800,0,200);
    TH1D * hist_id_negative_mu = new TH1D("hist_id_negative_mu", " id (#mu^{-}) " , 15,-15,0);
  

    TH1D * hist_gen_pT1_smear = new TH1D("hist_gen_pT1_smear", " Gen pT of first lepton after smearing " , 800,0,200);
    TH1D * hist_gen_pT2_smear = new TH1D("hist_gen_pT2_smear", " Gen pT of second lepton after smearing " , 800,0,200);
    TH1D * hist_id1_smear = new TH1D("hist_id1_smear", " id  of first lepton after smearing " , 30,-15,15);
    TH1D * hist_id2_smear = new TH1D("hist_id2_smear", " id  of second lepton after smearing " , 30,-15,15);
    TH1D * hist_gen_Zmass_smear = new TH1D("hist_gen_Zmass_smear"," Gen Z mass after smearing",600,60,120); 
    
    TH1D * hist_gen_positive_mu_smear = new TH1D("hist_gen_positive_mu_smear", " Gen pT (#mu^{+}) after smearing " , 600,0,200);
    TH1D * hist_id_positive_mu_smear = new TH1D("hist_id_positive_mu_smear", " id (#mu^{+}) after smearing " , 15,0,15);
   
    TH1D * hist_gen_negative_mu_smear = new TH1D("hist_gen_negative_mu_smear", " Gen pT (#mu^{-}) after smearing " , 600,0,200);
    TH1D * hist_id_negative_mu_smear = new TH1D("hist_id_negative_mu_smear", " id (#mu^{-}) after smearing " , 15,-15,0);
  
    TH1D * hist_reco_Zmass = new TH1D("hist_reco_Zmass", " m(#mu^{-} #mu^{-}) after smearing " , 600,60,120);

  
     TH1D *histogram_Zmass_positive_pt[10];
     TH1D *histogram_Zmass_negative_pt[10];
     TH1D *histogram_Zmass_positive_pt_smear[10];
     TH1D *histogram_Zmass_negative_pt_smear[10];
   
    // plot pT distribuiton for each bin before and after smearing and see the average mean of the distribution
    
    TH1D *pT_positive_bin[10] ; 
    TH1D *pT_negative_bin[10] ; 
    TH1D *pT_positive_bin_smear[10] ; 
    TH1D *pT_negative_bin_smear[10] ; 

        // functions
    std::pair<double,double> plotting_fitting_mass_BW(TH1D* hist_fit, TString saving_name, TString title_name);
    std::pair<double,double> plotting_fitting_mass_DSCB(TH1D* hist_fit, TString saving_name, TString title_name);
    // to plot fits on same plots 
    void plotting_fitting_mass_smearing_BW(TH1D* hist_gen, TH1D* hist_reco,TString title_name, TString saving_name);
    void plotting_fitting_mass_smearing_DSCB(TH1D* hist_gen,TH1D* hist_reco, TString title_name, TString saving_name);
    void plotting_mass_smearing(TH1D * hist_fit_gen, TH1D *hist_fit_smear, TString title_name, TString saving_name);

   
    void  plotting_hist(TH1D* hist_draw, TString title, TString saving_name, TString title_name_axis); 
   
    double count_positive_mu= 0 , count_negative_mu =0;
    double count_positive_mu_smear= 0 , count_negative_mu_smear =0;
    // to count total number of entries in each pT bin and also above 200 GeV and print them in a text file myfile_n_entries 
    void plot_entries();
    void total_entries();
    // plotting pT distribution for each pT bin 
    void evaluating_mean_pT();
    
    
    void graph_mean_pT_combine();
    void graph_mean_pT();
    void graph_mean_pT_reco();
    void graph_diff_Zmass_gen_reco();
    void smearing_pT();
    void reconstruct_Zmass();
 
    void histogram_declaration_pt();
    void histogram_declaration_pt_smear();
    
    // to declare the histograms for pT distributions 
    void histogram_pT_distribution();
    // to printout the values of mean of pT distribution before and after smearing
          
    // to draw and save the pT distributions
    void saving_histogram_pT();

    void histogram_filling_positive_pt(int i);
    void histogram_filling_negative_pt(int i);
    void histogram_filling_positive_pt_smear(int i);
    void histogram_filling_negative_pt_smear(int i);
    
};

    void DY_2018_macro :: histogram_pT_distribution(){
     for(int i= 0;i<10; i++){
      TString histogram_name_positive_pT = TString::Format("pT_positive_bin[%d]",i);
      TString title_positive = TString::Format("(pT)  #mu^{+} : %.0f  #leq pT < %.0f" ,pt_list[i], pt_list[i+1]) ; 
      pT_positive_bin[i] = new TH1D(histogram_name_positive_pT,title_positive, 30,pt_list[i],pt_list[i+1]);
     }
    for(int i= 0;i<10; i++){
      TString histogram_name_negative_pT = TString::Format("pT_negative_bin[%d]",i);
      TString title_negative = TString::Format("(pT)  #mu^{-} : %.0f  #leq pT < %.0f" ,pt_list[i], pt_list[i+1]) ; 
      pT_negative_bin[i] = new TH1D(histogram_name_negative_pT,title_negative, 30,pt_list[i],pt_list[i+1]);
     }
     for(int i= 0;i<10; i++){
      TString histogram_name_positive_pT_smear = TString::Format("pT_positive_bin_smear[%d]",i);
      TString title_positive_smear = TString::Format("(pT)  #mu^{+} : %.0f  #leq pT < %.0f" ,pt_list[i], pt_list[i+1]) ; 
      pT_positive_bin_smear[i] = new TH1D(histogram_name_positive_pT_smear,title_positive_smear, 30,pt_list[i],pt_list[i+1]);
     }
    for(int i= 0;i<10; i++){
      TString histogram_name_negative_pT_smear = TString::Format("pT_negative_bin_smear[%d]",i);
      TString title_negative_smear = TString::Format("(pT)  #mu^{-} : %.0f  #leq pT < %.0f" ,pt_list[i], pt_list[i+1]) ; 
      pT_negative_bin_smear[i] = new TH1D(histogram_name_negative_pT_smear,title_negative_smear, 30,pt_list[i],pt_list[i+1]);
     }

    myfile_mean_pT.open("mean_pT.txt");
    }



  // pT 
  void DY_2018_macro :: histogram_declaration_pt(){
   for(int i=0; i<10;i++)
   {
    TString histogram_name_positive = TString::Format("histogram_Zmass_positive_pt[%d]",i);
   TString title_positive = TString::Format("Gen Z mass before smearing for  #mu^{+} : %.0f  #leq pT < %.0f" ,pt_list[i], pt_list[i+1]) ; 
   histogram_Zmass_positive_pt[i] = new TH1D(histogram_name_positive,title_positive,600,60,120);
   }
   for(int i=0;i<10;i++){
    TString histogram_name_negative = TString::Format("histogram_Zmass_negative_pt[%d]",i);
    TString title_negative = TString::Format("Gen Z mass before smearing for  #mu^{-} : %.0f  #leq pT < %.0f" ,pt_list[i], pt_list[i+1]) ; 
    histogram_Zmass_negative_pt[i] = new TH1D(histogram_name_negative,title_negative,600,60,120);
   }
  }


  void DY_2018_macro :: histogram_filling_positive_pt(int i){
   histogram_Zmass_positive_pt[i]->Fill(GENmass2l); 
  } 

  void DY_2018_macro :: histogram_filling_negative_pt(int i){
   histogram_Zmass_negative_pt[i]->Fill(GENmass2l); 
  } 

  // pT  smered
  void DY_2018_macro :: histogram_declaration_pt_smear(){
   for(int i=0; i<10;i++)
   {
    TString histogram_name_positive = TString::Format("histogram_Zmass_positive_pt_smear[%d]",i);
   TString title_positive = TString::Format("Gen Z mass after smearing for  #mu^{+} : %.0f  #leq pT < %.0f" ,pt_list[i], pt_list[i+1]) ; 
   histogram_Zmass_positive_pt_smear[i] = new TH1D(histogram_name_positive,title_positive,600,60,120);
   }
   for(int i=0;i<10;i++){
    TString histogram_name_negative = TString::Format("histogram_Zmass_negative_pt_smear[%d]",i);
    TString title_negative = TString::Format("Gen Z mass after smearing for  #mu^{-} : %.0f  #leq pT < %.0f" ,pt_list[i], pt_list[i+1]) ; 
    histogram_Zmass_negative_pt_smear[i] = new TH1D(histogram_name_negative,title_negative,600,60,120);
   }
  }


  void DY_2018_macro :: histogram_filling_positive_pt_smear(int i){
   histogram_Zmass_positive_pt_smear[i]->Fill(massZ_reconstruct); 
  } 

  void DY_2018_macro :: histogram_filling_negative_pt_smear(int i){
   histogram_Zmass_negative_pt_smear[i]->Fill(massZ_reconstruct); 
  } 
 
   void DY_2018_macro :: graph_mean_pT_combine(){
   TCanvas *graph_canvas = new TCanvas("graph_canvas","mass(#mu^{+}#mu^{-})",900,600);
   graph_canvas->cd(); 
   TMultiGraph *mg = new TMultiGraph(); 
   mg->SetTitle("#mu^{+}");
  TGraphErrors *gr_positive = new TGraphErrors(10, pt_list_mean,mean_positive_pt, 0,sigma_positive_pt);
  // gr_positive->Draw("AP*");
//   gr_positive->SetLineColor(2);
   gr_positive->SetMarkerColor(4);
   gr_positive->SetMarkerSize(1.0);
   gr_positive->SetMarkerStyle(21);
   gr_positive->SetName("gr_positive"); 
   TGraphErrors *gr_positive_reco = new TGraphErrors(10, pt_list_mean,mean_positive_reco_pt, 0,sigma_positive_reco_pt);
 //  gr_positive_reco->Draw("AP*");
   gr_positive_reco->SetMarkerColor(2);
   gr_positive_reco->SetMarkerSize(1.0);
   gr_positive_reco->SetMarkerStyle(21);
    
   gr_positive_reco->SetName("gr_positive_reco"); 
   mg->Add(gr_positive);
   mg->Add(gr_positive_reco);
   mg->Draw("AP*");
   mg->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   mg->GetXaxis()->SetTitle("pT (GeV)");
   mg->GetYaxis()->SetRangeUser(90.95,91.4);
  
     TLegend* leg = new TLegend(0.7, 0.7, 0.88, 0.88);
     leg->AddEntry("gr_positive","before smearing", "EP");
     leg->AddEntry("gr_positive_reco","after smearing", "EP");
     leg->Draw();
   graph_canvas->SaveAs(saving_path+"mean_pT_mu_positive_combine.pdf"); 
   
   TCanvas *graph_canvas_negative = new TCanvas("graph_canvas_negative","mass(#mu^{+}#mu^{-})",900,600);
   // TGraph *gr = new TGraph(10,pT_list,mean);
  
   TMultiGraph *mg1 = new TMultiGraph(); 
   mg1->SetTitle("#mu^{-}");
      graph_canvas_negative->cd(); 
   TGraphErrors *gr_negative = new TGraphErrors(10, pt_list_mean,mean_negative_pt, 0,sigma_negative_pt);
   //gr_negative->Draw("AP*");
   gr_negative->SetMarkerColor(4);
   gr_negative->SetMarkerSize(1.0);
   gr_negative->SetMarkerStyle(21);
 
   gr_negative->SetName("gr_negative"); 

   TGraphErrors *gr_negative_reco = new TGraphErrors(10, pt_list_mean,mean_negative_reco_pt, 0,sigma_negative_reco_pt);
   // TGraph *gr = new TGraph(10,pT_list,mean);
   //gr_negative_reco->Draw("AP*");
   gr_negative_reco->SetMarkerColor(2);
   gr_negative_reco->SetMarkerSize(1.0);
   gr_negative_reco->SetMarkerStyle(21);
  
   gr_negative_reco->SetName("gr_negative_reco"); 
   mg1->Add(gr_negative);
   mg1->Add(gr_negative_reco);
   mg1->Draw("AP*");
   mg1->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   mg1->GetXaxis()->SetTitle("pT (GeV)");
   mg1->GetYaxis()->SetRangeUser(90.95,91.4);
  
 TLegend* leg1 = new TLegend(0.7, 0.7, 0.88, 0.88);
     leg1->AddEntry("gr_negative","before smearing", "EP");
     leg1->AddEntry("gr_negative_reco","after smearing", "EP");
     leg1->Draw();

 graph_canvas_negative->SaveAs(saving_path+"mean_pT_mu_negative_combine.pdf"); 
  
   }

 
   void DY_2018_macro :: graph_mean_pT(){
   TGraphErrors *gr_positive = new TGraphErrors(10, pt_list_mean,mean_positive_pt, 0,sigma_positive_pt);
   gr_positive->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   gr_positive->GetXaxis()->SetTitle("pT (GeV)");
   gr_positive->GetYaxis()->SetRangeUser(90.95,91.4);
   gr_positive->SetTitle("#mu^{+}");
   TCanvas *graph_canvas = new TCanvas("graph_canvas","mass(#mu^{+}#mu^{-})",900,600);
   graph_canvas->cd(); 
   
   gr_positive->Draw("AP*");
   graph_canvas->SaveAs(saving_path+"mean_pT_mu_positive.pdf"); 
 
   TGraphErrors *gr_negative = new TGraphErrors(10, pt_list_mean,mean_negative_pt, 0,sigma_negative_pt);
   gr_negative->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   gr_negative->GetXaxis()->SetTitle("pT (GeV)");
   gr_negative->SetTitle("#mu^{-}");
   gr_negative->GetYaxis()->SetRangeUser(90.95,91.4);
   TCanvas *graph_canvas_1 = new TCanvas("graph_canvas_1","mass(#mu^{+}#mu^{-})",900,600);
   graph_canvas_1->cd(); 
   
   gr_negative->Draw("AP*");
   graph_canvas_1->SaveAs(saving_path+"mean_pT_mu_negative.pdf"); 
  
   }

 void DY_2018_macro :: graph_mean_pT_reco(){
   TGraphErrors *gr_positive_reco = new TGraphErrors(10, pt_list_mean,mean_positive_reco_pt, 0,sigma_positive_reco_pt);
   // TGraph *gr = new TGraph(10,pT_list,mean);
   gr_positive_reco->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   gr_positive_reco->GetXaxis()->SetTitle("pT (GeV)");
   gr_positive_reco->SetTitle("#mu^{+}");
   gr_positive_reco->GetYaxis()->SetRangeUser(90.95,91.4);
   TCanvas *graph_canvas = new TCanvas("graph_canvas","mass(#mu^{+}#mu^{-})",900,600);
   graph_canvas->cd(); 
   
   gr_positive_reco->Draw("AP*");
   graph_canvas->SaveAs(saving_path+"mean_pT_mu_positive_reco.pdf"); 
 
   TGraphErrors *gr_negative_reco = new TGraphErrors(10, pt_list_mean,mean_negative_reco_pt, 0,sigma_negative_reco_pt);
   // TGraph *gr = new TGraph(10,pT_list,mean);
   gr_negative_reco->GetYaxis()->SetTitle("mass_{(#mu^{+}#mu^{-})}");
   gr_negative_reco->GetXaxis()->SetTitle("pT (GeV)");
   gr_negative_reco->SetTitle("#mu^{-}");
   gr_negative_reco->GetYaxis()->SetRangeUser(90.95,91.4);
   TCanvas *graph_canvas_1 = new TCanvas("graph_canvas_1","mass(#mu^{+}#mu^{-})",900,600);
   graph_canvas_1->cd(); 
   
   gr_negative_reco->Draw("AP*");
   graph_canvas_1->SaveAs(saving_path+"mean_pT_mu_negative_reco.pdf"); 
  
   }

 void DY_2018_macro :: graph_diff_Zmass_gen_reco(){
   TGraph *gr_diff_gen_reco_positive = new TGraph(10, pt_list_mean,diff_Zmass_positive_gen_reco);
   TGraph *gr_diff_gen_reco_negative = new TGraph(10, pt_list_mean,diff_Zmass_negative_gen_reco);
   gr_diff_gen_reco_positive->SetMarkerColor(4);
   gr_diff_gen_reco_positive->SetMarkerSize(1.0);
   gr_diff_gen_reco_positive->SetMarkerStyle(21);

   gr_diff_gen_reco_negative->SetMarkerColor(2);
   gr_diff_gen_reco_negative->SetMarkerSize(1.0);
   gr_diff_gen_reco_negative->SetMarkerStyle(21);
 
   TMultiGraph *mg = new TMultiGraph(); 
   mg->SetTitle("difference Z mass(mean) before and after smearing");
  
   TCanvas *graph_canvas = new TCanvas("graph_canvas","diff Gen and Reco Z mass",900,600);
   graph_canvas->cd(); 
   gr_diff_gen_reco_positive->SetName("positive");
   gr_diff_gen_reco_negative->SetName("negative");
   mg->Add(gr_diff_gen_reco_positive);
   mg->Add(gr_diff_gen_reco_negative);
   mg->Draw("AP*");
   mg->GetYaxis()->SetTitle("");
   mg->GetXaxis()->SetTitle("pT (GeV)");
   mg->GetYaxis()->SetRangeUser(-0.002,0.002);
     TLegend* leg = new TLegend(0.7, 0.7, 0.88, 0.88);
     leg->AddEntry("positive","#mu^{+}", "EP");
     leg->AddEntry("negative","#mu^{-}", "EP");
     leg->Draw();

   graph_canvas->SaveAs(saving_path+"diff_Zmas_gen_combine.pdf"); 
 
 }

   void DY_2018_macro :: plotting_hist(TH1D * hist_draw, TString title, TString saving_name, TString title_name_axis){
    TCanvas * c = new TCanvas("c",title,900,600);
    c->cd();
    hist_draw->GetXaxis()->SetTitle(title_name_axis+" (GeV)");
    hist_draw->Draw();
    c->SaveAs(saving_path+saving_name+".pdf");
   }



   std::pair<double,double> DY_2018_macro :: plotting_fitting_mass_BW(TH1D * hist_fit, TString saving_name, TString title_name){
  // Fit the mass into Breit Wigner
     RooRealVar mass_var("mass_var","mass_var",60,120);
     RooDataHist histo("histo","mass dataset",mass_var,hist_fit);
     RooRealVar mean_mass("mean_mass","mean of Z mass",91,87,95);
     RooRealVar width("width","width of Z mass",2,0.01,10);
   
     RooPlot *xframe=mass_var.frame(Title(title_name));
     histo.plotOn(xframe);
//     histo.statOn(xframe);
   
     RooBreitWigner BW("BW","Breit Wigner fit",mass_var, mean_mass,width);
     BW.fitTo(histo,Range(70,110));
    
     BW.plotOn(xframe,RooFit::LineColor(kRed+2),Name("BW_sig"));
    
     BW.paramOn(xframe,RooFit::Layout(0.6,0.9,0.7));
     
     TCanvas *tmp = new TCanvas("tmp","Gen Z mass", 900,600);
     tmp->cd();
     gPad->SetLeftMargin(0.15);
     xframe->getAttText()->SetTextSize(0.025);
     xframe->GetXaxis()->SetTitle("m_{#mu^{+}#mu^{-}} (GeV)");
    
     xframe->GetYaxis()->SetTitle("N/0.1 (GeV)");
     xframe->Draw();
   
     TLegend* leg2 = new TLegend(0.7, 0.7, 0.88, 0.88);
     leg2->SetFillColor(kWhite);
     leg2->SetLineColor(kBlack);
     leg2->AddEntry("histo","data", "EP");
     leg2->AddEntry("BW_sig","BW fit","LP");
     leg2->AddEntry("frame->chiSquare()",Form("#chi^{2}/ndf= %.2f",xframe->chiSquare()),"");
     leg2->AddEntry("histo.sumEntries()",Form("Events= %.0f",histo.sumEntries()),"");
     leg2->Draw("same");       


  
     gStyle->SetOptStat();
     tmp->SaveAs(saving_path+ saving_name+".pdf");
    
     std::cout<<" Z mass mean : "<<mean_mass.getVal()<<" width : "<<width.getVal()<<std::endl;
     return std::make_pair(mean_mass.getVal(),mean_mass.getError());   
     }
  
   std::pair<double,double> DY_2018_macro :: plotting_fitting_mass_DSCB(TH1D * hist_fit, TString saving_name, TString title_name){
  // Fit the mass into DSCB
    RooRealVar m4mu("m4mu", "var", 60,120, ""); 
    RooDataHist histo("histo","dataset with var",m4mu,hist_fit);
    RooRealVar Mean("Mean", "Mean",91, 88, 94);
    RooRealVar Sigma("#sigma", "#sigma", 1.00, 0.1, 3);//sigma[decay]);
    RooRealVar AlphaL("#alpha_{L}", "#alpha_{L}", 0.6, 0.3, 10);//alphaL[decay]);
    RooRealVar ExpL("n_{L}", "n_{L}", 1.5, 0.5, 30);//expL[decay]);
    RooRealVar AlphaR("#alpha_{R}", "#alpha_{R}", 0.6, 0.1, 30);//alphaR[decay]);
    RooRealVar ExpR("n_{R}", "n_{R}", 2.5, 1.5, 30);//expR[decay]);
    RooMyPDF_DSCB DSCB("DSCB", "DSCB", m4mu, Mean, Sigma, AlphaL, ExpL, AlphaR, ExpR);
   
    TCanvas *c_MC = new TCanvas("c_MC", "c_MC", 1000, 600);
    c_MC->SetFrameFillColor(0);
   
    RooPlot* xframe = m4mu.frame(RooFit::Title(title_name));
    histo.plotOn(xframe);
//    histo.statOn(xframe);
   
    Int_t color = kRed+2;
    Double_t size_text = 0.020;
    DSCB.fitTo(histo, Range(75,105));
    DSCB.plotOn(xframe, RooFit::LineColor(color),Name("DSCB_sig"));
    DSCB.paramOn(xframe, RooFit::Layout(0.15, 0.35, 0.90));
    c_MC->cd();
    xframe->getAttText()->SetTextSize(size_text);
    xframe->getAttText()->SetTextColor(color);
    xframe->GetXaxis()->SetTitle("m(#mu^{+} #mu^{-}) (GeV)");
    xframe->GetYaxis()->SetTitle("N/0.1 (GeV)");
    xframe->GetXaxis()->SetTitleOffset(1.4);
    xframe->chiSquare();
    xframe->Draw();
   
   TLegend* leg2 = new TLegend(0.7, 0.7, 0.88, 0.88);
     leg2->SetFillColor(kWhite);
     leg2->SetLineColor(kBlack);
     leg2->AddEntry("histo","data", "EP");
     leg2->AddEntry("DSCB_sig","DSCB fit","LP");
     leg2->AddEntry("frame->chiSquare()",Form("#chi^{2}/ndf= %.2f",xframe->chiSquare()),"");
     leg2->AddEntry("histo.sumEntries()",Form("Events= %.0f",histo.sumEntries()),"");
     leg2->Draw("same");       

    gStyle->SetOptStat();
    c_MC->SaveAs((saving_path+ saving_name + "DSCB.pdf"));// + ".pdf");
    
    std::cout<<" Z mass mean : "<<Mean.getVal()<<" width : "<<Sigma.getVal()<<std::endl;
    return std::make_pair(Mean.getVal(),Mean.getError());   
}

    void DY_2018_macro :: plotting_mass_smearing(TH1D * hist_fit_gen, TH1D *hist_fit_smear, TString title_name, TString saving_name){ 
     hist_fit_gen->Scale(1/hist_fit_gen->Integral());
     hist_fit_smear->Scale(1/hist_fit_smear->Integral());

      TCanvas *c = new TCanvas("c","Zmass",800,600);
      TPad *pad1 = new TPad("pad1","pad1",0,0.45,1,1.0); 
//      pad1->SetBottomMargin(0.3); 
      pad1->Draw();
      pad1->cd();
      hist_fit_gen->TAttLine::SetLineColor(kBlue);
      hist_fit_gen->GetXaxis()->SetTitle("m(#mu^{+} #mu^{-}) (GeV)");
      hist_fit_smear->TAttLine::SetLineColor(kRed);
    
      hist_fit_gen->Draw("E");
      gPad->Update();
      TPaveStats *ps1 = (TPaveStats*)hist_fit_gen->GetListOfFunctions()->FindObject("stats");
      ps1->SetX1NDC(0.6); ps1->SetX2NDC(0.8);
      ps1->SetTextColor(kBlue);
      hist_fit_smear->Draw("SAMES E");
      gPad->Update(); 
      TPaveStats *ps2 = (TPaveStats*)hist_fit_smear->GetListOfFunctions()->FindObject("stats");
      ps2->SetX1NDC(0.8); ps2->SetX2NDC(1.0);
      ps2->SetTextColor(kRed);
      
           c->cd();
      TPad *pad2 = new TPad("pad2","pad2",0,0.05,1,0.3);
      pad2->SetGridy(kTRUE);
      pad2->SetTopMargin(0);
      pad2->SetBottomMargin(0.2);// set Range for pad2 
      pad2->Draw();
      pad2->cd();
      TH1D *hist_fit_gen_clone = (TH1D*)hist_fit_gen->Clone();
      TH1D *hist_fit_smear_clone = (TH1D*)hist_fit_smear->Clone();
     

      hist_fit_smear_clone->Divide(hist_fit_gen_clone);
      hist_fit_smear_clone->GetYaxis()->SetTitle("after smearing / before smearing");
      hist_fit_smear_clone->SetStats(0);
      hist_fit_smear_clone->Draw("p E"); 
      hist_fit_smear_clone->GetYaxis()->SetRangeUser(0.5,1.7); 
      hist_fit_smear_clone->SetTitle("");
      c->SaveAs(saving_path+saving_name+".pdf");
    }

    void DY_2018_macro :: plotting_fitting_mass_smearing_DSCB(TH1D * hist_fit_gen, TH1D *hist_fit_smear, TString title_name, TString saving_name){
  // Fit the mass into DSCB
    RooRealVar m4mu("m4mu", "var", 60,120, ""); 
    RooDataHist histo_gen("histo_gen","dataset with var",m4mu,hist_fit_gen);
    RooDataHist histo_smear("histo_smear","dataset with var",m4mu,hist_fit_smear);

    RooRealVar Mean("Mean", "Mean",91, 88, 94);
    RooRealVar Sigma("#sigma", "#sigma", 1.00, 0.1, 3);//sigma[decay]);
    RooRealVar AlphaL("#alpha_{L}", "#alpha_{L}", 0.6, 0.3, 10);//alphaL[decay]);
    RooRealVar ExpL("n_{L}", "n_{L}", 1.5, 0.5, 30);//expL[decay]);
    RooRealVar AlphaR("#alpha_{R}", "#alpha_{R}", 0.6, 0.1, 30);//alphaR[decay]);
    RooRealVar ExpR("n_{R}", "n_{R}", 2.5, 1.5, 30);//expR[decay]);
    RooMyPDF_DSCB DSCB1("DSCB1", "DSCB", m4mu, Mean, Sigma, AlphaL, ExpL, AlphaR, ExpR);
    RooMyPDF_DSCB DSCB2("DSCB2", "DSCB", m4mu, Mean, Sigma, AlphaL, ExpL, AlphaR, ExpR);
   
    TCanvas *c_MC = new TCanvas("c_MC", "c_MC", 1000, 600);
    c_MC->SetFrameFillColor(0);
   
    RooPlot* xframe = m4mu.frame(RooFit::Title(title_name));
    histo_gen.plotOn(xframe, MarkerColor(kBlue), Name("hist_gen"));
//    histo.statOn(xframe);
   
    Int_t color1 = kBlue;
    Double_t size_text1 = 0.020;
    DSCB1.fitTo(histo_gen, Range(75,105));
    DSCB1.plotOn(xframe, RooFit::LineColor(color1),Name("DSCB_sig1"));
    DSCB1.paramOn(xframe, RooFit::Layout(0.15, 0.35, 0.90));
    c_MC->cd();
    xframe->getAttText()->SetTextSize(size_text1);
    xframe->getAttText()->SetTextColor(color1);
    xframe->GetXaxis()->SetTitle("m(#mu^{+} #mu^{-}) (GeV)");
    xframe->GetYaxis()->SetTitle("N/0.1 (GeV)");
    xframe->GetXaxis()->SetTitleOffset(1.4);
    xframe->chiSquare();
    xframe->Draw();
   
     TLegend* leg2 = new TLegend(0.7, 0.7, 0.88, 0.88);
     leg2->SetFillColor(kWhite);
     leg2->SetLineColor(kBlack);
     leg2->AddEntry("hist_gen","before smearing", "EP");
     leg2->AddEntry("DSCB_sig1","DSCB fit before smearing","LP");
     leg2->AddEntry("frame->chiSquare()",Form("#chi^{2}/ndf= %.2f",xframe->chiSquare()),"");
     leg2->AddEntry("histo_gen.sumEntries()",Form("Events= %.0f",histo_gen.sumEntries()),"");
     leg2->Draw("same");       

    Int_t color2 = kRed +2;
    Double_t size_text2 = 0.020;
    histo_smear.plotOn(xframe, MarkerColor(kBlack),Name("hist_smear"));
    DSCB2.fitTo(histo_smear, Range(75,105));
    DSCB2.plotOn(xframe, RooFit::LineColor(color2),Name("DSCB_sig2"));
    DSCB2.paramOn(xframe, RooFit::Layout(0.15, 0.35, 0.50));
    xframe->getAttText()->SetTextSize(size_text2);
    xframe->getAttText()->SetTextColor(color2);
    xframe->GetXaxis()->SetTitle("m(#mu^{+} #mu^{-}) (GeV)");
    xframe->GetYaxis()->SetTitle("N/0.1 (GeV)");
    xframe->GetXaxis()->SetTitleOffset(1.4);
    xframe->chiSquare();
    xframe->Draw();
   
     leg2->AddEntry("hist_smear","after smearing", "EP");
     leg2->AddEntry("DSCB_sig2","DSCB fit after smearing","LP");
     leg2->AddEntry("frame->chiSquare()",Form("#chi^{2}/ndf= %.2f",xframe->chiSquare()),"");
     leg2->AddEntry("histo_smear.sumEntries()",Form("Events= %.0f",histo_smear.sumEntries()),"");
     leg2->Draw("same");      
     gStyle->SetOptStat();
     c_MC->SaveAs((saving_path+ saving_name + "DSCB.pdf"));// + ".pdf");
}



void DY_2018_macro :: saving_histogram_pT(){
   TString string_pT_distribution_negative, string_pT_distribution_positive;  
   TString string_pT_distribution_negative_smear, string_pT_distribution_positive_smear;  
  
  for(int i=0; i<10; i++){
  TCanvas *canvas_pT_positive = new TCanvas("canvas_pT_positive", "pT distribution in each bin #mu^{+}", 900,600);
  canvas_pT_positive->cd();
  pT_positive_bin[i]->GetXaxis()->SetTitle("pT (GeV)");
  pT_positive_bin[i]->Draw();
  string_pT_distribution_positive ="pT_positive_" + bin_number_pt[i] + "bin";
  canvas_pT_positive->SaveAs(saving_path+string_pT_distribution_positive+".pdf");
  canvas_pT_positive->Close();

  TCanvas *canvas_pT_negative = new TCanvas("canvas_pT_negative", "pT distribution in each bin #mu^{-}", 900,600);
  canvas_pT_negative->cd();
  pT_negative_bin[i]->GetXaxis()->SetTitle("pT (GeV)");
  string_pT_distribution_positive ="pT_positive_" + bin_number_pt[i] + "bin";
  pT_negative_bin[i]->Draw();
  string_pT_distribution_negative ="pT_negative_" + bin_number_pt[i] + "bin";
  canvas_pT_negative->SaveAs(saving_path+string_pT_distribution_negative+".pdf");
  canvas_pT_negative->Close();

  TCanvas *canvas_pT_positive_smear = new TCanvas("canvas_pT_positive_smear", "pT distribution in each bin #mu^{+}", 900,600);
  canvas_pT_positive_smear->cd();
  pT_positive_bin_smear[i]->Draw();
  pT_positive_bin_smear[i]->GetXaxis()->SetTitle("pT (GeV)");
  string_pT_distribution_positive_smear ="pT_positive_" + bin_number_pt[i] +"bin_smear";
  canvas_pT_positive_smear->SaveAs(saving_path+string_pT_distribution_positive_smear+".pdf");
  canvas_pT_positive_smear->Close();

  TCanvas *canvas_pT_negative_smear = new TCanvas("canvas_pT_negative_smear", "pT distribution in each bin #mu^{-}", 900,600);
  canvas_pT_negative_smear->cd();
  pT_negative_bin_smear[i]->Draw();
  pT_negative_bin_smear[i]->GetXaxis()->SetTitle("pT (GeV)");
  string_pT_distribution_negative_smear ="pT_negative_" + bin_number_pt[i] + "bin_smear";
  canvas_pT_negative_smear->SaveAs(saving_path+string_pT_distribution_negative_smear+".pdf");
  canvas_pT_negative_smear->Close();
  }
}

void DY_2018_macro :: evaluating_mean_pT(){
  myfile_mean_pT<<"mean of the pT distribution before smearing : #mu^{+}"<<std::endl;
  for(int i=0; i<10; i++){
  mean_pT_positive[i] = pT_positive_bin[i]->GetMean(); 
  myfile_mean_pT<<mean_pT_positive[i]<<std::endl;
  }
  myfile_mean_pT<<"mean of the pT distribution after smearing : #mu^{+}"<<std::endl;
  for(int i=0; i<10; i++){
  mean_pT_positive_smear[i] = pT_positive_bin_smear[i]->GetMean(); 
  myfile_mean_pT<<mean_pT_positive_smear[i]<<std::endl;
  }
  myfile_mean_pT<<"mean of the pT distribution before smearing : #mu^{-}"<<std::endl;
  for(int i=0; i<10; i++){
  mean_pT_negative[i] = pT_negative_bin[i]->GetMean(); 
  myfile_mean_pT<<mean_pT_negative[i]<<std::endl;
  }
  myfile_mean_pT<<"mean of the pT distribution after smearing : #mu^{-}"<<std::endl;
  for(int i=0; i<10; i++){
  mean_pT_negative_smear[i] = pT_negative_bin_smear[i]->GetMean(); 
  myfile_mean_pT<<mean_pT_negative_smear[i]<<std::endl;
  }
}

void DY_2018_macro :: smearing_pT(){
  
 smear_value1 = random->Gaus(0,0.01*genLep_pt1);
 smear_value2 = random->Gaus(0,0.01*genLep_pt2);
 genLep_pt1 = genLep_pt1 +smear_value1;
 genLep_pt2 = genLep_pt2 +smear_value2;
}

void DY_2018_macro :: reconstruct_Zmass(){

   genLep1.SetPtEtaPhiM(genLep_pt1, genLep_eta1, genLep_phi1, mass_mu);
   genLep2.SetPtEtaPhiM(genLep_pt2, genLep_eta2, genLep_phi2, mass_mu);
   
   genZ = genLep1 + genLep2;
   massZ_reconstruct = genZ.M();
}
void DY_2018_macro :: total_entries(){
  total_entries_positive = 0; 
  total_entries_negative = 0; 
  total_entries_positive_smear = 0; 
  total_entries_negative_smear = 0; 
  for(int i=0; i<10;i++){
  total_entries_positive = n_positive_bin[i] + total_entries_positive;
  total_entries_negative = n_negative_bin[i] + total_entries_negative;
  total_entries_positive_smear = n_positive_bin_smear[i] + total_entries_positive_smear;
  total_entries_negative_smear = n_negative_bin_smear[i] + total_entries_negative_smear;
  }
   if(debug_entries == true){
    std::cout<<"total number of entries #mu^{+} "<<total_entries_positive<<std::endl;
    std::cout<<"total number of entries #mu^{-} "<<total_entries_negative<<std::endl;
    std::cout<<"total number of entries #mu^{+} after smearing "<<total_entries_positive_smear<<std::endl;
    std::cout<<"total number of entries #mu^{-} after smearing "<<total_entries_negative_smear<<std::endl;
   }
    myfile_n_entries.open("total_entries.txt");
    myfile_n_entries<<"total number of entries #mu^{+} "<<total_entries_positive<<std::endl;
    myfile_n_entries<<"total number of entries #mu^{-} "<<total_entries_negative<<std::endl;
    myfile_n_entries<<"total number of entries #mu^{+} after smearing "<<total_entries_positive_smear<<std::endl;
    myfile_n_entries<<"total number of entries #mu^{-} after smearing "<<total_entries_negative_smear<<std::endl;

    myfile_n_entries<<std::endl;

    myfile_n_entries<<"total number of entries above 200 GeV before smearing #mu^{+} "<<count_positive_mu<<std::endl;
    myfile_n_entries<<"total number of entries above 200 GeV after smearing #mu^{+} "<<count_positive_mu_smear<<std::endl;
    myfile_n_entries<<std::endl;
    myfile_n_entries<<"total number of entries #mu^{-} above 200 GeV before smearing "<<count_negative_mu<<std::endl;
    myfile_n_entries<<"total number of entries #mu^{-} above 200 GeV after smearing "<<count_negative_mu_smear<<std::endl;
    
}

void DY_2018_macro :: plot_entries(){
  TGraph *gr_positive_entries = new TGraph(10,pt_list_mean,n_positive_bin);
  TGraph *gr_negative_entries = new TGraph(10,pt_list_mean,n_negative_bin);
  TGraph *gr_positive_entries_smear = new TGraph(10,pt_list_mean,n_positive_bin_smear);
  TGraph *gr_negative_entries_smear = new TGraph(10,pt_list_mean,n_negative_bin_smear);

   gr_positive_entries->GetYaxis()->SetTitle("Entries");
   gr_positive_entries->GetXaxis()->SetTitle("pT (GeV)");
   gr_positive_entries->SetTitle("#mu^{+} before smearing");
 
   gr_negative_entries->GetYaxis()->SetTitle("Entries");
   gr_negative_entries->GetXaxis()->SetTitle("pT (GeV)");
   gr_negative_entries->SetTitle("#mu^{-} before smearing");
 
   gr_positive_entries_smear->GetYaxis()->SetTitle("Entries");
   gr_positive_entries_smear->GetXaxis()->SetTitle("pT (GeV)");
   gr_positive_entries_smear->SetTitle("#mu^{+} after smearing");
 
   gr_negative_entries_smear->GetYaxis()->SetTitle("Entries");
   gr_negative_entries_smear->GetXaxis()->SetTitle("pT (GeV)");
   gr_negative_entries_smear->SetTitle("#mu^{-} after smearing");
 
  TCanvas *canvas_entries_positive = new TCanvas("canvas_entries_positive","No. of entries in pT bin : #mu^{+}");
  canvas_entries_positive->Divide(2,1);
  canvas_entries_positive->cd(1);
  gr_positive_entries->Draw("AP*");
  canvas_entries_positive->cd(2);
  gr_positive_entries_smear->Draw("AP*");

  canvas_entries_positive->SaveAs(saving_path+"entries_positive.pdf");

  TCanvas *canvas_entries_negative = new TCanvas("canvas_entries_negative","No. of entries in pT bin : #mu^{-}");
  canvas_entries_negative->Divide(2,1);
  canvas_entries_negative->cd(1);
  gr_negative_entries->Draw("AP*");
  canvas_entries_negative->cd(2);
  gr_negative_entries_smear->Draw("AP*");
  canvas_entries_negative->SaveAs(saving_path+"entries_negative.pdf");
}
#endif

#ifdef DY_2018_macro_cxx
DY_2018_macro::DY_2018_macro(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../../DY_2018.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../../DY_2018.root");
      }
      f->GetObject("passedEvents",tree);

   }
   Init(tree);

}

DY_2018_macro::~DY_2018_macro()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t DY_2018_macro::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t DY_2018_macro::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void DY_2018_macro::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   cout<<"started"<<endl;
   fChain->SetBranchAddress("GENmass2l", &GENmass2l, &b_GENmass2l);
   fChain->SetBranchAddress("genLep_pt1", &genLep_pt1, &b_genLep_pt1);
   fChain->SetBranchAddress("genLep_pt2", &genLep_pt2, &b_genLep_pt2);
   fChain->SetBranchAddress("genLep_eta1", &genLep_eta1, &b_genLep_eta1);
   fChain->SetBranchAddress("genLep_eta2", &genLep_eta2, &b_genLep_eta2);
   fChain->SetBranchAddress("genLep_phi1", &genLep_phi1, &b_genLep_phi1);
   fChain->SetBranchAddress("genLep_phi2", &genLep_phi2, &b_genLep_phi2);
   fChain->SetBranchAddress("NInt", &NInt, &b_NInt);
   fChain->SetBranchAddress("NVtx", &NVtx, &b_NVtx);
   fChain->SetBranchAddress("PvX", &PvX, &b_PvX);
   fChain->SetBranchAddress("PvY", &PvY, &b_PvY);
   fChain->SetBranchAddress("PvZ", &PvZ, &b_PvZ);
   fChain->SetBranchAddress("BsX", &BsX, &b_BsX);
   fChain->SetBranchAddress("BsY", &BsY, &b_BsY);
   fChain->SetBranchAddress("BsZ", &BsZ, &b_BsZ);
   fChain->SetBranchAddress("massZ", &massZ, &b_massZ);
   fChain->SetBranchAddress("massZErr", &massZErr, &b_massZErr);
   fChain->SetBranchAddress("massZ_FSR", &massZ_FSR, &b_massZ_FSR);
   fChain->SetBranchAddress("massZErr_FSR", &massZErr_FSR, &b_massZErr_FSR);
   fChain->SetBranchAddress("massZ_single_BS", &massZ_single_BS, &b_massZ_single_BS);
   fChain->SetBranchAddress("massZ_vtx", &massZ_vtx, &b_massZ_vtx);
   fChain->SetBranchAddress("massZ_vtx_FSR", &massZ_vtx_FSR, &b_massZ_vtx_FSR);
   fChain->SetBranchAddress("massZErr_vtx", &massZErr_vtx, &b_massZErr_vtx);
   fChain->SetBranchAddress("massZErr_vtx_FSR", &massZErr_vtx_FSR, &b_massZErr_vtx_FSR);
   fChain->SetBranchAddress("massZ_vtxChi2", &massZ_vtxChi2, &b_massZ_vtxChi2);
   fChain->SetBranchAddress("massZ_vtx_BS", &massZ_vtx_BS, &b_massZ_vtx_BS);
   fChain->SetBranchAddress("massZ_vtx_BS_FSR", &massZ_vtx_BS_FSR, &b_massZ_vtx_BS_FSR);
   fChain->SetBranchAddress("massZErr_vtx_BS", &massZErr_vtx_BS, &b_massZErr_vtx_BS);
   fChain->SetBranchAddress("massZErr_vtx_BS_FSR", &massZErr_vtx_BS_FSR, &b_massZErr_vtx_BS_FSR);
   fChain->SetBranchAddress("massZ_vtxChi2_BS", &massZ_vtxChi2_BS, &b_massZ_vtxChi2_BS);
   fChain->SetBranchAddress("PvX1", &PvX1, &b_PvX1);
   fChain->SetBranchAddress("PvX2", &PvX2, &b_PvX2);
   fChain->SetBranchAddress("PvY1", &PvY1, &b_PvY1);
   fChain->SetBranchAddress("PvY2", &PvY2, &b_PvY2);
   fChain->SetBranchAddress("PvZ1", &PvZ1, &b_PvZ1);
   fChain->SetBranchAddress("PvZ2", &PvZ2, &b_PvZ2);
   fChain->SetBranchAddress("BsX1", &BsX1, &b_BsX1);
   fChain->SetBranchAddress("BsX2", &BsX2, &b_BsX2);
   fChain->SetBranchAddress("BsY1", &BsY1, &b_BsY1);
   fChain->SetBranchAddress("BsY2", &BsY2, &b_BsY2);
   fChain->SetBranchAddress("BsZ1", &BsZ1, &b_BsZ1);
   fChain->SetBranchAddress("BsZ2", &BsZ2, &b_BsZ2);
   fChain->SetBranchAddress("muonPV_x1", &muonPV_x1, &b_muonPV_x1);
   fChain->SetBranchAddress("muonPV_y1", &muonPV_y1, &b_muonPV_y1);
   fChain->SetBranchAddress("muonPV_z1", &muonPV_z1, &b_muonPV_z1);
   fChain->SetBranchAddress("muonPV_x2", &muonPV_x2, &b_muonPV_x2);
   fChain->SetBranchAddress("muonPV_y2", &muonPV_y2, &b_muonPV_y2);
   fChain->SetBranchAddress("muonPV_z2", &muonPV_z2, &b_muonPV_z2);
   fChain->SetBranchAddress("pT1_FromMuonBestTrack", &pT1_FromMuonBestTrack, &b_pT1_FromMuonBestTrack);
   fChain->SetBranchAddress("pT2_FromMuonBestTrack", &pT2_FromMuonBestTrack, &b_pT2_FromMuonBestTrack);
   fChain->SetBranchAddress("eta1_FromMuonBestTrack", &eta1_FromMuonBestTrack, &b_eta1_FromMuonBestTrack);
   fChain->SetBranchAddress("eta2_FromMuonBestTrack", &eta2_FromMuonBestTrack, &b_eta2_FromMuonBestTrack);
   fChain->SetBranchAddress("phi1_FromMuonBestTrack", &phi1_FromMuonBestTrack, &b_phi1_FromMuonBestTrack);
   fChain->SetBranchAddress("phi2_FromMuonBestTrack", &phi2_FromMuonBestTrack, &b_phi2_FromMuonBestTrack);
   fChain->SetBranchAddress("pT1_genFromReco", &pT1_genFromReco, &b_pT1_genFromReco);
   fChain->SetBranchAddress("pT2_genFromReco", &pT2_genFromReco, &b_pT2_genFromReco);
   fChain->SetBranchAddress("pT1", &pT1, &b_pT1);
   fChain->SetBranchAddress("pT2", &pT2, &b_pT2);
   fChain->SetBranchAddress("eta1", &eta1, &b_eta1);
   fChain->SetBranchAddress("eta2", &eta2, &b_eta2);
   fChain->SetBranchAddress("phi1", &phi1, &b_phi1);
   fChain->SetBranchAddress("phi2", &phi2, &b_phi2);
   fChain->SetBranchAddress("m1", &m1, &b_m1);
   fChain->SetBranchAddress("m2", &m2, &b_m2);
   fChain->SetBranchAddress("pT_FSR1", &pT_FSR1, &b_pT_FSR1);
   fChain->SetBranchAddress("pT_FSR2", &pT_FSR2, &b_pT_FSR2);
   fChain->SetBranchAddress("eta_FSR1", &eta_FSR1, &b_eta_FSR1);
   fChain->SetBranchAddress("eta_FSR2", &eta_FSR2, &b_eta_FSR2);
   fChain->SetBranchAddress("phi_FSR1", &phi_FSR1, &b_phi_FSR1);
   fChain->SetBranchAddress("phi_FSR2", &phi_FSR2, &b_phi_FSR2);
   fChain->SetBranchAddress("m_FSR1", &m_FSR1, &b_m_FSR1);
   fChain->SetBranchAddress("m_FSR2", &m_FSR2, &b_m_FSR2);
   fChain->SetBranchAddress("Tracker1", &Tracker1, &b_Tracker1);
   fChain->SetBranchAddress("Tracker2", &Tracker2, &b_Tracker2);
   fChain->SetBranchAddress("single_BS_pT1", &single_BS_pT1, &b_single_BS_pT1);
   fChain->SetBranchAddress("single_BS_pT2", &single_BS_pT2, &b_single_BS_pT2);
   fChain->SetBranchAddress("single_BS_eta1", &single_BS_eta1, &b_single_BS_eta1);
   fChain->SetBranchAddress("single_BS_eta2", &single_BS_eta2, &b_single_BS_eta2);
   fChain->SetBranchAddress("single_BS_phi1", &single_BS_phi1, &b_single_BS_phi1);
   fChain->SetBranchAddress("single_BS_phi2", &single_BS_phi2, &b_single_BS_phi2);
   fChain->SetBranchAddress("single_BS_m1", &single_BS_m1, &b_single_BS_m1);
   fChain->SetBranchAddress("single_BS_m2", &single_BS_m2, &b_single_BS_m2);
   fChain->SetBranchAddress("vtx_pT1", &vtx_pT1, &b_vtx_pT1);
   fChain->SetBranchAddress("vtx_pT2", &vtx_pT2, &b_vtx_pT2);
   fChain->SetBranchAddress("vtx_eta1", &vtx_eta1, &b_vtx_eta1);
   fChain->SetBranchAddress("vtx_eta2", &vtx_eta2, &b_vtx_eta2);
   fChain->SetBranchAddress("vtx_phi1", &vtx_phi1, &b_vtx_phi1);
   fChain->SetBranchAddress("vtx_phi2", &vtx_phi2, &b_vtx_phi2);
   fChain->SetBranchAddress("vtx_m1", &vtx_m1, &b_vtx_m1);
   fChain->SetBranchAddress("vtx_m2", &vtx_m2, &b_vtx_m2);
   fChain->SetBranchAddress("vtx_BS_pT1", &vtx_BS_pT1, &b_vtx_BS_pT1);
   fChain->SetBranchAddress("vtx_BS_pT2", &vtx_BS_pT2, &b_vtx_BS_pT2);
   fChain->SetBranchAddress("vtx_BS_eta1", &vtx_BS_eta1, &b_vtx_BS_eta1);
   fChain->SetBranchAddress("vtx_BS_eta2", &vtx_BS_eta2, &b_vtx_BS_eta2);
   fChain->SetBranchAddress("vtx_BS_phi1", &vtx_BS_phi1, &b_vtx_BS_phi1);
   fChain->SetBranchAddress("vtx_BS_phi2", &vtx_BS_phi2, &b_vtx_BS_phi2);
   fChain->SetBranchAddress("vtx_BS_m1", &vtx_BS_m1, &b_vtx_BS_m1);
   fChain->SetBranchAddress("vtx_BS_m2", &vtx_BS_m2, &b_vtx_BS_m2);
   fChain->SetBranchAddress("vtx_pT_FSR1", &vtx_pT_FSR1, &b_vtx_pT_FSR1);
   fChain->SetBranchAddress("vtx_pT_FSR2", &vtx_pT_FSR2, &b_vtx_pT_FSR2);
   fChain->SetBranchAddress("vtx_eta_FSR1", &vtx_eta_FSR1, &b_vtx_eta_FSR1);
   fChain->SetBranchAddress("vtx_eta_FSR2", &vtx_eta_FSR2, &b_vtx_eta_FSR2);
   fChain->SetBranchAddress("vtx_phi_FSR1", &vtx_phi_FSR1, &b_vtx_phi_FSR1);
   fChain->SetBranchAddress("vtx_phi_FSR2", &vtx_phi_FSR2, &b_vtx_phi_FSR2);
   fChain->SetBranchAddress("vtx_m_FSR1", &vtx_m_FSR1, &b_vtx_m_FSR1);
   fChain->SetBranchAddress("vtx_m_FSR2", &vtx_m_FSR2, &b_vtx_m_FSR2);
   fChain->SetBranchAddress("vtx_BS_pT_FSR1", &vtx_BS_pT_FSR1, &b_vtx_BS_pT_FSR1);
   fChain->SetBranchAddress("vtx_BS_pT_FSR2", &vtx_BS_pT_FSR2, &b_vtx_BS_pT_FSR2);
   fChain->SetBranchAddress("vtx_BS_eta_FSR1", &vtx_BS_eta_FSR1, &b_vtx_BS_eta_FSR1);
   fChain->SetBranchAddress("vtx_BS_eta_FSR2", &vtx_BS_eta_FSR2, &b_vtx_BS_eta_FSR2);
   fChain->SetBranchAddress("vtx_BS_phi_FSR1", &vtx_BS_phi_FSR1, &b_vtx_BS_phi_FSR1);
   fChain->SetBranchAddress("vtx_BS_phi_FSR2", &vtx_BS_phi_FSR2, &b_vtx_BS_phi_FSR2);
   fChain->SetBranchAddress("vtx_BS_m_FSR1", &vtx_BS_m_FSR1, &b_vtx_BS_m_FSR1);
   fChain->SetBranchAddress("vtx_BS_m_FSR2", &vtx_BS_m_FSR2, &b_vtx_BS_m_FSR2);
   fChain->SetBranchAddress("d0BS1", &d0BS1, &b_d0BS1);
   fChain->SetBranchAddress("d0BS2", &d0BS2, &b_d0BS2);
   fChain->SetBranchAddress("d0BS_vtx_BS1", &d0BS_vtx_BS1, &b_d0BS_vtx_BS1);
   fChain->SetBranchAddress("d0BS_vtx_BS2", &d0BS_vtx_BS2, &b_d0BS_vtx_BS2);
   fChain->SetBranchAddress("Id1", &Id1, &b_Id1);
   fChain->SetBranchAddress("Id2", &Id2, &b_Id2);
   fChain->SetBranchAddress("pterr1", &pterr1, &b_pterr1);
   fChain->SetBranchAddress("pterr2", &pterr2, &b_pterr2);
   fChain->SetBranchAddress("pterr1_VX", &pterr1_VX, &b_pterr1_VX);
   fChain->SetBranchAddress("pterr2_VX", &pterr2_VX, &b_pterr2_VX);
   fChain->SetBranchAddress("pterr1_VX_BS", &pterr1_VX_BS, &b_pterr1_VX_BS);
   fChain->SetBranchAddress("pterr2_VX_BS", &pterr2_VX_BS, &b_pterr2_VX_BS);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("nFSRPhotons", &nFSRPhotons, &b_nFSRPhotons);
   Notify();
   this->histogram_pT_distribution();
}

Bool_t DY_2018_macro::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void DY_2018_macro::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t DY_2018_macro::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef DY_2018_macro_cxx
