const char LispLibrary[] PROGMEM =
"(defvar *step-pattern* '((t t nil nil) (nil t t nil) (nil nil t t) (t nil nil t)))"
//wave_drive '((t nil nil nil) (nil t nil nil) (nil nil t nil) (nil nil nil t))
//half_step '((t nil nil nil) (t t nil nil) (nil t nil nil) (nil t t nil) (nil nil t nil) (nil nil t t) (nil nil nil t) (t nil nil t))
"(defvar *motor* '(22 24 26 28))"
"(defvar orientation 0)"

"(defun motor (steps) \
  (dotimes (x steps)\
    (mapc digitalwrite *motor* (nth (mod x 4) *step-pattern*))\
    (delay 3)))"
"(pinmode 22 1)"
"(pinmode 24 1)"
"(pinmode 26 1)"
"(pinmode 28 1)";



