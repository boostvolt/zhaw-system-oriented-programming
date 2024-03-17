SNP_SHARED_MAKEFILE := $(if $(SNP_SHARED_MAKEFILE),$(SNP_SHARED_MAKEFILE),~/snp/shared.mk)

TARGET     := bin/dep2dot
# Add all additional c-files to the SOURCES variable
# BEGIN-STUDENTS-TO-ADD-CODE
SOURCES    := src/main.c src/data.c src/output.c
# END-STUDENTS-TO-ADD-CODE
TSTSOURCES := tests/tests.c

include $(SNP_SHARED_MAKEFILE)


# DEPFILES :=  ... define a list of png file names: %.c -> %.c.png
# BEGIN-STUDENTS-TO-ADD-CODE

# DEPFILES is a list of .c.png files corresponding to each .c file in SOURCES.
# This is achieved by replacing the .c extension with .c.png for each file in SOURCES.
DEPFILES := $(SOURCES:.c=.c.png)

# END-STUDENTS-TO-ADD-CODE



# define dep target as .PHONEY
# BEGIN-STUDENTS-TO-ADD-CODE

# The .PHONEY target is used to specify that 'dep' is not a real file target.
# This means that 'make' will always run the commands associated with 'dep',
# regardless of whether a file named 'dep' exists or how up-to-date it is.
.PHONEY: dep

# END-STUDENTS-TO-ADD-CODE



# define dep target depending on FULLTARGET and DEPFILES above
# action: echo some text telling that the target is done using $@ - the echo command shall not be echoed before execution
# BEGIN-STUDENTS-TO-ADD-CODE

# The 'dep' target depends on the files in FULLTARGET and DEPFILES.
# When 'dep' is built, it prints a message indicating that the dependency files have been generated.
dep: $(FULLTARGET) $(DEPFILES)
	@echo "Dependency files generated: $@"

# END-STUDENTS-TO-ADD-CODE



# define new suffix rule for %.png depending on %.dot
# action: dot -Tpng $< >$@ || $(RM) $@
# BEGIN-STUDENTS-TO-ADD-CODE

# This rule defines how to create a .png file from a .dot file.
# It uses the 'dot' command to convert the .dot file ($<) to a .png file ($@).
# If the 'dot' command fails, it removes the output file ($@) to avoid keeping a potentially corrupted file.
%.png: %.dot
	dot -Tpng $< >$@ || $(RM) $@

# END-STUDENTS-TO-ADD-CODE



# define new suffix rule for %.dot depending on %.dep
# action: call $(TARGET) $(@:.dot=) <$< >$@ || $(RM) $@
# BEGIN-STUDENTS-TO-ADD-CODE

# This rule defines how to create a .dot file from a .dep file.
# It calls the TARGET with the name of the .dep file (without the .dep extension) as an argument.
# The output of the TARGET is redirected to the .dot file.
# If the call to the TARGET fails, it removes the output file to avoid keeping a potentially corrupted file.
%.dot: %.dep
	call $(TARGET) $(@:.dot=) <$< >$@ || $(RM) $@

# END-STUDENTS-TO-ADD-CODE



# converts any .c file into a .c.dep file by means of GCC -H switch
# note: it removes intermediate files which were created as side effect
%.c.dep: %.c
	$(COMPILE.c) -H -o $@.x $< 2>$@ && $(RM) $@.x $@.d


# cleanup all results, including the ones od creating the dependencies
dep-clean: clean
	$(RM) $(DEPFILES) $(wildcard src/*.dep src/*.dot)

