PULP_APP = PULPissimoEmbedded	
PULP_APP_SRCS = Core/Src/main.c Core/Src/delay.S
PULP_CFLAGS = -O3 -g

include $(PULPRT_HOME)/rules/pulp.mk
