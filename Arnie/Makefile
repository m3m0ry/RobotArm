LISP ?= sbcl
APP ?= arnie
Q ?= @

.PHONY: clean build

build:
	$(Q)$(LISP) --eval '(asdf:make :$(APP))' --quit
#$(LISP) --load $(APP).asd \
#  	--eval '(ql:quickload :$(APP))' \
#		--eval '(asdf:make :$(APP))' \
#		--eval '(quit)'

clean:
	@echo "===>  CLEAN"
	$(Q)rm $(APP)

