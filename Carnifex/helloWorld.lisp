;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    helloWorld.lisp                                    :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/01/23 15:59:57 by angagnie          #+#    #+#              ;
;    Updated: 2016/01/24 19:53:58 by angagnie         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

(ql:quickload 'lispbuilder-sdl)
;(require 'lispbuilder-sdl)


(defparameter *width* 1920)
(defparameter *height* 1080)
(defparameter *side* (min *width* *height*))
(defparameter *grid-w* 6)
(defparameter *grid-h* 4)
(defparameter *length* (* *grid-w* *grid-h*))
(defparameter *grid* nil)
(defparameter *speed* 1)
(defparameter *time* 0)
(defparameter *time-save* 0)
(defparameter *zoom* 8)
(defparameter *pause* 0)
(defparameter *grid-tmp* nil)


(defun new-grid (n v)
  (if (eq n 1)
	  (cons v nil)
	(cons v (new-grid (- n 1 ) v))
	)
  )

(defun get-val (grid i)
  (if (eq i 0)
	  (car grid)
	  (get-val (rest grid) (- i 1))
	)
  )

(defun get-valxy (grid x y)
  (get-val grid (+ (* y *grid-w*) x))
  )

(defun set-value (grid i v)
  (if (eq i 0)
 	  (setf (car grid) v)
	(set-value (rest grid) (- i 1) v)
	)
  )



(defun life0 (grid i)
  (set-value grid (mod (floor *time*) *length*) 1)
  (set-value grid (mod (floor (- *time* *speed*)) *length*) 0)
  grid
  ;; (if (eq i *length*)
  ;; 	  (cons 0 0)
  ;; 	(cons 0 (life (rest grid) (+ i 1)))
  ;; 	)
  )

(defun life1 (grid i)
  (let ((x (mod i *grid-w*))
		(y ))
	)
  )

(defun render ()
;  (format t "Repainting~%")
  (sdl:clear-display sdl:*black*)
  (defvar i 0)
  (defvar posx 0)
  (defvar posy 0)
  (dotimes (i (+ 0 *length*) t)
	(let ((x (mod i *grid-w*)) (y (floor (/ i *grid-w*))))
	  (setf posx (floor (/ (* x *width*) *grid-w*)))
	  (setf posy (floor (/ (* y *height*) *grid-h*)))
;	  (format t "grid[~$] = ~$~%(~$, ~$)~%" i (get-val *grid* i) x y)
	  (if (eq (get-val *grid* i) 1)
										;		(format t "Alive~%")
										;	  (format t "Dead ~%"))
		  (sdl:draw-box-* posx posy (floor (/ *width* *grid-w*)) (ceiling (/ *height* *grid-h*)) :color sdl:*white*)
		(sdl:draw-rectangle-* posx posy (floor (/ *width* *grid-w*)) (ceiling (/ *height* *grid-h*)) :color sdl:*white*))
	  )
	)
  )

(defun main (argv)
  "Makes me cry :'("
  (format t "0 : ~$~%1 : ~$~%2 : ~$~%" (first argv) (second argv) (third argv))
  (if (or (eq (length argv) 1) (eq (second argv) "-h") (eq (second argv) "--help"))
	  (format t "usage: sbcl --load game_of_life.lsp [-h] width height~%~%
positional arguments:~%
width                 width of the grid~%
height                height of the grid~%~%
optional arguments:~%
  -h, --help            show this help message and exit~%")
	(progn (setf *grid-w* (parse-integer (second argv)))
		   (setf *grid-h* (parse-integer (third argv)))
		   (setf *length* (* *grid-h* *grid-w*))
		   )
	)
  (setf *grid* (new-grid *length* 0))
  (set-value *grid* 5 1)
  (sdl:with-init ()
				 (sdl:window *width* *height* :title-caption "Conway's Game of Life")
				 (setf (sdl:frame-rate) 20)
				 (sdl:update-display)
				 (sdl:with-events ()
								  (:quit-event () (exit))
								  (:key-up-event (:KEY KEY :mod mod)
												 (format t "Key : ~$ ~$ ~%" key mod)
												 (case key
													   (:sdl-key-escape (format t " -> Pressed Esc~%")(sdl:push-quit-event))
													   (:sdl-key-kp-plus (format t " -> Pressed [+]~%")(setf *zoom* (* *zoom* 2)))
													   (:sdl-key-kp-minus (format t " -> Pressed [-]~%")(setf *zoom* (/ *zoom* 2)))
													   (:sdl-key-p (format t " -> Pressed P~%")(incf *pause* 1))
													   (:sdl-key-period (format t " -> Pressed >~%")(if (eq mod 1) (setf *speed* (* *speed* 2))))
													   (:sdl-key-comma (format t " -> Pressed <~%")(if (eq mod 1) (setf *speed* (/ *speed* 2))))
													   )
												 )
										;(:video-expose-event (sdl:update-display))
								  (:idle ()
										 (setf *time-save* *time*)
										 (incf *time* (* *speed* (mod *pause* 2)))
										 (if (not (eq (floor *time-save*) (floor *time*))) (progn
																							 ;; --=== Life 1 : Way 1 ===--
																							 (setf *grid-tmp* (new-grid *length* 2))
																							 (setf *grid* (life1 *grid* 0))
																							 ;; --=== Life 0 : debug ===--
																							 ;; (setf *grid* (life0 *grid* 0))
																							 ;; ------========------
										 													 (render)
										 													 (sdl:update-display)
										 													 ))
										 )
								  )
				 )
  )

(sb-int:with-float-traps-masked (:invalid :inexact :overflow) (main *posix-argv*))
