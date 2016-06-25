##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Design_Patterns
ConfigurationName      :=Debug
WorkspacePath          := "/home/sainath-atmel/Documents/C_Patterns/Design_Patterns_states"
ProjectPath            := "/home/sainath-atmel/Documents/C_Patterns/Design_Patterns_states"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Sainath Nambiar
Date                   :=08/06/16
CodeLitePath           :="/home/sainath-atmel/.codelite"
LinkerName             :=/usr/bin/g++
SharedObjectLinkerName :=/usr/bin/g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.i
DebugSwitch            :=-g 
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E
ObjectsFileList        :="Design_Patterns.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := /usr/bin/ar rcu
CXX      := /usr/bin/g++
CC       := /usr/bin/gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := /usr/bin/as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IntermediateDirectory)/State_Pattern_ATM_All_States.c$(ObjectSuffix) $(IntermediateDirectory)/State_Pattern_AtmStateWatch.c$(ObjectSuffix) $(IntermediateDirectory)/State_Pattern_ATM.c$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d ./Debug || $(MakeDirCommand) ./Debug


$(IntermediateDirectory)/.d:
	@test -d ./Debug || $(MakeDirCommand) ./Debug

PreBuild:

# PreCompiled Header
/home/sainath-atmel/Documents/C_Patterns/Design_Patterns_states/State_Pattern_AtmStateWatch.h.gch: /home/sainath-atmel/Documents/C_Patterns/Design_Patterns_states/State_Pattern_AtmStateWatch.h
	$(CXX) $(SourceSwitch) /home/sainath-atmel/Documents/C_Patterns/Design_Patterns_states/State_Pattern_AtmStateWatch.h $(PCHCompileFlags)



##
## Objects
##
$(IntermediateDirectory)/main.c$(ObjectSuffix): main.c $(IntermediateDirectory)/main.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/sainath-atmel/Documents/C_Patterns/Design_Patterns_states/main.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.c$(DependSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.c$(ObjectSuffix) -MF$(IntermediateDirectory)/main.c$(DependSuffix) -MM "main.c"

$(IntermediateDirectory)/main.c$(PreprocessSuffix): main.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.c$(PreprocessSuffix) "main.c"

$(IntermediateDirectory)/State_Pattern_ATM_All_States.c$(ObjectSuffix): State_Pattern_ATM_All_States.c $(IntermediateDirectory)/State_Pattern_ATM_All_States.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/sainath-atmel/Documents/C_Patterns/Design_Patterns_states/State_Pattern_ATM_All_States.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/State_Pattern_ATM_All_States.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/State_Pattern_ATM_All_States.c$(DependSuffix): State_Pattern_ATM_All_States.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/State_Pattern_ATM_All_States.c$(ObjectSuffix) -MF$(IntermediateDirectory)/State_Pattern_ATM_All_States.c$(DependSuffix) -MM "State_Pattern_ATM_All_States.c"

$(IntermediateDirectory)/State_Pattern_ATM_All_States.c$(PreprocessSuffix): State_Pattern_ATM_All_States.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/State_Pattern_ATM_All_States.c$(PreprocessSuffix) "State_Pattern_ATM_All_States.c"

$(IntermediateDirectory)/State_Pattern_AtmStateWatch.c$(ObjectSuffix): State_Pattern_AtmStateWatch.c $(IntermediateDirectory)/State_Pattern_AtmStateWatch.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/sainath-atmel/Documents/C_Patterns/Design_Patterns_states/State_Pattern_AtmStateWatch.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/State_Pattern_AtmStateWatch.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/State_Pattern_AtmStateWatch.c$(DependSuffix): State_Pattern_AtmStateWatch.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/State_Pattern_AtmStateWatch.c$(ObjectSuffix) -MF$(IntermediateDirectory)/State_Pattern_AtmStateWatch.c$(DependSuffix) -MM "State_Pattern_AtmStateWatch.c"

$(IntermediateDirectory)/State_Pattern_AtmStateWatch.c$(PreprocessSuffix): State_Pattern_AtmStateWatch.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/State_Pattern_AtmStateWatch.c$(PreprocessSuffix) "State_Pattern_AtmStateWatch.c"

$(IntermediateDirectory)/State_Pattern_ATM.c$(ObjectSuffix): State_Pattern_ATM.c $(IntermediateDirectory)/State_Pattern_ATM.c$(DependSuffix)
	$(CC) $(SourceSwitch) "/home/sainath-atmel/Documents/C_Patterns/Design_Patterns_states/State_Pattern_ATM.c" $(CFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/State_Pattern_ATM.c$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/State_Pattern_ATM.c$(DependSuffix): State_Pattern_ATM.c
	@$(CC) $(CFLAGS) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/State_Pattern_ATM.c$(ObjectSuffix) -MF$(IntermediateDirectory)/State_Pattern_ATM.c$(DependSuffix) -MM "State_Pattern_ATM.c"

$(IntermediateDirectory)/State_Pattern_ATM.c$(PreprocessSuffix): State_Pattern_ATM.c
	@$(CC) $(CFLAGS) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/State_Pattern_ATM.c$(PreprocessSuffix) "State_Pattern_ATM.c"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r ./Debug/
	$(RM) /home/sainath-atmel/Documents/C_Patterns/Design_Patterns_states/State_Pattern_AtmStateWatch.h.gch


