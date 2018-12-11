const char LispLibrary[] PROGMEM =
"\
\
(defvar *full_step* '((t t nil nil) (nil t t nil) (nil nil t t) (t nil nil t)))\
(defvar *wave_drive* '((t nil nil nil) (nil t nil nil) (nil nil t nil) (nil nil nil t)))\
(defvar *half_step* '((t nil nil nil) (t t nil nil) (nil t nil nil) (nil t t nil) (nil nil t nil) (nil nil t t) (nil nil nil t) (t nil nil t)))\
(defvar *step-pattern* *full_step*)\
\
(defvar *motors* '((22 24 26 28) (30 32 34 36) (38 40 42 44) (46 48 50 52)))\
(defvar *orientations* '(0 0 0 0))\
\
(defun motor (steps motor)\
  (let ((m (nth motor *motors*))\
        (step-length (length *step-pattern*))\
        (orientation (nth motor *orientations*))\
        (1+- (if (plusp steps) 1 -1)))\
    (dotimes (x (abs steps))\
      (setf orientation (mod (+ 1+- orientation) step-length))\
      (mapc #'digitalwrite m (nth orientation *step-pattern*))\
      (delayMicroseconds 2500))\
    (setf (nth motor *orientations*) orientation)))\
\
(dolist (motor *motors*)\
  (dolist (pin motor)\
    (pinmode pin 1)))\
";
