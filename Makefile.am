
bin_PROGRAMS = sndbanker
bindir = $(prefix)/$(PACKAGE)

sndbanker_SOURCES = \
	src/sndbanker.cpp \
	src/sndbanker_ver.h \
	src/prog_options.h \
	config.h

if HAS_WINDRES
sndbanker_RESRCS = sndbanker_stdres.res
else
sndbanker_RESRCS =
endif

if HAS_WINDRES
%.res: $(top_srcdir)/res/%.rc
	$(WINDRES) $(sndbanker_RCFLAGS) -i $< -J rc -o $@ -O coff
endif

doc_DATA = README.md
docdir = $(prefix)/$(PACKAGE)

EXTRA_DIST = GPL3 doc res

# Include dynamic libraries in the package
if TARGET_WINDOWS
install-exec-hook:
	mkdir -p "$(DESTDIR)${prefix}/$(PACKAGE)"
	## Find main executable dependencies
	$(eval lib_SHARED_INSTALL := $(shell objdump -p sndbanker$(EXEEXT) | \
		sed -n 's/\s*\(DLL Name:\|NEEDED\)\s*\(.*\)$$/\2/p' | \
		xargs -I {} find $(shell dirname $(shell which ${CXX})) -name '{}'))
	## Find sub-dependencies for the previous dependencies
	$(eval lib_SHARED_INSTALL += $(shell echo -n '$(lib_SHARED_INSTALL)' | \
        xargs -d ' ' -I {} objdump -p '{}' | \
		sed -n 's/\s*\(DLL Name:\|NEEDED\)\s*\(.*\)$$/\2/p' | \
		xargs -I {} find $(shell dirname $(shell which ${CXX})) -name '{}'))
	## Remove duplicates
	$(eval lib_SHARED_INSTALL := $(sort $(lib_SHARED_INSTALL)))
	cp $(lib_SHARED_INSTALL) $(DESTDIR)${prefix}/$(PACKAGE)
endif

install-data-hook:
	cd "$(DESTDIR)${prefix}/$(PACKAGE)"; \
	mv README.md sndbanker_readme.md
