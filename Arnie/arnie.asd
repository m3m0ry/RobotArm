(defsystem "arnie"
  :version "0.0.1"
  :author "Jan Hönig"
  :licence "GLPv3"
  :depends-on ("cserial-port" "bordeaux-threads")
  :components ((:module "src"
                :components
                ((:file "arnie"))))
  :description "Command server of my robotic arm"
  :long-description
  #.(read-file-string
     (subpathname *load-pathname* "README.md"))
  :build-operation "program-op"
  :build-pathname "arnie"
  :entry-point "arnie:repl")
