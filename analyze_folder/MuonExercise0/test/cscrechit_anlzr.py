import FWCore.ParameterSet.Config as cms
from FWCore.ParameterSet.VarParsing import VarParsing

#provide input path by inputFiles
#provide output file path by outputFile
# so command to run cmsRun readFile.py inputFiles="path/to/input/file" outputFile="path/to/output/file"

options = VarParsing ('analysis')
options.parseArguments()
process = cms.Process("Demo")

process.load("Configuration/Geometry/GeometryIdeal2015Reco_cff")
process.load("Configuration/StandardSequences/MagneticField_cff")
process.load('Configuration.StandardSequences.FrontierConditions_GlobalTag_cff')
process.load("Configuration/StandardSequences/RawToDigi_Data_cff")
process.load("Configuration.StandardSequences.Reconstruction_cff")
process.load("RecoMuon.MuonSeedGenerator.standAloneMuonSeeds_cff")

process.GlobalTag.globaltag = '80X_dataRun2_Prompt_v16'

process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('LogicError','ProductNotFound')
)
process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
      options.inputFiles
  #  'file:../../../testRF838_new_third.root'
    )
)
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
process.source.duplicateCheckMode = cms.untracked.string('noDuplicateCheck')

process.demo = cms.EDAnalyzer('MuonExercise0',
    #sta = cms.int32(2),
    #stripDigiTag = cms.InputTag("muonCSCDigis","MuonCSCStripDigi"),
    #compDigiTag = cms.InputTag("muonCSCDigis","MuonCSCComparatorDigi"),
    #wireDigiTag = cms.InputTag("muonCSCDigis","MuonCSCWireDigi"),
    #alctDigiTag = cms.InputTag("muonCSCDigis","MuonCSCALCTDigi"),
    #clctDigiTag = cms.InputTag("muonCSCDigis","MuonCSCCLCTDigi"),
    #corrlctDigiTag = cms.InputTag("muonCSCDigis","MuonCSCCorrelatedLCTDigi"),
    cscSegments = cms.untracked.InputTag('cscSegments'),
    cscRecHits = cms.untracked.InputTag('csc2DRecHits'),
)

process.TFileService = cms.Service("TFileService", fileName = cms.string(options.outputFile) )

process.p = cms.Path(process.muonCSCDigis  *process.csc2DRecHits * process.cscSegments * process.demo)
