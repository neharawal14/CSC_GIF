// -*- C++ -*-
//
// Package:    DASExercises/MuonExercise0
// Class:      MuonExercise0
//
/**\class MuonExercise0 MuonExercise0.cc DASExercises/MuonExercise0/plugins/MuonExercise0.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Jian Wang
//         Created:  Wed, 27 Nov 2019 09:09:57 GMT
//
//


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/one/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "FWCore/ServiceRegistry/interface/Service.h"
#include "CommonTools/UtilAlgos/interface/TFileService.h"

#include "DataFormats/CSCRecHit/interface/CSCSegmentCollection.h"
#include "DataFormats/CSCRecHit/interface/CSCRecHit2DCollection.h"
#include<TH2F.h>
using namespace edm;
using namespace std;

//
// class declaration
//



class MuonExercise0 : public edm::one::EDAnalyzer<edm::one::SharedResources>  {
   public:
      explicit MuonExercise0(const edm::ParameterSet&); ~MuonExercise0(); static void fillDescriptions(edm::ConfigurationDescriptions& descriptions); private: virtual void beginJob() override;
      virtual void analyze(const edm::Event&, const edm::EventSetup&) override;
      virtual void endJob() override;



      // member functions created by me
      
      void fill_charge_ME11();
      void fill_charge_ME21();
      void fill_charge_ME11_with_cuts();
      void fill_charge_ME21_with_cuts();
      void fill_charge_CFEB_ME11();
      void fill_charge_CFEB_ME21();
      void fill_charge_ME21_with_position_cuts();

      // ----------member data ---------------------------
      EDGetTokenT<CSCSegmentCollection>           theCSCSegmentToken;
      EDGetTokenT<CSCRecHit2DCollection>          theCSCRecHitToken;

      TH1F *nSeg, *nHit, *Qhit;
      TH1F *rHSumQ_layer_11[7], *rHSumQ_layer_21[7];
      TH1F *rHSumQ_with_cuts_layer_21[7];
      TH1F *rHSumQ_with_position_cuts_layer_21[7];
      TH1F *rHSumQ_with_cuts_layer_11[7];
      TH1F *rHSumQ_strip1_ME11, *rHSumQ_strip2_ME11, *rHSumQ_strip3_ME11;
      TH1F *rHSumQ_strip1_ME21, *rHSumQ_strip2_ME21, *rHSumQ_strip3_ME21, *rHSumQ_strip4_ME21;
      TH2F* cs_hit;
      TH1F* center_Strip_dist_ME21;
      TH1F* center_Strip_dist_ME11;
      TH1F *rHSumQ_ME11, *rHSumQ_ME21, *rHSumQ_ME11_with_cuts, *rHSumQ_ME21_with_cuts;
      TH1F *rHSumQ_ME21_with_position_cuts; 
      bool debug_value;
      bool debug_entries ;
      bool bool_ME11 = true;
      bool bool_ME21 = true; 
      bool bool_position_cuts = true; 
      double year = 2018;

      double rHSumQ;
      double rHSumQ_with_cuts;
      int kLayer, kChamber, kRing, kStation, kEndcap, centerStrip, numberStrips;

     //  if(debug_entries)
      double n_entries_total,n_entries_ME11, n_entries_ME21, n_entries_CFEB, n_entries_not, n_entries_ME21_with_cuts, n_entries_ME11_with_cuts, n_entries_ME21_with_position_cuts;
     
      float xreco, yreco;
      TH2F *hist_position_reco_ME11; 
      TH2F *hist_position_reco_ME21; 
};

//
// constants, enums and typedefs
//

//
// static data member definitions
//

//
// constructors and destructor
//
MuonExercise0::MuonExercise0(const edm::ParameterSet& iConfig)
 :
  theCSCSegmentToken(consumes<CSCSegmentCollection>(iConfig.getUntrackedParameter<edm::InputTag>("cscSegments"))),
  theCSCRecHitToken(consumes<CSCRecHit2DCollection>(iConfig.getUntrackedParameter<edm::InputTag>("cscRecHits")))
{
   //now do what ever initialization is needed

   Service<TFileService> fs; // a CMSSW framework to store histograms

   // if you want to debug 

    debug_value = false ;
    debug_entries = true;
    if(debug_entries) {
     n_entries_total =0;
     n_entries_ME11 = 0;
     n_entries_ME21 = 0;
     n_entries_ME21_with_cuts = 0;
     n_entries_ME11_with_cuts = 0;
     n_entries_CFEB = 0;
     n_entries_not = 0; 
     n_entries_ME21_with_position_cuts = 0;
    }

           // my member variable initialization

           nSeg = fs->make<TH1F>("nSeg", "Number of CSC segments", 5, 0, 5 );
           nHit = fs->make<TH1F>("nHit", "Number of RecHits per segment", 8, 0, 8 );
           Qhit = fs->make<TH1F>("Qhit", "ADC charge of each RecHit", 100, 0, 2000 );
           center_Strip_dist_ME21 = fs->make<TH1F>("center_Strip_dist_ME21", "Central Strip number : ME21", 70, 0, 70 );
           center_Strip_dist_ME11 = fs->make<TH1F>("center_Strip_dist_ME11", "Central Strip number : ME11", 70, 0, 70 );
           cs_hit = fs->make<TH2F>("cs_hit"," RecHitCentral strip vs NStrips", 65,0,64,5,0,5); 
           hist_position_reco_ME11 = fs->make<TH2F>("hist_position_reco_ME11","histogram for x-y position local ME11",160,-80,80,320,-160,160); 
           hist_position_reco_ME21 = fs->make<TH2F>("hist_position_reco_ME21","histogram for x-y position local ME21",160,-80,80,320,-160,160); 

          rHSumQ_ME21_with_position_cuts = fs->make<TH1F>("rHSumQ_ME21_with_position_cuts", "Charge deposited on ME21 after position selection"  , 100 , 0 , 2000 );
          rHSumQ_ME11 = fs->make<TH1F>("rHSumQ_ME11", "Charge deposited on ME11"  , 100 , 0 , 2000 );
          rHSumQ_ME21 = fs->make<TH1F>("rHSumQ_ME21", "Charge deposited on ME21"  , 100 , 0 , 2000 );
          rHSumQ_ME11_with_cuts = fs->make<TH1F>("rHSumQ_ME11_with_cuts", "Charge deposited on ME11 after selection"  , 100 , 0 , 2000 );
          rHSumQ_ME21_with_cuts = fs->make<TH1F>("rHSumQ_ME21_with_cuts", "Charge deposited on ME21 after selection"  , 100 , 0 , 2000 );
           for (int i=1; i<7; i++){ 
             TString hist_name11 = TString::Format( "rHSumQ_layer_11[%d]" , i);
             cout<<hist_name11<<endl;
             TString hist_title_11 = TString::Format("Charge deposited on %d layer ME11",i);
             rHSumQ_layer_11[i] = fs->make<TH1F>(hist_name11, hist_title_11  , 100 , 0 , 2000 );
 
             TString hist_name11_with_cuts = TString::Format( "rHSumQ_with_cuts_layer_11[%d]" , i);
             cout<<hist_name11_with_cuts<<endl;
             TString hist_title_11_with_cuts = TString::Format("Charge deposited on %d layer ME11 with cuts",i);
             rHSumQ_with_cuts_layer_11[i] = fs->make<TH1F>(hist_name11_with_cuts, hist_title_11_with_cuts ,  100 , 0 , 2000 );
            
             TString hist_name21_with_position_cuts = TString::Format( "rHSumQ_with_position_cuts_layer_21[%d]" , i);
             cout<<hist_name21_with_position_cuts<<endl;
  
            TString hist_title_21_with_position_cuts = TString::Format("Charge deposited on %d layer ME21 with position cuts",i);
            rHSumQ_with_position_cuts_layer_21[i] = fs->make<TH1F>(hist_name21_with_position_cuts, hist_title_21_with_position_cuts ,  100 , 0 , 2000 );
 
           
             TString hist_name21 = TString::Format( "rHSumQ_layer_21[%d]" , i);
             TString hist_name21_with_cuts = TString::Format( "rHSumQ_with_cuts_layer_21[%d]" , i);
             cout<<hist_name21<<"\t \t"<<hist_name21_with_cuts<<endl;
  
             TString hist_title_21 = TString::Format("Charge deposited on %d layer ME21",i);
             rHSumQ_layer_21[i] = fs->make<TH1F>(hist_name21, hist_title_21 ,  100 , 0 , 2000 );
             TString hist_title_21_with_cuts = TString::Format("Charge deposited on %d layer ME21 with cuts",i);
             rHSumQ_with_cuts_layer_21[i] = fs->make<TH1F>(hist_name21_with_cuts, hist_title_21_with_cuts ,  100 , 0 , 2000 );
            }
        
           rHSumQ_strip1_ME11 = fs->make<TH1F>("rHSumQ_strip1_ME11"," charge on first CFEB ME11",100,0,2000);
           rHSumQ_strip2_ME11 = fs->make<TH1F>("rHSumQ_strip2_ME11"," charge on second CFEB ME11",100,0,2000);
           rHSumQ_strip3_ME11 = fs->make<TH1F>("rHSumQ_strip3_ME11"," charge on third CFEB ME11",100,0,2000);
 
           rHSumQ_strip1_ME21 = fs->make<TH1F>("rHSumQ_strip1_ME21"," charge on first CFEB ME21",100,0,2000);
           rHSumQ_strip2_ME21 = fs->make<TH1F>("rHSumQ_strip2_ME21"," charge on second CFEB ME21",100,0,2000);
           rHSumQ_strip3_ME21 = fs->make<TH1F>("rHSumQ_strip3_ME21"," charge on third CFEB ME21",100,0,2000);
           rHSumQ_strip4_ME21 = fs->make<TH1F>("rHSumQ_strip4_ME21"," charge on fourth CFEB ME21",100,0,2000);

}  
        

MuonExercise0::~MuonExercise0()
{

   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called for each event  ------------
void
MuonExercise0::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
   Handle<CSCSegmentCollection> cscSegments;
   iEvent.getByToken(theCSCSegmentToken, cscSegments);

    //  if(cscSegments->size()!=1)return; // let's simply ignore events with >1 segments for the moment
   
   // to loop over all the segments of the track 

   for(CSCSegmentCollection::const_iterator seg = cscSegments->begin(); seg!= cscSegments->end(); seg++){

      CSCDetId id = (CSCDetId)(*seg).cscDetId();
          kEndcap = id.endcap();
          kRing = id.ring();
          kStation = id.station();
          kChamber = id.chamber();
    
      if(debug_value) cout<<"kRing \t kStation \t kLayer \t for segment"<<endl;
      if(debug_value) cout<<kRing<<"\t"<<kStation<<"\t"<<kChamber<<"\t"<<kEndcap<<endl;
     
       // taking out specific rechit from the segments 
      vector<CSCRecHit2D> theRecHits = seg->specificRecHits();
      for(vector<CSCRecHit2D>::const_iterator iRH = theRecHits.begin(); iRH != theRecHits.end(); iRH++) {

       LocalPoint rhitlocal = (*iRH).localPosition();
       xreco = rhitlocal.x();
       yreco = rhitlocal.y();
          if(debug_entries) n_entries_total++;

          CSCDetId idRH = (CSCDetId)(*iRH).cscDetId();
          kLayer = idRH.layer();
        
         // total number of strips the rechit had

         numberStrips = (*iRH).nStrips();
         centerStrip = (*iRH).channels(1); 
         // other way to evaluate central strip number 
         //centerStrip = iRH->channels(1); 
         
         //to check number of strips covered by each hit
   
//         std::cout<<"number of strips and corresponding strip number"<<centerStrip<<"  "<<numberStrips<<endl;   
         cs_hit->Fill(centerStrip, numberStrips);
        
        // fill strips only when a rechit has 3 strips

        if(numberStrips==3){


         // work with these good hits 
           rHSumQ = 0;
           rHSumQ_with_cuts = 0;
          for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
              rHSumQ += (*iRH).adcs(i,j);
             }
           }
        if(debug_value) cout<<"wire and channel number"<<(*iRH).hitWire()<<"\t"<<(*iRH).channels(1)<<endl;
     
        }
        else break;
 

    
       if(debug_value) cout<<"kRing \t kStation \t kLayer \t for hit"<<endl;
       if(debug_value) cout<<kRing<<"\t"<<kStation<<"\t"<<kChamber<<"\t"<<kEndcap<<endl;
 
       // to fill the evaluated charge in different histograms per layer 
      
       if(debug_value)  cout<<"filling values ers"<<endl;
       if(kStation == 1 && kRing == 1) fill_charge_ME11(); 
       if(kStation == 1 && kRing == 1) hist_position_reco_ME11->Fill(xreco, yreco);
       
       if(debug_value)  cout<<"filling values bers"<<endl;
      if(kStation == 2 && kRing == 1) fill_charge_ME21();
      if(kStation == 2 && kRing == 1) hist_position_reco_ME21->Fill(xreco, yreco);
       
       if(debug_value)  cout<<"filling values ME chambers"<<endl;
         // Charge per CFEB for ME21 
      if(kStation ==2 && kRing ==1) fill_charge_CFEB_ME21();
      if(kStation ==1 && kRing ==1) fill_charge_CFEB_ME11();
//      if(kStation ==1 && kRing ==2) cout<<"ME 2/1 strip number "<<centerStrip<<endl;
//      if(kStation ==1 && kRing ==1) cout<<"ME 1/1 strip number "<<centerStrip<<endl;

       if(debug_value)  cout<<"filling values cfeb"<<endl;
         // Charge per CFEB for ME21 
      if(kStation ==2 && kRing ==1)
        center_Strip_dist_ME21->Fill(centerStrip);
      
      if(kStation ==1 && kRing ==1) center_Strip_dist_ME11->Fill(centerStrip);
      Qhit->Fill(rHSumQ);

       if(! (kStation == 1 && kRing ==1 )){
       if(! (kStation ==2 && kRing == 1)){
          n_entries_not++;
       if(debug_entries) cout<<kStation<<"  \t ring not matching "<<kRing<<endl;      
         }
       }
     if(bool_position_cuts == true){  
      if(year ==2021){
        if(kStation == 2 && kRing == 1) {     // applying vladimir cuts  
        if(xreco > -46 && xreco< -28 && yreco >-8 && yreco < 9){
        if(debug_value) cout<<"passed the conditions with position cuts"<<xreco<<"\t"<<yreco<<endl;
        fill_charge_ME21_with_position_cuts();
         } 
        }

      } 
       if(year ==2018){
        // applying vladimir cuts  
        if(kStation == 2 && kRing == 1) {     // applying vladimir cuts  
        if( xreco > -43 && xreco< -25 && yreco< 9 && yreco> -10){
        if(debug_value) cout<<"passed the conditions with position cuts for 2018"<<xreco<<"\t"<<yreco<<endl;
        fill_charge_ME21_with_position_cuts();
          }
        }
      } 
     } 
       if(bool_ME21==true){ 

       if((*iRH).hitWire() <= 64 && (*iRH).hitWire() >= 59) {
          if((*iRH).channels(1) <= 11 && (*iRH).channels(1) >= 4){ 
           if(debug_value)cout<<"passed the conditions wire and channel number"<<(*iRH).hitWire()<<"\t"<<(*iRH).channels(1)<<endl;
           if(kStation == 2 && kRing == 1) fill_charge_ME21_with_cuts();
          }
       } 
      // if((*iRH).hitWire()>64 || (*iRH).hitWire()<59) continue;
      // if((*iRH).channels(1)>11 || (*iRH).channels(1)<4) continue;
     // if(kStation == 1 && kRing == 1) fill_charge_ME11_with_cuts();
      }

      if(bool_ME11==true){ 
        if((*iRH).hitWire() <= 40 && (*iRH).hitWire() >= 38) {
          if((*iRH).channels(1) <= 25 && (*iRH).channels(1) >= 20){ 
          if(debug_value) cout<<"passed the conditions wire and channel number"<<(*iRH).hitWire()<<"\t"<<(*iRH).channels(1)<<endl;
     //  if(kStation == 1 && kRing == 2) fill_charge_ME21_with_cuts();
         if(kStation == 1 && kRing == 1) fill_charge_ME11_with_cuts();
      }
     }
    }

      // end of rechit loop 
      }
      // end of segment loop
   }
      // end of analyze function loop   
}

void
MuonExercise0::fill_charge_ME11(){
      n_entries_ME11++;        
     rHSumQ_ME11->Fill(rHSumQ);
      if(kLayer == 1)
      rHSumQ_layer_11[1]->Fill(rHSumQ); 
      if(kLayer == 2)
      rHSumQ_layer_11[2] ->Fill(rHSumQ); 
      if(kLayer == 3)
      rHSumQ_layer_11[3] ->Fill(rHSumQ); 
      if(kLayer == 4)
      rHSumQ_layer_11[4]->Fill(rHSumQ); 
      if(kLayer == 5)
      rHSumQ_layer_11[5]->Fill(rHSumQ); 
      if(kLayer == 6)
      rHSumQ_layer_11[6]->Fill(rHSumQ); 
   
}

void
MuonExercise0::fill_charge_ME21(){
      n_entries_ME21++;
      rHSumQ_ME21->Fill(rHSumQ);
      if(kLayer == 1)
      rHSumQ_layer_21[1]->Fill(rHSumQ); 
      if(kLayer == 2)
      rHSumQ_layer_21[2] ->Fill(rHSumQ); 
      if(kLayer == 3)
      rHSumQ_layer_21[3] ->Fill(rHSumQ); 
      if(kLayer == 4)
      rHSumQ_layer_21[4]->Fill(rHSumQ); 
      if(kLayer == 5)
      rHSumQ_layer_21[5]->Fill(rHSumQ); 
      if(kLayer == 6)
      rHSumQ_layer_21[6]->Fill(rHSumQ); 
    
}

void
MuonExercise0::fill_charge_ME21_with_cuts(){
      n_entries_ME21_with_cuts++;
      rHSumQ_ME21_with_cuts->Fill(rHSumQ);
      if(kLayer == 1)
      rHSumQ_with_cuts_layer_21[1]->Fill(rHSumQ); 
      if(kLayer == 2)
      rHSumQ_with_cuts_layer_21[2] ->Fill(rHSumQ); 
      if(kLayer == 3)
      rHSumQ_with_cuts_layer_21[3] ->Fill(rHSumQ); 
      if(kLayer == 4)
      rHSumQ_with_cuts_layer_21[4]->Fill(rHSumQ); 
      if(kLayer == 5)
      rHSumQ_with_cuts_layer_21[5]->Fill(rHSumQ); 
      if(kLayer == 6)
      rHSumQ_with_cuts_layer_21[6]->Fill(rHSumQ); 
    
}
void
MuonExercise0::fill_charge_ME21_with_position_cuts(){
      n_entries_ME21_with_position_cuts++;
      rHSumQ_ME21_with_position_cuts->Fill(rHSumQ);
      if(kLayer == 1)
      rHSumQ_with_position_cuts_layer_21[1]->Fill(rHSumQ); 
      if(kLayer == 2)
      rHSumQ_with_position_cuts_layer_21[2] ->Fill(rHSumQ); 
      if(kLayer == 3)
      rHSumQ_with_position_cuts_layer_21[3] ->Fill(rHSumQ); 
      if(kLayer == 4)
      rHSumQ_with_position_cuts_layer_21[4]->Fill(rHSumQ); 
      if(kLayer == 5)
      rHSumQ_with_position_cuts_layer_21[5]->Fill(rHSumQ); 
      if(kLayer == 6)
      rHSumQ_with_position_cuts_layer_21[6]->Fill(rHSumQ); 
    
}
void
MuonExercise0::fill_charge_ME11_with_cuts(){
      n_entries_ME11_with_cuts++;
      rHSumQ_ME11_with_cuts->Fill(rHSumQ);
      if(kLayer == 1)
      rHSumQ_with_cuts_layer_11[1]->Fill(rHSumQ); 
      if(kLayer == 2)
      rHSumQ_with_cuts_layer_11[2] ->Fill(rHSumQ); 
      if(kLayer == 3)
      rHSumQ_with_cuts_layer_11[3] ->Fill(rHSumQ); 
      if(kLayer == 4)
      rHSumQ_with_cuts_layer_11[4]->Fill(rHSumQ); 
      if(kLayer == 5)
      rHSumQ_with_cuts_layer_11[5]->Fill(rHSumQ); 
      if(kLayer == 6)
      rHSumQ_with_cuts_layer_11[6]->Fill(rHSumQ); 
    
}

void 
MuonExercise0::fill_charge_CFEB_ME21(){
    n_entries_CFEB++;
    if(1<= centerStrip && centerStrip <=16)
    {
     if(debug_value) cout<<"ME21 CFEB1"<<endl;
     rHSumQ_strip1_ME21 ->Fill(rHSumQ);
    }
    if(17<= centerStrip && centerStrip <=32)
    {
      if(debug_value)cout<<"ME21 CFEB2"<<endl;
     rHSumQ_strip2_ME21 ->Fill(rHSumQ);
    }
    if(33<= centerStrip && centerStrip <=48)
    {
     if(debug_value) cout<<"ME21 CFEB3"<<endl;
     rHSumQ_strip3_ME21 ->Fill(rHSumQ);
    }
    if(49<= centerStrip && centerStrip <=64)
    {
     if(debug_value) cout<<"ME21 CFEB4"<<endl;
     rHSumQ_strip4_ME21 ->Fill(rHSumQ);
    }
    if(centerStrip==0 || centerStrip >64){
      cout<<" ME21"<<centerStrip<<endl;
    }
  }

void 
MuonExercise0::fill_charge_CFEB_ME11(){
    if(1<= centerStrip && centerStrip <=16)
    {
     if(debug_value) cout<<"ME11 CFEB1 "<<endl;
     rHSumQ_strip1_ME11 ->Fill(rHSumQ);
    }
    if(17<= centerStrip && centerStrip <=32)
    {
      if(debug_value)cout<<"ME11 CFEB2"<<endl;
     rHSumQ_strip2_ME11->Fill(rHSumQ);
    }
    if(33<= centerStrip && centerStrip <=48)
    {
     if(debug_value) cout<<"ME11 CFEB3"<<endl;
     rHSumQ_strip3_ME11 ->Fill(rHSumQ);
    }
  }



// ------------ method called once each job just before starting event loop  ------------
void
MuonExercise0::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void
MuonExercise0::endJob()
{
  if(debug_entries)
  {
    cout<<"number of entries "<<n_entries_total<<"\t"<<"ME11 "<<n_entries_ME11<<"\t"<<"ME21 "<<n_entries_ME21<<"CFEB "<<n_entries_CFEB<<endl;
    cout<<"number of entries in ME11 after cuts"<<n_entries_ME11_with_cuts<<endl;
    cout<<"number of entries in ME21 after cuts"<<n_entries_ME21_with_cuts<<endl;
    cout<<"number of entries in ME21 after position cuts"<<n_entries_ME21_with_position_cuts<<endl;
    cout<<"not common "<<n_entries_not<<endl;
  }

}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
MuonExercise0::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);

  //Specify that only 'tracks' is allowed
  //To use, remove the default given above and uncomment below
  //ParameterSetDescription desc;
  //desc.addUntracked<edm::InputTag>("tracks","ctfWithMaterialTracks");
  //descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(MuonExercise0);

// Ways with which we can select rechit directly without selecting segment 
// there is a container CSCRecHit2DCollection to do so
/*edm::Handle<CSCRecHit2DCollection> recHits;
iEvent.getByToken(cscRecHitsToken, recHits);

CSCRecHit2DCollection::const_iterator dRHIter;
for (dRHIter = recHits->begin(); dRHIter != recHits->end(); dRHIter++) {

  cs_hit->Fill((*dRHIter).channels(1),(*dRHIter).nStrips()); // Histogram I was showing in my report

  if((*dRHIter).nStrips()==3){ .....  // Check if RecHit has 3 strips.
    // Work with good hits
    // };
    // }; // End of Loop on all RecHits in collection. */
