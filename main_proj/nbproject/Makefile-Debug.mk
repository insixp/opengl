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
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/close_function.o \
	${OBJECTDIR}/keyboard_function.o \
	${OBJECTDIR}/load_function.o \
	${OBJECTDIR}/primitives/CAMERA.o \
	${OBJECTDIR}/primitives/CUBE.o \
	${OBJECTDIR}/primitives/OBJECT.o \
	${OBJECTDIR}/render_function.o \
	${OBJECTDIR}/resize_function.o \
	${OBJECTDIR}/shaders/BUFFER_ARRAY.o \
	${OBJECTDIR}/shaders/PROGRAM.o \
	${OBJECTDIR}/shaders/SHADER.o \
	${OBJECTDIR}/utils/utils.o \
	${OBJECTDIR}/win_main.o


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
LDLIBSOPTIONS=-lglew32 -lglew32s -lfreeglut -lfreeglut_static -lopengl32 -lglu32 -lglew32

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/main_proj.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/main_proj.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.cc} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/main_proj ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/close_function.o: close_function.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/close_function.o close_function.cpp

${OBJECTDIR}/keyboard_function.o: keyboard_function.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/keyboard_function.o keyboard_function.cpp

${OBJECTDIR}/load_function.o: load_function.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/load_function.o load_function.cpp

${OBJECTDIR}/primitives/CAMERA.o: primitives/CAMERA.cpp
	${MKDIR} -p ${OBJECTDIR}/primitives
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/primitives/CAMERA.o primitives/CAMERA.cpp

${OBJECTDIR}/primitives/CUBE.o: primitives/CUBE.cpp
	${MKDIR} -p ${OBJECTDIR}/primitives
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/primitives/CUBE.o primitives/CUBE.cpp

${OBJECTDIR}/primitives/OBJECT.o: primitives/OBJECT.cpp
	${MKDIR} -p ${OBJECTDIR}/primitives
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/primitives/OBJECT.o primitives/OBJECT.cpp

${OBJECTDIR}/render_function.o: render_function.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/render_function.o render_function.cpp

${OBJECTDIR}/resize_function.o: resize_function.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/resize_function.o resize_function.cpp

${OBJECTDIR}/shaders/BUFFER_ARRAY.o: shaders/BUFFER_ARRAY.cpp
	${MKDIR} -p ${OBJECTDIR}/shaders
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/shaders/BUFFER_ARRAY.o shaders/BUFFER_ARRAY.cpp

${OBJECTDIR}/shaders/PROGRAM.o: shaders/PROGRAM.cpp
	${MKDIR} -p ${OBJECTDIR}/shaders
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/shaders/PROGRAM.o shaders/PROGRAM.cpp

${OBJECTDIR}/shaders/SHADER.o: shaders/SHADER.cpp
	${MKDIR} -p ${OBJECTDIR}/shaders
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/shaders/SHADER.o shaders/SHADER.cpp

${OBJECTDIR}/utils/utils.o: utils/utils.cpp
	${MKDIR} -p ${OBJECTDIR}/utils
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/utils/utils.o utils/utils.cpp

${OBJECTDIR}/win_main.o: win_main.cpp
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.cc) -g -I../../../../../../../MinGW/include -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/win_main.o win_main.cpp

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
