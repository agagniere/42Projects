;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    carnifex.lsp                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/01/24 20:07:18 by angagnie          #+#    #+#              ;
;    Updated: 2016/01/25 01:44:18 by angagnie         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

(ql:quickload 'lispbuilder-sdl)
;(require 'lispbuilder-sdl)


(defparameter *sw* 1920)
(defparameter *sh* 1080)

(defparameter *tw* nil)
(defparameter *tx* nil)

(defparameter *vx* nil)
(defparameter *vy* nil)

(defparameter *ox* 0)
(defparameter *oy* 0)

(defparameter *grid* nil)


;; (defparameter *side* (min *width* *height*))
;; (defparameter *grid-w* 6)
;; (defparameter *grid-h* 4)
;; (defparameter *length* (* *grid-w* *grid-h*))
;; (defparameter *speed* 1)
;; (defparameter *time* 0)
;; (defparameter *time-save* 0)
;; (defparameter *zoom* 8)
;; (defparameter *pause* 0)
;; (defparameter *grid-tmp* nil)


;; (defun new-grid (n v)
;;   (if (eq n 1)
;; 	  (cons v nil)
;; 	(cons v (new-grid (- n 1 ) v))
;; 	)
;;   )

;; (defun get-val (grid i)
;;   (if (eq i 0)
;; 	  (car grid)
;; 	  (get-val (rest grid) (- i 1))
;; 	)
;;   )

;; (defun get-valxy (grid x y)
;;   (get-val grid (+ (* y *grid-w*) x))
;;   )

;; (defun set-value (grid i v)
;;   (if (eq i 0)
;;  	  (setf (car grid) v)
;; 	(set-value (rest grid) (- i 1) v)
;; 	)
;;   )

;; (defun life0 (grid i)
;;   (set-value grid (mod (floor *time*) *length*) 1)
;;   (set-value grid (mod (floor (- *time* *speed*)) *length*) 0)
;;   grid
;;   ;; (if (eq i *length*)
;;   ;; 	  (cons 0 0)
;;   ;; 	(cons 0 (life (rest grid) (+ i 1)))
;;   ;; 	)
;;   )

;; (defun set-state (initial nb total)
;;   (format t "Initial : ~$  nb : ~$  total : ~$~%" initial nb total)
;;   (if (> total 3)
;; 	  0
;; 	(if (eq (length nb) 0)
;; 		(if (< total 2)
;; 			0
;; 		  (if (eq total 3)
;; 			  1
;; 			initial
;; 			)
;; 		  )
;; 	  (set-state initial (rest nb) (+ total (car nb)))
;; 	  )
;; 	)
;;   )

;; (defun life1 (grid i)
;;   (if (eq i (- *length* (* 2 *grid-w*) 2))
;; 	  *grid-tmp*
;; 	(let* ((x (mod i *grid-w*))
;; 		   (y (floor (/ i *grid-h*)))
;; 		   (indexes (list 0 1 2 *grid-w* (+ 1 *grid-w*) (+ 2 *grid-w*) (* 2 *grid-w*) (+ 1 (* 2 *grid-w*)) (+ 2 (* 2 *grid-w*))))
;; 		   (cache (mapcar #'(lambda (idk) (get-val grid idk)) indexes))
;; 		   (cache2 (mapcar #'(lambda (idk) (get-val *grid-tmp* (+ idk i))) indexes)))
;; 	  (defparameter i 0)
;; 	  (dotimes (i 9)
;; 	  	(format t "~$[~$] = ~$ / ~$~%" i (get-val indexes i) (get-val cache i) (get-val cache2 i))
;; 	  	)
;; 	  (if (and (eq x 0) (eq y 0) (eq 2 (car cache2)))
;; 	  	  (progn (format t "csg~%")
;; 	  			 (setf
;; 				  *grid-tmp*
;; 				  (set-value
;; 				   *grid-tmp*
;; 				   i
;; 				   (set-state
;; 					(car cache)
;; 					(list (second cache) (fourth cache) (fifth cache))
;; 					0
;; 					)
;; 				   )
;; 				  )
;; 	  			 )
;; 	  	(format t "nope~%")
;; 	  	)
;; 	  ;; (if (and (eq y 0) (eq 2 (second cache2)))
;; 	  ;; 	  (progn (format t "c")
;; 	  ;; 			 ;;(setf *grid-tmp* (set-value *grid-tmp* (+ i 1) (set-state (second cache) (list (car cache) (third cache) (fourth cache) (fifth cache) (sixth cache)) 0)))
;; 	  ;; 			 )
;; 	  ;; 	(format t " ")
;; 	  ;; 	)
;; 	  ;; (if (and (eq x (- *grid-w* 3)) (eq y 0) (eq 2 (third cache2)))
;; 	  ;; 	  (progn (format t "c~%")
;; 	  ;; 			 (setf *grid-tmp* (set-value *grid-tmp* (+ i 2) (set-state (third cache) (list (second cache) (fifth cache) (sixth cache)) 0)))
;; 	  ;; 			 )
;; 	  ;; 	(format t "~%")
;; 	  ;; 	)
;; 	  ;; (if (and (eq x 0) (eq 2 (fourth cache2)))
;; 	  ;; 	  (setf *grid-tmp* (set-value *grid-tmp* (+ i *grid-w*) (set-state (fourth cache) (list (car cache) (second cache) (fifth cache) (seventh cache) (heighth cache)) 0)))
;; 	  ;; 	)
;; 	  ;; (if (eq 2 (fifth cache2))
;; 	  ;; 	  (setf *grid-tmp* (set-value *grid-tmp* (+ i 1 *grid-w*) (set-state (fifth cache) (set-value cache 5 0) 0)))
;; 	  ;; 	)
;; 	  ;; (if (and (eq x (- *grid-w* 3)) (eq 2 (sixth cache2)))
;; 	  ;; 	  (setf *grid-tmp* (set-value *grid-tmp* (+ i 2 *grid-w*) (set-state (sixth cache) (list (second cache) (third cache) (fifth cache) (heighth cache) (ninth cache)) 0)))
;; 	  ;; 	)
;; 	  ;; (if (and (eq x (- *grid-w* 3)) (eq 2 (sixth cache2)))
;; 	  ;; 	  (setf *grid-tmp* (set-value *grid-tmp* (+ i 2 *grid-w*) (set-state (sixth cache) (list (second cache) (third cache) (fifth cache) (heighth cache) (ninth cache)) 0)))
;; 	  ;; 	)
;; 	  (format t "Recursion~%")
;; 	  (life1 (rest grid) (+ i 1))
;; 	  )
;; 	)
;;   )

(defun render ()
  (dotimes (i (* 4 *vx*))
	(dotimes (j (* 4 *vy*))

	  )
	)
  )
;; ;  (format t "Repainting~%")
;;   (sdl:clear-display sdl:*black*)
;;   (defvar i 0)
;;   (defvar posx 0)
;;   (defvar posy 0)
;;   (dotimes (i (+ 0 *length*) t)
;; 	(let ((x (mod i *grid-w*)) (y (floor (/ i *grid-w*))))
;; 	  (setf posx (floor (/ (* x *width*) *grid-w*)))
;; 	  (setf posy (floor (/ (* y *height*) *grid-h*)))
;; ;	  (format t "grid[~$] = ~$~%(~$, ~$)~%" i (get-val *grid* i) x y)
;; 	  (if (eq (get-val *grid* i) 1)
;; 		  (sdl:draw-box-* posx posy (floor (/ *width* *grid-w*)) (ceiling (/ *height* *grid-h*)) :color sdl:*white*)
;; 		(sdl:draw-rectangle-* posx posy (floor (/ *width* *grid-w*)) (ceiling (/ *height* *grid-h*)) :color sdl:*white*)
;; 		)
;; 	  (if (eq (get-val *grid* i) 2)
;; 		  (sdl:draw-box-* posx posy (floor (/ *width* *grid-w*)) (ceiling (/ *height* *grid-h*)) :color sdl:*red*)
;; 		)
;; 	  )
;; 	)
;;  )

(defun init-grid ()
  (setf *grid* make-array '(*tw* *th*))
  (dotimes (i *tw*)
	(dotimes (j *th*)
	  (setf (aref *grid* i j) 0)
	  )
	)
  )

(defun zoom ()
  (incf *ox* *vx*)
  (incf *oy* *vy*)
  (setf *vx* (/ *vx* 2))
  (setf *vy* (/ *vy* 2))
  )
(defun zoom ()
  (setf *vx* (* *vx* 2))
  (setf *vy* (* *vy* 2))
  (dncf *ox* *vx*)
  (dncf *oy* *vy*)
  )

(defun main (argv)
  "Makes me cry :'("
;  (format t "0 : ~$~%1 : ~$~%2 : ~$~%" (first argv) (second argv) (third argv))
  (if (or (eq (length argv) 1) (eq (second argv) "-h") (eq (second argv) "--help"))
	  (format t "usage: sbcl --load game_of_life.lsp [-h] width height~%~%
positional arguments:~%
width                 width of the grid~%
height                height of the grid~%~%
optional arguments:~%
  -h, --help            show this help message and exit~%")
	(progn (setf *tw* (parse-integer (second argv)))
		   (setf *th* (parse-integer (third argv)))
		   (setf *vx* (floor (/ *tw* 4)))
		   (setf *vy* (floor (/ *th* 4)))
		   )
	)
  (init-grid)
  ;; --== Sample ==--
  (setf (aref *grid* 0 0) 1)
  (setf (aref *grid* 1 1) 1)
  (setf (aref *grid* 1 0) 1)
  (setf (aref *grid* 2 2) 1)
  (setf (aref *grid* 4 4) 1)
  (setf (aref *grid* 4 2) 1)
  (sdl:with-init ()
				 (sdl:window *width* *height* :title-caption "Conway's Game of Life")
				 (setf (sdl:frame-rate) 20)
				 (render)
				 (sdl:update-display)
				 (sdl:with-events ()
								  (:quit-event () (exit))
								  (:key-up-event (:KEY KEY :mod mod)
												 (format t "Key : ~$ ~$ ~%" key mod)
												 (case key
													   (:sdl-key-escape (format t " -> Pressed Esc~%")(sdl:push-quit-event))
													   (:sdl-key-kp-plus (format t " -> Pressed [+]~%")(zoom))
													   (:sdl-key-kp-minus (format t " -> Pressed [-]~%")(unzoom)
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
