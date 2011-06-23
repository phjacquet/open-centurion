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
	${OBJECTDIR}/Sources/Field/FieldIterator.o \
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
	${OBJECTDIR}/Sources/Field/DoubleMeshField.o \
	${OBJECTDIR}/Sources/Material/Library.o \
	${OBJECTDIR}/Sources/Solution/Flux.o

# Test Directory
TESTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tests

# Test Files
TESTFILES= \
	${TESTDIR}/TestFiles/f1

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
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${TESTDIR}/TestFiles/f1.exe

${TESTDIR}/TestFiles/f1.exe: ${OBJECTFILES}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc} -o ${TESTDIR}/TestFiles/f1 ${OBJECTFILES} ${LDLIBSOPTIONS} 

${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion.o: Sources/Mesh/CartesianOneDimRegion.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion.o Sources/Mesh/CartesianOneDimRegion.cpp

${OBJECTDIR}/Sources/Solution/ScatteringSource.o: Sources/Solution/ScatteringSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScatteringSource.o Sources/Solution/ScatteringSource.cpp

${OBJECTDIR}/Sources/Mesh/EnergyGroup.o: Sources/Mesh/EnergyGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/EnergyGroup.o Sources/Mesh/EnergyGroup.cpp

${OBJECTDIR}/Sources/Solver/PijSolver.o: Sources/Solver/PijSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solver
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solver/PijSolver.o Sources/Solver/PijSolver.cpp

${OBJECTDIR}/Sources/Mesh/Mesh.o: Sources/Mesh/Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/Mesh.o Sources/Mesh/Mesh.cpp

${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o: Sources/Mesh/CartesianOneDimMesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o Sources/Mesh/CartesianOneDimMesh.cpp

${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection.o: Sources/Sections/DefaultTotalCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection.o Sources/Sections/DefaultTotalCrossSection.cpp

${OBJECTDIR}/Sources/Mesh/Region.o: Sources/Mesh/Region.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/Region.o Sources/Mesh/Region.cpp

${OBJECTDIR}/Sources/Sections/FissionDistribution.o: Sources/Sections/FissionDistribution.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/FissionDistribution.o Sources/Sections/FissionDistribution.cpp

${OBJECTDIR}/Sources/Field/FieldIterator.o: Sources/Field/FieldIterator.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Field
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Field/FieldIterator.o Sources/Field/FieldIterator.cpp

${OBJECTDIR}/Sources/Material/Geometry.o: Sources/Material/Geometry.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Material
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Material/Geometry.o Sources/Material/Geometry.cpp

${OBJECTDIR}/Sources/Solution/ScalarSource.o: Sources/Solution/ScalarSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScalarSource.o Sources/Solution/ScalarSource.cpp

${OBJECTDIR}/Sources/Exceptions/InputConsistency.o: Sources/Exceptions/InputConsistency.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Exceptions
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Exceptions/InputConsistency.o Sources/Exceptions/InputConsistency.cpp

${OBJECTDIR}/Sources/main.o: Sources/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/main.o Sources/main.cpp

${OBJECTDIR}/Sources/Solution/ScalarSolution.o: Sources/Solution/ScalarSolution.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScalarSolution.o Sources/Solution/ScalarSolution.cpp

${OBJECTDIR}/Sources/Sections/FissionCrossSection.o: Sources/Sections/FissionCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/FissionCrossSection.o Sources/Sections/FissionCrossSection.cpp

${OBJECTDIR}/Sources/Sections/ProblemCrossSections.o: Sources/Sections/ProblemCrossSections.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/ProblemCrossSections.o Sources/Sections/ProblemCrossSections.cpp

${OBJECTDIR}/Sources/Mesh/EnergyMesh.o: Sources/Mesh/EnergyMesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/EnergyMesh.o Sources/Mesh/EnergyMesh.cpp

${OBJECTDIR}/Sources/Sections/CrossSection.o: Sources/Sections/CrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/CrossSection.o Sources/Sections/CrossSection.cpp

${OBJECTDIR}/Sources/Solution/FissionSource.o: Sources/Solution/FissionSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/FissionSource.o Sources/Solution/FissionSource.cpp

${OBJECTDIR}/Sources/Solution/ReactionRate.o: Sources/Solution/ReactionRate.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ReactionRate.o Sources/Solution/ReactionRate.cpp

${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o: Sources/Sections/DefaultScatteringCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o Sources/Sections/DefaultScatteringCrossSection.cpp

${OBJECTDIR}/Sources/Field/DoubleMeshField.o: Sources/Field/DoubleMeshField.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Field
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Field/DoubleMeshField.o Sources/Field/DoubleMeshField.cpp

${OBJECTDIR}/Sources/Material/Library.o: Sources/Material/Library.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Material
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Material/Library.o Sources/Material/Library.cpp

${OBJECTDIR}/Sources/Solution/Flux.o: Sources/Solution/Flux.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	${RM} $@.d
	$(COMPILE.cc) -O2 -ISources -I. -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/Flux.o Sources/Solution/Flux.cpp

# Subprojects
.build-subprojects:

# Build Test Targets
.build-tests-conf: .build-conf ${TESTFILES}
${TESTDIR}/TestFiles/f1: ${TESTDIR}/Tests/DoubleMeshFieldSimpleTest.o ${OBJECTFILES:%.o=%_nomain.o}
	${MKDIR} -p ${TESTDIR}/TestFiles
	${LINK.cc}   -o ${TESTDIR}/TestFiles/f1 $^ ${LDLIBSOPTIONS} 


${TESTDIR}/Tests/DoubleMeshFieldSimpleTest.o: Tests/DoubleMeshFieldSimpleTest.cpp 
	${MKDIR} -p ${TESTDIR}/Tests
	${RM} $@.d
	$(COMPILE.cc) -O2 -I. -I. -ISources -I. -MMD -MP -MF $@.d -o ${TESTDIR}/Tests/DoubleMeshFieldSimpleTest.o Tests/DoubleMeshFieldSimpleTest.cpp


${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion_nomain.o: ${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion.o Sources/Mesh/CartesianOneDimRegion.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion_nomain.o Sources/Mesh/CartesianOneDimRegion.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion.o ${OBJECTDIR}/Sources/Mesh/CartesianOneDimRegion_nomain.o;\
	fi

${OBJECTDIR}/Sources/Solution/ScatteringSource_nomain.o: ${OBJECTDIR}/Sources/Solution/ScatteringSource.o Sources/Solution/ScatteringSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Solution/ScatteringSource.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScatteringSource_nomain.o Sources/Solution/ScatteringSource.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Solution/ScatteringSource.o ${OBJECTDIR}/Sources/Solution/ScatteringSource_nomain.o;\
	fi

${OBJECTDIR}/Sources/Mesh/EnergyGroup_nomain.o: ${OBJECTDIR}/Sources/Mesh/EnergyGroup.o Sources/Mesh/EnergyGroup.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Mesh/EnergyGroup.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/EnergyGroup_nomain.o Sources/Mesh/EnergyGroup.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Mesh/EnergyGroup.o ${OBJECTDIR}/Sources/Mesh/EnergyGroup_nomain.o;\
	fi

${OBJECTDIR}/Sources/Solver/PijSolver_nomain.o: ${OBJECTDIR}/Sources/Solver/PijSolver.o Sources/Solver/PijSolver.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solver
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Solver/PijSolver.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solver/PijSolver_nomain.o Sources/Solver/PijSolver.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Solver/PijSolver.o ${OBJECTDIR}/Sources/Solver/PijSolver_nomain.o;\
	fi

${OBJECTDIR}/Sources/Mesh/Mesh_nomain.o: ${OBJECTDIR}/Sources/Mesh/Mesh.o Sources/Mesh/Mesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Mesh/Mesh.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/Mesh_nomain.o Sources/Mesh/Mesh.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Mesh/Mesh.o ${OBJECTDIR}/Sources/Mesh/Mesh_nomain.o;\
	fi

${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh_nomain.o: ${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o Sources/Mesh/CartesianOneDimMesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh_nomain.o Sources/Mesh/CartesianOneDimMesh.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh.o ${OBJECTDIR}/Sources/Mesh/CartesianOneDimMesh_nomain.o;\
	fi

${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection_nomain.o: ${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection.o Sources/Sections/DefaultTotalCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection_nomain.o Sources/Sections/DefaultTotalCrossSection.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection.o ${OBJECTDIR}/Sources/Sections/DefaultTotalCrossSection_nomain.o;\
	fi

${OBJECTDIR}/Sources/Mesh/Region_nomain.o: ${OBJECTDIR}/Sources/Mesh/Region.o Sources/Mesh/Region.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Mesh/Region.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/Region_nomain.o Sources/Mesh/Region.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Mesh/Region.o ${OBJECTDIR}/Sources/Mesh/Region_nomain.o;\
	fi

${OBJECTDIR}/Sources/Sections/FissionDistribution_nomain.o: ${OBJECTDIR}/Sources/Sections/FissionDistribution.o Sources/Sections/FissionDistribution.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Sections/FissionDistribution.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/FissionDistribution_nomain.o Sources/Sections/FissionDistribution.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Sections/FissionDistribution.o ${OBJECTDIR}/Sources/Sections/FissionDistribution_nomain.o;\
	fi

${OBJECTDIR}/Sources/Field/FieldIterator_nomain.o: ${OBJECTDIR}/Sources/Field/FieldIterator.o Sources/Field/FieldIterator.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Field
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Field/FieldIterator.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Field/FieldIterator_nomain.o Sources/Field/FieldIterator.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Field/FieldIterator.o ${OBJECTDIR}/Sources/Field/FieldIterator_nomain.o;\
	fi

${OBJECTDIR}/Sources/Material/Geometry_nomain.o: ${OBJECTDIR}/Sources/Material/Geometry.o Sources/Material/Geometry.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Material
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Material/Geometry.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Material/Geometry_nomain.o Sources/Material/Geometry.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Material/Geometry.o ${OBJECTDIR}/Sources/Material/Geometry_nomain.o;\
	fi

${OBJECTDIR}/Sources/Solution/ScalarSource_nomain.o: ${OBJECTDIR}/Sources/Solution/ScalarSource.o Sources/Solution/ScalarSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Solution/ScalarSource.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScalarSource_nomain.o Sources/Solution/ScalarSource.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Solution/ScalarSource.o ${OBJECTDIR}/Sources/Solution/ScalarSource_nomain.o;\
	fi

${OBJECTDIR}/Sources/Exceptions/InputConsistency_nomain.o: ${OBJECTDIR}/Sources/Exceptions/InputConsistency.o Sources/Exceptions/InputConsistency.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Exceptions
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Exceptions/InputConsistency.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Exceptions/InputConsistency_nomain.o Sources/Exceptions/InputConsistency.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Exceptions/InputConsistency.o ${OBJECTDIR}/Sources/Exceptions/InputConsistency_nomain.o;\
	fi

${OBJECTDIR}/Sources/main_nomain.o: ${OBJECTDIR}/Sources/main.o Sources/main.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/main.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/main_nomain.o Sources/main.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/main.o ${OBJECTDIR}/Sources/main_nomain.o;\
	fi

${OBJECTDIR}/Sources/Solution/ScalarSolution_nomain.o: ${OBJECTDIR}/Sources/Solution/ScalarSolution.o Sources/Solution/ScalarSolution.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Solution/ScalarSolution.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ScalarSolution_nomain.o Sources/Solution/ScalarSolution.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Solution/ScalarSolution.o ${OBJECTDIR}/Sources/Solution/ScalarSolution_nomain.o;\
	fi

${OBJECTDIR}/Sources/Sections/FissionCrossSection_nomain.o: ${OBJECTDIR}/Sources/Sections/FissionCrossSection.o Sources/Sections/FissionCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Sections/FissionCrossSection.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/FissionCrossSection_nomain.o Sources/Sections/FissionCrossSection.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Sections/FissionCrossSection.o ${OBJECTDIR}/Sources/Sections/FissionCrossSection_nomain.o;\
	fi

${OBJECTDIR}/Sources/Sections/ProblemCrossSections_nomain.o: ${OBJECTDIR}/Sources/Sections/ProblemCrossSections.o Sources/Sections/ProblemCrossSections.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Sections/ProblemCrossSections.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/ProblemCrossSections_nomain.o Sources/Sections/ProblemCrossSections.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Sections/ProblemCrossSections.o ${OBJECTDIR}/Sources/Sections/ProblemCrossSections_nomain.o;\
	fi

${OBJECTDIR}/Sources/Mesh/EnergyMesh_nomain.o: ${OBJECTDIR}/Sources/Mesh/EnergyMesh.o Sources/Mesh/EnergyMesh.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Mesh
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Mesh/EnergyMesh.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Mesh/EnergyMesh_nomain.o Sources/Mesh/EnergyMesh.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Mesh/EnergyMesh.o ${OBJECTDIR}/Sources/Mesh/EnergyMesh_nomain.o;\
	fi

${OBJECTDIR}/Sources/Sections/CrossSection_nomain.o: ${OBJECTDIR}/Sources/Sections/CrossSection.o Sources/Sections/CrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Sections/CrossSection.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/CrossSection_nomain.o Sources/Sections/CrossSection.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Sections/CrossSection.o ${OBJECTDIR}/Sources/Sections/CrossSection_nomain.o;\
	fi

${OBJECTDIR}/Sources/Solution/FissionSource_nomain.o: ${OBJECTDIR}/Sources/Solution/FissionSource.o Sources/Solution/FissionSource.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Solution/FissionSource.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/FissionSource_nomain.o Sources/Solution/FissionSource.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Solution/FissionSource.o ${OBJECTDIR}/Sources/Solution/FissionSource_nomain.o;\
	fi

${OBJECTDIR}/Sources/Solution/ReactionRate_nomain.o: ${OBJECTDIR}/Sources/Solution/ReactionRate.o Sources/Solution/ReactionRate.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Solution/ReactionRate.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/ReactionRate_nomain.o Sources/Solution/ReactionRate.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Solution/ReactionRate.o ${OBJECTDIR}/Sources/Solution/ReactionRate_nomain.o;\
	fi

${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection_nomain.o: ${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o Sources/Sections/DefaultScatteringCrossSection.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Sections
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection_nomain.o Sources/Sections/DefaultScatteringCrossSection.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection.o ${OBJECTDIR}/Sources/Sections/DefaultScatteringCrossSection_nomain.o;\
	fi

${OBJECTDIR}/Sources/Field/DoubleMeshField_nomain.o: ${OBJECTDIR}/Sources/Field/DoubleMeshField.o Sources/Field/DoubleMeshField.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Field
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Field/DoubleMeshField.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Field/DoubleMeshField_nomain.o Sources/Field/DoubleMeshField.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Field/DoubleMeshField.o ${OBJECTDIR}/Sources/Field/DoubleMeshField_nomain.o;\
	fi

${OBJECTDIR}/Sources/Material/Library_nomain.o: ${OBJECTDIR}/Sources/Material/Library.o Sources/Material/Library.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Material
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Material/Library.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Material/Library_nomain.o Sources/Material/Library.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Material/Library.o ${OBJECTDIR}/Sources/Material/Library_nomain.o;\
	fi

${OBJECTDIR}/Sources/Solution/Flux_nomain.o: ${OBJECTDIR}/Sources/Solution/Flux.o Sources/Solution/Flux.cpp 
	${MKDIR} -p ${OBJECTDIR}/Sources/Solution
	@NMOUTPUT=`${NM} ${OBJECTDIR}/Sources/Solution/Flux.o`; \
	if (echo "$$NMOUTPUT" | ${GREP} '|main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T main$$') || \
	   (echo "$$NMOUTPUT" | ${GREP} 'T _main$$'); \
	then  \
	    ${RM} $@.d;\
	    $(COMPILE.cc) -O2 -ISources -I. -Dmain=__nomain -MMD -MP -MF $@.d -o ${OBJECTDIR}/Sources/Solution/Flux_nomain.o Sources/Solution/Flux.cpp;\
	else  \
	    ${CP} ${OBJECTDIR}/Sources/Solution/Flux.o ${OBJECTDIR}/Sources/Solution/Flux_nomain.o;\
	fi

# Run Test Targets
.test-conf:
	@if [ "${TEST}" = "" ]; \
	then  \
	    ${TESTDIR}/TestFiles/f1 || true; \
	else  \
	    ./${TEST} || true; \
	fi

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${TESTDIR}/TestFiles/f1.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
