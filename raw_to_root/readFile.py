# based on CMSSW_12_0_0_pre2/src/IORawData/CSCCommissioning/test/readFile_b904_Run3.py
import FWCore.ParameterSet.Config as cms
from FWCore.ParameterSet.VarParsing import VarParsing
 
 options = VarParsing ('analysis')
  # setup any defaults you want
  options.inputFiles = '/afs/cern.ch/user/n/nrawal/work/CSC_GIF/CMSSW_12_0_0_pre4/src/input_files/'
  options.outputFile= 'output_root_files/csc_raw.root'


  #provide input path by inputFiles
  #provide output file path by outputFile
  # so command to run cmsRun readFile.py inputFiles="path/to/input/file" outputFile="path/to/output/file"

   # get and parse the command line arguments
   options.parseArguments()
   process = cms.Process("reader")

   process.load("FWCore.MessageLogger.MessageLogger_cfi")
   process.MessageLogger.cout.threshold = cms.untracked.string('DEBUG')
   process.MessageLogger.debugModules = cms.untracked.vstring('*')
   process.MessageLogger.cerr.FwkReport.reportEvery = 1000
   process.options = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

   #first run is needed only for running L1Emulator (see p.2 of
   #https://indico.cern.ch/event/1046913/contributions/4398858/attachments/2261412/3838507/CSCDPG_SD_20210609.pdf)
   #options.register ("firstRun", 341761, VarParsing.multiplicity.singleton, VarParsing.varType.int)

   options.maxEvents = 50000


   # Better to know actual number of events in the .raw data file to set maxEvents.
   # Otherwise it doesn't stop automatically at the end of reading of .raw data file
   process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(options.maxEvents) )

   process.source = cms.Source("EmptySource",
              #firstRun= cms.untracked.uint32(options.firstRun),
                     firstRun= cms.untracked.uint32(1),
                            numberEventsInLuminosityBlock = cms.untracked.uint32(200),
                                   numberEventsInRun       = cms.untracked.uint32(0)
                                    )

   # GIF++: FED838 vme1 dmb2 corresponds  to E:1 S:1 R:1 C:1
   process.rawDataCollector = cms.EDProducer('CSCFileReader',
           firstEvent  = cms.untracked.int32(0),
               FED838 = cms.untracked.vstring('RUI01'),
                   FED839 = cms.untracked.vstring('RUI01'),
                       RUI01  = cms.untracked.vstring(options.inputFiles)
                       )

   process.FEVT = cms.OutputModule("PoolOutputModule",
               fileName = cms.untracked.string(options.outputFile),
                       outputCommands = cms.untracked.vstring("keep *")
                       )

   process.p = cms.Path( process.rawDataCollector)

   process.outpath = cms.EndPath(process.FEVT)
