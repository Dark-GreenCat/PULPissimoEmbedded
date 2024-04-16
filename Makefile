PULP_APP = PULPissimoEmbedded	
PULP_APP_SRCS = Core/Src/main.c $(wildcard HardwareLayer/*/*.c)
PULP_CFLAGS = -O3 -g -I Core/Inc/ -I HardwareLayer/

include $(PULPRT_HOME)/rules/pulp.mk
