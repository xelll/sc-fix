## ----------------------------------------------------------- ##
## Don't touch the next line unless you know what you're doing.##
## ----------------------------------------------------------- ##
include ${SOFT_WORKDIR}/env/compilation/compilevars.mk

# Name of the module
LOCAL_NAME := platform/base/sx

# list all modules APIs that are neccessary to compile this module
LOCAL_API_DEPENDS := \
					platform \
					platform/chip/hal \
					platform/chip/defs \
				    platform/chip/pal \
					platform/base/common \
					platform/base/std \
					platform/stack/l1 \
					platform/stack \
                    platform/chip/defs \
					platform/stack/cmn \
					platform/stack/fsm \
					platform/stack/itf \
					platform/stack/cod \
				    platform/phy 

# list all the modules that need to be compiled prior to using this module
LOCAL_MODULE_DEPENDS ?= 

# Generates the CoolProfile headers automatically.
AUTO_XCP2H ?= yes

# Generates the CoolWatcher headers automatically.
AUTO_XMD2H ?= yes

# Generate the revision (version) file automatically during the make process.
AUTO_GEN_REVISION_HEADER := yes

## ------------------------------------ ##
## 	Add your custom flags here          ##
## ------------------------------------ ##
LOCAL_EXPORT_FLAG += __XCPU__ __TARGET__ __SXS_NO_FLASH_HANDLER__

# A mechanism to disable the trace compression.
ifndef SXS_NO_STR_TO_ID
LOCAL_EXPORT_FLAG += __SXS_STR_TO_ID__
endif

ifeq "${CT_RELEASE}" "cool_profile"
	LOCAL_EXPORT_FLAG += SX_PROFILING
endif

## ------------------------------------- ##
##	List all your sources here           ##
## ------------------------------------- ##
include src/make.srcs

WITHOUT_WSHADOW=1

## ------------------------------------- ##
##  Do Not touch below this line         ##
## ------------------------------------- ##
include ${SOFT_WORKDIR}/env/compilation/compilerules.mk
