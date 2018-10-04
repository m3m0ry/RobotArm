LISP ?= sbcl
APP ?= arnie
Q ?= @

.PHONY: clean build

build:
	$(Q)$(LISP) --eval '(asdf:make :$(APP))' --quit

clean:
	@echo "===>  CLEAN"
	$(Q)rm $(APP)

