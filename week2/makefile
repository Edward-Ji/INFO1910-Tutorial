# Set variables
CCOMPILER = gcc
COMPILERFLAGS = -Wall -Werror
TARGETS = $(wildcard *.c)

# If the rule all is given then make the target
all: $(TARGET)

# If a particular target is given then make it
$(TARGETS):
	$(CCOMPILER) $(COMPILERFLAGS) -o $@ $@.c
	./$@

# If the rule clean is given then clean up the compiled files
clean:
	rm $(TARGETS)