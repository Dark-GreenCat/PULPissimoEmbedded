PULP_APP = main	
PULP_APP_SRCS = Core/Src/main.c HardwareLayer/gpio/gpio_hcl.c
PULP_CFLAGS = -O3 -g -I Core/Inc/ -I HardwareLayer/*/

include $(PULPRT_HOME)/rules/pulp.mk
