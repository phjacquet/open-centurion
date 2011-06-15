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
FC=gfortran.exe
AS=as.exe

# Macros
CND_PLATFORM=MinGW-Windows
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion.o \
	${OBJECTDIR}/Sources/Solution/ScatteringSource.o \
	${OBJECTDIR}/Sources/Mesh/EnergyGroup.o \
	${OBJECTDIR}/Sources/Solver/PijSolver.o \
	${OBJECTDIR}/Sources/Mesh/Mesh.o \
	${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o \
	${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection.o \
	${OBJECTDIR}/Sources/Mesh/Region.o \
	${OBJECTDIR}/Sources/Sections/FissionDistribution.o \
	${OBJECTDIR}/Sources/Material/Geometry.o \
	${OBJECTDIR}/Sources/Solution/ScalarSource.o \
	${OBJECTDIR}/Sources/Exceptions/InputConsistency.o \
	${OBJECTDIR}/Sources/main.o \
	${OBJECTDIR}/Sources/Solution/ScalarSolution.o \
	${OBJECTDIR}/Sources/Sections/FissionCrossSection.o \
	${OBJECTDIR}/Sources/Sections/ProblemCrossSections.o \
	${OBJECTDIR}/Sources/Mesh/EnergyMesh.o \
	${OBJECTDIR}/Sources/Sections/CrossSection.o \
	${OBJECTDIR}/Sources/Solution/FissionSource.o \
	${OBJECTDIR}/Sources/Solution/ReactionRate.o \
	${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o \
	${OBJECTDIR}/Sources/Solution/Flux.o \
	${OBJECTDIR}/Sources/Material/Library.o


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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/centurion_v0.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/centurion_v0.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/centurion_v0 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion.o: Sources/Mesh/CartesianOneDimRegion.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion.o Sources/Mesh/CartesianOneDimRegion.cpp

${OBJECTDIR}/Sources/Solution/ScatteringSource.o: Sources/Solution/ScatteringSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScatteringSource.o Sources/Solution/ScatteringSource.cpp

${OBJECTDIR}/Sources/Mesh/EnergyGroup.o: Sources/Mesh/EnergyGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/EnergyGroup.o Sources/Mesh/EnergyGroup.cpp

${OBJECTDIR}/Sources/Solver/PijSolver.o: Sources/Solver/PijSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solver
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solver/PijSolver.o Sources/Solver/PijSolver.cpp

${OBJECTDIR}/Sources/Mesh/Mesh.o: Sources/Mesh/Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/Mesh.o Sources/Mesh/Mesh.cpp

${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o: Sources/Mesh/CartesianOneDimMesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o Sources/Mesh/CartesianOneDimMesh.cpp

${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection.o: Sources/Sections/DefaultTotalCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection.o Sources/Sections/DefaultTotalCrossSection.cpp

${OBJECTDIR}/Sources/Mesh/Region.o: Sources/Mesh/Region.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/Region.o Sources/Mesh/Region.cpp

${OBJECTDIR}/Sources/Sections/FissionDistribution.o: Sources/Sections/FissionDistribution.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/FissionDistribution.o Sources/Sections/FissionDistribution.cpp

${OBJECTDIR}/Sources/Material/Geometry.o: Sources/Material/Geometry.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Material
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Material/Geometry.o Sources/Material/Geometry.cpp

${OBJECTDIR}/Sources/Solution/ScalarSource.o: Sources/Solution/ScalarSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScalarSource.o Sources/Solution/ScalarSource.cpp

${OBJECTDIR}/Sources/Exceptions/InputConsistency.o: Sources/Exceptions/InputConsistency.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Exceptions
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Exceptions/InputConsistency.o Sources/Exceptions/InputConsistency.cpp

${OBJECTDIR}/Sources/main.o: Sources/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/main.o Sources/main.cpp

${OBJECTDIR}/Sources/Solution/ScalarSolution.o: Sources/Solution/ScalarSolution.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScalarSolution.o Sources/Solution/ScalarSolution.cpp

${OBJECTDIR}/Sources/Sections/FissionCrossSection.o: Sources/Sections/FissionCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/FissionCrossSection.o Sources/Sections/FissionCrossSection.cpp

${OBJECTDIR}/Sources/Sections/ProblemCrossSections.o: Sources/Sections/ProblemCrossSections.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/ProblemCrossSections.o Sources/Sections/ProblemCrossSections.cpp

${OBJECTDIR}/Sources/Mesh/EnergyMesh.o: Sources/Mesh/EnergyMesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/EnergyMesh.o Sources/Mesh/EnergyMesh.cpp

${OBJECTDIR}/Sources/Sections/CrossSection.o: Sources/Sections/CrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/CrossSection.o Sources/Sections/CrossSection.cpp

${OBJECTDIR}/Sources/Solution/FissionSource.o: Sources/Solution/FissionSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/FissionSource.o Sources/Solution/FissionSource.cpp

${OBJECTDIR}/Sources/Solution/ReactionRate.o: Sources/Solution/ReactionRate.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ReactionRate.o Sources/Solution/ReactionRate.cpp

${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o: Sources/Sections/DefaultScatteringCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o Sources/Sections/DefaultScatteringCrossSection.cpp

${OBJECTDIR}/Sources/Solution/Flux.o: Sources/Solution/Flux.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/Flux.o Sources/Solution/Flux.cpp

${OBJECTDIR}/Sources/Material/Library.o: Sources/Material/Library.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Material
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Material/Library.o Sources/Material/Library.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/centurion_v0.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
