#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/onyx_uChip_048.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=${DISTDIR}/onyx_uChip_048.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=-mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=code/src/timers/tmr1.c code/src/uart/uart1.c code/src/usb/usb_events.c code/src/usb/usb_descriptors.c code/src/usb/usb_device.c system.c app_device_audio_midi.c main.c byteToSound.c chanels.c samplerMode.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/code/src/timers/tmr1.o ${OBJECTDIR}/code/src/uart/uart1.o ${OBJECTDIR}/code/src/usb/usb_events.o ${OBJECTDIR}/code/src/usb/usb_descriptors.o ${OBJECTDIR}/code/src/usb/usb_device.o ${OBJECTDIR}/system.o ${OBJECTDIR}/app_device_audio_midi.o ${OBJECTDIR}/main.o ${OBJECTDIR}/byteToSound.o ${OBJECTDIR}/chanels.o ${OBJECTDIR}/samplerMode.o
POSSIBLE_DEPFILES=${OBJECTDIR}/code/src/timers/tmr1.o.d ${OBJECTDIR}/code/src/uart/uart1.o.d ${OBJECTDIR}/code/src/usb/usb_events.o.d ${OBJECTDIR}/code/src/usb/usb_descriptors.o.d ${OBJECTDIR}/code/src/usb/usb_device.o.d ${OBJECTDIR}/system.o.d ${OBJECTDIR}/app_device_audio_midi.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/byteToSound.o.d ${OBJECTDIR}/chanels.o.d ${OBJECTDIR}/samplerMode.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/code/src/timers/tmr1.o ${OBJECTDIR}/code/src/uart/uart1.o ${OBJECTDIR}/code/src/usb/usb_events.o ${OBJECTDIR}/code/src/usb/usb_descriptors.o ${OBJECTDIR}/code/src/usb/usb_device.o ${OBJECTDIR}/system.o ${OBJECTDIR}/app_device_audio_midi.o ${OBJECTDIR}/main.o ${OBJECTDIR}/byteToSound.o ${OBJECTDIR}/chanels.o ${OBJECTDIR}/samplerMode.o

# Source Files
SOURCEFILES=code/src/timers/tmr1.c code/src/uart/uart1.c code/src/usb/usb_events.c code/src/usb/usb_descriptors.c code/src/usb/usb_device.c system.c app_device_audio_midi.c main.c byteToSound.c chanels.c samplerMode.c



CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk ${DISTDIR}/onyx_uChip_048.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=32MM0256GPM048
MP_LINKER_FILE_OPTION=
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assembleWithPreprocess
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/code/src/timers/tmr1.o: code/src/timers/tmr1.c  .generated_files/flags/default/a0d15db0e2aa767617909e14038c0786c8ce8642 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/code/src/timers" 
	@${RM} ${OBJECTDIR}/code/src/timers/tmr1.o.d 
	@${RM} ${OBJECTDIR}/code/src/timers/tmr1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/code/src/timers/tmr1.o.d" -o ${OBJECTDIR}/code/src/timers/tmr1.o code/src/timers/tmr1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/code/src/uart/uart1.o: code/src/uart/uart1.c  .generated_files/flags/default/2ee0329ad99256f59d30c195e0410de9a3e0e8b9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/code/src/uart" 
	@${RM} ${OBJECTDIR}/code/src/uart/uart1.o.d 
	@${RM} ${OBJECTDIR}/code/src/uart/uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/code/src/uart/uart1.o.d" -o ${OBJECTDIR}/code/src/uart/uart1.o code/src/uart/uart1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/code/src/usb/usb_events.o: code/src/usb/usb_events.c  .generated_files/flags/default/8dd836f4c060fa5fad347d163ea1a72586a670b2 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/code/src/usb" 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_events.o.d 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_events.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/code/src/usb/usb_events.o.d" -o ${OBJECTDIR}/code/src/usb/usb_events.o code/src/usb/usb_events.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/code/src/usb/usb_descriptors.o: code/src/usb/usb_descriptors.c  .generated_files/flags/default/93c7c4544ac02eabf08b11d76d374d30ea08762a .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/code/src/usb" 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/code/src/usb/usb_descriptors.o.d" -o ${OBJECTDIR}/code/src/usb/usb_descriptors.o code/src/usb/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/code/src/usb/usb_device.o: code/src/usb/usb_device.c  .generated_files/flags/default/17e6f94ef0192010686ee324ed091ac33522e538 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/code/src/usb" 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/code/src/usb/usb_device.o.d" -o ${OBJECTDIR}/code/src/usb/usb_device.o code/src/usb/usb_device.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/default/13523b5f48e500ff76d979e980f63efd859e2435 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/app_device_audio_midi.o: app_device_audio_midi.c  .generated_files/flags/default/b8ca759903f2bc066b51bbb0d9c9c34a5cad131 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_device_audio_midi.o.d 
	@${RM} ${OBJECTDIR}/app_device_audio_midi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/app_device_audio_midi.o.d" -o ${OBJECTDIR}/app_device_audio_midi.o app_device_audio_midi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/f2f23aa796bcfd0c562af6df9e1e4bc929deeac9 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/byteToSound.o: byteToSound.c  .generated_files/flags/default/7c490094f51a3f8686ce8bb9931442880f6f028b .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/byteToSound.o.d 
	@${RM} ${OBJECTDIR}/byteToSound.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/byteToSound.o.d" -o ${OBJECTDIR}/byteToSound.o byteToSound.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/chanels.o: chanels.c  .generated_files/flags/default/2493b86d17e3f9f881152abbbcde91b95cfbafc .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/chanels.o.d 
	@${RM} ${OBJECTDIR}/chanels.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/chanels.o.d" -o ${OBJECTDIR}/chanels.o chanels.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/samplerMode.o: samplerMode.c  .generated_files/flags/default/79d0edf4bee60016ff4bc8ddcd9e275de2f50274 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/samplerMode.o.d 
	@${RM} ${OBJECTDIR}/samplerMode.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE) -g -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1  -fframe-base-loclist  -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/samplerMode.o.d" -o ${OBJECTDIR}/samplerMode.o samplerMode.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
else
${OBJECTDIR}/code/src/timers/tmr1.o: code/src/timers/tmr1.c  .generated_files/flags/default/44a2aa3d26ac39263dfb907c53c4be5fb3ab6e56 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/code/src/timers" 
	@${RM} ${OBJECTDIR}/code/src/timers/tmr1.o.d 
	@${RM} ${OBJECTDIR}/code/src/timers/tmr1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/code/src/timers/tmr1.o.d" -o ${OBJECTDIR}/code/src/timers/tmr1.o code/src/timers/tmr1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/code/src/uart/uart1.o: code/src/uart/uart1.c  .generated_files/flags/default/7ca334daeafea18b7645235affea6093dfd4a0b3 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/code/src/uart" 
	@${RM} ${OBJECTDIR}/code/src/uart/uart1.o.d 
	@${RM} ${OBJECTDIR}/code/src/uart/uart1.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/code/src/uart/uart1.o.d" -o ${OBJECTDIR}/code/src/uart/uart1.o code/src/uart/uart1.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/code/src/usb/usb_events.o: code/src/usb/usb_events.c  .generated_files/flags/default/47dab5add5df757246fcd7039f079b0ae7ca7946 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/code/src/usb" 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_events.o.d 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_events.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/code/src/usb/usb_events.o.d" -o ${OBJECTDIR}/code/src/usb/usb_events.o code/src/usb/usb_events.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/code/src/usb/usb_descriptors.o: code/src/usb/usb_descriptors.c  .generated_files/flags/default/a8179ef37d49c060e4a02fca7aed8b10f036a4fb .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/code/src/usb" 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_descriptors.o.d 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_descriptors.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/code/src/usb/usb_descriptors.o.d" -o ${OBJECTDIR}/code/src/usb/usb_descriptors.o code/src/usb/usb_descriptors.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/code/src/usb/usb_device.o: code/src/usb/usb_device.c  .generated_files/flags/default/2c1de0686d6ce0929a8ab4c835a7083f795a8a41 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}/code/src/usb" 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_device.o.d 
	@${RM} ${OBJECTDIR}/code/src/usb/usb_device.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/code/src/usb/usb_device.o.d" -o ${OBJECTDIR}/code/src/usb/usb_device.o code/src/usb/usb_device.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/system.o: system.c  .generated_files/flags/default/f276dec458262469e0823b12a2eb266caf621441 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/system.o.d 
	@${RM} ${OBJECTDIR}/system.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/system.o.d" -o ${OBJECTDIR}/system.o system.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/app_device_audio_midi.o: app_device_audio_midi.c  .generated_files/flags/default/fe63d297de205abe37aa770f02e3976b5331cb76 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/app_device_audio_midi.o.d 
	@${RM} ${OBJECTDIR}/app_device_audio_midi.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/app_device_audio_midi.o.d" -o ${OBJECTDIR}/app_device_audio_midi.o app_device_audio_midi.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/main.o: main.c  .generated_files/flags/default/4943e6f31fe2fcb535dc94c37fba1e5fa3c2819d .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/main.o.d" -o ${OBJECTDIR}/main.o main.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/byteToSound.o: byteToSound.c  .generated_files/flags/default/54e03b85a3f6b23e34a0ce1a9baa3c99d077277e .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/byteToSound.o.d 
	@${RM} ${OBJECTDIR}/byteToSound.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/byteToSound.o.d" -o ${OBJECTDIR}/byteToSound.o byteToSound.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/chanels.o: chanels.c  .generated_files/flags/default/11cf2f7ad73f0bf00e1b90100ea66aa5dc3afb45 .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/chanels.o.d 
	@${RM} ${OBJECTDIR}/chanels.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/chanels.o.d" -o ${OBJECTDIR}/chanels.o chanels.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
${OBJECTDIR}/samplerMode.o: samplerMode.c  .generated_files/flags/default/28d5c8e8665b7cea6c9782f02f614967296d12ea .generated_files/flags/default/da39a3ee5e6b4b0d3255bfef95601890afd80709
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/samplerMode.o.d 
	@${RM} ${OBJECTDIR}/samplerMode.o 
	${MP_CC}  $(MP_EXTRA_CC_PRE)  -g -x c -c -mprocessor=$(MP_PROCESSOR_OPTION)  -MP -MMD -MF "${OBJECTDIR}/samplerMode.o.d" -o ${OBJECTDIR}/samplerMode.o samplerMode.c    -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)    
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compileCPP
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${DISTDIR}/onyx_uChip_048.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE) -g -mdebugger -D__MPLAB_DEBUGGER_PK3=1 -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/onyx_uChip_048.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)   -mreserve=data@0x0:0x1FC -mreserve=boot@0x1FC00490:0x1FC016FF -mreserve=boot@0x1FC00490:0x1FC00BEF  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--defsym=__MPLAB_DEBUG=1,--defsym=__DEBUG=1,-D=__DEBUG_D,--defsym=__MPLAB_DEBUGGER_PK3=1,--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	
else
${DISTDIR}/onyx_uChip_048.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} ${DISTDIR} 
	${MP_CC} $(MP_EXTRA_LD_PRE)  -mprocessor=$(MP_PROCESSOR_OPTION)  -o ${DISTDIR}/onyx_uChip_048.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} ${OBJECTFILES_QUOTED_IF_SPACED}          -DXPRJ_default=$(CND_CONF)    $(COMPARISON_BUILD)  -Wl,--defsym=__MPLAB_BUILD=1$(MP_EXTRA_LD_POST)$(MP_LINKER_FILE_OPTION),--no-code-in-dinit,--no-dinit-in-serial-mem,-Map="${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map",--memorysummary,${DISTDIR}/memoryfile.xml 
	${MP_CC_DIR}\\xc32-bin2hex ${DISTDIR}/onyx_uChip_048.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX} 
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${OBJECTDIR}
	${RM} -r ${DISTDIR}

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(wildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
