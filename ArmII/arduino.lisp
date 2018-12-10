; Here are arduino functions, which are needed for testing
(in-package #:cl-user)

(when (find-package :arduino) (delete-package :arduino))

(defpackage :arduino (:use :common-lisp))

(in-package :arduino)

(defparameter *arduino-functions*
  '("millis"
    "for-millis"
    "with-i2c"
    "restart-i2c"
    "with-serial"
    "with-spi"
    "with-sd-card"
    "pinmode"
    "digitalread"
    "digitalwrite"
    "analogread"
    "analogwrite"
    "delay"
    "note"))

(defun generate-function (name)
  (lambda (&rest args) (format t "~a:~{ ~a~}~%" name args)))

(dolist (af *arduino-functions*)
  (let ((sym (intern (string-upcase af))))
    (setf (fdefinition sym)
          (generate-function af))
    (setf (documentation sym 'function)
          (format nil "Simulated call to the arduino function ~a" af))
    (export sym)))
