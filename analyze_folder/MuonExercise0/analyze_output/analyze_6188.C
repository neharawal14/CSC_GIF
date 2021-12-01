#include<fstream>                                                       
#include "RooRealVar.h"                                                 
#include "RooDataSet.h"                                                 
#include "RooGaussian.h"                                                
#include "RooConstVar.h"                                                
#include "RooHistPdf.h"                                                 
#include "RooPolynomial.h"                                              
#include "RooAbsArg.h"                                                  
#include "RooPlot.h" 
#include "RooAddPdf.h"     
#include "RooFitResult.h" 
#include "TAxis.h"
#include "TH1.h" 
using namespace RooFit ;  
class plotting{

  public:
    plotting(TString filename, TString dir_name);
    void fitting_landau(TH1F *histogram, TString, TString, double, double, double ,double);
    void filling_hist();
    std::pair<double,double> trail_chopping(TH1F* hist_fit);
    void drawing_hist();
    TString saving_path = "/afs/cern.ch/user/n/nrawal/work/CSC_GIF/CMSSW_12_0_0_pre4/src/analyze_folder/MuonExercise0/analyze_output/plots/run_6188/";
  public: 
    TFile *my_file;
    TDirectoryFile *directory_name;
    bool debug = false;
    // histogram declaration
    TH2F *h_csc_hit;    
    TH1F *h_11[7], *h_21[7];
    TH1F *h_with_cuts_11[7] ,*h_with_cuts_21[7];
    TH1F* h_charge_total;
    TH1F * h_charge_CFEB_1_ME21; 
    TH1F * h_charge_CFEB_2_ME21; 
    TH1F * h_charge_CFEB_3_ME21; 
    TH1F * h_charge_CFEB_4_ME21; 

    TH1F * h_charge_CFEB_1_ME11; 
    TH1F * h_charge_CFEB_2_ME11; 
    TH1F * h_charge_CFEB_3_ME11; 

    TH1F * h_center_strip_ME21;
    TH1F * h_center_strip_ME11;
};

plotting::plotting(TString filename, TString dir_name){
   
    my_file = TFile::Open(filename);
    directory_name = (TDirectoryFile*)my_file->Get(dir_name);
 
}

void plotting::filling_hist(){
    
    h_charge_total = (TH1F*) directory_name->Get("Qhit");
    for(int i=1; i<7; i++) {
       TString hist_name_11 = TString::Format("rHSumQ_layer_11[%d]",i);
       TString hist_name_21 = TString::Format("rHSumQ_layer_21[%d]",i);
       TString hist_name_with_cuts_21 = TString::Format("rHSumQ_with_cuts_layer_21[%d]",i);
       TString hist_name_with_cuts_11 = TString::Format("rHSumQ_with_cuts_layer_11[%d]",i);

       h_11[i] = (TH1F*) directory_name->Get(hist_name_11);
       h_21[i] = (TH1F*) directory_name->Get(hist_name_21);
       h_with_cuts_11[i] = (TH1F*) directory_name->Get(hist_name_with_cuts_11);
       h_with_cuts_21[i] = (TH1F*) directory_name->Get(hist_name_with_cuts_21);
    } 


       h_charge_CFEB_1_ME11 = (TH1F*) directory_name -> Get("rHSumQ_strip1_ME11");
       h_charge_CFEB_2_ME11 = (TH1F*) directory_name -> Get("rHSumQ_strip2_ME11");
       h_charge_CFEB_3_ME11 = (TH1F*) directory_name -> Get("rHSumQ_strip3_ME11");
     
       h_charge_CFEB_1_ME21 = (TH1F*) directory_name -> Get("rHSumQ_strip1_ME21");
       h_charge_CFEB_2_ME21 = (TH1F*) directory_name -> Get("rHSumQ_strip2_ME21");
       h_charge_CFEB_3_ME21 = (TH1F*) directory_name -> Get("rHSumQ_strip3_ME21");
       h_charge_CFEB_4_ME21 = (TH1F*) directory_name -> Get("rHSumQ_strip4_ME21");
       
       h_center_strip_ME21 = (TH1F*) directory_name -> Get("center_Strip_dist_ME21");
       h_center_strip_ME11 = (TH1F*) directory_name -> Get("center_Strip_dist_ME11");
       h_csc_hit = (TH2F*) directory_name->Get("cs_hit");    

 }

void plotting::drawing_hist(){

      TCanvas *charge_canvas = new TCanvas("charge_canvas","ADC charge for rechit per layer",1000,1000);
      charge_canvas->Divide(3,2);
 
      TCanvas *charge_canvas_2= new TCanvas("charge_canvas_2","ADC charge for rechit per layer",1000,1000);
      charge_canvas_2->Divide(3,2);
 
      TCanvas *charge_canvas_with_cuts_11= new TCanvas("charge_canvas_with_cuts_11","ADC charge for rechit per layer with cuts ME11",1000,1000);
      charge_canvas_with_cuts_11->Divide(3,2);
 
      TCanvas *charge_canvas_with_cuts_21= new TCanvas("charge_canvas_with_cuts_21","ADC charge for rechit per layer with cuts ME21",1000,1000);
      charge_canvas_with_cuts_21->Divide(3,2);
      
      TCanvas *charge_canvas_total = new TCanvas("charge_canvas_total","ADC charge for total rechit ",1000,1000);
 
      TCanvas *charge_canvas_CFEB_ME21= new TCanvas("charge_canvas_CFEB_ME21","ADC charge per CFEB for ME21 ",1000,1000);
      charge_canvas_CFEB_ME21->Divide(2,2);
 
      TCanvas *charge_canvas_CFEB_ME11= new TCanvas("charge_canvas_CFEB_ME11","ADC charge per CFEB for ME11 ",1000,1000);
      charge_canvas_CFEB_ME11->Divide(2,2);
    
     TCanvas *center_strip_canvas = new TCanvas("center_strip_canvas","strip number for ME2/1 ",1000,1000);

     TCanvas *strip_hit_canvas = new TCanvas("strip_hit_canvas","Strip number with Number of strips in the strip hit ",1000,1000);
      // drawing the histograms on the canvas and saving them

      // for charge per layer for ME11 chamber  
      for(int i=1 ; i<7 ; i++){
         charge_canvas->cd(i);
         h_11[i]->Draw();
      }
      charge_canvas->SaveAs(saving_path+"Charge_layer_ME11.pdf");

   
      // for charge per layer for ME21 chamber  
      for(int i=1 ; i<7 ; i++){
         charge_canvas_2->cd(i);
          h_21[i]->Draw();
       }
      charge_canvas_2 ->SaveAs(saving_path+"Charge_layer_ME21.pdf");

     // for charge per layer for ME21 chamber after the cuts
      for(int i=1 ; i<7 ; i++){
         charge_canvas_with_cuts_21->cd(i);
          h_with_cuts_21[i]->Draw();
       }

      for(int i=1 ; i<7 ; i++){
         charge_canvas_with_cuts_11->cd(i);
          h_with_cuts_11[i]->Draw();
       }

      charge_canvas_with_cuts_11 ->SaveAs(saving_path+"Charge_layer_ME11_with_cuts.pdf");
      charge_canvas_with_cuts_21 ->SaveAs(saving_path+"Charge_layer_ME21_with_cuts.pdf");


      // for total charge  
      charge_canvas_total->cd();
      h_charge_total->Draw();
      charge_canvas_total->SaveAs(saving_path+"total_charge.pdf");

      center_strip_canvas->Divide(2,1);
      center_strip_canvas->cd(1);
      h_center_strip_ME11->Draw();
      center_strip_canvas->cd(2);
      h_center_strip_ME21->Draw();
      center_strip_canvas->SaveAs(saving_path+"center_strip_numbers.pdf");

     // for charge per CFEB for ME11 chamber  
      charge_canvas_CFEB_ME11->cd(1);
      h_charge_CFEB_1_ME11->Draw();
      charge_canvas_CFEB_ME11->cd(2);
      h_charge_CFEB_2_ME11->Draw();
      charge_canvas_CFEB_ME11->cd(3);
      h_charge_CFEB_3_ME11->Draw();
      charge_canvas_CFEB_ME11 ->SaveAs(saving_path+"Charge_CFEB_ME11.pdf");


      // for charge per CFEB for ME21 chamber  
      charge_canvas_CFEB_ME21->cd(1);
      h_charge_CFEB_1_ME21->Draw();
      charge_canvas_CFEB_ME21->cd(2);
      h_charge_CFEB_2_ME21->Draw();
      charge_canvas_CFEB_ME21->cd(3);
      h_charge_CFEB_3_ME21->Draw();
      charge_canvas_CFEB_ME21->cd(4);
      h_charge_CFEB_4_ME21->Draw();

      charge_canvas_CFEB_ME21 ->SaveAs(saving_path+"Charge_CFEB_ME21.pdf");

      strip_hit_canvas->cd();
      h_csc_hit->Draw("colz");
      strip_hit_canvas->SaveAs(saving_path+"strip_number.pdf");
  
  }

void plotting::fitting_landau(TH1F* histogram, TString canvas_name, TString saving_name_fit, double const_min, double const_max, double fit_range_min, double fit_range_max){

  TF1 *landau = new TF1("landau","[2]*TMath::Landau(x,[0],[1])",fit_range_min,fit_range_max);
  landau->SetParLimits(0,100,600);
  landau->SetParLimits(1,20,200);

  landau->SetParLimits(2,const_min,const_max);
  landau->SetParNames("MPV","Sigma","Constant");
  TCanvas *tmp = new TCanvas("tmp","RAW ADC", 800,400);   
 // tmp->Divide(2,1);   
  tmp->cd();   
  histogram->Fit(landau,"R");
    gStyle->SetOptFit(0001);    
    gStyle->SetOptStat(0111);    
//   tmp->cd(2);
//   landau->Draw();
 //  histogram->Fit("gaus");
  tmp->SaveAs(saving_path+saving_name_fit);
}
/*
void plotting::fitting_landau_very_large(TH1F* histogram, TString canvas_name, TString saving_name_fit){

  TF1 *landau = new TF1("landau","[2]*TMath::Landau(x,[0],[1])",150,700);
  landau->SetParLimits(0,0,600);
  landau->SetParLimits(1,0,500);
  landau->SetParLimits(2,10000,1000000);
  landau->SetParNames("MPV","Sigma","Constant");
  TCanvas *tmp = new TCanvas("tmp","RAW ADC", 800,400);   
 // tmp->Divide(2,1);   
  tmp->cd();   
  histogram->Fit(landau,"R");
    gStyle->SetOptFit(0001);    
    gStyle->SetOptStat(0111);    
//   tmp->cd(2);
//   landau->Draw();
 //  histogram->Fit("gaus");
  tmp->SaveAs(saving_path+saving_name_fit);
}
void plotting::fitting_landau_small(TH1F* histogram, TString canvas_name, TString saving_name_fit){ 
  TF1 *landau = new TF1("landau","[2]*TMath::Landau(x,[0],[1])",200,600);
  landau->SetParLimits(0,0,600);
  landau->SetParLimits(1,0,500);
  landau->SetParLimits(2,100,10000);
  landau->SetParNames("MPV","Sigma","Constant");
  TCanvas *tmp = new TCanvas("tmp","RAW ADC", 800,400);   
 // tmp->Divide(2,1);   
  tmp->cd();   
  histogram->Fit(landau,"R");
    gStyle->SetOptFit(0001);    
    gStyle->SetOptStat(0111);    
//   tmp->cd(2);
//   landau->Draw();
 //  histogram->Fit("gaus");
  tmp->SaveAs(saving_path+saving_name_fit);
}

void plotting::fitting_landau_small(TH1F* histogram, TString canvas_name, TString saving_name_fit){ 
  TF1 *landau = new TF1("landau","[2]*TMath::Landau(x,[0],[1])",200,600);
  landau->SetParLimits(0,0,600);
  landau->SetParLimits(1,0,500);
  landau->SetParLimits(2,100,10000);
  landau->SetParNames("MPV","Sigma","Constant");
  TCanvas *tmp = new TCanvas("tmp","RAW ADC", 800,400);   
 // tmp->Divide(2,1);   
  tmp->cd();   
  histogram->Fit(landau,"R");
    gStyle->SetOptFit(0001);    
    gStyle->SetOptStat(0111);    
//   tmp->cd(2);
//   landau->Draw();
 //  histogram->Fit("gaus");
  tmp->SaveAs(saving_path+saving_name_fit);
}



void plotting::fitting_landau(TH1F* histogram, TString canvas_name, TString saving_name){
 RooRealVar charge_var("charge_var", "charge_var",0,2000);
 RooDataHist histo("histo","dataset with charge var",charge_var,histogram);                                                                            
TString title_name = "Raw ADC " + canvas_name;                                             
RooRealVar MVP("MVP","MVP",200,0,600);      
RooPlot *xframe=charge_var.frame(Title(title_name)); 
histo.plotOn(xframe);    
histo.statOn(xframe);   
RooRealVar Sigma("Sigma","Sigma",50,0,100);
RooLandau landau("landau","landau",charge_var, MVP, Sigma);     
landau.fitTo(histo,Range(140,800));       
landau.plotOn(xframe,RooFit::LineColor(kRed+2)); 
landau.paramOn(xframe,RooFit::Layout(0.6,0.9,0.7));                                                                                                    
TCanvas *tmp = new TCanvas("tmp","RAW ADC", 800,400);   
tmp->cd();                                                                       
gPad->SetLeftMargin(0.15);        
xframe->getAttText()->SetTextSize(0.025);                                                                          
xframe->getAttText()->SetTextColor(kRed+2);                                                                        
xframe->GetXaxis()->SetTitle("charge");                                                        
xframe->GetYaxis()->SetTitle("number of entries");                                                                  
xframe->Draw();                                                                                                                                        
gStyle->SetOptStat();                                                                                                                                  
tmp->SaveAs((saving_path + saving_name)); 
}
                            */                          
void analyze_6188(){
gROOT->SetBatch(kTRUE);


TString input_file = "/afs/cern.ch/user/n/nrawal/work/CSC_GIF/CMSSW_12_0_0_pre4/src/analyze_folder/MuonExercise0/test/outputFiles/output_6188.root";
TString direc_name = "demo";
plotting obj(input_file,direc_name);
obj.filling_hist();
obj.drawing_hist();

obj.fitting_landau(obj.h_charge_total,"total charge","total_charge_fit.pdf",10000,100000,150,600);

//obj.fitting_landau(obj.h_21[1], "ME21 1st layer", "ME21_first_layer.pdf",10000,50000,200,650);
//obj.fitting_landau(obj.h_21[2], "ME21 2nd layer", "ME21_second_layer.pdf",10000,50000,200,650);
//obj.fitting_landau(obj.h_21[3], "ME21 3rd layer", "ME21_third_layer.pdf",10000,50000,200,650);
//obj.fitting_landau(obj.h_21[4], "ME21 4th layer", "ME21_fourth_layer.pdf",10000,50000,200,650);
//obj.fitting_landau(obj.h_21[5], "ME21 5th layer", "ME21_fifth_layer.pdf",10000,50000,200,650);
//obj.fitting_landau(obj.h_21[6], "ME21 6th layer", "ME21_sixth_layer.pdf",10000,50000,200,650);
/*
obj.fitting_landau(obj.h_11[1], "ME11 1st layer", "ME11_first_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_11[2], "ME11 2nd layer", "ME11_second_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_11[3], "ME11 3rd layer", "ME11_third_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_11[4], "ME11 4th layer", "ME11_fourth_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_11[5], "ME11 5th layer", "ME11_fifth_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_11[6], "ME11 6th layer", "ME11_sixth_layer.pdf",10000,50000,200,650);

obj.fitting_landau(obj.h_with_cuts_21[1], "ME21 1st layer after selection", "ME21_with_cuts_first_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_with_cuts_21[2], "ME21 2nd layer after selection", "ME21_with_cuts_second_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_with_cuts_21[3], "ME21 3rd layer after selection", "ME21_with_cuts_third_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_with_cuts_21[4], "ME21 4th layer after selection", "ME21_with_cuts_fourth_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_with_cuts_21[5], "ME21 5th layer after selection", "ME21_with_cuts_fifth_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_with_cuts_21[6], "ME21 6th layer after selection", "ME21_with_cuts_sixth_layer.pdf",10000,50000,200,650);

obj.fitting_landau(obj.h_with_cuts_11[1], "ME11 1st layer after selection", "ME11_with_cuts_first_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_with_cuts_11[2], "ME11 2nd layer after selection", "ME11_with_cuts_second_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_with_cuts_11[3], "ME11 3rd layer after selection", "ME11_with_cuts_third_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_with_cuts_11[4], "ME11 4th layer after selection", "ME11_with_cuts_fourth_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_with_cuts_11[5], "ME11 5th layer after selection", "ME11_with_cuts_fifth_layer.pdf",10000,50000,200,650);
obj.fitting_landau(obj.h_with_cuts_11[6], "ME11 6th layer after selection", "ME11_with_cuts_sixth_layer.pdf",10000,50000,200,650);
*/
std::pair<double,double> range_fit_ME11_first_layer;
std::pair<double,double> range_fit_ME11_second_layer;
std::pair<double,double> range_fit_ME11_third_layer;
std::pair<double,double> range_fit_ME11_fourth_layer;
std::pair<double,double> range_fit_ME11_fifth_layer;
std::pair<double,double> range_fit_ME11_sixth_layer;



std::pair<double,double> range_fit_ME21_first_layer;
std::pair<double,double> range_fit_ME21_second_layer;
std::pair<double,double> range_fit_ME21_third_layer;
std::pair<double,double> range_fit_ME21_fourth_layer;
std::pair<double,double> range_fit_ME21_fifth_layer;
std::pair<double,double> range_fit_ME21_sixth_layer;

std::pair<double,double> range_fit_ME21_with_cuts_first_layer;
std::pair<double,double> range_fit_ME21_with_cuts_second_layer;
std::pair<double,double> range_fit_ME21_with_cuts_third_layer;
std::pair<double,double> range_fit_ME21_with_cuts_fourth_layer;
std::pair<double,double> range_fit_ME21_with_cuts_fifth_layer;
std::pair<double,double> range_fit_ME21_with_cuts_sixth_layer;
std::pair<double,double> range_fit_ME11_CFEB1;
std::pair<double,double> range_fit_ME11_CFEB2;
std::pair<double,double> range_fit_ME11_CFEB3;
std::pair<double,double> range_fit_ME21_CFEB1;
std::pair<double,double> range_fit_ME21_CFEB2;
std::pair<double,double> range_fit_ME21_CFEB3;
std::pair<double,double> range_fit_ME21_CFEB4;
range_fit_ME11_first_layer = obj.trail_chopping(obj.h_11[1]);
double minimum_ME11_first_layer = range_fit_ME11_first_layer.first;
double maximum_ME11_first_layer = range_fit_ME11_first_layer.second;

range_fit_ME11_second_layer = obj.trail_chopping(obj.h_11[2]);
double minimum_ME11_second_layer = range_fit_ME11_second_layer.first;
double maximum_ME11_second_layer = range_fit_ME11_second_layer.second;

range_fit_ME11_third_layer = obj.trail_chopping(obj.h_11[3]);
double minimum_ME11_third_layer = range_fit_ME11_third_layer.first;
double maximum_ME11_third_layer = range_fit_ME11_third_layer.second;

range_fit_ME11_fourth_layer = obj.trail_chopping(obj.h_11[4]);
double minimum_ME11_fourth_layer = range_fit_ME11_fourth_layer.first;
double maximum_ME11_fourth_layer = range_fit_ME11_fourth_layer.second;

range_fit_ME11_fifth_layer = obj.trail_chopping(obj.h_11[5]);
double minimum_ME11_fifth_layer = range_fit_ME11_fifth_layer.first;
double maximum_ME11_fifth_layer = range_fit_ME11_fifth_layer.second;

range_fit_ME11_sixth_layer = obj.trail_chopping(obj.h_11[6]);
double minimum_ME11_sixth_layer = range_fit_ME11_sixth_layer.first;
double maximum_ME11_sixth_layer = range_fit_ME11_sixth_layer.second;

range_fit_ME11_CFEB1 = obj.trail_chopping(obj.h_charge_CFEB_1_ME11);
double minimum_ME11_CFEB1 = range_fit_ME11_CFEB1.first;
double maximum_ME11_CFEB1 = range_fit_ME11_CFEB1.second;

range_fit_ME11_CFEB2 = obj.trail_chopping(obj.h_charge_CFEB_2_ME11);
double minimum_ME11_CFEB2 = range_fit_ME11_CFEB2.first;
double maximum_ME11_CFEB2 = range_fit_ME11_CFEB2.second;

range_fit_ME11_CFEB3 = obj.trail_chopping(obj.h_charge_CFEB_3_ME11);
double minimum_ME11_CFEB3 = range_fit_ME11_CFEB3.first;
double maximum_ME11_CFEB3 = range_fit_ME11_CFEB3.second;



range_fit_ME21_CFEB1 = obj.trail_chopping(obj.h_charge_CFEB_1_ME21);
double minimum_ME21_CFEB1 = range_fit_ME21_CFEB1.first;
double maximum_ME21_CFEB1 = range_fit_ME21_CFEB1.second;

range_fit_ME21_CFEB2 = obj.trail_chopping(obj.h_charge_CFEB_2_ME21);
double minimum_ME21_CFEB2 = range_fit_ME21_CFEB2.first;
double maximum_ME21_CFEB2 = range_fit_ME21_CFEB2.second;

range_fit_ME21_CFEB3 = obj.trail_chopping(obj.h_charge_CFEB_3_ME21);
double minimum_ME21_CFEB3 = range_fit_ME21_CFEB3.first;
double maximum_ME21_CFEB3 = range_fit_ME21_CFEB3.second;

range_fit_ME21_CFEB4 = obj.trail_chopping(obj.h_charge_CFEB_4_ME21);
double minimum_ME21_CFEB4 = range_fit_ME21_CFEB4.first;
double maximum_ME21_CFEB4 = range_fit_ME21_CFEB4.second;



range_fit_ME21_first_layer = obj.trail_chopping(obj.h_21[1]);
double minimum_ME21_first_layer = range_fit_ME21_first_layer.first;
double maximum_ME21_first_layer = range_fit_ME21_first_layer.second;

range_fit_ME21_second_layer = obj.trail_chopping(obj.h_21[2]);
double minimum_ME21_second_layer = range_fit_ME21_second_layer.first;
double maximum_ME21_second_layer = range_fit_ME21_second_layer.second;

range_fit_ME21_third_layer = obj.trail_chopping(obj.h_21[3]);
double minimum_ME21_third_layer = range_fit_ME21_third_layer.first;
double maximum_ME21_third_layer = range_fit_ME21_third_layer.second;

range_fit_ME21_fourth_layer = obj.trail_chopping(obj.h_21[4]);
double minimum_ME21_fourth_layer = range_fit_ME21_fourth_layer.first;
double maximum_ME21_fourth_layer = range_fit_ME21_fourth_layer.second;

range_fit_ME21_fifth_layer = obj.trail_chopping(obj.h_21[5]);
double minimum_ME21_fifth_layer = range_fit_ME21_fifth_layer.first;
double maximum_ME21_fifth_layer = range_fit_ME21_fifth_layer.second;

range_fit_ME21_sixth_layer = obj.trail_chopping(obj.h_21[6]);
double minimum_ME21_sixth_layer = range_fit_ME21_sixth_layer.first;
double maximum_ME21_sixth_layer = range_fit_ME21_sixth_layer.second;

range_fit_ME21_with_cuts_first_layer = obj.trail_chopping(obj.h_with_cuts_21[1]);
double minimum_ME21_with_cuts_first_layer = range_fit_ME21_with_cuts_first_layer.first;
double maximum_ME21_with_cuts_first_layer = range_fit_ME21_with_cuts_first_layer.second;

range_fit_ME21_with_cuts_second_layer = obj.trail_chopping(obj.h_with_cuts_21[2]);
double minimum_ME21_with_cuts_second_layer = range_fit_ME21_with_cuts_second_layer.first;
double maximum_ME21_with_cuts_second_layer = range_fit_ME21_with_cuts_second_layer.second;

range_fit_ME21_with_cuts_third_layer = obj.trail_chopping(obj.h_with_cuts_21[3]);
double minimum_ME21_with_cuts_third_layer = range_fit_ME21_with_cuts_third_layer.first;
double maximum_ME21_with_cuts_third_layer = range_fit_ME21_with_cuts_third_layer.second;

range_fit_ME21_with_cuts_fourth_layer = obj.trail_chopping(obj.h_with_cuts_21[4]);
double minimum_ME21_with_cuts_fourth_layer = range_fit_ME21_with_cuts_fourth_layer.first;
double maximum_ME21_with_cuts_fourth_layer = range_fit_ME21_with_cuts_fourth_layer.second;

range_fit_ME21_with_cuts_fifth_layer = obj.trail_chopping(obj.h_with_cuts_21[5]);
double minimum_ME21_with_cuts_fifth_layer = range_fit_ME21_with_cuts_fifth_layer.first;
double maximum_ME21_with_cuts_fifth_layer = range_fit_ME21_with_cuts_fifth_layer.second;

range_fit_ME21_with_cuts_sixth_layer = obj.trail_chopping(obj.h_with_cuts_21[6]);
double minimum_ME21_with_cuts_sixth_layer = range_fit_ME21_with_cuts_sixth_layer.first;
double maximum_ME21_with_cuts_sixth_layer = range_fit_ME21_with_cuts_sixth_layer.second;

obj.fitting_landau(obj.h_with_cuts_21[1], "ME21 1st layer after selection", "ME21_with_cuts_first_layer.pdf",3000,90000,minimum_ME21_with_cuts_first_layer,maximum_ME21_with_cuts_first_layer);
obj.fitting_landau(obj.h_with_cuts_21[2], "ME21 2nd layer after selection", "ME21_with_cuts_second_layer.pdf",1000,10000,minimum_ME21_with_cuts_second_layer,maximum_ME21_with_cuts_second_layer);
obj.fitting_landau(obj.h_with_cuts_21[3], "ME21 3rd layer after selection", "ME21_with_cuts_third_layer.pdf",1000,10000,minimum_ME21_with_cuts_third_layer,maximum_ME21_with_cuts_third_layer);
obj.fitting_landau(obj.h_with_cuts_21[4], "ME21 4th layer after selection", "ME21_with_cuts_fourth_layer.pdf",1000,10000,minimum_ME21_with_cuts_fourth_layer,maximum_ME21_with_cuts_fourth_layer);
obj.fitting_landau(obj.h_with_cuts_21[5], "ME21 5th layer after selection", "ME21_with_cuts_fifth_layer.pdf",1000,10000,minimum_ME21_with_cuts_fifth_layer,maximum_ME21_with_cuts_fifth_layer);
obj.fitting_landau(obj.h_with_cuts_21[6], "ME21 6th layer after selection", "ME21_with_cuts_sixth_layer.pdf",1000,10000,minimum_ME21_with_cuts_sixth_layer,maximum_ME21_with_cuts_sixth_layer);

obj.fitting_landau(obj.h_11[1], "ME11 1st layer", "ME11_first_layer.pdf",10000,50000,minimum_ME11_first_layer,maximum_ME11_first_layer);
obj.fitting_landau(obj.h_11[2], "ME11 2nd layer", "ME11_second_layer.pdf",10000,50000,minimum_ME11_second_layer,maximum_ME11_second_layer);
obj.fitting_landau(obj.h_11[3], "ME11 3rd layer", "ME11_third_layer.pdf",10000,50000,minimum_ME11_third_layer,maximum_ME11_third_layer);
obj.fitting_landau(obj.h_11[4], "ME11 4th layer", "ME11_fourth_layer.pdf",10000,50000,minimum_ME11_fourth_layer,maximum_ME11_fourth_layer);
obj.fitting_landau(obj.h_11[5], "ME11 5th layer", "ME11_fifth_layer.pdf",10000,50000,minimum_ME11_fifth_layer,maximum_ME11_fifth_layer);
obj.fitting_landau(obj.h_11[6], "ME11 6th layer", "ME11_sixth_layer.pdf",10000,50000,minimum_ME11_sixth_layer,maximum_ME11_sixth_layer);


obj.fitting_landau(obj.h_21[1], "ME21 1st layer", "ME21_first_layer.pdf",8000,50000,minimum_ME21_first_layer,maximum_ME21_first_layer);
obj.fitting_landau(obj.h_21[2], "ME21 2nd layer", "ME21_second_layer.pdf",8000,50000,minimum_ME21_second_layer,maximum_ME21_second_layer);
obj.fitting_landau(obj.h_21[3], "ME21 3rd layer", "ME21_third_layer.pdf",8000,50000,minimum_ME21_third_layer,maximum_ME21_third_layer);
obj.fitting_landau(obj.h_21[4], "ME21 4th layer", "ME21_fourth_layer.pdf",8000,50000,minimum_ME21_fourth_layer,maximum_ME21_fourth_layer);
obj.fitting_landau(obj.h_21[5], "ME21 5th layer", "ME21_fifth_layer.pdf",8000,50000,minimum_ME21_fifth_layer,maximum_ME21_fifth_layer);
obj.fitting_landau(obj.h_21[6], "ME21 6th layer", "ME21_sixth_layer.pdf",5000,50000,minimum_ME21_sixth_layer,maximum_ME21_sixth_layer);


obj.fitting_landau(obj.h_charge_CFEB_1_ME11, "ME11 CFEB1", "ME11_CFEB1.pdf",1000,10000,minimum_ME11_CFEB1,maximum_ME11_CFEB1);
obj.fitting_landau(obj.h_charge_CFEB_2_ME11, "ME11 CFEB2", "ME11_CFEB2.pdf",10000,100000,minimum_ME11_CFEB2,maximum_ME11_CFEB2);
obj.fitting_landau(obj.h_charge_CFEB_3_ME11, "ME11 CFEB3", "ME11_CFEB3.pdf",8000,50000,minimum_ME11_CFEB3,maximum_ME11_CFEB3);

obj.fitting_landau(obj.h_charge_CFEB_1_ME21, "ME21 CFEB1", "ME21_CFEB1.pdf",10000,200000,minimum_ME21_CFEB1,maximum_ME21_CFEB1);
obj.fitting_landau(obj.h_charge_CFEB_2_ME21, "ME21 CFEB2", "ME21_CFEB2.pdf",1000,10000,minimum_ME21_CFEB2,maximum_ME21_CFEB2);
obj.fitting_landau(obj.h_charge_CFEB_3_ME21, "ME21 CFEB3", "ME21_CFEB3.pdf",1000,10000,minimum_ME21_CFEB3,maximum_ME21_CFEB3);
obj.fitting_landau(obj.h_charge_CFEB_4_ME21, "ME21 CFEB4", "ME21_CFEB4.pdf",1000,10000,minimum_ME21_CFEB4,maximum_ME21_CFEB4);

obj.fitting_landau(obj.h_charge_CFEB_1_ME21, "ME21 CFEB1", "ME21_CFEB1.pdf",10000,500000,200,700);
obj.fitting_landau(obj.h_charge_CFEB_2_ME21, "ME21 CFEB2", "ME21_CFEB2.pdf",500,5000,200,700);
obj.fitting_landau(obj.h_charge_CFEB_3_ME21, "ME21 CFEB3", "ME21_CFEB3.pdf",10,1000,200,700);
obj.fitting_landau(obj.h_charge_CFEB_4_ME21, "ME21 CFEB4", "ME21_CFEB4.pdf",10,1000,200,700);

} 
std::pair<double,double> plotting::trail_chopping(TH1F * hist_fit)
 {
   int n_entries1;
   double integral_charge;
   int upper_edge, lower_edge; 
   double percentage_charge, percentage_charge_lower;
   int sum_charge = 0, sum_charge_lower = 0;
   double minimum_hist, maximum_hist; 
   std::pair<double,double> pair;

   n_entries1 = hist_fit->GetNbinsX()+1;
   integral_charge = hist_fit->Integral(0,n_entries1);
  
  if(debug){ 
   cout<<" bin content first "<<hist_fit->GetBinContent(1)<<endl;
   cout<<" bin content second "<<hist_fit->GetBinContent(2)<<endl;
   cout<<" bin content last "<<hist_fit->GetBinContent(n_entries1)<<endl;
   // for charge
   //
   }
   for(upper_edge = 1 ; upper_edge<= n_entries1; upper_edge++){
    sum_charge = sum_charge + hist_fit->GetBinContent(upper_edge);
    percentage_charge = sum_charge/integral_charge;
    if(percentage_charge >= 0.7) break;
   }
 
   for(lower_edge = 1 ; lower_edge<= n_entries1; lower_edge++){
    sum_charge_lower = sum_charge_lower + hist_fit->GetBinContent(lower_edge);
    percentage_charge_lower = sum_charge_lower/integral_charge;
    if(percentage_charge_lower >= 0.02) break;
   }
  
   TAxis* xAxis = hist_fit->GetXaxis(); 
   minimum_hist =   xAxis->GetBinLowEdge(lower_edge); 
   maximum_hist = xAxis->GetBinUpEdge(upper_edge);

//   charge_new->ResetStats();
if(debug){
   cout<<" total n_entries "<<hist_fit->GetEntries()<<endl;
   cout<<"total integral "<<integral_charge<<endl;
   cout<<"bin covering till 5% "<<lower_edge<<endl;
   cout<<"bin again 5% " <<hist_fit->Integral(0,lower_edge);
   cout<<"bin again 5% "<<sum_charge_lower<<endl;
  
   cout<<"bin covering till 70% "<<upper_edge<<endl;
  cout<<"bin again 70% " <<hist_fit->Integral(0,upper_edge);
  cout<<"bin again 70% "<<sum_charge<<endl;

  cout<<"minimum and maximum values to cut off "<<minimum_hist<<"\t "<<maximum_hist<<endl;
  }
 pair= make_pair (minimum_hist,maximum_hist);
return pair; 
 } 
