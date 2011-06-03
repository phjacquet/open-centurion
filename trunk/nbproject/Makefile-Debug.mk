#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc.exe
CCC=g++.exe
CXX=g++.exe
FC=
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_CONF=Debug
CND_DISTDIR=dist

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=build/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Sources/Solver/PijSolver.o \
	${OBJECTDIR}/Sources/Solution/ScatteringSource.o \
	${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o \
	${OBJECTDIR}/Sources/Sections/FissionDistribution.o \
	${OBJECTDIR}/Sources/Sections/DefaultCrossSection.o \
	${OBJECTDIR}/Sources/Solution/ScalarSource.o \
	${OBJECTDIR}/Sources/main.o \
	${OBJECTDIR}/Sources/TotalCrossSection/DefaultTotalCrossSection.o \
	${OBJECTDIR}/Sources/Solution/ScalarSolution.o \
	${OBJECTDIR}/Sources/Sections/FissionCrossSection.o \
	${OBJECTDIR}/Sources/Solution/FissionSource.o \
	${OBJECTDIR}/Sources/Solution/ReactionRate.o \
	${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o \
	${OBJECTDIR}/Sources/Solution/Flux.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-Debug.mk dist/Debug/MinGW-Windows/centurion_v0.exe

dist/Debug/MinGW-Windows/centurion_v0.exe: ${OBJECTFILES}
	${MKDIR} -p dist/Debug/MinGW-Windows
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/centurion_v0 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Sources/Solver/PijSolver.o: Sources/Solver/PijSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solver
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solver/PijSolver.o Sources/Solver/PijSolver.cpp

${OBJECTDIR}/Sources/Solution/ScatteringSource.o: Sources/Solution/ScatteringSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScatteringSource.o Sources/Solution/ScatteringSource.cpp

${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o: Sources/Mesh/CartesianOneDimMesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o Sources/Mesh/CartesianOneDimMesh.cpp

${OBJECTDIR}/Sources/Sections/FissionDistribution.o: Sources/Sections/FissionDistribution.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/FissionDistribution.o Sources/Sections/FissionDistribution.cpp

${OBJECTDIR}/Sources/Sections/DefaultCrossSection.o: Sources/Sections/DefaultCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/DefaultCrossSection.o Sources/Sections/DefaultCrossSection.cpp

${OBJECTDIR}/Sources/Solution/ScalarSource.o: Sources/Solution/ScalarSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScalarSource.o Sources/Solution/ScalarSource.cpp

${OBJECTDIR}/Sources/main.o: Sources/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/main.o Sources/main.cpp

${OBJECTDIR}/Sources/TotalCrossSection/DefaultTotalCrossSection.o: Sources/TotalCrossSection/DefaultTotalCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/TotalCrossSection
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/TotalCrossSection/DefaultTotalCrossSection.o Sources/TotalCrossSection/DefaultTotalCrossSection.cpp

${OBJECTDIR}/Sources/Solution/ScalarSolution.o: Sources/Solution/ScalarSolution.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScalarSolution.o Sources/Solution/ScalarSolution.cpp

${OBJECTDIR}/Sources/Sections/FissionCrossSection.o: Sources/Sections/FissionCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/FissionCrossSection.o Sources/Sections/FissionCrossSection.cpp

${OBJECTDIR}/Sources/Solution/FissionSource.o: Sources/Solution/FissionSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/FissionSource.o Sources/Solution/FissionSource.cpp

${OBJECTDIR}/Sources/Solution/ReactionRate.o: Sources/Solution/ReactionRate.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ReactionRate.o Sources/Solution/ReactionRate.cpp

${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o: Sources/Sections/DefaultScatteringCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o Sources/Sections/DefaultScatteringCrossSection.cpp

${OBJECTDIR}/Sources/Solution/Flux.o: Sources/Solution/Flux.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -g -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/Flux.o Sources/Solution/Flux.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/Debug
	${RM} dist/Debug/MinGW-Windows/centurion_v0.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
