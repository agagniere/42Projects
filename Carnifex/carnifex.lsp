;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    carnifex.lsp                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/01/24 20:07:18 by angagnie          #+#    #+#              ;
;    Updated: 2016/01/28 17:34:17 by angagnie         ###   ########.fr        ;
;                                                                              ;
;******************************************************************************;

(ql:quickload 'lispbuilder-sdl)

;; --== Global Variables ==--

;; Screen Dimensions
(defparameter *sw* 1920)
(defparameter *sh* 1080)

;; Grid Dimensions
(defparameter *tw* nil)
(defparameter *th* nil)

;; View system
(defparameter *vx* 2)
(defparameter *vy* 1)

;; View Position
(defparameter *ox* 0)
(defparameter *oy* 0)

;; The grid
(defparameter *grid* nil)

;; Background Color and Foreground Color
(defparameter *background* sdl:*black*)
(defparameter *foreground* sdl:*white*)

;; Time, time-speed and time-pause
(defparameter *time* 0)
(defparameter *speed* 1)
(defparameter *pause* 0)

;; Bounds : 1 => limits
;;			_ => free
(defparameter *bounds* 0)

;; Show grid ? (boolean)
(defparameter *show-grid* 0)

(defun convert (index total screen)
  (floor (/ (* index screen) total))
  )
(defun unconvert (pixel total screen)
  (floor (/ (* pixel total) screen))
  )

;; Render visible cells
(defun render ()
  (sdl:clear-display *background*)
  (let ((vw (* 4 *vx*)) (vh (* 4 *vy*)))
	(dotimes (i vw)
	  (if (and (< (+ i *ox*) *tw*) (>= (+ i *ox*) 0))
		  (dotimes (j vh)
			(if (and (< (+ j *oy*) *th*) (>= (+ j *oy*) 0))
				(if (eq 1 (aref *grid* (+ i *ox*) (+ j *oy*)))
					(sdl:draw-box-* (convert i vw *sw*) (convert j vh *sh*) (convert 1 vw *sw*) (convert 1 vh *sh*) :color *foreground*)
				  (if (eq *show-grid* 1) (sdl:draw-rectangle-* (convert i vw *sw*) (convert j vh *sh*) (convert 1 vw *sw*) (convert 1 vh *sh*) :color *foreground*))
				  )
			  )
			)
		)
	  )
	)
  )

(defun init-grid ()
  (format t "Creating Grid~%")
  (setf *grid* (make-array (list *tw* *th*)))
  (dotimes (i *tw*)
	(dotimes (j *th*)
	  (setf (aref *grid* i j) 0)
	  )
	)
  )

(defun zoom ()
  (if (> *vy* 1)
	  (progn
		(incf *ox* *vx*)
		(incf *oy* *vy*)
		(setf *vx* (/ *vx* 2))
		(setf *vy* (/ *vy* 2))
		)
	)
  )

(defun unzoom ()
  (setf *vx* (* *vx* 2))
  (setf *vy* (* *vy* 2))
  (if (eq *bounds* 1)
	  (progn ; then
		(setf *ox* (max 0 (- *ox* *vx*)))
		(setf *oy* (max 0 (- *oy* *vy*))))
	(progn ; else
	  (decf *ox* *vx*)
	  (decf *oy* *vy*))
	)
  )

(defun life (grid)
  (dotimes (i *tw*)
	(dotimes (j *th*)
	  (let ((total 0))
		(if (> i 0) (incf total (aref *grid* (- i 1) j)))
		(if (> j 0) (incf total (aref *grid* i (- j 1))))
		(if (and (> i 0) (> j 0)) (incf total (aref *grid* (- i 1) (- j 1))))
		(if (< i (- *tw* 1)) (incf total (aref *grid* (+ i 1) j)))
		(if (< j (- *th* 1)) (incf total (aref *grid* i (+ j 1))))
		(if (and (< i (- *tw* 1)) (< j (- *th* 1))) (incf total (aref *grid* (+ i 1) (+ j 1))))
		(if (and (> i 0) (< j (- *th* 1))) (incf total (aref *grid* (- i 1) (+ j 1))))
		(if (and (> j 0) (< i (- *tw* 1))) (incf total (aref *grid* (+ i 1) (- j 1))))
		;; --==--
		(setf (aref grid i j) (aref *grid* i j))
		(if (or (> total 3) (< total 2)) (setf (aref grid i j) 0))
		(if (= total 3) (setf (aref grid i j) 1))
		)
	  )
	)
  )

(defun grid-copy (grid)
  (dotimes (x *tw*)
	(dotimes (y *th*)
	  (setf (aref *grid* x y) (aref grid x y))
	  )
	)
  )

(defun main (argv)
  "Better now"
  (format t "0 : ~$~%1 : ~$~%2 : ~$~%" (first argv) (second argv) (third argv))
  (if (or (eq (length argv) 1) (eq (second argv) "-h") (eq (second argv) "--help"))
	  (progn (format t "usage: sbcl --load game_of_life.lsp [-h] width height~%~%
positional arguments:~%width                 width of the grid~%height                height of the grid~%~%optional arguments:~%
  -h, --help            show this help message and exit~%")
			 (exit)
			 )
	(progn (setf *tw* (parse-integer (second argv)))
		   (setf *th* (parse-integer (third argv)))
		   (setf *ox* (- (/ *tw* 2) 4))
		   (setf *oy* (- (/ *th* 2) 2))
		   )
	)
  (init-grid)
  (sdl:with-init ()
				 (sdl:window *sw* *sh* :title-caption "Conway's Game of Life")
				 (setf (sdl:frame-rate) 20)
				 (render)
				 (sdl:update-display)
				 (sdl:with-events ()
								  (:quit-event () (exit))
								  (:mouse-button-up-event (:button button :x x :y y)
														  (format t "Button : ~$ Coordonnees = x : ~$ y : ~$ ~%" button x y)
														  (let ((tx (+ *ox* (unconvert x (* 4 *vx*) *sw*)))
																(ty (+ *oy* (unconvert y (* 4 *vy*) *sh*))))
															(format t "x : ~$  y : ~$~%" tx ty)
															(if (and (< tx *tw*) (< ty *th*) (>= tx 0) (>= ty 0))
																(case button
																	  (1 (setf (aref *grid* tx ty) 1))
																	  (3 (setf (aref *grid* tx ty) 0))
																	  )
															  )
															)
														  (render)
														  (sdl:update-display)
														  )
								  (:key-up-event (:KEY KEY :mod mod)
												 (format t "Key : ~$ ~$ ~%" key mod)
												 (case key
													   (:sdl-key-escape		(sdl:push-quit-event))
													   (:sdl-key-kp-plus	(zoom))
													   (:sdl-key-kp-minus	(unzoom))
													   (:sdl-key-p			(incf *pause* 1))
													   (:sdl-key-period		(if (eq mod 1) (setf *speed* (* *speed* 2))))
													   (:sdl-key-comma		(if (eq mod 1) (setf *speed* (/ *speed* 2))))
													   (:sdl-key-w			(if (eq *bounds* 1)
																				(setf *oy* (max 0 (- *oy* *vy*)))
																			  (decf *oy* *vy*)))
													   (:sdl-key-s			(if (eq *bounds* 1)
																				(setf *oy* (min (- *th* (* 4 *vy*)) (+ *oy* *vy*)))
																			  (incf *oy* *vy*)))
													   (:sdl-key-a			(if (eq *bounds* 1)
																				(setf *ox* (max 0 (- *ox* *vx*)))
																			  (decf *ox* *vx*)))
													   (:sdl-key-d			(if (eq *bounds* 1)
																				(setf *ox* (min (- *tw* (* 4 *vx*)) (+ *ox* *vx*)))
																			  (incf *ox* *vx*)))
													   (:sdl-key-r			(progn (init-grid)
																				   (setf *pause* 0)))
													   )
												 (render)
												 (sdl:update-display)
												 )
								  ;(:video-expose-event (format t "Video Expose Event~%")(sdl:update-display))
								  (:idle ()
										 (let ((time-save *time*))
										   (incf *time* (* *speed* (mod *pause* 2)))
										   (if (not (eq (floor time-save) (floor *time*))) (progn
																							 (let ((grid-tmp (make-array (list *tw* *th*))))
																							   (life grid-tmp)
																							   (grid-copy grid-tmp)
																							   )
																							 (render)
																							 (sdl:update-display)
																							 )
											 )
										   )
										 )
								  )
				 )
  )

(sb-int:with-float-traps-masked (:invalid :inexact :overflow) (main *posix-argv*))
