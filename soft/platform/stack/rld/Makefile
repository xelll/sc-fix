## ----------------------------------------------------------- ##
## Don't touch the next line unless you know what you're doing.##
## ----------------------------------------------------------- ##
include ${SOFT_WORKDIR}/env/compilation/compilevars.mk

# Name of the module
LOCAL_NAME := platform/stack/rld

# list all modules APIs that are neccessary to compile this module
LOCAL_API_DEPENDS := platform/phy  platform/chip/defs  platform platform/base/common platform/base/std platform/base/sx platform/chip/hal platform/chip/pal \
	platform/stack platform/stack/cmn platform/stack/fsm platform/stack/itf platform/stack/cod

# list all the modules that need to be compiled prior to using this module
LOCAL_MODULE_DEPENDS ?= 

LOCAL_EXPORT_FLAG += __XCPU__ __TARGET__ __SXS_NO_FLASH_HANDLER__

# A mechanism to disable the trace compression.
ifndef SXS_NO_STR_TO_ID
LOCAL_EXPORT_FLAG += __SXS_STR_TO_ID__
endif



## ------------------------------------ ##
## 	Add your custom flags here          ##
## ------------------------------------ ##

LOCAL_EXPORT_FLAG +=

## ------------------------------------- ##
##	List all your sources here           ##
## ------------------------------------- ##
include src/make.srcs
include ../stack.mk

## ------------------------------------- ##
##  Do Not touch below this line         ##
## ------------------------------------- ##
include ${SOFT_WORKDIR}/env/compilation/compilerules.mk
