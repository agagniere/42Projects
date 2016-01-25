;******************************************************************************;
;                                                                              ;
;                                                         :::      ::::::::    ;
;    carnifex.lsp                                       :+:      :+:    :+:    ;
;                                                     +:+ +:+         +:+      ;
;    By: angagnie <angagnie@student.42.fr>          +#+  +:+       +#+         ;
;                                                 +#+#+#+#+#+   +#+            ;
;    Created: 2016/01/24 20:07:18 by angagnie          #+#    #+#              ;
;    Updated: 2016/01/25 22:00:23 by angagnie         ###   ########.fr        ;
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
	  (if (< (+ i *ox*) *tw*)
		  (dotimes (j vh)
			(if (< (+ j *oy*) *th*)
				(if (eq 1 (aref *grid* (+ i *ox*) (+ j *oy*)))
					(sdl:draw-box-* (convert i vw *sw*) (convert j vh *sh*) (convert 1 vw *sw*) (convert 1 vh *sh*) :color *foreground*)
				  (sdl:draw-rectangle-* (convert i vw *sw*) (convert j vh *sh*) (convert 1 vw *sw*) (convert 1 vh *sh*) :color *foreground*)
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
  (setf *ox* (max 0 (- *ox* *vx*)))
  (setf *oy* (max 0 (- *oy* *vy*)))
  )

(defun main (argv)
  "Makes me cry :'("
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
  ;; --== Sample ==--
  (setf (aref *grid* 0 0) 1)
  (setf (aref *grid* 1 1) 1)
  (setf (aref *grid* 1 0) 1)
  (setf (aref *grid* 2 2) 1)
  (setf (aref *grid* 4 4) 1)
  (setf (aref *grid* 4 2) 1)
  (setf (aref *grid* 10 10) 1)
  (setf (aref *grid* (/ *tw* 2) (/ *th* 2)) 1)
  (setf (aref *grid* (+ 3 (/ *tw* 2)) (/ *th* 2)) 1)
  (setf (aref *grid* (/ *tw* 2) (+ 3 (/ *th* 2))) 1)
  ;; --====--
  (sdl:with-init ()
				 (sdl:window *sw* *sh* :title-caption "Conway's Game of Life")
				 (setf (sdl:frame-rate) 20)
				 (render)
				 (sdl:update-display)
				 (sdl:with-events ()
								  (:quit-event () (exit))
								  (:mouse-button-up-event (:button button :x x :y y)
														  (format t "Button : ~$ Coordonnees = x : ~$ y : ~$ ~%" button x y)
														  (case button
																(let ((tx (+ *ox* (unconvert x (* 4 *vx*) *sw*)))
																	  (ty (+ *oy* (unconvert y (* 4 *vy*) *sh*))))
																  (format t "x : ~$  y : ~$~%" tx ty)
																  (if (and (< tx *tw*) (< ty *th*))
																	  (progn
																		(1 (setf (aref *grid* tx ty) 1))
																		(2 (setf (aref *grid* tx ty) 0))
																		)
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
													   (:sdl-key-w			(setf *oy* (max 0 (- *oy* *vy*))))
													   (:sdl-key-s			(setf *oy* (min (- *th* (* 4 *vy*)) (+ *oy* *vy*))))
													   (:sdl-key-a			(setf *ox* (max 0 (- *ox* *vx*))))
													   (:sdl-key-d			(setf *ox* (min (- *tw* (* 4 *vx*)) (+ *ox* *vx*))))
													   )
												 (render)
												 (sdl:update-display)
												 )
								  ;(:video-expose-event (format t "Video Expose Event~%")(sdl:update-display))
								  (:idle ()
										 (let ((time-save *time*))
										   (incf *time* (* *speed* (mod *pause* 2)))
										   (if (not (eq (floor time-save) (floor *time*))) (progn
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
