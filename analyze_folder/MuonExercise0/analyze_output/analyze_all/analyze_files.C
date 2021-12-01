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

    plotting(TString filename, TString dir_name, int run);
    double fitting_landau(TH1F *histogram, TString, TString,TString,TString);
    void filling_hist();

    std::pair<double,double> trail_chopping(TH1F* hist_fit);
    std::pair<double,double> constant_value(TH1F * hist_fit);

    double trimmed_mean(TH1F *hist_fit, TString hist_to_save);
    
    void drawing_hist();
   
    void plotting_mpv(double mpv_values[],int size, TString pdf_name);
//    TString saving_path_new = saving_path+run_number;
    TString saving_path = "/afs/cern.ch/user/n/nrawal/work/CSC_GIF_new/CMSSW_12_0_0_pre4/src/analyze_folder/MuonExercise0/analyze_output/analyze_all/plots/run_8097_all/";
  public: 
    TFile *my_file;
    TDirectoryFile *directory_name;
    bool debug = false;
    // histogram declaration
    TH2F *h_csc_hit;    
    TH1F *h_11[7], *h_21[7];
    TH1F *h_with_cuts_11[7] ,*h_with_cuts_21[7];
    TH1F *h_with_position_cuts_21[7];
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
    double layers[6] = {1,2,3,4,5,6};
    double chi_square, mpv_value, n_degree, chi_square_degree;
    ofstream myfile_ME11, myfile_ME21, myfile_ME21_cuts, myfile_ME11_cuts;
    ofstream  myfile_ME21_position_cuts;

    TH1F *h_charge_ME11;
    TH1F *h_charge_ME21;
    TH1F *h_charge;
    TH1F *h_charge_ME11_cuts;
    TH1F *h_charge_ME21_cuts;
    TH1F *h_charge_ME21_position_cuts;
    TH2F *h_position_reco_ME11;
    TH2F *h_position_reco_ME21;
//    TH1F *h_yreco;
    TH1F *hist_trim = new TH1F("hist_trim","histogram after trim",100,0,2000);

    };

plotting::plotting(TString filename, TString dir_name, int run){
   
    my_file = TFile::Open(filename);
    directory_name = (TDirectoryFile*)my_file->Get(dir_name);
    myfile_ME11.open("ME11_MPV.txt",std::ios_base::app);
    myfile_ME21.open("ME21_MPV.txt",std::ios_base::app);
    myfile_ME11_cuts.open("ME11_MPV_cuts.txt",std::ios_base::app);
    myfile_ME21_cuts.open("ME21_MPV_cuts.txt",std::ios_base::app);
    myfile_ME21_position_cuts.open("ME21_MPV_position_cuts.txt",std::ios_base::app);

    myfile_ME11<<"run"<<run<<endl; 
    myfile_ME21<<"run"<<run<<endl;
    myfile_ME11_cuts<<"run"<<run<<endl;
    myfile_ME21_cuts<<"run"<<run<<endl;
   myfile_ME21_position_cuts<<"run"<<run<<endl;
//      myfile_ME21<<"layer"<<"\t\t"<<"MPV"<<"\t\t"<<"chi_square"<<endl;

 //     myfile_ME11<<"layer"<<"\t\t"<<"MPV"<<"\t\t"<<"chi_square"<<endl;
      
  //    myfile_ME21_cuts<<"layer"<<"\t\t"<<"MPV"<<"\t\t"<<"chi_square"<<endl;


}
// function to plot mpv with layer number
void plotting::plotting_mpv(double mpv_values[],int size,TString pdf_name){
  
  TGraph *gr = new TGraph(6,layers,mpv_values);
  TCanvas *mpv_canvas = new TCanvas("mpv","MPV with different layers");
  mpv_canvas->cd();
  gStyle->SetLegendBorderSize(1);
  gStyle->SetTextColor(kBlue);
  gStyle->SetLegendFont(42);
  gStyle->SetLegendTextSize(0.02);

  gr->SetMarkerColor(9);
  gr->SetMarkerStyle(kFullDotLarge);
  gr->SetName(pdf_name); 
  gr->SetTitle(pdf_name); 
  gr->Draw("AP");
  gr->GetYaxis()->SetTitle("MPV");
  gr->GetXaxis()->SetTitle("Layer"); 

  
  auto legend = new TLegend(0.1,0.7,0.48,0.9);
  legend->AddEntry(pdf_name,"Aug2018","p");
  legend->SetTextColor(9);
  legend->Draw();

//  legend->SetHeader("The Legend Title","C"); // option "C" allows to center the header
      mpv_canvas->SaveAs(saving_path+"MPV" +pdf_name+".pdf");
}
void plotting::filling_hist(){
    
    h_charge_total = (TH1F*) directory_name->Get("Qhit");
    for(int i=1; i<7; i++) {
       TString hist_name_11 = TString::Format("rHSumQ_layer_11[%d]",i);
       TString hist_name_21 = TString::Format("rHSumQ_layer_21[%d]",i);
       TString hist_name_with_cuts_21 = TString::Format("rHSumQ_with_cuts_layer_21[%d]",i);
       TString hist_name_with_position_cuts_21 = TString::Format("rHSumQ_with_position_cuts_layer_21[%d]",i);
       TString hist_name_with_cuts_11 = TString::Format("rHSumQ_with_cuts_layer_11[%d]",i);

       h_11[i] = (TH1F*) directory_name->Get(hist_name_11);
       h_21[i] = (TH1F*) directory_name->Get(hist_name_21);
       h_with_cuts_11[i] = (TH1F*) directory_name->Get(hist_name_with_cuts_11);
       h_with_cuts_21[i] = (TH1F*) directory_name->Get(hist_name_with_cuts_21);
       h_with_position_cuts_21[i] = (TH1F*) directory_name->Get(hist_name_with_position_cuts_21);
    } 

       h_position_reco_ME11 = (TH2F*) directory_name->Get("hist_position_reco_ME11");
       h_position_reco_ME21 = (TH2F*) directory_name->Get("hist_position_reco_ME21");
//       h_yreco = (TH1F*) directory_name->Get("hist_xreco");
       h_charge_ME11 = (TH1F*) directory_name -> Get("rHSumQ_ME11");
       h_charge_ME21 = (TH1F*) directory_name -> Get("rHSumQ_ME21");
       h_charge_ME11_cuts = (TH1F*) directory_name -> Get("rHSumQ_ME11_with_cuts");
       h_charge_ME21_cuts = (TH1F*) directory_name -> Get("rHSumQ_ME21_with_cuts");
       h_charge_ME21_position_cuts = (TH1F*) directory_name -> Get("rHSumQ_ME21_with_position_cuts");
       
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
 
      TCanvas *charge_canvas_with_position_cuts_21= new TCanvas("charge_canvas_with_position_cuts_21","ADC charge for rechit per layer with position cuts ME21",1000,1000);
      charge_canvas_with_position_cuts_21->Divide(3,2);
      
      TCanvas *charge_canvas_total = new TCanvas("charge_canvas_total","ADC charge for total rechit ",1000,1000);
 
      TCanvas *charge_canvas_CFEB_ME21= new TCanvas("charge_canvas_CFEB_ME21","ADC charge per CFEB for ME21 ",1000,1000);
      charge_canvas_CFEB_ME21->Divide(2,2);
 
      TCanvas *charge_canvas_CFEB_ME11= new TCanvas("charge_canvas_CFEB_ME11","ADC charge per CFEB for ME11 ",1000,1000);
      charge_canvas_CFEB_ME11->Divide(2,2);
    
      TCanvas *charge_canvas_ME11= new TCanvas("charge_canvas_ME11","charge ME11 ",1000,1000);
      TCanvas *charge_canvas_ME21= new TCanvas("charge_canvas_ME11","charge ME21 ",1000,1000);
      TCanvas *charge_canvas_ME11_cuts= new TCanvas("charge_canvas_ME11_cuts","charge ME11 after selection ",1000,1000);
      TCanvas *charge_canvas_ME21_cuts= new TCanvas("charge_canvas_ME21_cuts","charge ME21 after selection ",1000,1000);
      TCanvas *charge_canvas_ME21_position_cuts= new TCanvas("charge_canvas_ME21_position_cuts","charge ME21 after position selection ",1000,1000);
     TCanvas *center_strip_canvas = new TCanvas("center_strip_canvas","strip number for ME2/1 ",1000,1000);

     TCanvas *strip_hit_canvas = new TCanvas("strip_hit_canvas","Strip number with Number of strips in the strip hit ",1000,1000);
     TCanvas *canvas_position_segment = new TCanvas("canvas_position_segment"," x and y position of segment ",1000,1000);
     canvas_position_segment->Divide(2,1);
     canvas_position_segment->cd(1);
     h_position_reco_ME11->GetXaxis()->SetTitle("x");
     h_position_reco_ME11->GetYaxis()->SetTitle("y");
     h_position_reco_ME11->Draw("colz");
     canvas_position_segment->cd(2);
     h_position_reco_ME21->GetXaxis()->SetTitle("x");
     h_position_reco_ME21->GetYaxis()->SetTitle("y");
     h_position_reco_ME21->Draw("colz");

     canvas_position_segment->SaveAs(saving_path+"positions_segment.pdf");


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
      charge_canvas_with_cuts_21 ->SaveAs(saving_path+"Charge_layer_ME21_with_cuts.pdf");
    
      // for charge per layer for ME21 chamber after the position cuts
      for(int i=1 ; i<7 ; i++){
         charge_canvas_with_position_cuts_21->cd(i);
          h_with_position_cuts_21[i]->Draw();
       }

      charge_canvas_with_position_cuts_21 ->SaveAs(saving_path+"Charge_layer_ME21_with_position_cuts.pdf");

      for(int i=1 ; i<7 ; i++){
         charge_canvas_with_cuts_11->cd(i);
          h_with_cuts_11[i]->Draw();
       }

      charge_canvas_with_cuts_11 ->SaveAs(saving_path+"Charge_layer_ME11_with_cuts.pdf");


      // for total charge  
      charge_canvas_total->cd();
      h_charge_total->Draw();
      charge_canvas_total->SaveAs(saving_path+"total_charge.pdf");

      charge_canvas_ME11->cd();
      h_charge_ME11->Draw();
      charge_canvas_ME11->SaveAs(saving_path+"total_charge_ME11.pdf");

      charge_canvas_ME21->cd();
      h_charge_ME21->Draw();
      charge_canvas_ME21->SaveAs(saving_path+"total_charge_ME21.pdf");

      charge_canvas_ME11_cuts->cd();
      h_charge_ME11_cuts->Draw();
      charge_canvas_ME11_cuts->SaveAs(saving_path+"total_charge_ME11_cuts.pdf");

      charge_canvas_ME21_cuts->cd();
      h_charge_ME21_cuts->Draw();
      charge_canvas_ME21_cuts->SaveAs(saving_path+"total_charge_ME21_cuts.pdf");

      charge_canvas_ME21_position_cuts->cd();
      h_charge_ME21_position_cuts->Draw();
      charge_canvas_ME21_position_cuts->SaveAs(saving_path+"total_charge_ME21_position_cuts.pdf");



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

double plotting::fitting_landau(TH1F* histogram, TString canvas_name, TString saving_name_fit,TString chamber,TString layer){

  std::pair<double,double> fit_range, const_value;
  double fit_range_min, fit_range_max; 
  double const_min, const_max; 

  fit_range = this->trail_chopping(histogram);
  const_value = this->constant_value(histogram);
  
  fit_range_min = fit_range.first;
  fit_range_max = fit_range.second;
 
  const_min = const_value.first;
  const_max = const_value.second;
 
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
    chi_square = landau->GetChisquare(); 
    n_degree = landau->GetNDF(); 
    mpv_value = landau->GetParameter(0);
    chi_square_degree = chi_square/n_degree;
  if(chamber=="ME11"){

   myfile_ME11<<layer<<"layer";
   myfile_ME11<<"\t\t"<<mpv_value<<"\t\t"<<chi_square<<"\t\t"<<n_degree<<"\t\t"<<chi_square_degree<<endl;
  }
  if(chamber=="ME11_cuts"){

   myfile_ME11_cuts<<layer<<"layer";
   myfile_ME11_cuts<<"\t\t"<<mpv_value<<"\t\t"<<chi_square<<"\t\t"<<n_degree<<"\t\t"<<chi_square_degree<<endl;
  }


  if(chamber=="ME21"){
    myfile_ME21<<layer<<"layer";
    myfile_ME21<<"\t\t"<<mpv_value<<"\t\t"<<chi_square<<"\t\t"<<n_degree<<"\t\t"<<chi_square_degree<<endl;
  }

  if(chamber=="ME21_cuts"){
  
    myfile_ME21_cuts<<layer<<"layer";
    myfile_ME21_cuts<<"\t\t"<<mpv_value<<"\t\t"<<chi_square<<"\t\t"<<n_degree<<"\t\t"<<chi_square_degree<<endl;
  }
  if(chamber=="ME21_position_cuts"){
  
    myfile_ME21_position_cuts<<layer<<"layer";
    myfile_ME21_position_cuts<<"\t\t"<<mpv_value<<"\t\t"<<chi_square<<"\t\t"<<n_degree<<"\t\t"<<chi_square_degree<<endl;
  }


    return landau->GetParameter(0);
  
}
                   
void analyze_files(){
gROOT->SetBatch(kTRUE);


TString input_file = "/afs/cern.ch/user/n/nrawal/work/CSC_GIF_new/CMSSW_12_0_0_pre4/src/analyze_folder/MuonExercise0/test/outputFiles/output_8097_all.root";
TString direc_name = "demo";
int run_number = 8097;
plotting obj(input_file,direc_name, run_number);
obj.filling_hist();
obj.drawing_hist();
double mpv_ME11, mpv_ME21,  mpv_ME11_cuts, mpv_ME21_cuts, mpv_ME21_position_cuts;; 
double mpv_ME11_layers[6], mpv_ME21_layers[6],  mpv_ME11_layers_with_cuts[6], mpv_ME21_layers_with_cuts[6]; 
double mpv_ME21_layers_with_position_cuts[6];

double charge_total_mpv = obj.fitting_landau(obj.h_charge_total,"total charge","total_charge_fit.pdf","total_charge","all");
mpv_ME11 = obj.fitting_landau(obj.h_charge_ME11, "ME11 layer", "ME11.pdf","ME11","layers");
mpv_ME21 = obj.fitting_landau(obj.h_charge_ME21, "ME21 layer", "ME21.pdf","ME21","layers");
mpv_ME21_cuts= obj.fitting_landau(obj.h_charge_ME21_cuts, "ME21 layer after selection", "ME21_with_cuts.pdf","ME21_cuts","layers");
mpv_ME11_cuts= obj.fitting_landau(obj.h_charge_ME11_cuts, "ME11 layer after selection", "ME11_with_cuts.pdf","ME11_cuts","layers");

TString layer_number[6] = {"1st", "2nd", "3rd", "4th", "5th", "6th"};

TString saving_name_ME11_with_cuts[6] = {"ME11_with_cuts_first_layer.pdf", "ME11_with_cuts_second_layer.pdf", "ME11_with_cuts_third_layer.pdf", "ME11_with_cuts_fourth_layer.pdf", "ME11_with_cuts_fifth_layer.pdf", "ME11_with_cuts_sixth_layer.pdf" };
TString saving_name_ME21_with_cuts[6] = {"ME21_with_cuts_first_layer.pdf", "ME21_with_cuts_second_layer.pdf", "ME21_with_cuts_third_layer.pdf", "ME21_with_cuts_fourth_layer.pdf", "ME21_with_cuts_fifth_layer.pdf", "ME21_with_cuts_sixth_layer.pdf" };

TString saving_name_ME21_with_position_cuts[6] = {"ME21_with_position_cuts_first_layer.pdf", "ME21_with_position_cuts_second_layer.pdf", "ME21_with_position_cuts_third_layer.pdf", "ME21_with_position_cuts_fourth_layer.pdf", "ME21_with_position_cuts_fifth_layer.pdf", "ME21_with_position_cuts_sixth_layer.pdf" };

TString saving_name_ME11[6] = {"ME11_first_layer.pdf", "ME11_second_layer.pdf", "ME11_third_layer.pdf", "ME11_fourth_layer.pdf", "ME11_fifth_layer.pdf", "ME11_sixth_layer.pdf" };
TString saving_name_ME21[6] = {"ME21_first_layer.pdf", "ME21_second_layer.pdf", "ME21_third_layer.pdf", "ME21_fourth_layer.pdf", "ME21_fifth_layer.pdf", "ME21_sixth_layer.pdf" };


TString title_name_ME11_with_cuts[6] = {"ME11 1st layer after selection", "ME11 2nd layer after selection", "ME11 3rd layer after selection","ME11 4th layer after selection", "ME11 5th layer after selection", "ME11 6th layer after selection"};
 TString title_name_ME21_with_cuts[6] = {"ME21 1st layer after selection", "ME21 2nd layer after selection", "ME21 3rd layer after selection","ME21 4th layer after selection", "ME21 5th layer after selection", "ME21 6th layer after selection"};
 TString title_name_ME21_with_position_cuts[6] = {"ME21 1st layer after position selection", "ME21 2nd layer after position selection", "ME21 3rd layer after position selection","ME21 4th layer after position selection", "ME21 5th layer after position selection", "ME21 6th layer after position selection"};
 TString title_name_ME11[6] = {"ME11 1st layer", "ME11 2nd layer", "ME11 3rd layer", "ME11 4th layer", "ME11 5th layer", "ME11 6th layer" };
 TString title_name_ME21[6] = {"ME21 1st layer", "ME21 2nd layer", "ME21 3rd layer", "ME21 4th layer", "ME21 5th layer", "ME21 6th layer" };

 TString title_name_trimmed_ME11_layers_with_cuts[6] = {"trim_mean_ME11_with_cuts_1stlayer.pdf","trim_mean_with_cuts_ME11_2ndlayer.pdf","trim_mean_with_cuts_ME11_3rdlayer.pdf","trim_mean_with_cuts_ME11_4thlayer.pdf","trim_mean_with_cuts_ME11_5thlayer.pdf","trim_mean_with_cuts_ME11_6thlayer.pdf"};
 TString title_name_trimmed_ME21_layers_with_cuts[6] = {"trim_mean_ME21_with_cuts_1stlayer.pdf","trim_mean_with_cuts_ME21_2ndlayer.pdf","trim_mean_with_cuts_ME21_3rdlayer.pdf","trim_mean_with_cuts_ME21_4thlayer.pdf","trim_mean_with_cuts_ME21_5thlayer.pdf","trim_mean_with_cuts_ME21_6thlayer.pdf"};


 TString title_name_trimmed_ME21_layers_with_position_cuts[6] = {"trim_mean_position_cut_ME21_1stlayer.pdf","trim_mean_position_cut_ME21_2ndlayer.pdf","trim_mean_position_cut_ME21_3rdlayer.pdf","trim_mean_position_cut_ME21_4thlayer.pdf","trim_mean_position_cut_ME21_5thlayer.pdf","trim_mean_position_cut_ME21_6thlayer.pdf"};

double trimmed_mean_ME11_layers_with_cuts[6], trimmed_mean_ME21_layers_with_cuts[6], trimmed_mean_ME21[6], trimmed_mean_ME11[6];
double trimmed_mean_ME21_layers_with_position_cuts[6];
for(int i=0; i<6;i++){
  
mpv_ME21_layers_with_cuts[i] = obj.fitting_landau(obj.h_with_cuts_21[i+1], title_name_ME21_with_cuts[i],saving_name_ME21_with_cuts[i],"ME21_cuts",layer_number[i]);
mpv_ME21_layers_with_position_cuts[i] = obj.fitting_landau(obj.h_with_position_cuts_21[i+1], title_name_ME21_with_position_cuts[i],saving_name_ME21_with_position_cuts[i],"ME21_position_cuts",layer_number[i]);
mpv_ME11_layers_with_cuts[i] = obj.fitting_landau(obj.h_with_cuts_11[i+1], title_name_ME11_with_cuts[i],saving_name_ME11_with_cuts[i],"ME11_cuts",layer_number[i]);
mpv_ME21_layers[i] = obj.fitting_landau(obj.h_21[i+1], title_name_ME21[i],saving_name_ME21[i],"ME21",layer_number[i]);
mpv_ME11_layers[i] = obj.fitting_landau(obj.h_11[i+1], title_name_ME11[i],saving_name_ME11[i],"ME11",layer_number[i]);

trimmed_mean_ME11_layers_with_cuts[i] = obj.trimmed_mean(obj.h_with_cuts_11[i+1],title_name_trimmed_ME11_layers_with_cuts[i]);
trimmed_mean_ME21_layers_with_cuts[i] = obj.trimmed_mean(obj.h_with_cuts_21[i+1],title_name_trimmed_ME21_layers_with_cuts[i]);
trimmed_mean_ME21_layers_with_position_cuts[i] = obj.trimmed_mean(obj.h_with_position_cuts_21[i+1],title_name_trimmed_ME21_layers_with_position_cuts[i]);
//trimmed_mean_ME11[i] = obj.trimmed_mean(obj.h_11[i+1], trimmed_name_ME11);
//trimmed_mean_ME21[i] = obj.trimmed_mean(obj.h_21[i+1], trimmed_name_ME21);
 }

//ofstream fit_txt_ME11, fit_txt_ME21, fit_txt_ME11_with_cuts, fit_txt_ME21_with_cuts;
ofstream fit_txt_mpv;//
ofstream fit_txt_ME21_with_position_cuts;
ofstream fit_txt_ME11_with_cuts;
ofstream fit_txt_ME21_with_cuts;
//fit_txt_ME11.open("ME11_MPV.txt");
//fit_txt_ME21.open("ME21_MPV.txt");
//fit_txt_ME11_with_cuts.open("ME11_MPV_cuts.txt");
fit_txt_ME21_with_position_cuts.open("ME21_position_cuts_trimmed.txt",std::ios_base::app);
fit_txt_mpv.open("ME21_with_cuts_trimmed.txt",std::ios_base::app);
fit_txt_ME11_with_cuts.open("ME11_with_cuts_trimmed.txt",std::ios_base::app);
fit_txt_mpv<<"run"<<run_number<<endl;
fit_txt_ME21_with_position_cuts<<"run"<<run_number<<endl;
fit_txt_ME11_with_cuts<<"run"<<run_number<<endl;
fit_txt_ME21_with_cuts<<"run"<<run_number<<endl;
/*
 fit_txt_ME11<<"ME11 MPV all layers"<<std::endl;
 fit_txt_ME11<<mpv_ME11<<std::endl;
 fit_txt_ME21<<"ME11 MPV all layers"<<std::endl;
 fit_txt_ME21<<mpv_ME21<<std::endl;
 fit_txt_ME21<<"ME11 MPV all layers"<<std::endl;
 fit_txt_ME11_with_cuts<<mpv_ME11<<std::endl;
 fit_txt_ME21_with_cuts<<"ME11 MPV all layers"<<std::endl;
 fit_txt_ME21_with_cuts<<mpv_ME21<<std::endl;


  fit_txt_mpv<<"mpv_ME21_layers_with_cuts landau fit"<<std::endl;
for(int i=0; i<6;i++){
 fit_txt_ME11<<mpv_ME11<<std::endl;
 fit_txt_ME21<<mpv_ME21<<std::endl;
 fit_txt_ME11_with_cuts<<mpv_ME11<<std::endl;
 fit_txt_ME21_with_cuts<<mpv_ME11<<std::endl;

  fit_txt_mpv<<mpv_ME21_layers_with_cuts[i]<<std::endl;
}

 // fit_txt_mpv<<"mpv_ME21_layers_with_position_cuts landau fit"<<std::endl;
//for(int i=0; i<6;i++){
 fit_txt_ME11<<mpv_ME11<<std::endl;
 fit_txt_ME21<<mpv_ME21<<std::endl;
 fit_txt_ME11_with_cuts<<mpv_ME11<<std::endl;
 fit_txt_ME21_with_cuts<<mpv_ME11<<std::endl;

// fit_txt_mpv<<mpv_ME21_layers_with_position_cuts[i]<<std::endl;
//}
*/

fit_txt_mpv<<"mpv_ME21_layers_with_cuts trimmed fit"<<std::endl;
for(int i=0; i<6;i++){
/* fit_txt_ME11<<mpv_ME11<<std::endl;
 fit_txt_ME21<<mpv_ME21<<std::endl;
 fit_txt_ME11_with_cuts<<mpv_ME11<<std::endl;
 fit_txt_ME21_with_cuts<<mpv_ME11<<std::endl;
*/
  fit_txt_mpv<<trimmed_mean_ME21_layers_with_cuts[i]<<std::endl;
}
fit_txt_ME21_with_position_cuts<<"mpv ME21 layers with postiion cuts trimmed fit"<<std::endl;
for(int i=0; i<6;i++){
/* fit_txt_ME11<<mpv_ME11<<std::endl;
 fit_txt_ME21<<mpv_ME21<<std::endl;
 fit_txt_ME11_with_cuts<<mpv_ME11<<std::endl;
 fit_txt_ME21_with_cuts<<mpv_ME11<<std::endl;
*/
  fit_txt_ME21_with_position_cuts<<trimmed_mean_ME21_layers_with_position_cuts[i]<<std::endl;
}
fit_txt_ME11_with_cuts<<"mpv ME11 layers with cuts trimmed fit"<<std::endl;
for(int i=0; i<6;i++){
/* fit_txt_ME11<<mpv_ME11<<std::endl;
 fit_txt_ME21<<mpv_ME21<<std::endl;
 fit_txt_ME11_with_cuts<<mpv_ME11<<std::endl;
 fit_txt_ME21_with_cuts<<mpv_ME11<<std::endl;
*/
  fit_txt_ME11_with_cuts<<trimmed_mean_ME11_layers_with_cuts[i]<<std::endl;
}

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
    if(percentage_charge_lower >= 0.09) break;
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

double plotting::trimmed_mean(TH1F *hist_fit, TString hist_to_save)
{
   int n_entries1;
   double integral_charge;
   int upper_edge, lower_edge; 
   double percentage_charge, percentage_charge_lower;
   int sum_charge = 0, sum_charge_lower = 0;
   double minimum_hist, maximum_hist; 
   std::pair<double,double> pair;

   double mean_charge;
   double value;
  
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
    sum_charge_lower = sum_charge_lower + hist_fit->GetBinContent(lower_edge); percentage_charge_lower = sum_charge_lower/integral_charge;
    if(percentage_charge_lower >= 0.09) break;
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
mean_charge = 0;

   for(int i=lower_edge; i<= upper_edge; i++){
     value = hist_fit->GetBinContent(i);
     hist_trim->SetBinContent(i,value);
   }
   hist_trim->ResetStats();
TCanvas *canvas_trim = new TCanvas("canvas_trim","canvas after trim");
canvas_trim->cd();
   hist_trim->Draw();
   mean_charge = hist_trim->GetMean();

/*   TLegend* leg2 = new TLegend(0.7, 0.7, 0.88, 0.88);
     leg2->SetFillColor(kWhite);
     leg2->SetLineColor(kBlack);
     leg2->AddEntry("entries",Form("Events= %.0f",hist_trim->GetEntries()),"");
     leg2->AddEntry("mean_charge",Form("mean = %.2f",mean_charge),"");
     leg2->Draw("same");*/
     gStyle->SetOptStat();

canvas_trim->SaveAs(saving_path+hist_to_save);
  if(debug){
    std::cout<<"trimmed mean value"<<mean_charge<<std::endl;
  } 

   // mean of the trimed histogram is returned and used
   return mean_charge;
}

std::pair<double,double> plotting::constant_value(TH1F * hist_fit){
  int entries;
  double constant_min, constant_max;
  std::pair<double,double> constant_pair;
  entries = hist_fit->GetEntries();
  
  if(entries >=10000 && entries <= 20000){
  constant_min = 2000;
  constant_max = 8000;

}

if(entries >=30000 && entries <= 50000){
  constant_min = 5000;
  constant_max = 25000;

}

if(entries >=50000 && entries <= 100000){
  constant_min = 10000;
  constant_max = 50000;

}

if(entries >=100000 && entries <= 1000000){
  constant_min = 50000;
  constant_max = 100000;

}
constant_pair = make_pair(constant_min, constant_max);
return constant_pair;
}
