PULP_APP = test
PULP_APP_SRCS = test.c gpio_hcl.c
PULP_CFLAGS = -O3 -g

include $(PULPRT_HOME)/rules/pulp.mk
