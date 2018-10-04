(defpackage #:arnie
  (:use :cl)
  (:export #:connect #:disconnect #:kill-reader #:repl))

(in-package :arnie)

(defvar *arduino* nil)
(defvar *reader* nil)

(defun read-serial-until (serial &key (stop-char #\Newline))
  ;(when (cserial-port:serial-input-available-p serial)
    (loop for c = (cserial-port:read-serial-char serial)
          with l = '()
          when (char/= c #\Return)
            do (push c l)
            and
              when (char= c stop-char) do (return (coerce (reverse l) 'string))))

(defun connect ( &key (name "/dev/ttyACM0") (baud-rate 115200))
  (when (null *arduino*)
    (setf *arduino*
          (cserial-port:open-serial name :baud-rate baud-rate))))

(defun disconnect ()
  (prog1
      (cserial-port:close-serial *arduino*)
    (setf *arduino* nil)))

(defun kill-reader ()
  (when (bt:thread-alive-p *reader*)
    (bt:destroy-thread *reader*))
  (setf *reader* nil))

(defun repl ()
  (connect)
  (when (null *reader*)
    (setf *reader* (bt:make-thread #'reading)))
  ;TODO catch EOF and break
  (loop for line = (string (read-line))
        do (cserial-port:write-serial-string line *arduino*))
  (kill-reader)
  (disconnect))

(defun reading()
  (loop
    do (format t (read-serial-until *arduino*))
    do (sleep 1)))
